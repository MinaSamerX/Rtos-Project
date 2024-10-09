/*
 * system.c
 *
 *  Created on: Sep 15, 2024
 *      Author: Mina
 */


#include "system.h"
#include"RTOS_cfg/includes.h"


/* Define initial heating levels for driver and passenger */
HeatingLevel ucDriverHeaterIntensity    = TURN_OFF_HEATER;       /* Initialize driver heater intensity */
HeatingLevel ucPassengerHeaterIntensity = TURN_OFF_HEATER;    /* Initialize passenger heater intensity */

/* Define desired temperature for driver and passenger seats */
uint8 usDriver_Seat_Desired_Temp    = HEATING_LVL_OFF;          /* Initialize driver seat desired temperature */
uint8 usPassenger_Seat_Desired_Temp = HEATING_LVL_OFF;        /* Initialize passenger seat desired temperature */

/* Define current temperature variables for driver and passenger seats */
uint16 usDriverSeatCurrentTemp;                               /* Variable to hold driver seat current temperature */
uint16 usPassengerSeatCurrentTemp;                            /* Variable to hold passenger seat current temperature */

/* Define a structure to record failures */
FailureRecord latestFailure[2];                               /* Array to hold latest failure records */

TaskInformation DriverSeatTask =
{
 /* Driver Task ID*/ DRIVER_TASK_ID,                          /* Task ID for driver seat */
 /* Driver Seat Button */  SW1_BUTTON_INDEX,          /* Button pin number for driver seat */
 /* Driver Seat Button Presses Count */ 0,                    /* Button presses count for driver seat */
 /* Driver Seat Heating Temp*/ HEATING_LVL_OFF               /* Initial heating level for driver seat */
};

/* Structure to hold passenger seat task information */
TaskInformation PassengerSeatTask =
{
 /* Passenger Task ID*/ PASSENGER_TASK_ID,                    /* Task ID for passenger seat */
 /* Passenger Seat Button */  SW2_BUTTON_INDEX,       /* Button pin number for passenger seat */
 /* Passenger Seat Button Presses Count*/ 0,                  /* Button presses count for passenger seat */
 /* Passenger Seat Heating Temp*/ HEATING_LVL_OFF            /* Initial heating level for passenger seat */
};

/*******************************************************************************
 *                         Public Functions Definitions                        *
 *******************************************************************************/

/************************************************************************************
 * Service Name: Init_Task
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * Parameters (in): None
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Task executes once to initialize all the Modules.
 ************************************************************************************/
void Init_Task(void)
{
    /* Initialize Mcu Driver */
    Mcu_Init();

    /* Initialize Dio Driver */
    Dio_Init(&Dio_Configuration);

    /* Initialize Port Driver */
    Port_Init(&Port_Configuration);

    /* Initialize UART0 Driver */
    UART0_Init();

    /* Initialize ADC0 Driver */
    ADC0_Init();

    /* Initialize ADC1 Driver */
    ADC1_Init();
}

/************************************************************************************
Service name:           Heat_LVL
Sync/Async:             Asynchronous
Reentrancy:             Reentrant for different tasks
Parameters (in):        pTaskInformation - Pointer to TaskInformation structure
                        SeatsRequiredTemperatures[] - array for lvls
                        Button_flag - flag for checking
Parameters (inout):     None
Parameters (out):       None
Return value:           None
Description:            Task to manage seat heating levels based on button presses.
                        Handles button presses, updates desired temperatures, and communicates
                        with UART0 if necessary. Monitors a specific seat identified by TaskInformation.
 ************************************************************************************/
void Heat_LVL(TaskInformation *pTaskInformation ,uint8 Button_flag ,uint8 *SeatsRequiredTemperatures)
{
    if (Button_GetState(pTaskInformation->ucSeatButton) == BUTTON_PRESSED) /* Check if button is pressed */
    {
        if (Button_flag == 0) /* Check if button flag is not set */
        {
            pTaskInformation->ucSeatButtonPressesCount += 1; /* Increment button press count */
            if ((pTaskInformation->ucSeatButtonPressesCount) == 4) /* Check if button press count reaches maximum */
            {
                pTaskInformation->ucSeatButtonPressesCount = 0; /* Reset button press count */
            }
            pTaskInformation->ucSeatHeatingTemp = SeatsRequiredTemperatures[pTaskInformation->ucSeatButtonPressesCount]; /* Update desired temperature */

            if (pTaskInformation->ucTaskID == PASSENGER_TASK_ID) /* Check if task is for passenger */
            {
                usPassenger_Seat_Desired_Temp = pTaskInformation->ucSeatHeatingTemp; /* Update passenger seat desired temperature */
#ifdef DEBUG
                if (xSemaphoreTake(xMutex, portMAX_DELAY) == pdTRUE){
                    UART0_SendInteger(usPassenger_Seat_Desired_Temp); /* Example: Send temperature via UART0 */
                    xSemaphoreGive(xMutex);
                }
#endif
            }
            else
            {
                usDriver_Seat_Desired_Temp = pTaskInformation->ucSeatHeatingTemp; /* Update driver seat desired temperature */
#ifdef DEBUG
                if (xSemaphoreTake(xMutex, portMAX_DELAY) == pdTRUE){
                    UART0_SendInteger(usDriver_Seat_Desired_Temp); /* Example: Send temperature via UART0 */
                    UART0_SendString("Driver ^^\r\n"); /* Example: Send debug message via UART0 */
                    xSemaphoreGive(xMutex);
                }
#endif
            }
            Button_flag = 1; /* Set button flag indicating button was pressed */
            xEventGroupSetBits(xSystemEventGroup, SEAT_MONITOR_TASK_BIT); /* Set event bit for seat monitor task */
        }
    }
    else
    {
        Button_flag = 0; /* Reset button flag indicating button is not pressed */
    }
    vTaskDelay(pdMS_TO_TICKS(200)); /* Delay task execution for 200 milliseconds */
}

/************************************************************************************
Service name:           Get_Temp
Sync/Async:             Asynchronous
Reentrancy:             Reentrant for different tasks
Parameters (in):        None
Parameters (inout):     None
Parameters (out):       None
Return value:           None
Description:            Task to read current temperatures from ADC channels.
                        Calculates current temperatures for driver and passenger seats
                        and updates global variables. Communicates temperature readings
                        using UART0. Monitors ADC channels ADC0 and ADC1.
 ************************************************************************************/
void Get_Temp(void)
{
    usDriverSeatCurrentTemp = LM35_getTemperature(SEAT1_INDEX); /* Read and calculate driver seat temperature */
    Delay_MS(10);
    usPassengerSeatCurrentTemp = LM35_getTemperature(SEAT2_INDEX); /* Read and calculate passenger seat temperature */
    xEventGroupSetBits(xSystemEventGroup, SEAT_CURRENT_TEMP_TASK_BIT); /* Set event bit for current temperature task */
    vTaskDelay(pdMS_TO_TICKS(500)); /* Delay task execution for 500 milliseconds */
}

/************************************************************************************
Service name: Heater_Monitor
Sync/Async: Synchronous
Reentrancy: Non Reentrant
Parameters (in): xEventGroupValue
                 xBitsToWaitFor
Parameters (inout): None
Parameters (out): None
Return value: None
Description: Monitors seat heater temperatures and adjusts heater intensities based on desired and current temperatures for both driver and passenger seats.
 ************************************************************************************/
void Heater_Monitor(EventBits_t xEventGroupValue, const EventBits_t xBitsToWaitFor)
{


    /* Block to wait for event bits to become set within the event group. */
    xEventGroupValue = xEventGroupWaitBits(
            xSystemEventGroup, /* The event group to read. */
            xBitsToWaitFor,   /* Bits to test. */
            pdTRUE,           /* Clear bits on exit if the unblock condition is met. */
            pdFALSE,          /* Don't wait for all bits. */
            portMAX_DELAY     /* Don't time out. */
    );

    if (((xEventGroupValue & SEAT_CURRENT_TEMP_TASK_BIT) != 0) || ((xEventGroupValue & SEAT_MONITOR_TASK_BIT) != 0))
    {
        if ((usDriver_Seat_Desired_Temp - usDriverSeatCurrentTemp) >= 10)
        {
            ucDriverHeaterIntensity = HIGH_HEATER_INTENSITY;
        }
        else if ((usDriver_Seat_Desired_Temp - usDriverSeatCurrentTemp) >= 5 && (usDriver_Seat_Desired_Temp - usDriverSeatCurrentTemp) < 10)
        {
            ucDriverHeaterIntensity = MEDIUM_HEATER_INTENSITY;
        }
        else if ((usDriver_Seat_Desired_Temp - usDriverSeatCurrentTemp) > 2 && (usDriver_Seat_Desired_Temp - usDriverSeatCurrentTemp) < 5)
        {
            ucDriverHeaterIntensity = LOW_HEATER_INTENSITY;
        }
        else if ((usDriverSeatCurrentTemp - usDriver_Seat_Desired_Temp) <= 3)
        {
            ucDriverHeaterIntensity = TURN_OFF_HEATER;
        }
        else
        {
            /* Nothing to do */
        }

        if ((usPassenger_Seat_Desired_Temp - usPassengerSeatCurrentTemp) >= 10)
        {
            ucPassengerHeaterIntensity = HIGH_HEATER_INTENSITY;
        }
        else if ((usPassenger_Seat_Desired_Temp - usPassengerSeatCurrentTemp) >= 5 && (usPassenger_Seat_Desired_Temp - usPassengerSeatCurrentTemp) < 10)
        {
            ucPassengerHeaterIntensity = MEDIUM_HEATER_INTENSITY;
        }
        else if ((usPassenger_Seat_Desired_Temp - usPassengerSeatCurrentTemp) > 2 && (usPassenger_Seat_Desired_Temp - usPassengerSeatCurrentTemp) < 5)
        {
            ucPassengerHeaterIntensity = LOW_HEATER_INTENSITY;
        }
        else if ((usPassengerSeatCurrentTemp - usPassenger_Seat_Desired_Temp) <= 3)
        {
            ucPassengerHeaterIntensity = TURN_OFF_HEATER;
        }
        else
        {
            /* Nothing to do */
        }
    }

    xEventGroupSetBits(xSystemEventGroup, SEAT_HEATER_INTENSITY_TASK_BIT);
    xEventGroupSetBits(xSystemEventGroup, SEAT_CURRENT_TEMP_TASK_BIT);
    vTaskDelay(500);

}

/************************************************************************************
Service name: Heater_control
Sync/Async: Synchronous
Reentrancy: Non Reentrant
Parameters (in): xEventGroupValue
                 xBitsToWaitFor
Parameters (inout): None
Parameters (out): None
Return value: None
Description: Controls the activation of seat heaters based on the intensity levels calculated by the Heater Monitor task.
 ************************************************************************************/
void Heater_control(EventBits_t xEventGroupValue, const EventBits_t xBitsToWaitFor)
{
    xEventGroupValue = xEventGroupWaitBits(
            xSystemEventGroup, /* The event group to read. */
            xBitsToWaitFor,   /* Bits to test. */
            pdTRUE,           /* Clear bits on exit if the unblock condition is met. */
            pdFALSE,          /* Don't wait for all bits. */
            portMAX_DELAY     /* Don't time out. */
    );
    if (((xEventGroupValue & xBitsToWaitFor ) != 0))
    {
        if (ucDriverHeaterIntensity == LOW_HEATER_INTENSITY)
        {
            Led_SetOff(BLUE_LED_Index);
            Led_SetOn(GREEN_LED_Index);
            Delay_MS(250);
        }
        else if (ucDriverHeaterIntensity == MEDIUM_HEATER_INTENSITY)
        {
            Led_SetOn(BLUE_LED_Index);
            Led_SetOff(GREEN_LED_Index);
            Delay_MS(250);
        }
        else if (ucDriverHeaterIntensity == HIGH_HEATER_INTENSITY)
        {
            Led_SetOn(BLUE_LED_Index);
            Led_SetOn(GREEN_LED_Index);
            Delay_MS(250);
        }
        else
        {
            Led_SetOff(BLUE_LED_Index);
            Led_SetOff(GREEN_LED_Index);
            Delay_MS(250);
        }

        /* Control passenger seat heater */
        if (ucPassengerHeaterIntensity == LOW_HEATER_INTENSITY)
        {
            Led_SetOff(BLUE_LED_Index);
            Led_SetOn(GREEN_LED_Index);
            Delay_MS(250);
        }
        else if (ucPassengerHeaterIntensity == MEDIUM_HEATER_INTENSITY)
        {
            Led_SetOn(BLUE_LED_Index);
            Led_SetOff(GREEN_LED_Index);
            Delay_MS(250);
        }
        else if (ucPassengerHeaterIntensity == HIGH_HEATER_INTENSITY)
        {
            Led_SetOn(BLUE_LED_Index);
            Led_SetOn(GREEN_LED_Index);
            Delay_MS(250);
        }
        else
        {
            Led_SetOff(BLUE_LED_Index);
            Led_SetOff(GREEN_LED_Index);
            Delay_MS(250);
        }
    }
}

/************************************************************************************
Service name: Dashbord
Sync/Async: Synchronous
Reentrancy: Non Reentrant
Parameters (in): xEventGroupValue
                 xBitsToWaitFor
Parameters (inout): None
Parameters (out): None
Return value: None
Description: Updates and displays dashboard information including seat heater states, desired and current temperatures, task execution times, and CPU load on the UART console.
 *************************************************************************************/
void Dashbord (EventBits_t xEventGroupValue, const EventBits_t xBitsToWaitFor)
{
    xEventGroupValue = xEventGroupWaitBits(
            xSystemEventGroup,             /* The event group to read. */
            xBitsToWaitFor,                /* Bits to test. */
            pdTRUE,                        /* Clear bits on exit if the unblock condition is met. */
            pdFALSE,                       /* Don't wait for all bits. */
            portMAX_DELAY                  /* Don't time out. */
    );
    if (((xEventGroupValue & xBitsToWaitFor ) != 0))
    {
        if (xSemaphoreTake(xMutex, portMAX_DELAY) == pdTRUE){
            UART0_SendString("\033[2J");  // Clear the entire screen
            UART0_SendString("\033[H");   // Move cursor to the top-left corner
            UART0_SendString("\t\tDriver Seat ");
            UART0_SendString("\t  Passenger Seat ");
            UART0_SendString("\r\n\nHEATER STATE:       ");
            switch (ucDriverHeaterIntensity)
            {
            case 4:
                UART0_SendString("OFF");
                break;
            case 3:
                UART0_SendString("HIGH");
                break;
            case 2:
                UART0_SendString("MEDIUM");
                break;
            case 1:
                UART0_SendString("LOW");
                break;
            default:
                break;
            }

            UART0_SendString("                 ");
            switch (ucPassengerHeaterIntensity)
            {
            case 4:
                UART0_SendString("OFF");
                break;
            case 3:
                UART0_SendString("HIGH");
                break;
            case 2:
                UART0_SendString("MEDIUM");
                break;
            case 1:
                UART0_SendString("LOW");
                break;
            default:
                break;
            }

            UART0_SendString("\r\n\nRequired Temp:       ");
            UART0_SendInteger(usDriver_Seat_Desired_Temp);
            UART0_SendString("                   ");
            UART0_SendInteger(usPassenger_Seat_Desired_Temp);
            UART0_SendString("\r\n\nCurrent Temp:       ");
            UART0_SendInteger(usDriverSeatCurrentTemp);
            UART0_SendString("                   ");
            UART0_SendInteger(usPassengerSeatCurrentTemp);

            taskENTER_CRITICAL();
            UART0_SendString("\r\n\nIdleTask execution time is ");
            UART0_SendInteger(ullTasksTotalTime[0] / 10);
            UART0_SendString(" msec \r\n");
            UART0_SendString("DriverSeatHeatingLevelTask execution time is ");
            UART0_SendInteger(ullTasksTotalTime[1] / 10);
            UART0_SendString(" msec \r\n");
            UART0_SendString("PassengerSeatHeatingLevelTask execution time is ");
            UART0_SendInteger(ullTasksTotalTime[2] / 10);
            UART0_SendString(" msec \r\n");
            UART0_SendString("HeaterMonitorTask execution time is ");
            UART0_SendInteger(ullTasksTotalTime[5] / 10);
            UART0_SendString(" msec \r\n");
            UART0_SendString("HeaterControlTask execution time is ");
            UART0_SendInteger(ullTasksTotalTime[6] / 10);
            UART0_SendString(" msec \r\n");
            UART0_SendString("GetCurrentTempTask execution time is ");
            UART0_SendInteger(ullTasksTotalTime[3] / 10);
            UART0_SendString(" msec \r\n");
            UART0_SendString("DashboardDisplayTask execution time is ");
            UART0_SendInteger(ullTasksTotalTime[7] / 10);
            UART0_SendString(" msec \r\n");
            UART0_SendString("FailureHandleTask execution time is ");
            UART0_SendInteger(ullTasksTotalTime[4] / 10);
            UART0_SendString(" msec \r\n");
            UART0_SendString("RunTimeMeasurementsTask execution time is ");
            UART0_SendInteger(ullTasksTotalTime[8] / 10);
            UART0_SendString(" msec \r\n");
            UART0_SendString("CPU Load is ");
            UART0_SendInteger(ucCPU_Load);
            UART0_SendString("% \r\n");
            taskEXIT_CRITICAL();
            xSemaphoreGive(xMutex);
        }
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

/************************************************************************************
Service name: Failure_Handle
Sync/Async: Synchronous
Reentrancy: Non Reentrant
Parameters (in): xEventGroupValue
                 xBitsToWaitFor
Parameters (inout): None
Parameters (out): None
Return value: None
Description: Handles temperature sensor failure conditions for driver and passenger seats.
             Updates latest failure information and adjusts heater intensity accordingly.
 ************************************************************************************/
void Failure_Handle(EventBits_t xEventGroupValue, const EventBits_t xBitsToWaitFor)
{

    xEventGroupValue = xEventGroupWaitBits(
            xSystemEventGroup,             /* The event group to read. */
            xBitsToWaitFor,                /* Bits to test. */
            pdTRUE,                        /* Clear bits on exit if the unblock condition is met. */
            pdFALSE,                       /* Don't wait for all bits. */
            portMAX_DELAY                  /* Don't time out. */
    );
    if (((xEventGroupValue & xBitsToWaitFor ) != 0))
    {
        if (((usDriverSeatCurrentTemp < 5) || (usDriverSeatCurrentTemp > 40)))
        {
            latestFailure[0].failureMessage = "Invalid Driver Temperature Sensor Range ";
            latestFailure[0].level = ucDriverHeaterIntensity;
            latestFailure[0].timestamp = GPTM_WTimer0Read();
            Led_SetOn(RED_LED_Index);
            ucDriverHeaterIntensity = TURN_OFF_HEATER;
        }
        else
        {
            Led_SetOff(RED_LED_Index);
        }

        if (((usPassengerSeatCurrentTemp < 5) || (usPassengerSeatCurrentTemp > 40)))
        {
            latestFailure[1].failureMessage = "Invalid Passenger Temperature Sensor Range ";
            latestFailure[1].level = ucPassengerHeaterIntensity;
            latestFailure[1].timestamp = GPTM_WTimer0Read();
            Led_SetOn(RED_LED_Index);
            ucPassengerHeaterIntensity = TURN_OFF_HEATER;
        }
        else
        {
            Led_SetOff(RED_LED_Index);
        }
    }
}





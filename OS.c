/*
 * OS.c
 *
 *  Created on: Sep 21, 2024
 *      Author: Mina
 */

/*******************************************************************************
 *                                Inclusions                                   *
 *******************************************************************************/
#include"OS.h"
#include"system.h"

/*******************************************************************************
 *                         Private Functions protype                           *
 *******************************************************************************/

/* The HW setup function */
static void prvSetupHardware( void );

/* FreeRTOS tasks */
void vSeatHeatingLevelTask(void *pvParameters);               /* Prototype for seat heating level task */
void vHeaterMonitorTask(void *pvParameters);                  /* Prototype for heater monitor task */
void vHeaterControlTask(void *pvParameters);                  /* Prototype for heater control task */
void vGetCurrentTempTask(void *pvParameters);                 /* Prototype for get current temperature task */
void vDashboardDisplayTask(void *pvParameters);               /* Prototype for dashboard display task */
void vFailureHandleTask(void *pvParameters);                  /* Prototype for failure handle task */
void vRunTimeMeasurementsTask(void *pvParameters);            /* Prototype for runtime measurements task */

/*******************************************************************************
 *                         Public Functions Definitions                        *
 *******************************************************************************/
void OS_Init(void){
    prvSetupHardware(); /* Setup the hardware for use with the Tiva C board. */
    xSystemEventGroup = xEventGroupCreate();      /* Create event group */
    xMutex = xSemaphoreCreateMutex();            /* Create a Mutex */

}

void OS_TaskCreation(void){
    /* Create Tasks here */
        xTaskCreate(vSeatHeatingLevelTask,   "DriverSeatHeatingLevelTask",    150, (void*)&DriverSeatTask,    4, &xDriverSeatHeatingLevelTask);
        xTaskCreate(vSeatHeatingLevelTask,   "PassengerSeatHeatingLevelTask", 150, (void*)&PassengerSeatTask, 4, &xPassengerSeatHeatingLevelTask);
        xTaskCreate(vGetCurrentTempTask,     "GetCurrentTempTask",            150, NULL,                      3, &xGetCurrentTempTask);
        xTaskCreate(vFailureHandleTask,      "Failure",                       150, NULL,                      1, &xFailureHandleTask);
        xTaskCreate(vHeaterMonitorTask,      "HeaterMonitorTask",             256, NULL,                      2, &xHeaterMonitorTask);
        xTaskCreate(vHeaterControlTask,      "HeaterControlTask",             100, NULL,                      1, &xHeaterControlTask);
        xTaskCreate(vDashboardDisplayTask,   "DashboardDisplayTask",          150, NULL,                      1, &xDashboardDisplayTask);
        xTaskCreate(vRunTimeMeasurementsTask,"RunTimeMeasurementsTask",       256, NULL,                      1, &xRunTimeMeasurementsTask);

        /* Set application task tags for runtime statistics */
        vTaskSetApplicationTaskTag(xDriverSeatHeatingLevelTask,    (TaskHookFunction_t) 1);
        vTaskSetApplicationTaskTag(xPassengerSeatHeatingLevelTask, (TaskHookFunction_t) 2);
        vTaskSetApplicationTaskTag(xGetCurrentTempTask,            (TaskHookFunction_t) 3);
        vTaskSetApplicationTaskTag(xFailureHandleTask,             (TaskHookFunction_t) 4);
        vTaskSetApplicationTaskTag(xHeaterMonitorTask,             (TaskHookFunction_t) 5);
        vTaskSetApplicationTaskTag(xHeaterControlTask,             (TaskHookFunction_t) 6);
        vTaskSetApplicationTaskTag(xDashboardDisplayTask,          (TaskHookFunction_t) 7);
        vTaskSetApplicationTaskTag(xRunTimeMeasurementsTask,       (TaskHookFunction_t) 8);
}

/*******************************************************************************
 *                         Private Functions Definitions                        *
 *******************************************************************************/

/************************************************************************************
 * Service Name: prvSetupHardware
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * Parameters (in): None
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Task executes once to initialize all the Modules.
 ************************************************************************************/
static void prvSetupHardware( void )
{
    Init_Task();
}
/************************************************************************************
Service name:           vSeatHeatingLevelTask
Sync/Async:             Asynchronous
Reentrancy:             Reentrant for different tasks
Parameters (in):        pvParameters - Pointer to TaskInformation structure
Parameters (inout):     None
Parameters (out):       None
Return value:           None
Description:            Task to manage seat heating levels based on button presses.
                        Handles button presses, updates desired temperatures, and communicates
                        with UART0 if necessary. Monitors a specific seat identified by TaskInformation.
 ************************************************************************************/
void vSeatHeatingLevelTask(void *pvParameters)
{
    uint8 Button_flag = 0;  /* Variable to track button press state */
    uint8 SeatsRequiredTemperatures[4] = {HEATING_LVL_OFF, HEATING_LVL_LOW, HEATING_LVL_MEDIUM, HEATING_LVL_HIGH}; /* Array defining heating levels */
    TaskInformation *pTaskInformation = (TaskInformation *)pvParameters; /* Cast pvParameters to TaskInformation pointer */
    for(;;)
    {
        Heat_LVL(pTaskInformation ,Button_flag ,SeatsRequiredTemperatures);
    }
}

/************************************************************************************
Service name:           vGetCurrentTempTask
Sync/Async:             Asynchronous
Reentrancy:             Reentrant for different tasks
Parameters (in):        pvParameters - Pointer to task parameters (not used)
Parameters (inout):     None
Parameters (out):       None
Return value:           None
Description:            Task to read current temperatures from ADC channels.
                        Calculates current temperatures for driver and passenger seats
                        and updates global variables. Communicates temperature readings
                        using UART0. Monitors ADC channels ADC0 and ADC1.
 ************************************************************************************/
void vGetCurrentTempTask(void *pvParameters)
{
    for(;;)
    {
        Get_Temp();
    }
}

/************************************************************************************
Service name: vHeaterMonitorTask
Sync/Async: Synchronous
Reentrancy: Non Reentrant
Parameters (in): pvParameters - Pointer to task parameters
Parameters (inout): None
Parameters (out): None
Return value: None
Description: Monitors seat heater temperatures and adjusts heater intensities based on desired and current temperatures for both driver and passenger seats.
 ************************************************************************************/
void vHeaterMonitorTask(void *pvParameters)
{
    EventBits_t xEventGroupValue;
    const EventBits_t xBitsToWaitFor = (SEAT_CURRENT_TEMP_TASK_BIT | SEAT_MONITOR_TASK_BIT);
    for(;;)
    {
        Heater_Monitor(xEventGroupValue,xBitsToWaitFor);
    }
}

/************************************************************************************
Service name: vHeaterControlTask
Sync/Async: Synchronous
Reentrancy: Non Reentrant
Parameters (in): pvParameters - Pointer to task parameters
Parameters (inout): None
Parameters (out): None
Return value: None
Description: Controls the activation of seat heaters based on the intensity levels calculated by the Heater Monitor task.
 ************************************************************************************/
void vHeaterControlTask(void *pvParameters)
{
    EventBits_t xEventGroupValue;
    const EventBits_t xBitsToWaitFor = SEAT_HEATER_INTENSITY_TASK_BIT;
    for(;;)
    {
        Heater_control(xEventGroupValue,xBitsToWaitFor);
    }
}

/************************************************************************************
Service name: vDashboardDisplayTask
Sync/Async: Synchronous
Reentrancy: Non Reentrant
Parameters (in): pvParameters - Pointer to task parameters
Parameters (inout): None
Parameters (out): None
Return value: None
Description: Updates and displays dashboard information including seat heater states, desired and current temperatures,
task execution times, and CPU load on the UART console.
 *************************************************************************************/
void vDashboardDisplayTask(void *pvParameters)
{
    EventBits_t xEventGroupValue;
    const EventBits_t xBitsToWaitFor = SEAT_HEATER_INTENSITY_TASK_BIT;
    for(;;)
    {
        Dashbord(xEventGroupValue,xBitsToWaitFor);
    }
}

/************************************************************************************
Service name: vFailureHandleTask
Sync/Async: Synchronous
Reentrancy: Non Reentrant
Parameters (in): pvParameters - Pointer to task parameters
Parameters (inout): None
Parameters (out): None
Return value: None
Description: Handles temperature sensor failure conditions for driver and passenger seats.
             Updates latest failure information and adjusts heater intensity accordingly.
 ************************************************************************************/
void vFailureHandleTask(void *pvParameters)
{
    EventBits_t xEventGroupValue;
    const EventBits_t xBitsToWaitFor = SEAT_CURRENT_TEMP_TASK_BIT;
    for(;;)
    {
        Failure_Handle(xEventGroupValue,xBitsToWaitFor);
    }
}

/************************************************************************************
Service name: vRunTimeMeasurementsTask
Sync/Async: Synchronous
Reentrancy: Non Reentrant
Parameters (in): pvParameters - Pointer to task parameters
Parameters (inout): None
Parameters (out): None
Return value: None
Description: Measures and updates the total execution time of critical tasks and calculates
             CPU load based on the execution times.
 ************************************************************************************/
void vRunTimeMeasurementsTask(void *pvParameters)
{
    TickType_t xLastWakeTime = xTaskGetTickCount();
    for (;;)
    {
        vTaskDelayUntil(&xLastWakeTime, RUNTIME_MEASUREMENTS_TASK_PERIODICITY);
        ucRunTimeMeasurements();
    }
}

/*
 * system_Cfg.h
 *
 *  Created on: Sep 17, 2024
 *      Author: Mina
 */

#ifndef SYSTEM_CFG_H_
#define SYSTEM_CFG_H_

#define HEATING_LVL_OFF              0
#define HEATING_LVL_LOW              25
#define HEATING_LVL_MEDIUM           30
#define HEATING_LVL_HIGH             35

#define TEMP_CTRL_RESOLUTION         2

#define MAX_VALID_TEMP               5
#define MIN_VALID_TEMP               40

#define DRIVER_TASK_ID 0
#define PASSENGER_TASK_ID 1

#define RUNTIME_MEASUREMENTS_TASK_PERIODICITY (2000U)

/* Enum defining different heating levels */
typedef enum
{
    LOW_HEATER_INTENSITY = 1,
    MEDIUM_HEATER_INTENSITY = 2,
    HIGH_HEATER_INTENSITY = 3,
    TURN_OFF_HEATER = 4
} HeatingLevel;

/* Struct to record failure details */
typedef struct {
    char *failureMessage;  // Message describing the failure
    uint32_t timestamp;    // Timestamp of when the failure occurred
    HeatingLevel level;    // Heating level at the time of failure
} FailureRecord;

/* Struct defining task-specific information */
typedef struct
{
    const uint8_t ucTaskID;            // Task ID for identification
    const uint8_t  ucSeatButton;       // Button associated with the seat
    uint8_t ucSeatButtonPressesCount;  // Number of presses on the seat button
    uint8_t ucSeatHeatingTemp;         // Current heating temperature setting
} TaskInformation;

/* Task handles */
TaskHandle_t xDriverSeatHeatingLevelTask;                     /* Task handle for driver seat heating level task */
TaskHandle_t xPassengerSeatHeatingLevelTask;                  /* Task handle for passenger seat heating level task */
TaskHandle_t xHeaterMonitorTask;                              /* Task handle for heater monitor task */
TaskHandle_t xHeaterControlTask;                              /* Task handle for heater control task */
TaskHandle_t xGetCurrentTempTask;                             /* Task handle for get current temperature task */
TaskHandle_t xDashboardDisplayTask;                           /* Task handle for dashboard display task */
TaskHandle_t xFailureHandleTask;                              /* Task handle for failure handle task */
TaskHandle_t xRunTimeMeasurementsTask;                        /* Task handle for runtime measurements task */

/* Event group handle */
EventGroupHandle_t xSystemEventGroup;
/* FreeRTOS Mutxes */
xSemaphoreHandle xMutex;

/* Definitions for the event bits in the event group */
#define SEAT_MONITOR_TASK_BIT ( 1UL << 0UL )               // Event bit 0
#define SEAT_CURRENT_TEMP_TASK_BIT ( 1UL << 1UL )          // Event bit 1
#define SEAT_HEATER_INTENSITY_TASK_BIT ( 1UL << 2UL )      // Event bit 2


#endif /* SYSTEM_CFG_H_ */

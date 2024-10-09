/*
 * run_time_measurements.h
 *
 *  Created on: Sep 8, 2024
 *      Author: Mina
 */

#ifndef RUN_TIME_MEASUREMENTS_H_
#define RUN_TIME_MEASUREMENTS_H_

#include "RTOS_cfg/define.h"
#include "MCU_Commen/Std_Types.h"

#define NOM_OF_TASKS   9

extern uint32 ullTasksOutTime[NOM_OF_TASKS];
extern uint32 ullTasksInTime[NOM_OF_TASKS];
extern uint32 ullTasksExecutionTime[NOM_OF_TASKS];
extern uint32 ullTasksTotalTime[NOM_OF_TASKS];
extern uint8 ucCPU_Load;

#ifdef RUN_TIME_MEASURE

#include "MCU_Commen/Std_Types.h"

#ifdef RUN_TIME_MEASURE_ext

void ucRunTimeMeasurements(void);

#elif defined (RUN_TIME_MEASURE_FREERTOS)

uint8 ucRunTimeMeasurements( uint8  *cBuffer);

#endif

#endif

#endif /* RUN_TIME_MEASUREMENTS_H_ */

/*
 * run_time_measurements.c
 *
 *  Created on: Sep 8, 2024
 *      Author: Mina
 */

#include "run_time_measurements.h"



#ifdef RUN_TIME_MEASURE

#ifdef RUN_TIME_MEASURE_ext

#include "GPTM.h"

uint32 ullTasksOutTime[NOM_OF_TASKS];
uint32 ullTasksInTime[NOM_OF_TASKS];
uint32 ullTasksExecutionTime[NOM_OF_TASKS];
uint32 ullTasksTotalTime[NOM_OF_TASKS];
uint8 ucCPU_Load=0;


void ucRunTimeMeasurements(void)
{

    uint8 ucCounter;
    uint32 ullTotalTasksTime = 0;

    for(ucCounter = 1; ucCounter < NOM_OF_TASKS; ucCounter++)
    {
        ullTotalTasksTime += ullTasksTotalTime[ucCounter];
    }
    ucCPU_Load = ((ullTotalTasksTime * 100) /  GPTM_WTimer0Read());
}
#elif defined (RUN_TIME_MEASURE_FREERTOS)

#include "FreeRTOS.h"
#include "task.h"

uint8 ucRunTimeMeasurements(uint8  *cBuffer)
{

     vTaskGetRunTimeStats(cBuffer);
}

#endif
#endif



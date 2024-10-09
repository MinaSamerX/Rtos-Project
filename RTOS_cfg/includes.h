/*
 * includes.h
 *
 *  Created on: Aug 31, 2024
 *      Author: Mina
 */

#ifndef INCLUDES_H_
#define INCLUDES_H_

/*******************************************************************************
 *                                Inclusions                                   *
 *******************************************************************************/

#include "define.h"

/*******************************************************************************
 *                              Kernel includes                                *
 *******************************************************************************/

#include "FreeRTOS.h"
#include "task.h"

#ifdef TIMER
#include "timers.h"
#endif

/*******************************************************************************
 *                               MCAL includes                                 *
 *******************************************************************************/

#ifdef MCU
#include"MCAL/MCU/Mcu.h"
#endif

#ifdef DIO
#include"MCAL/DIO/Dio.h"
#endif

#ifdef PORT
#include"MCAL/PORT/Port.h"
#endif

#ifdef GPIO
#include "gpio.h"
#endif

#ifdef UART
#include "MCAL/UART/uart0.h"
#endif

#ifdef GPTM
#include "MCAL/GPTM/GPTM.h"
#endif

#ifdef ADC
#include "MCAL/ADC/ADC.h"
#endif

/*******************************************************************************
 *                               ECUAL includes                                 *
 *******************************************************************************/

#ifdef LED
#include "ECUAL/LED/Led.h"
#endif

#ifdef BUTTON
#include "ECUAL/Button/Button.h"
#endif

#ifdef LM35
#include "ECUAL/lm35/lm35.h"
#endif

/*******************************************************************************
 *                              optional includes                              *
 *******************************************************************************/

#if defined(SEMPHR) || defined(MUTEXES) || defined(COUNTING_SEMAPHORES)
#include "semphr.h"
#endif

#ifdef EVENT_GRP
#include "event_groups.h"
#endif

#ifdef  QUEUE
#include "queue.h"
#endif

#ifdef RUN_TIME_MEASURE
#include "run_rime_measure/run_time_measurements.h"
#endif

/*******************************************************************************
 *                               other includes                                *
 *******************************************************************************/
#ifdef STD
#include "MCU_Commen/Std_Types.h"
#endif

#ifdef STD_LIB
#include <stdlib.h>
#endif

#ifdef DELAY
#include "SERVICES/delay/delay.h"
#endif
/**********************************************************************************
 *                                End of File                                     *
 **********************************************************************************/



#endif /* INCLUDES_H_ */

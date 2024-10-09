/*
 * define.h
 *
 *  Created on: Sep 3, 2024
 *      Author: Mina
 */

#ifndef DEFINE_H_
#define DEFINE_H_


/*******************************************************************************
 *                                Definitions.                                 *
 *******************************************************************************/

                                   /*Debugging*/
//#define DEBUG

                                  /*Scheduling*/
#define PRE_EMPTIVE_WITH_TIME_SLICING
//#define PRE_EMPTIVE_WITHOUT_TIME_SLICING
//#define CO_OPERATIVE

                                  /*include*/
#define vTASK_DELAY
//#define vTASK_SUSPEND
//#define vTASK_PRIORITY_SET
//#define vTASK_PRIORITY_GET
#define vTASK_DELAY_UNTILL
//#define vTASK_DELETE
//#define xTIMER_PEND_CALL

                                 /*configUSE*/
//#define SEMPHR
#define MUTEXES
//#define COUNTING_SEMAPHORES
#define APPLICATION_TASK_TAG

                                   /*Memory*/
#define DYNAMIC
//#define STAITC
//#define MIXED

                               /*Software timer*/
//#define TIMER
//#define ISR

                                  /*Hooks*/
//#define IDLE_HOOK
//#define TICK_HOOK
//#define STACK_OVERFLOW_HOOK_METHOD_1
//#define STACK_OVERFLOW_HOOK_METHOD_2

                                  /*MCAL*/
#define DIO
#define MCU
#define PORT
//#define GPIO
#define UART
#define GPTM
#define ADC

                                  /*ECUAL*/
#define LED
#define BUTTON
#define LM35

                                 /*Options*/
#define EVENT_GRP
//#define QUEUE

                            /*RUN TIME measurement*/
#define RUN_TIME_MEASURE
#define RUN_TIME_MEASURE_ext
//#define RUN_TIME_MEASURE_FREERTOS
                                /*others*/
#define STD
//#define STD_LIB
#define DELAY
/**********************************************************************************
 *                                End of File                                     *
 **********************************************************************************/

#endif /* DEFINE_H_ */

/*
 * optional_fun.h
 *
 *  Created on: Aug 28, 2024
 *      Author: Mina
 */

#ifndef OPTIONAL_FUN_H_
#define OPTIONAL_FUN_H_

/*******************************************************************************
 *                                Inclusions                                   *
 *******************************************************************************/

#include "define.h"

/*******************************************************************************
 *                 Scheduling behavior related definitions.                    *
 *******************************************************************************/

/* Set configUSE_PREEMPTION to 1 to use pre-emptive scheduling. Set
 * configUSE_PREEMPTION to 0 to use co-operative scheduling. */

/* Set configUSE_TIME_SLICING to 1 to have the scheduler switch between Ready
 * state tasks of equal priority on every tick interrupt.  Set
 * configUSE_TIME_SLICING to 0 to prevent the scheduler switching between Ready
 * state tasks just because there was a tick interrupt. */

#ifdef PRE_EMPTIVE_WITH_TIME_SLICING
#define configUSE_PREEMPTION                  (1)
#define configUSE_TIME_SLICING                (1)   //default
#elif defined(PRE_EMPTIVE_WITHOUT_TIME_SLICING)
#define configUSE_PREEMPTION                  (1)
#define configUSE_TIME_SLICING                (0)
#elif defined(CO_OPERATIVE)
#define configUSE_PREEMPTION                  (0)
#define configUSE_TIME_SLICING                (0)
#endif
/*******************************************************************************
 *             Definitions that include or exclude functionality.              *
 *******************************************************************************/

/* incldue the named API function,Most linkers will remove unused functions even when the constant is 1. */

#ifdef vTASK_DELAY
#define INCLUDE_vTaskDelay                    1  //delay at blocking state (non blocking delay) as another task continue
#endif

#ifdef vTASK_SUSPEND
#define INCLUDE_vTaskSuspend                  1  // send it to suspend state or  resume from  suspend state (TaskHandle_t xTaskHandle;)
#endif

#ifdef vTASK_PRIORITY_SET
#define INCLUDE_vTaskPrioritySet              1  // set pri to spec. task
#endif

#ifdef vTASK_PRIORITY_GET
#define INCLUDE_uxTaskPriorityGet             1  // get pri to spec. task
#endif

#ifdef vTASK_DELAY_UNTILL
#define INCLUDE_vTaskDelayUntil               1  //delay at blocking state (non blocking delay) as another task continue but with no of ticks
#endif

#ifdef vTASK_DELETE
#define INCLUDE_vTaskDelete                   1  //delete task
#endif

#if defined(xTIMER_PEND_CALL) || defined(ISR)
#define INCLUDE_xTimerPendFunctionCall          1
#endif

/*******************************************************************************
 *                        Definitions for configUSE.                           *
 *******************************************************************************/

/* Set the following configUSE_* constants to 1 to include the named feature in
 * the build, or 0 to exclude the named feature from the build. */

#ifdef MUTEXES
#define configUSE_MUTEXES                      1
#endif

#ifdef COUNTING_SEMAPHORES
#define configUSE_COUNTING_SEMAPHORES         1
#endif

/* Set the following configUSE_* constants to 1 to include the named feature in
 * the build, or 0 to exclude the named feature from the build. */

#if defined(APPLICATION_TASK_TAG) || defined (RUN_TIME_MEASURE_ext)
#define configUSE_APPLICATION_TASK_TAG         1
#endif

/*******************************************************************************
 *                 Memory allocation related definitions.                       *
 *******************************************************************************/

/* Set configSUPPORT_STATIC_ALLOCATION to 1 to include FreeRTOS API functions
 * that create FreeRTOS objects (tasks, queues, etc.) using statically allocated
 * memory in the build.  Set to 0 to exclude the ability to create statically
 * allocated objects from the build.  Defaults to 0 if left undefined. */

/* Set configSUPPORT_DYNAMIC_ALLOCATION to 1 to include FreeRTOS API functions
 * that create FreeRTOS objects (tasks, queues, etc.) using dynamically allocated
 * memory in the build.  Set to 0 to exclude the ability to create dynamically
 * allocated objects from the build.  Defaults to 1 if left undefined. */

#ifdef DYNAMIC
#define configSUPPORT_STATIC_ALLOCATION              0
#define configSUPPORT_DYNAMIC_ALLOCATION             1
#elif defined(STAITC)
#define configSUPPORT_STATIC_ALLOCATION              1
#define configSUPPORT_DYNAMIC_ALLOCATION             0
#elif defined(MIXED)
#define configSUPPORT_STATIC_ALLOCATION              1
#define configSUPPORT_DYNAMIC_ALLOCATION             1
#endif

/*******************************************************************************
 *                   Software timer related definitions.                       *
 *******************************************************************************/

#if defined(TIMER) || defined(ISR)
/* Set configUSE_TIMERS to 1 to include software timer functionality in the
 * build.  Set to 0 to exclude software timer functionality from the build.  The
 * FreeRTOS/source/timers.c source file must be included in the build if
 * configUSE_TIMERS is set to 1.  Default to 0 if left undefined. */
#define configUSE_TIMERS                      1

/* configTIMER_TASK_PRIORITY sets the priority used by the timer task.  Only
 * used if configUSE_TIMERS is set to 1.  The timer task is a standard FreeRTOS
 * task, so its priority is set like any other task. Only used if configUSE_TIMERS
 * is set to 1. */
#define configTIMER_TASK_PRIORITY             (configMAX_PRIORITIES - 1)

/* configTIMER_QUEUE_LENGTH sets the length of the queue (the number of discrete
 * items the queue can hold) used to send commands to the timer task. Only used
 * if configUSE_TIMERS is set to 1. */
#define configTIMER_QUEUE_LENGTH              10

/* configTIMER_TASK_STACK_DEPTH sets the size of the stack allocated to the
 * timer task (in words, not in bytes!).  The timer task is a standard FreeRTOS
 * task. Only used if configUSE_TIMERS is set to 1. */
#define configTIMER_TASK_STACK_DEPTH          configMINIMAL_STACK_SIZE
#endif

/*******************************************************************************
 *              Hook and callback function related definitions.                *
 *******************************************************************************/

/* Set the following configUSE_* constants to 1 to include the named hook
 * functionality in the build.  Set to 0 to exclude the hook functionality from the
 * build.  The application writer is responsible for providing the hook function
 * for any set to 1. */

#ifdef IDLE_HOOK
#define configUSE_IDLE_HOOK                   1
#elif defined(TICK_HOOK)
#define configUSE_TICK_HOOK                   1
#else
#define configUSE_IDLE_HOOK                   0
#define configUSE_TICK_HOOK                   0
#endif

/* Set configCHECK_FOR_STACK_OVERFLOW to 1 or 2 for FreeRTOS to check for a
 * stack overflow at the time of a context switch.  Set to 0 to not look for a
 * stack overflow.  If configCHECK_FOR_STACK_OVERFLOW is 1 then the check only
 * looks for the stack pointer being out of bounds when a task's context is saved
 * to its stack - this is fast but somewhat ineffective.  If
 * configCHECK_FOR_STACK_OVERFLOW is 2 then the check looks for a pattern written
 * to the end of a task's stack having been overwritten.  This is slower, but will
 * catch most (but not all) stack overflows. The application writer must provide
 * the stack overflow callback when configCHECK_FOR_STACK_OVERFLOW is enabled.
 * Defaults to 0 if left undefined. */

#ifdef STACK_OVERFLOW_HOOK_METHOD_1
#define configCHECK_FOR_STACK_OVERFLOW        1
#elif defined(STACK_OVERFLOW_HOOK_METHOD_2)
#define configCHECK_FOR_STACK_OVERFLOW        2
#endif

/*******************************************************************************
 *                        RTOS Runtime Measurements.                           *
 *******************************************************************************/

#ifdef RUN_TIME_MEASURE

#ifdef RUN_TIME_MEASURE_ext
#include "GPTM.h"
#include "MCU_Commen/std_types.h"
#include "run_rime_measure/run_time_measurements.h"

#define traceTASK_SWITCHED_IN()                                    \
        do{                                                                \
            uint32 taskInTag = (uint32)(pxCurrentTCB->pxTaskTag);          \
            ullTasksInTime[taskInTag] = GPTM_WTimer0Read();                \
        }while(0);

#define traceTASK_SWITCHED_OUT()                                                                  \
        do{                                                                                               \
            uint32 taskOutTag = (uint32)(pxCurrentTCB->pxTaskTag);                                        \
            ullTasksOutTime[taskOutTag] = GPTM_WTimer0Read();                                             \
            ullTasksExecutionTime[taskOutTag] = ullTasksOutTime[taskOutTag] - ullTasksInTime[taskOutTag]; \
        }while(0);

#elif defined (RUN_TIME_MEASURE_FREERTOS)

/* Set configGENERATE_RUN_TIME_STATS to 1 to enable collection of run-time statistics.
 * When this is done, both portCONFIGURE_TIMER_FOR_RUN_TIME_STATS()
 * and portGET_RUN_TIME_COUNTER_VALUE() or portALT_GET_RUN_TIME_COUNTER_VALUE(x) must also be defined. */
#define configGENERATE_RUN_TIME_STATS 1

/* portCONFIGURE_TIMER_FOR_RUN_TIME_STATS() is defined to call the function that initializes
   the 32-bit timer */
#define portCONFIGURE_TIMER_FOR_RUN_TIME_STATS() GPTM_WTimer0Init()

/* portGET_RUN_TIME_COUNTER_VALUE() is defined to get the current run-time
 * timer value. The returned time value is 32-bits long, and is formed by subtracting the
 * current timer value from its max value because of our timer is counting down  */
#define portGET_RUN_TIME_COUNTER_VALUE()  GPTM_WTimer0Read()

/* Set to 1 to include the vTaskList() and vTaskGetRunTimeStats() functions in
 * the build.  Set to 0 to exclude these functions from the build.  These two
 * functions introduce a dependency on string formatting functions that would
 * otherwise not exist - hence they are kept separate.  Defaults to 0 if left
 * undefined. */
#define configUSE_STATS_FORMATTING_FUNCTIONS 1

/* Set configUSE_TRACE_FACILITY to include additional task structure members
 * are used by trace and visualization functions and tools.  Set to 0 to exclude
 * the additional information from the structures. Defaults to 0 if left
 * undefined. */
#define configUSE_TRACE_FACILITY             1

#endif

#endif

/**********************************************************************************
 *                                End of File                                     *
 **********************************************************************************/

#endif /* OPTIONAL_FUN_H_ */

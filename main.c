/******************************************************************************
 * File Name: main.c
 *
 * Author: Mina Samer
 ******************************************************************************/
#include "OS.h"

int main()
{
     OS_Init();
     OS_TaskCreation();

    /* Now all the tasks have been started - start the scheduler.

	NOTE : Tasks run in system mode and the scheduler runs in Supervisor mode.
	The processor MUST be in supervisor mode when vTaskStartScheduler is 
	called.  The demo applications included in the FreeRTOS.org download switch
	to supervisor mode prior to main being called.  If you are not using one of
	these demo application projects then ensure Supervisor mode is used here. */ 
    vTaskStartScheduler();

    /* Should never reach here!  If you do then there was not enough heap
	available for the idle task to be created. */
    for (;;);

}
/*-----------------------------------------------------------*/

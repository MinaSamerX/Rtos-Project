/*
 * OS.h
 *
 *  Created on: Sep 21, 2024
 *      Author: Mina
 */

#ifndef OS_H_
#define OS_H_

#include "MCU_Commen/std_types.h"

extern struct TaskInformation DriverSeatTask;
extern struct TaskInformation PassengerSeatTask;

void OS_Init(void);
void OS_TaskCreation(void);

#endif /* OS_H_ */

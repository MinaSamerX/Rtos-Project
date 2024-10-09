/*
 * system.h
 *
 *  Created on: Sep 15, 2024
 *      Author: Mina
 */

#ifndef SYSTEM_H_
#define SYSTEM_H_

#include"RTOS_cfg/includes.h"
#include "system_Cfg.h"

void Init_Task(void);
void Heat_LVL(TaskInformation *pTaskInformation ,uint8 Button_flag ,uint8 *SeatsRequiredTemperatures);
void Get_Temp(void);
void Heater_Monitor(EventBits_t xEventGroupValue, const EventBits_t xBitsToWaitFor);
void Heater_control(EventBits_t xEventGroupValue, const EventBits_t xBitsToWaitFor);
void Dashbord(EventBits_t xEventGroupValue, const EventBits_t xBitsToWaitFor);
void Failure_Handle(EventBits_t xEventGroupValue, const EventBits_t xBitsToWaitFor);

#endif /* SYSTEM_H_ */

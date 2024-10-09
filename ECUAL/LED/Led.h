/******************************************************************************
 *
 * Module: Led
 *
 * File Name: Led.h
 *
 * Description: Header file for Led Module.
 *
 * Author: Mina Samer
 ******************************************************************************/
#ifndef LED_H
#define LED_H

#include "MCU_Commen/Std_Types.h"
#include "Led_Cfg.h"

/* Description: Set the LED state to ON */
void Led_SetOn(uint8 LED_index);

/* Description: Set the LED state to OFF */
void Led_SetOff(uint8 LED_index);

/*Description: Toggle the LED state */
void Led_Toggle(uint8 LED_index);




#endif /* LED_H */

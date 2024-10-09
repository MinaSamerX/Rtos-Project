/******************************************************************************
 *
 * Module: Button
 *
 * File Name: Button.h
 *
 * Description: Header file for Button Module.
 *
 * Author: Mina Samer
 ******************************************************************************/
#ifndef BUTTON_H
#define BUTTON_H

#include "MCU_Commen/Std_Types.h"
#include "Button_Cfg.h"


/* Description: Read the Button state Pressed/Released */
uint8 Button_GetState(uint8 Button_PIN_INDEX);

#endif /* BUTTON_H */

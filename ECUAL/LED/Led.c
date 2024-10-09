/******************************************************************************
 *
 * Module: Led
 *
 * File Name: Led.c
 *
 * Description: Source file for Led Module.
 *
 * Author: Mina Samer
 ******************************************************************************/
#include "MCAL/DIO/Dio.h"
#include "Led.h"


/*********************************************************************************************/
void Led_SetOn(uint8 LED_index)
{
    Dio_WriteChannel(LED_index,LED_ON);  /* LED ON */
}

/*********************************************************************************************/
void Led_SetOff(uint8 LED_index)
{
    Dio_WriteChannel(LED_index,LED_OFF); /* LED OFF */
}


/*********************************************************************************************/

void Led_Toggle(uint8 LED_index)
{
    Dio_FlipChannel(LED_index);
}

/*********************************************************************************************/

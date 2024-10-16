/******************************************************************************
 *
 * Module: Button
 *
 * File Name: Button.c
 *
 * Description: Source file for Button Module.
 *
 * Author: Mina Samer
 ******************************************************************************/
#include "MCAL/DIO/Dio.h"
#include "Button.h"

/*******************************************************************************************************************/
uint8 Button_GetState(uint8 Button_PIN_INDEX)
{
    return  (Dio_ReadChannel(Button_PIN_INDEX));
}
/*******************************************************************************************************************/


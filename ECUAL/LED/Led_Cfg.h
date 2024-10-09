/******************************************************************************
 *
 * Module: Led
 *
 * File Name: Led_Cfg.h
 *
 * Description: Header file for Pre-Compiler configuration used by Led Module
 *
 * Author: Mina Samer
 ******************************************************************************/

#ifndef LED_CFG_H_
#define LED_CFG_H_

/* Set the led ON/OFF according to its configuration Positive logic or negative logic */
#define LED_ON  STD_HIGH
#define LED_OFF STD_LOW

/* Set the LED Index */
#define RED_LED_Index   DioConf_LED1_CHANNEL_ID_INDEX
#define BLUE_LED_Index  DioConf_LED2_CHANNEL_ID_INDEX
#define GREEN_LED_Index DioConf_LED3_CHANNEL_ID_INDEX



#endif /* LED_CFG_H_ */

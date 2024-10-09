/******************************************************************************
 *
 * Module: Button
 *
 * File Name: Button_Cfg.h
 *
 * Description: Header file for Pre-Compiler configuration used by Button Module
 *
 * Author: Mina Samer
 ******************************************************************************/

#ifndef BUTTON_CFG_H_
#define BUTTON_CFG_H_

/* Button State according to its configuration PULL UP/Down */
#define BUTTON_PRESSED  STD_LOW
#define BUTTON_RELEASED STD_HIGH

/* Set the Button INDEX*/
#define SW1_BUTTON_INDEX DioConf_SW1_CHANNEL_ID_INDEX
#define SW2_BUTTON_INDEX DioConf_SW2_CHANNEL_ID_INDEX
#define SW3_BUTTON_INDEX DioConf_SW3_CHANNEL_ID_INDEX


#endif /* BUTTON_CFG_H_ */

/*
 * lm35.h
 *
 *  Created on: Sep 15, 2024
 *      Author: Mina
 */

#ifndef ECUAL_LM35_LM35_H_
#define ECUAL_LM35_LM35_H_


#include "MCU_Commen/std_types.h"
#include "MCAL/ADC/ADC.h"
#include "LM35_Cfg.h"

/*Definitions*/
#define LM35_MAX_VOLT 1.5
#define LM35_MAX_TEMPERATURE 150

#ifdef DEBUG
#define POTENTIOMETER_MAX_VOLT
#define POTENTIOMETER_MAX_reading
#endif

/*Function to analyze and return the digital value converted by the ADC*/
uint8 LM35_getTemperature(uint8 channel_index);



#endif /* ECUAL_LM35_LM35_H_ */

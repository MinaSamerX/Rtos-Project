/*
 * LM35.c
 *
 *  Created on: Sep 15, 2024
 *      Author: Mina
 */

#include "LM35.h"
#include "MCAL/ADC/ADC.h"
#include "SERVICES/delay/delay.h"

uint8 LM35_getTemperature(uint8 channel_index)
{
    uint8 temperature = 0;
    uint32 adcResult =0;
    switch (channel_index)
    {
    case ADC0_INDEX:
        adcResult =  ADC0_ReadChannel();
        break;
    case ADC1_INDEX:
        adcResult = ADC0_ReadChannel();
        break;
    }

    /* Make delay for some time until g_adcResult value is updated with the ADC interrupt */
    Delay_MS(10);

#ifdef DEBUG
    temperature = (uint8)(((uint32)adcResult*POTENTIOMETER_MAX_reading*ADC_REF_VOLTAGE)/(ADC_MAX_VALUE*POTENTIOMETER_MAX_VOLT));
#else
    temperature = (uint8)(((uint32)adcResult*LM35_MAX_TEMPERATURE*ADC_REF_VOLTAGE)/(ADC_MAX_VALUE*LM35_MAX_VOLT));
#endif
    return temperature;
}



/******************************************************************************
 *
 * Module: Mcu
 *
 * File Name: Mcu.c
 *
 * Description: Source file for TM4C123GH6PM Microcontroller - Mcu Driver
 *
 * Author: Mohamed Tarek
 ******************************************************************************/

#include "tm4c123gh6pm_registers.h"

void Mcu_Init(void)
{
    /* Enable clock for All PORTs and wait for clock to start */
    SYSCTL_RCGCGPIO_REG |= 0x3F;
    while(!(SYSCTL_PRGPIO_REG & 0x3F));

    /* Enable clock for UART0 and Wait until UART0 clock is activated*/
    SYSCTL_RCGCUART_REG |= 0x01;
    while(!(SYSCTL_PRUART_REG & 0x01));

    /* Enable clock for ADC0 and Wait until ADC clock is activated */
    SYSCTL_RCGCADC_REG |= 0x01;
    while(!(SYSCTL_PRADC_REG & 0x01));

    /* Enable clock for ADC1 and Wait until ADC clock is activated */
    SYSCTL_RCGCADC_REG |= 0x02;
    while(!(SYSCTL_PRADC_REG & 0x02));
}

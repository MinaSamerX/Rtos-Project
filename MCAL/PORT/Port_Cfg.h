/******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port_Cfg.h
 *
 * Description: Pre-Compile Configuration Header file for TM4C123GH6PM Microcontroller - Port Driver
 *
 * Author: Mina Samer
 ******************************************************************************/

#ifndef PORT_CFG_H_
#define PORT_CFG_H_

/*
 * Module Version 1.0.0
 */
#define PORT_CFG_SW_MAJOR_VERSION              (1U)
#define PORT_CFG_SW_MINOR_VERSION              (0U)
#define PORT_CFG_SW_PATCH_VERSION              (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define PORT_CFG_AR_RELEASE_MAJOR_VERSION     (4U)
#define PORT_CFG_AR_RELEASE_MINOR_VERSION     (0U)
#define PORT_CFG_AR_RELEASE_PATCH_VERSION     (3U)

/* Pre-compile option for Development Error Detect */
#define PORT_DEV_ERROR_DETECT                (STD_ON)

/* Pre-compile option for Version Info API */
#define PORT_VERSION_INFO_API                (STD_ON)

/* Precompile option for setting Pin direction API */
#define PORT_SET_PIN_DIRECTION_API            (STD_ON)

/* Precompile option to set pin mode API */
#define PORT_SET_PIN_MODE_API                 (STD_ON)

/* Pre-compile parameter for number of pins */
#define PORT_NUMBER_OF_PORT_PINS                   (43U)

/* Precompile and Post Build option for Port pin mode changeability */
#define PORT_PIN_MODE_CHANGEABLE               (STD_ON)

/* Precompile and Post Build option for Port pin mode changeability */
#define PORT_PIN_DIRECTION_CHANGEABLE         (STD_ON)

/*******************************************************************************
 *                           Port Modes                                        *
 *******************************************************************************/
/*
Port pin mode from mode list. Note that more than one mode is allowed by
default. That way it is e.g. possible to combine DIO with another mode such as ICU.
More HW specific literals may be added by module implementor.
E.g. SPI may be further broken down into SpiCsHw, SpiCsSw, etc. if necessary.
*/

/**/
typedef enum {
  PORTA_ID =0,
  PORTB_ID =1,
  PORTC_ID =2,
  PORTD_ID =3,
  PORTE_ID =4,
  PORTF_ID =5
}PORT_ID;

typedef enum {
 PIN0_ID =0,
 PIN1_ID =1,
 PIN2_ID =2,
 PIN3_ID =3,
 PIN4_ID =4,
 PIN5_ID =5,
 PIN6_ID =6,
 PIN7_ID =7,
}PIN_ID;

/* Default Mode Of Configuration */
#define PORT_PIN_MODE_ADC        (uint8)9     /* ADC Mode */
#define PORT_PIN_MODE_DIO        (uint8)0   /* GPIO Mode */
#define PORT_PIN_MODE_UART       (uint8)1   /* UART Mode */
#define PORT_PIN_MODE_SPI        (uint8)2   /* SPI Mode */
#define PORT_PIN_MODE_I2C        (uint8)3   /* I2C Mode */
#define PORT_PIN_MODE_M0PWM      (uint8)4   /*M0PWM Mode */
#define PORT_PIN_MODE_M0FAULT    (uint8)4   /*Motion Control Module  Mode */
#define PORT_PIN_MODE_M1PWM      (uint8)5   /*M1PWM Mode */
#define PORT_PIN_MODE_IDX_PHASE  (uint8)6   /* IDX AND PHASE Mode */
#define PORT_PIN_MODE_TIMER      (uint8)7   /* TIMER  Mode */
#define PORT_PIN_MODE_CAN        (uint8)8   /* CAN Mode */
#define PORT_PIN_MODE_USB        (uint8)8   /* USB Mode */
#define PORT_PIN_MODE_NMI        (uint8)8  /*Non-Maskable Interrupt*/

/*******************************************************************************
 *                          Pins Initialization                                *
 *******************************************************************************/
#define PORTA_PIN0_INITIALIZATION          (STD_ON) /*UART*/
#define PORTA_PIN1_INITIALIZATION          (STD_ON) /*UART*/
#define PORTA_PIN2_INITIALIZATION          (STD_OFF)
#define PORTA_PIN3_INITIALIZATION          (STD_OFF)
#define PORTA_PIN4_INITIALIZATION          (STD_OFF)
#define PORTA_PIN5_INITIALIZATION          (STD_OFF)
#define PORTA_PIN6_INITIALIZATION          (STD_OFF)
#define PORTA_PIN7_INITIALIZATION          (STD_OFF)

#define PORTB_PIN0_INITIALIZATION          (STD_OFF)
#define PORTB_PIN1_INITIALIZATION          (STD_OFF)
#define PORTB_PIN2_INITIALIZATION          (STD_OFF)
#define PORTB_PIN3_INITIALIZATION          (STD_OFF)
#define PORTB_PIN4_INITIALIZATION          (STD_OFF)
#define PORTB_PIN5_INITIALIZATION          (STD_OFF)
#define PORTB_PIN6_INITIALIZATION          (STD_OFF)
#define PORTB_PIN7_INITIALIZATION          (STD_OFF)

#define PORTC_PIN0_INITIALIZATION          (STD_OFF)
#define PORTC_PIN1_INITIALIZATION          (STD_OFF)
#define PORTC_PIN2_INITIALIZATION          (STD_OFF)
#define PORTC_PIN3_INITIALIZATION          (STD_OFF)
#define PORTC_PIN4_INITIALIZATION          (STD_OFF)
#define PORTC_PIN5_INITIALIZATION          (STD_OFF)
#define PORTC_PIN6_INITIALIZATION          (STD_OFF)
#define PORTC_PIN7_INITIALIZATION          (STD_OFF)

#define PORTD_PIN0_INITIALIZATION          (STD_OFF)
#define PORTD_PIN1_INITIALIZATION          (STD_OFF)
#define PORTD_PIN2_INITIALIZATION          (STD_ON)   /*stearing wheel*/
#define PORTD_PIN3_INITIALIZATION          (STD_OFF)
#define PORTD_PIN4_INITIALIZATION          (STD_OFF)
#define PORTD_PIN5_INITIALIZATION          (STD_OFF)
#define PORTD_PIN6_INITIALIZATION          (STD_OFF)
#define PORTD_PIN7_INITIALIZATION          (STD_OFF)

#define PORTE_PIN0_INITIALIZATION          (STD_OFF)
#define PORTE_PIN1_INITIALIZATION          (STD_OFF)
#define PORTE_PIN2_INITIALIZATION          (STD_ON)
#define PORTE_PIN3_INITIALIZATION          (STD_ON)
#define PORTE_PIN4_INITIALIZATION          (STD_OFF)
#define PORTE_PIN5_INITIALIZATION          (STD_OFF)

#define PORTF_PIN0_INITIALIZATION          (STD_ON)
#define PORTF_PIN1_INITIALIZATION          (STD_ON)
#define PORTF_PIN2_INITIALIZATION          (STD_ON)
#define PORTF_PIN3_INITIALIZATION          (STD_ON)
#define PORTF_PIN4_INITIALIZATION          (STD_ON)

/*******************************************************************************
 *                           Pins Direction                                    *
 *******************************************************************************/
#define PORTA_PIN0_DIRECTION       (PORT_PIN_IN) /*UART*/
#define PORTA_PIN1_DIRECTION       (PORT_PIN_OUT) /*UART*/
#define PORTA_PIN2_DIRECTION       (PORT_PIN_IN)
#define PORTA_PIN3_DIRECTION       (PORT_PIN_IN)
#define PORTA_PIN4_DIRECTION       (PORT_PIN_IN)
#define PORTA_PIN5_DIRECTION       (PORT_PIN_IN)
#define PORTA_PIN6_DIRECTION       (PORT_PIN_IN)
#define PORTA_PIN7_DIRECTION       (PORT_PIN_IN)

#define PORTB_PIN0_DIRECTION       (PORT_PIN_IN)
#define PORTB_PIN1_DIRECTION       (PORT_PIN_IN)
#define PORTB_PIN2_DIRECTION       (PORT_PIN_IN)
#define PORTB_PIN3_DIRECTION       (PORT_PIN_IN)
#define PORTB_PIN4_DIRECTION       (PORT_PIN_IN)
#define PORTB_PIN5_DIRECTION       (PORT_PIN_IN)
#define PORTB_PIN6_DIRECTION       (PORT_PIN_IN)
#define PORTB_PIN7_DIRECTION       (PORT_PIN_IN)

#define PORTC_PIN0_DIRECTION       (PORT_PIN_IN)
#define PORTC_PIN1_DIRECTION       (PORT_PIN_IN)
#define PORTC_PIN2_DIRECTION       (PORT_PIN_IN)
#define PORTC_PIN3_DIRECTION       (PORT_PIN_IN)
#define PORTC_PIN4_DIRECTION       (PORT_PIN_IN)
#define PORTC_PIN5_DIRECTION       (PORT_PIN_IN)
#define PORTC_PIN6_DIRECTION       (PORT_PIN_IN)
#define PORTC_PIN7_DIRECTION       (PORT_PIN_IN)

#define PORTD_PIN0_DIRECTION       (PORT_PIN_IN)
#define PORTD_PIN1_DIRECTION       (PORT_PIN_IN)
#define PORTD_PIN2_DIRECTION       (PORT_PIN_IN)      /*stearing wheel*/
#define PORTD_PIN3_DIRECTION       (PORT_PIN_IN)
#define PORTD_PIN4_DIRECTION       (PORT_PIN_IN)
#define PORTD_PIN5_DIRECTION       (PORT_PIN_IN)
#define PORTD_PIN6_DIRECTION       (PORT_PIN_IN)
#define PORTD_PIN7_DIRECTION       (PORT_PIN_IN)

#define PORTE_PIN0_DIRECTION       (PORT_PIN_IN)
#define PORTE_PIN1_DIRECTION       (PORT_PIN_IN)
#define PORTE_PIN2_DIRECTION       (PORT_PIN_IN)
#define PORTE_PIN3_DIRECTION       (PORT_PIN_IN)  /*adc*/
#define PORTE_PIN4_DIRECTION       (PORT_PIN_IN)
#define PORTE_PIN5_DIRECTION       (PORT_PIN_IN)

#define PORTF_PIN0_DIRECTION       (PORT_PIN_IN)
#define PORTF_PIN1_DIRECTION       (PORT_PIN_OUT) /* LED */
#define PORTF_PIN2_DIRECTION       (PORT_PIN_OUT)
#define PORTF_PIN3_DIRECTION       (PORT_PIN_OUT)
#define PORTF_PIN4_DIRECTION       (PORT_PIN_IN) /* Switch */

/*******************************************************************************
 *                            Pins Initial value                               *
 *******************************************************************************/
#define PORTA_PIN0_DATA       (STD_LOW)
#define PORTA_PIN1_DATA       (STD_LOW)
#define PORTA_PIN2_DATA       (STD_LOW)
#define PORTA_PIN3_DATA       (STD_LOW)
#define PORTA_PIN4_DATA       (STD_LOW)
#define PORTA_PIN5_DATA       (STD_LOW)
#define PORTA_PIN6_DATA       (STD_LOW)
#define PORTA_PIN7_DATA       (STD_LOW)

#define PORTB_PIN0_DATA       (STD_LOW)
#define PORTB_PIN1_DATA       (STD_LOW)
#define PORTB_PIN2_DATA       (STD_LOW)
#define PORTB_PIN3_DATA       (STD_LOW)
#define PORTB_PIN4_DATA       (STD_LOW)
#define PORTB_PIN5_DATA       (STD_LOW)
#define PORTB_PIN6_DATA       (STD_LOW)
#define PORTB_PIN7_DATA       (STD_LOW)

#define PORTC_PIN0_DATA       (STD_LOW)
#define PORTC_PIN1_DATA       (STD_LOW)
#define PORTC_PIN2_DATA       (STD_LOW)
#define PORTC_PIN3_DATA       (STD_LOW)
#define PORTC_PIN4_DATA       (STD_LOW)
#define PORTC_PIN5_DATA       (STD_LOW)
#define PORTC_PIN6_DATA       (STD_LOW)
#define PORTC_PIN7_DATA       (STD_LOW)

#define PORTD_PIN0_DATA       (STD_LOW)
#define PORTD_PIN1_DATA       (STD_LOW)
#define PORTD_PIN2_DATA       (STD_LOW)
#define PORTD_PIN3_DATA       (STD_LOW)
#define PORTD_PIN4_DATA       (STD_LOW)
#define PORTD_PIN5_DATA       (STD_LOW)
#define PORTD_PIN6_DATA       (STD_LOW)
#define PORTD_PIN7_DATA       (STD_LOW)

#define PORTE_PIN0_DATA       (STD_LOW)
#define PORTE_PIN1_DATA       (STD_LOW)
#define PORTE_PIN2_DATA       (STD_LOW)
#define PORTE_PIN3_DATA       (STD_LOW)
#define PORTE_PIN4_DATA       (STD_LOW)
#define PORTE_PIN5_DATA       (STD_LOW)

#define PORTF_PIN0_DATA       (STD_LOW)
#define PORTF_PIN1_DATA       (STD_LOW)
#define PORTF_PIN2_DATA       (STD_LOW)
#define PORTF_PIN3_DATA       (STD_LOW)
#define PORTF_PIN4_DATA       (STD_LOW)

/*******************************************************************************
 *                             Pins data type                                  *
 *******************************************************************************/
#define PORTA_PIN0_DATA_TYPE       (DIGITAL)
#define PORTA_PIN1_DATA_TYPE       (DIGITAL)
#define PORTA_PIN2_DATA_TYPE       (DIGITAL)
#define PORTA_PIN3_DATA_TYPE       (DIGITAL)
#define PORTA_PIN4_DATA_TYPE       (DIGITAL)
#define PORTA_PIN5_DATA_TYPE       (DIGITAL)
#define PORTA_PIN6_DATA_TYPE       (DIGITAL)
#define PORTA_PIN7_DATA_TYPE       (DIGITAL)

#define PORTB_PIN0_DATA_TYPE       (DIGITAL)
#define PORTB_PIN1_DATA_TYPE       (DIGITAL)
#define PORTB_PIN2_DATA_TYPE       (DIGITAL)
#define PORTB_PIN3_DATA_TYPE       (DIGITAL)
#define PORTB_PIN4_DATA_TYPE       (DIGITAL)
#define PORTB_PIN5_DATA_TYPE       (DIGITAL)
#define PORTB_PIN6_DATA_TYPE       (DIGITAL)
#define PORTB_PIN7_DATA_TYPE       (DIGITAL)

#define PORTC_PIN0_DATA_TYPE       (DIGITAL)
#define PORTC_PIN1_DATA_TYPE       (DIGITAL)
#define PORTC_PIN2_DATA_TYPE       (DIGITAL)
#define PORTC_PIN3_DATA_TYPE       (DIGITAL)
#define PORTC_PIN4_DATA_TYPE       (DIGITAL)
#define PORTC_PIN5_DATA_TYPE       (DIGITAL)
#define PORTC_PIN6_DATA_TYPE       (DIGITAL)
#define PORTC_PIN7_DATA_TYPE       (DIGITAL)

#define PORTD_PIN0_DATA_TYPE       (DIGITAL)
#define PORTD_PIN1_DATA_TYPE       (DIGITAL)
#define PORTD_PIN2_DATA_TYPE       (DIGITAL)
#define PORTD_PIN3_DATA_TYPE       (DIGITAL)
#define PORTD_PIN4_DATA_TYPE       (DIGITAL)
#define PORTD_PIN5_DATA_TYPE       (DIGITAL)
#define PORTD_PIN6_DATA_TYPE       (DIGITAL)
#define PORTD_PIN7_DATA_TYPE       (DIGITAL)

#define PORTE_PIN0_DATA_TYPE       (DIGITAL)
#define PORTE_PIN1_DATA_TYPE       (DIGITAL)
#define PORTE_PIN2_DATA_TYPE       (ANALOG)
#define PORTE_PIN3_DATA_TYPE       (ANALOG)  /*adc*/
#define PORTE_PIN4_DATA_TYPE       (DIGITAL)
#define PORTE_PIN5_DATA_TYPE       (DIGITAL)

#define PORTF_PIN0_DATA_TYPE       (DIGITAL)
#define PORTF_PIN1_DATA_TYPE       (DIGITAL)
#define PORTF_PIN2_DATA_TYPE       (DIGITAL)
#define PORTF_PIN3_DATA_TYPE       (DIGITAL)
#define PORTF_PIN4_DATA_TYPE       (DIGITAL)

/*******************************************************************************
 *                           Pins Alternate Function                           *
 *******************************************************************************/
#define PORTA_PIN0_MODE_TYPE      (PORT_PIN_MODE_UART)
#define PORTA_PIN1_MODE_TYPE      (PORT_PIN_MODE_UART)
#define PORTA_PIN2_MODE_TYPE      (PORT_PIN_MODE_DIO)
#define PORTA_PIN3_MODE_TYPE      (PORT_PIN_MODE_DIO)
#define PORTA_PIN4_MODE_TYPE      (PORT_PIN_MODE_DIO)
#define PORTA_PIN5_MODE_TYPE      (PORT_PIN_MODE_DIO)
#define PORTA_PIN6_MODE_TYPE      (PORT_PIN_MODE_DIO)
#define PORTA_PIN7_MODE_TYPE      (PORT_PIN_MODE_DIO)

#define PORTB_PIN0_MODE_TYPE      (PORT_PIN_MODE_DIO)
#define PORTB_PIN1_MODE_TYPE      (PORT_PIN_MODE_DIO)
#define PORTB_PIN2_MODE_TYPE      (PORT_PIN_MODE_DIO)
#define PORTB_PIN3_MODE_TYPE      (PORT_PIN_MODE_DIO)
#define PORTB_PIN4_MODE_TYPE      (PORT_PIN_MODE_DIO)
#define PORTB_PIN5_MODE_TYPE      (PORT_PIN_MODE_DIO)
#define PORTB_PIN6_MODE_TYPE      (PORT_PIN_MODE_DIO)
#define PORTB_PIN7_MODE_TYPE      (PORT_PIN_MODE_DIO)

#define PORTC_PIN0_MODE_TYPE      (PORT_PIN_MODE_DIO)
#define PORTC_PIN1_MODE_TYPE      (PORT_PIN_MODE_DIO)
#define PORTC_PIN2_MODE_TYPE      (PORT_PIN_MODE_DIO)
#define PORTC_PIN3_MODE_TYPE      (PORT_PIN_MODE_DIO)
#define PORTC_PIN4_MODE_TYPE      (PORT_PIN_MODE_DIO)
#define PORTC_PIN5_MODE_TYPE      (PORT_PIN_MODE_DIO)
#define PORTC_PIN6_MODE_TYPE      (PORT_PIN_MODE_DIO)
#define PORTC_PIN7_MODE_TYPE      (PORT_PIN_MODE_DIO)

#define PORTD_PIN0_MODE_TYPE      (PORT_PIN_MODE_DIO)
#define PORTD_PIN1_MODE_TYPE      (PORT_PIN_MODE_DIO)
#define PORTD_PIN2_MODE_TYPE      (PORT_PIN_MODE_DIO)
#define PORTD_PIN3_MODE_TYPE      (PORT_PIN_MODE_DIO)
#define PORTD_PIN4_MODE_TYPE      (PORT_PIN_MODE_DIO)
#define PORTD_PIN5_MODE_TYPE      (PORT_PIN_MODE_DIO)
#define PORTD_PIN6_MODE_TYPE      (PORT_PIN_MODE_DIO)
#define PORTD_PIN7_MODE_TYPE      (PORT_PIN_MODE_DIO)

#define PORTE_PIN0_MODE_TYPE      (PORT_PIN_MODE_DIO)
#define PORTE_PIN1_MODE_TYPE      (PORT_PIN_MODE_DIO)
#define PORTE_PIN2_MODE_TYPE      (PORT_PIN_MODE_ADC)
#define PORTE_PIN3_MODE_TYPE      (PORT_PIN_MODE_ADC)  /*adc*/
#define PORTE_PIN4_MODE_TYPE      (PORT_PIN_MODE_DIO)
#define PORTE_PIN5_MODE_TYPE      (PORT_PIN_MODE_DIO)

#define PORTF_PIN0_MODE_TYPE      (PORT_PIN_MODE_DIO)
#define PORTF_PIN1_MODE_TYPE      (PORT_PIN_MODE_DIO)
#define PORTF_PIN2_MODE_TYPE      (PORT_PIN_MODE_DIO)
#define PORTF_PIN3_MODE_TYPE      (PORT_PIN_MODE_DIO)
#define PORTF_PIN4_MODE_TYPE      (PORT_PIN_MODE_DIO)

/*******************************************************************************
 *                           Pins Internal Resistor                            *
 *******************************************************************************/
#define PORTA_PIN0_RESISTOR       (PULL_UP)
#define PORTA_PIN1_RESISTOR       (PULL_UP)
#define PORTA_PIN2_RESISTOR       (PULL_UP)
#define PORTA_PIN3_RESISTOR       (PULL_UP)
#define PORTA_PIN4_RESISTOR       (PULL_UP)
#define PORTA_PIN5_RESISTOR       (PULL_UP)
#define PORTA_PIN6_RESISTOR       (PULL_UP)
#define PORTA_PIN7_RESISTOR       (PULL_UP)

#define PORTB_PIN0_RESISTOR       (PULL_UP)
#define PORTB_PIN1_RESISTOR       (PULL_UP)
#define PORTB_PIN2_RESISTOR       (PULL_UP)
#define PORTB_PIN3_RESISTOR       (PULL_UP)
#define PORTB_PIN4_RESISTOR       (PULL_UP)
#define PORTB_PIN5_RESISTOR       (PULL_UP)
#define PORTB_PIN6_RESISTOR       (PULL_UP)
#define PORTB_PIN7_RESISTOR       (PULL_UP)

#define PORTC_PIN0_RESISTOR       (PULL_UP)
#define PORTC_PIN1_RESISTOR       (PULL_UP)
#define PORTC_PIN2_RESISTOR       (PULL_UP)
#define PORTC_PIN3_RESISTOR       (PULL_UP)
#define PORTC_PIN4_RESISTOR       (PULL_UP)
#define PORTC_PIN5_RESISTOR       (PULL_UP)
#define PORTC_PIN6_RESISTOR       (PULL_UP)
#define PORTC_PIN7_RESISTOR       (PULL_UP)

#define PORTD_PIN0_RESISTOR       (PULL_UP)
#define PORTD_PIN1_RESISTOR       (PULL_UP)
#define PORTD_PIN2_RESISTOR       (PULL_UP)
#define PORTD_PIN3_RESISTOR       (PULL_UP)
#define PORTD_PIN4_RESISTOR       (PULL_UP)
#define PORTD_PIN5_RESISTOR       (PULL_UP)
#define PORTD_PIN6_RESISTOR       (PULL_UP)
#define PORTD_PIN7_RESISTOR       (PULL_UP)

#define PORTE_PIN0_RESISTOR       (PULL_UP)
#define PORTE_PIN1_RESISTOR       (PULL_UP)
#define PORTE_PIN2_RESISTOR       (PULL_UP)
#define PORTE_PIN3_RESISTOR       (PULL_UP)
#define PORTE_PIN4_RESISTOR       (PULL_UP)
#define PORTE_PIN5_RESISTOR       (PULL_UP)

#define PORTF_PIN0_RESISTOR       (PULL_UP)
#define PORTF_PIN1_RESISTOR       (OFF)
#define PORTF_PIN2_RESISTOR       (OFF)
#define PORTF_PIN3_RESISTOR       (OFF)
#define PORTF_PIN4_RESISTOR       (PULL_UP)

/*******************************************************************************
 *                          Pins Direction Changable                           *
 *******************************************************************************/
#define PORTA_PIN0_DIRECTION_CHANGABLE         (STD_OFF)
#define PORTA_PIN1_DIRECTION_CHANGABLE         (STD_OFF)
#define PORTA_PIN2_DIRECTION_CHANGABLE         (STD_OFF)
#define PORTA_PIN3_DIRECTION_CHANGABLE         (STD_OFF)
#define PORTA_PIN4_DIRECTION_CHANGABLE         (STD_OFF)
#define PORTA_PIN5_DIRECTION_CHANGABLE         (STD_OFF)
#define PORTA_PIN6_DIRECTION_CHANGABLE         (STD_OFF)
#define PORTA_PIN7_DIRECTION_CHANGABLE         (STD_OFF)

#define PORTB_PIN0_DIRECTION_CHANGABLE         (STD_OFF)
#define PORTB_PIN1_DIRECTION_CHANGABLE         (STD_OFF)
#define PORTB_PIN2_DIRECTION_CHANGABLE         (STD_OFF)
#define PORTB_PIN3_DIRECTION_CHANGABLE         (STD_OFF)
#define PORTB_PIN4_DIRECTION_CHANGABLE         (STD_OFF)
#define PORTB_PIN5_DIRECTION_CHANGABLE         (STD_OFF)
#define PORTB_PIN6_DIRECTION_CHANGABLE         (STD_OFF)
#define PORTB_PIN7_DIRECTION_CHANGABLE         (STD_OFF)

#define PORTC_PIN0_DIRECTION_CHANGABLE         (STD_OFF)
#define PORTC_PIN1_DIRECTION_CHANGABLE         (STD_OFF)
#define PORTC_PIN2_DIRECTION_CHANGABLE         (STD_OFF)
#define PORTC_PIN3_DIRECTION_CHANGABLE         (STD_OFF)
#define PORTC_PIN4_DIRECTION_CHANGABLE         (STD_OFF)
#define PORTC_PIN5_DIRECTION_CHANGABLE         (STD_OFF)
#define PORTC_PIN6_DIRECTION_CHANGABLE         (STD_OFF)
#define PORTC_PIN7_DIRECTION_CHANGABLE         (STD_OFF)

#define PORTD_PIN0_DIRECTION_CHANGABLE         (STD_OFF)
#define PORTD_PIN1_DIRECTION_CHANGABLE         (STD_OFF)
#define PORTD_PIN2_DIRECTION_CHANGABLE         (STD_OFF)
#define PORTD_PIN3_DIRECTION_CHANGABLE         (STD_OFF)
#define PORTD_PIN4_DIRECTION_CHANGABLE         (STD_OFF)
#define PORTD_PIN5_DIRECTION_CHANGABLE         (STD_OFF)
#define PORTD_PIN6_DIRECTION_CHANGABLE         (STD_OFF)
#define PORTD_PIN7_DIRECTION_CHANGABLE         (STD_OFF)

#define PORTE_PIN0_DIRECTION_CHANGABLE         (STD_OFF)
#define PORTE_PIN1_DIRECTION_CHANGABLE         (STD_OFF)
#define PORTE_PIN2_DIRECTION_CHANGABLE         (STD_OFF)
#define PORTE_PIN3_DIRECTION_CHANGABLE         (STD_OFF)
#define PORTE_PIN4_DIRECTION_CHANGABLE         (STD_OFF)
#define PORTE_PIN5_DIRECTION_CHANGABLE         (STD_OFF)

#define PORTF_PIN0_DIRECTION_CHANGABLE         (STD_OFF)
#define PORTF_PIN1_DIRECTION_CHANGABLE         (STD_OFF)
#define PORTF_PIN2_DIRECTION_CHANGABLE         (STD_OFF)
#define PORTF_PIN3_DIRECTION_CHANGABLE         (STD_OFF)
#define PORTF_PIN4_DIRECTION_CHANGABLE         (STD_OFF)

/*******************************************************************************
 *                          Pins Mode Changable                                *
 *******************************************************************************/

#define PORTA_PIN0_MODE_CHANGABLE         (STD_OFF)
#define PORTA_PIN1_MODE_CHANGABLE         (STD_OFF)
#define PORTA_PIN2_MODE_CHANGABLE         (STD_OFF)
#define PORTA_PIN3_MODE_CHANGABLE         (STD_OFF)
#define PORTA_PIN4_MODE_CHANGABLE         (STD_OFF)
#define PORTA_PIN5_MODE_CHANGABLE         (STD_OFF)
#define PORTA_PIN6_MODE_CHANGABLE         (STD_OFF)
#define PORTA_PIN7_MODE_CHANGABLE         (STD_OFF)

#define PORTB_PIN0_MODE_CHANGABLE         (STD_OFF)
#define PORTB_PIN1_MODE_CHANGABLE         (STD_OFF)
#define PORTB_PIN2_MODE_CHANGABLE         (STD_OFF)
#define PORTB_PIN3_MODE_CHANGABLE         (STD_OFF)
#define PORTB_PIN4_MODE_CHANGABLE         (STD_OFF)
#define PORTB_PIN5_MODE_CHANGABLE         (STD_OFF)
#define PORTB_PIN6_MODE_CHANGABLE         (STD_OFF)
#define PORTB_PIN7_MODE_CHANGABLE         (STD_OFF)

#define PORTC_PIN0_MODE_CHANGABLE         (STD_OFF)
#define PORTC_PIN1_MODE_CHANGABLE         (STD_OFF)
#define PORTC_PIN2_MODE_CHANGABLE         (STD_OFF)
#define PORTC_PIN3_MODE_CHANGABLE         (STD_OFF)
#define PORTC_PIN4_MODE_CHANGABLE         (STD_OFF)
#define PORTC_PIN5_MODE_CHANGABLE         (STD_OFF)
#define PORTC_PIN6_MODE_CHANGABLE         (STD_OFF)
#define PORTC_PIN7_MODE_CHANGABLE         (STD_OFF)

#define PORTD_PIN0_MODE_CHANGABLE         (STD_OFF)
#define PORTD_PIN1_MODE_CHANGABLE         (STD_OFF)
#define PORTD_PIN2_MODE_CHANGABLE         (STD_OFF)
#define PORTD_PIN3_MODE_CHANGABLE         (STD_OFF)
#define PORTD_PIN4_MODE_CHANGABLE         (STD_OFF)
#define PORTD_PIN5_MODE_CHANGABLE         (STD_OFF)
#define PORTD_PIN6_MODE_CHANGABLE         (STD_OFF)
#define PORTD_PIN7_MODE_CHANGABLE         (STD_OFF)

#define PORTE_PIN0_MODE_CHANGABLE         (STD_OFF)
#define PORTE_PIN1_MODE_CHANGABLE         (STD_OFF)
#define PORTE_PIN2_MODE_CHANGABLE         (STD_OFF)
#define PORTE_PIN3_MODE_CHANGABLE         (STD_OFF)
#define PORTE_PIN4_MODE_CHANGABLE         (STD_OFF)
#define PORTE_PIN5_MODE_CHANGABLE         (STD_OFF)

#define PORTF_PIN0_MODE_CHANGABLE         (STD_OFF)
#define PORTF_PIN1_MODE_CHANGABLE         (STD_OFF)
#define PORTF_PIN2_MODE_CHANGABLE         (STD_OFF)
#define PORTF_PIN3_MODE_CHANGABLE         (STD_OFF)
#define PORTF_PIN4_MODE_CHANGABLE         (STD_OFF)


#endif /* PORT_CFG_H_ */

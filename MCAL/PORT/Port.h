/******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port.h
 *
 * Description: Header file for TM4C123GH6PM Microcontroller - Port Driver.
 *
 * Author: Mina Samer
 ******************************************************************************/

#ifndef PORT_H
#define PORT_H

/*******************************************************************************
 *                           Module Definitions                                *
 *******************************************************************************/

/* Id for the company in the AUTOSAR */
#define PORT_VENDOR_ID    (1000U)

/* PORT Module Id */
#define PORT_MODULE_ID    ((uint16)120)

/* PORT Instance Id */
#define PORT_INSTANCE_ID  ((uint8)0)

/*
 * Module Version 1.0.0
 */
#define PORT_SW_MAJOR_VERSION           (1U)
#define PORT_SW_MINOR_VERSION           (0U)
#define PORT_SW_PATCH_VERSION           (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define PORT_AR_RELEASE_MAJOR_VERSION   (4U)
#define PORT_AR_RELEASE_MINOR_VERSION   (0U)
#define PORT_AR_RELEASE_PATCH_VERSION   (3U)

/*
 * Macros for PORT Status
 */
#define PORT_INITIALIZED                (1U)
#define PORT_NOT_INITIALIZED            (0U)

/*******************************************************************************
 *                                Inclusions                                   *
 *******************************************************************************/

/* Standard AUTOSAR types */
#include "MCU_Commen/Std_Types.h"

/* AUTOSAR checking between Std Types and PORT Modules */
#if ((STD_TYPES_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
        ||  (STD_TYPES_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
        ||  (STD_TYPES_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
#error "The AR version of Std_Types.h does not match the expected version"
#endif

/* PORT Pre-Compile Configuration Header file */
#include "PORT_Cfg.h"

/* AUTOSAR Version checking between PORT_Cfg.h and PORT.h files */
#if ((PORT_CFG_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
        ||  (PORT_CFG_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
        ||  (PORT_CFG_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
#error "The AR version of PORT_Cfg.h does not match the expected version"
#endif

/* Software Version checking between PORT_Cfg.h and PORT.h files */
#if ((PORT_CFG_SW_MAJOR_VERSION != PORT_SW_MAJOR_VERSION)\
        ||  (PORT_CFG_SW_MINOR_VERSION != PORT_SW_MINOR_VERSION)\
        ||  (PORT_CFG_SW_PATCH_VERSION != PORT_SW_PATCH_VERSION))
#error "The SW version of PORT_Cfg.h does not match the expected version"
#endif

/* Non AUTOSAR files */
#include "MCU_Commen/Common_Macros.h"

/******************************************************************************
 *                      API Service Id Macros                                 *
 ******************************************************************************/
/* Service ID for PORT Init */
#define PORT_INIT_SID                             (uint8)0x00

/* Service ID for PORT Set Pin Direction */
#if (PORT_SET_PIN_DIRECTION_API == STD_ON)
#define PORT_SET_PIN_DIRECTION_SID                (uint8)0x01
#endif

/* Service ID for PORT Refresh Port Direction */
#define PORT_REFRESH_PORT_DIRECTION_SID           (uint8)0x02

/* Service ID for PORT GetVersionInfo */
#if (PORT_VERSION_INFO_API == STD_ON)
#define PORT_GET_VERSION_INFO_SID                 (uint8)0x03
#endif

/* Service ID for PORT Set Pin Mode */
#if (PORT_SET_PIN_MODE_API == STD_ON)
#define PORT_SET_PIN_MODE_SID                      (uint8)0x04
#endif

/*******************************************************************************
 *                      DET Error Codes                                        *
 *******************************************************************************/
/* DET code to report Invalid Port Pin ID */
#define PORT_E_PARAM_PIN                           (uint8)0x0A

/* Port Pin not configured as changeable */
#define PORT_E_DIRECTION_UNCHANGEABLE              (uint8)0x0B

/* API Port_Init service called with wrong parameter. */
#define PORT_E_PARAM_CONFIG                        (uint8)0x0C

/* API Port_SetPinMode service called when mode is unchangeable. */
#define PORT_E_PARAM_INVALID_MODE                  (uint8)0x0D
#define PORT_E_MODE_UNCHANGEABLE                   (uint8)0x0E

/* API service called without module initialization*/
#define PORT_E_UNINIT                              (uint8)0x0F

/* APIs called with a Null Pointer */
#define PORT_E_PARAM_POINTER                        (uint8)0x10

/*******************************************************************************
 *                              Module Data Types                              *
 *******************************************************************************/

/* Type definition for whether pin can be initialized */
typedef uint8 Port_PinInit;

/* Data type for the symbolic name of a port pin. */
typedef uint8 Port_PinType;

/* Type definition for the type of a port (used by the DIO APIs) */
typedef uint8 Port_PortType;

/* Different port pin modes. */
typedef uint8 Port_PinModeType;

/* Type definition for whether pin direction is changable */
typedef uint8 Port_PinDirectionChangable;

/* Type definition for whether pin mode is changable */
typedef uint8 Port_PinModeChangable;

/* Description: Possible directions of a port pin. */
typedef enum
{
    PORT_PIN_IN,PORT_PIN_OUT
}Port_PinDirectionType;

/* Description: Enum to hold internal resistor type for PIN */
typedef enum
{
    OFF,PULL_UP,PULL_DOWN
}Port_InternalResistorType;

/* Type definition for whether pin mode is changable */
typedef enum
{
    ANALOG,DIGITAL
} Port_DataType;

/* Description: Structure to configure each individual PIN:
 *	1. the PORT Which the pin belongs to. 0, 1, 2, 3, 4 or 5
 *	2. the number of the pin in the PORT.
 *      3. the direction of pin --> INPUT or OUTPUT
 *      4. the internal resistor --> Disable, Pull up or Pull down
 */
typedef struct 
{
    Port_PinInit Pin_Init;                                  /* STD_ON,STD_OFF            */
    Port_PortType Port_Num;                                 /* PortA, PortB, PortC, ..   */
    Port_PinType Pin_Num;                                   /* PA0, PA1, ... , PF3, PF4  */
    Port_PinDirectionType Pin_Direction;                    /* PORT_PIN_IN, PORT_PIN_OUT */
    uint8 initial_value;                                    /* Initial value of the pin  */
    Port_PinModeType Pin_Mode;                              /* Initial mode of pin       */
    Port_InternalResistorType Resistor;                     /* OFF,PULL_UP,PULL_DOW      */
    Port_DataType Pin_Data;                                 /* Analog, Digital           */
    Port_PinDirectionChangable Pin_DirectionChangable;      /* STD_ON,STD_OFF            */
    Port_PinModeChangable Pin_ModeChangable;                /* STD_ON,STD_OFF            */
} Port_ConfigPins;

/* Structure containing initialization data for PORT module */
typedef struct {
    Port_ConfigPins Pins[PORT_NUMBER_OF_PORT_PINS];
} Port_ConfigType;

/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/

/************************************************************************************
 * Service Name: Port_Init
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * Parameters (in): ConfigPtr - Pointer to post-build configuration data
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Initializes the Port Driver module.
 ************************************************************************************/
void Port_Init(const Port_ConfigType* ConfigPtr);

/************************************************************************************
 * Service Name: Port_SetPinDirection
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): Pin - Port Pin ID number
 *                  Direction - Port Pin Direction
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Sets the port pin direction.
 ************************************************************************************/
#if (PORT_SET_PIN_DIRECTION_API == STD_ON)
void Port_SetPinDirection(Port_PinType Pin, Port_PinDirectionType Direction);
#endif

/************************************************************************************
 * Service Name: Port_RefreshPortDirection
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * Parameters (in): None
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Refreshes port direction.
 ************************************************************************************/
void Port_RefreshPortDirection(void);

/************************************************************************************
 * Service Name: Port_GetVersionInfo
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * Parameters (in): None
 * Parameters (inout): None
 * Parameters (out): versioninfo - Pointer to where to store the version information of this module.
 * Return value: None
 * Description: Returns the version information of this module.
 ************************************************************************************/
#if (PORT_VERSION_INFO_API == STD_ON)
void Port_GetVersionInfo(Std_VersionInfoType* versioninfo);
#endif

/************************************************************************************
 * Service Name: Port_SetPinMode
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): Pin - Port Pin ID number
 *                  Mode- New Port Pin mode to be set on port pin.
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Sets the port pin mode.
 ************************************************************************************/
#if (PORT_SET_PIN_MODE_API == STD_ON)
void Port_SetPinMode(Port_PinType Pin, Port_PinModeType Mode);
#endif

/************************************************************************************
 *                            External Variables                                    *
 ************************************************************************************/
/* Extern PB structures to be used by PORT and other modules */

extern const Port_ConfigType Port_Configuration;

/*******************************************************************************
 *                           Preprocessor Definitions                          *
 *******************************************************************************/
#define PORT_LOCK_KEY     0x4C4F434B

/************************************************************************************
 *                                 End of File                                      *
 ************************************************************************************/

#endif /* PORT_H */

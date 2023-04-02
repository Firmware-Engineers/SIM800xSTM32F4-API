/**
 ******************************************************************************
 * @file            SIM800x.h
 * @author          Maxime  
 * @brief           Main header file for SIM800 series Modem API
 * @brief           This file provides macros and function definitions common
 *                  to the SIM800 series.
 * 
 * @brief           Supported devices are listed in the include section.
 * @brief           See dependencies in the include section.
 * 
 * @note            History:
 *                   - March 30, 2023: Initial release
 *                   	* Based on SIM800xPIC18-API
 * 
 * @note            It has been successfully tested with:
 *                  - IDE: 
 *                      * STMCube IDE V1.11.0
 *                  - Toolchain:
 *                      * GNU Tools for STM32 V10.3
 *                  - DTE Devices: 
 *                      * STM32F407
 *                  - DCE Devices:
 *                      * SIM800L
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; </center></h2>
 *
 *
 ******************************************************************************
 */

#ifndef __SIM800X_H
#define	__SIM800X_H

#ifdef	__cplusplus
extern "C" {
#endif

//-----------------------------------
#include "SIM800x_SDM.h"
#include "SIM800x_Types.h"
#include "SIM800x_ID.h"
#include "SIM800x_IP.h"
#include "SIM800x_GPRS.h"
#include "SIM800x_HTTP.h"
#include "SIM800x_3GPPTS270057.h"
#include "SIM800x_V25Ter.h"
#include <stdio.h>
#include <stdlib.h>
//-----------------------------------

//-----------------------------------    
/**
 * @brief   Initialize the API
 * @note    This function will:
 *              - Initialize the SDM driver and associated libraries
 *              - Set modem communication baud rate 
 * @note    Prior to using this function, make sure to define the global macro FOSC_MHZ,
 *          with the MCU crystal frequency in megahertz, in the project settings.
 * @note    Modem baud rate has to be known prior to calling this function. The initialization will fail if 
 *          modem and controller baud rates are not synchronized.
 * @note    **Use a USB to TTL converter (ex. FT232R) and serial a terminal (ex. FLOTERM) to configure and save the modem baud rate.**
 * @param   br: Modem communication baud rate (see @ref CONFIG_API_BAUDRATE_CONSTANTS)   
 * @retval  SIM800x_APIStatusType
 * 
 *              - SIM800X_OK: success
 *              - SIM800X_TIME_OUT: no response from the modem
 *              - SIM800X_BR_ERROR: could not set the baud rate
 * 
 * @warning  **initialization takes 5.5 to 10s to complete.**
 * @warning  **When calling this function on PIC18 or STM32 based applications,
 * 			make sure not to let the UART/USART RX pin floating. Use a pull-up instead.**
 *
 */ 
extern SIM800x_APIStatusType SIM800xInit(uint32_t br);
//-----------------------------------

//-----------------------------------    
/**
 * @brief   Perform a reset of the modem
 * @note    This function will:
 *              - Attempt to reset the modem via the reset pin if @ref CONFIG_USE_RST_CTRL_PIN is defined
 *              - Reset the modem via serial communication if reset pin not defined
 * @param   none  
 * @retval  SIM800x_APIStatusType
 * 
 *              - SIM800X_OK: success
 *              - SIM800X_ERROR: reset via serial COM failed
 * 
 * @note    **At least 6 seconds are required after reset, for modem to get ready.**  
 *
 */ 
extern SIM800x_APIStatusType SIM800xReset(void);
//-----------------------------------

//-----------------------------------    
/**
 * @brief   Turn on power supply circuit for the modem
 * @note    This function will turn on the modem power supply circuitry 
 *          via the @ref CONFIG_USE_PWR_CTRL_PIN is defined
 * 
 * @param   none  
 * @retval  SIM800x_APIStatusType
 * 
 *              - SIM800X_OK: success
 *              - NOT DEFINED: power-on pin not defined
 *
 */ 
extern SIM800x_APIStatusType SIM800xPWROn(void);
//-----------------------------------

//-----------------------------------    
/**
 * @brief   Turn off power supply circuit for the modem
 * @note    This function will turn off the modem power supply circuitry 
 *          via the @ref CONFIG_USE_PWR_CTRL_PIN is defined
 * 
 * @param   none  
 * @retval  SIM800x_APIStatusType
 * 
 *              - SIM800X_OK: success
 *              - NOT DEFINED: power-off pin not defined
 *
 */ 
extern SIM800x_APIStatusType SIM800xPWROff(void);
//-----------------------------------

//-----------------------------------    
/**
 * @brief   Set modem baud rate
 * @note    This function will:
 *              - Attempt to set the modem baud rate
 *              - If successful, the local baud rate will also be adjusted accordingly
 * @param   none  
 * @retval  SIM800x_APIStatusType
 * 
 *              - SIM800X_OK: success
 *              - SIM800X_TIME_OUT: no response from the modem
 *              - SIM800X_ERROR: could not change modem baud rate
 * @warning		It takes around 600ms to complete.
 *
 */ 
extern SIM800x_APIStatusType SIM800xSetBaudRate(uint32_t br);
//-----------------------------------

//-----------------------------------    
/**
 * @brief   Get modem state
 * @note    This function will check if the modem is ready for communication
 * @param   none  
 * @retval  SIM800x_APIStatusType
 * 
 *              - SIM800X_OK: ready
 *              - SIM800X_TIME_OUT: no response from the modem
 *              - SIM800X_ERROR: error
 *
 */ 
extern SIM800x_APIStatusType SIM800xGetState(void);
//-----------------------------------

//-----------------------------------    
/**
 * @brief   Turn off modem
 * @note    This function will:
 *              - Attempt to turn off the modem via @ref CONFIG_USE_PWRKEY_PIN if defined
 *              - Turn off the modem via serial communication if PWRKEY not defined
 * @note    If successful, the modem will restart after approximatively 33s.
 * @param   none  
 * @retval  SIM800x_APIStatusType
 * 
 *              - SIM800X_OK: success
 *              - SIM800X_TIME_OUT: no response from the modem
 *              - SIM800X_ERROR: could not power off via serial COM
 *
 */ 
extern SIM800x_APIStatusType SIM800xOff(void);
//-----------------------------------

#ifdef	__cplusplus
}
#endif

#endif	/* __SIM800X_H */


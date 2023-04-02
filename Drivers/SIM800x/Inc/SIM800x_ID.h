/**
 ******************************************************************************
 * @file            SIM800x_ID.h
 * @author          Maxime  
 * @brief           Header file for SIM800 series modems ID numbers
 * @brief           This file provides function definitions used for requesting 
 *                  some ID numbers from the modem.
 * 
 * @note            IDs include:
 *                      - Manufacturer ID
 *                      - Model ID
 *                      - Revision ID of Software Release
 *                      - Global Object ID
 *                      - Serial Number ID or IMEI
 *                      - Product Identification Information
 *                      - International Mobile Subscriber Identity
 * 
 * @brief           Supported devices are listed below.
 * @brief           See dependencies in the include section.
 * 
 * @note            History:
 *                   - March 3, 2023: Initial release
 *                   - March 28, 2023:
 *                      * Added SIM800xGetProductID()
 *                      * Added SIM800xGetIMSI()
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

#ifndef __SIM800X_ID_H
#define	__SIM800X_ID_H

#ifdef	__cplusplus
extern "C" {
#endif

//-----------------------------------
#include <stdlib.h>
#include "SIM800x_Types.h"    
//-----------------------------------

    
//-----------------------------------    
/**
 * @brief   Request Manufacturer ID
 * @param   id: requested id (null terminated string)
 * @note    **Min array size for id is 11**  
 * @retval  SIM800x_APIStatusType
 * 
 *              - SIM800X_OK: success
 *              - SIM800X_TIME_OUT: no data received
 *              - SIM800X_INVALID_RESPONSE: invalid
 *              - SIM800X_INVALID_RESPONSE: unexpected response
 *
 */ 
extern SIM800x_APIStatusType SIM800xGetManufacturerID(char * id);
//-----------------------------------

//-----------------------------------    
/**
 * @brief   Request Model ID
 * @param   id: requested id (null terminated string)
 * @note    **Min array size for id is 15**  
 * @retval  SIM800x_APIStatusType
 * 
 *              - SIM800X_OK: success
 *              - SIM800X_TIME_OUT: no data received
 *              - SIM800X_INVALID_RESPONSE: invalid
 *              - SIM800X_INVALID_RESPONSE: unexpected response
 *
 */ 
extern SIM800x_APIStatusType SIM800xGetModelID(char * id);
//-----------------------------------

//-----------------------------------    
/**
 * @brief   Request Software Revision ID
 * @param   id: requested id (null terminated string)
 * @note    **Min array size for id is 15**  
 * @retval  SIM800x_APIStatusType
 * 
 *              - SIM800X_OK: success
 *              - SIM800X_TIME_OUT: no data received
 *              - SIM800X_INVALID_RESPONSE: invalid
 *              - SIM800X_INVALID_RESPONSE: unexpected response
 *
 */ 
extern SIM800x_APIStatusType SIM800xGetSoftwareRevisionID(char * id);
//-----------------------------------

//-----------------------------------    
/**
 * @brief   Request Global Object ID
 * @param   id: requested id (null terminated string)
 * @note    **Min array size for id is 7**  
 * @retval  SIM800x_APIStatusType
 * 
 *              - SIM800X_OK: success
 *              - SIM800X_TIME_OUT: no data received
 *              - SIM800X_INVALID_RESPONSE: invalid
 *              - SIM800X_INVALID_RESPONSE: unexpected response
 *
 */ 
extern SIM800x_APIStatusType SIM800xGetGlobalObjectID(char * id);
//-----------------------------------

//-----------------------------------    
/**
 * @brief   Request Serial Number ID or IMEI (International Mobile Equipment Identity number)
 * @param   id: requested id (null terminated string)
 * @note    **Min array size for id is 16**  
 * @retval  SIM800x_APIStatusType
 * 
 *              - SIM800X_OK: success
 *              - SIM800X_TIME_OUT: no data received
 *              - SIM800X_INVALID_RESPONSE: invalid
 *              - SIM800X_INVALID_RESPONSE: unexpected response
 *
 */ 
extern SIM800x_APIStatusType SIM800xGetIMEI(char * id);
//-----------------------------------

//-----------------------------------    
/**
 * @brief   Request Product Identification Information
 * @param   id: requested id (null terminated string)
 * @note    **Min array size for id is 15**  
 * @retval  SIM800x_APIStatusType
 * 
 *              - SIM800X_OK: success
 *              - SIM800X_TIME_OUT: no data received
 *              - SIM800X_INVALID_RESPONSE: invalid
 *              - SIM800X_INVALID_RESPONSE: unexpected response
 *
 */ 
extern SIM800x_APIStatusType SIM800xGetProductID(char * id);
//-----------------------------------

//-----------------------------------    
/**
 * @brief       Request International Mobile Subscriber Identity (IMSI)
 * @note        This ID can only be returned when the SIM card is present and working properly.
 * @param       id: requested id (null terminated string)
 * @param[out]  errcode: CME_ERROR code (See description in SIM800x_Types.h)
 * @note        **Min array size for id is 16**
 * @retval      SIM800x_APIStatusType
 * 
 *              - SIM800X_OK: success
 *              - SIM800X_TIME_OUT: no data received
 *              - SIM800X_INVALID_RESPONSE: invalid
 *              - SIM800X_CME_ERROR: ME ERROR
 *
 */ 
extern SIM800x_APIStatusType SIM800xGetIMSI(char * id, uint16_t* errcode);
//-----------------------------------

#ifdef	__cplusplus
}
#endif

#endif	/* __SIM800X_ID_H */


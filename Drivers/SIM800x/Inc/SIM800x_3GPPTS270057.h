/**
 ******************************************************************************
 * @file            SIM800x_3GPPTS270057.h
 * @author          Maxime  
 * @brief           Header file for SIM800 series 3GPP TS 27.005/7 functionalities
 * 
 * @brief           Supported devices are listed in the include section.
 * @brief           See dependencies in the include section.
 * 
 * @note            History:
 *                   - March 28, 2023: Initial release
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

#ifndef __SIM800X_3GPPTS270057_H
#define	__SIM800X_3GPPTS270057_H

#ifdef	__cplusplus
extern "C" {
#endif

//-----------------------------------
#include <stdlib.h>
#include "SIM800x_Types.h"
//-----------------------------------

//-----------------------------------
/**
 * @brief       Request registered operator name
 * @param       opname: requested name (null terminated string)
 * @param[out]  errcode: CME_ERROR code (See description in SIM800x_Types.h)
 * @note        **Min array size for opname is 20**
 * @retval      SIM800x_APIStatusType
 *
 *              - SIM800X_OK: success
 *              - SIM800X_TIME_OUT: no data received
 *              - SIM800X_CME_ERROR: invalid
 *              - SIM800X_INVALID_RESPONSE: unexpected response
 *
 */
extern SIM800x_APIStatusType SIM800x3GPPGetOperatorName(char *name, uint16_t* errcode);
//-----------------------------------

//-----------------------------------
/**
 * @brief       Get signal quality
 * @param[out]  rssi: Receive Signal Strength Indicator. Supported values are:
 *              - 0: -115 dBm or less
 *              - 1: -111 dBm
 *              - 2..30: -110...-54 dBm
 *              - 31: -52 dBm or greater
 *              - 99: not known or detectable
 *
 * @param[out]  ber: Bit Error Rate in percentage. Supported values are:
 *              - 0..7 or 99.
 *
 * @param[out]  errcode: CME_ERROR code (See description in SIM800x_Types.h)
 * @note        **Min array size for opname is 20**
 * @retval      SIM800x_APIStatusType
 *
 *              - SIM800X_OK: success
 *              - SIM800X_TIME_OUT: no data received
 *              - SIM800X_CME_ERROR: invalid
 *              - SIM800X_INVALID_RESPONSE: unexpected response
 *
 */
extern SIM800x_APIStatusType SIM800x3GPPGetSignalQuality(uint8_t *rssi, uint8_t *ber, uint16_t* errcode);
//-----------------------------------

//-----------------------------------
/**
 * @brief       Get Subscriber number
 * @param[out]  num: requested name (null terminated string)
 *
 * @param[out]  errcode: CME_ERROR code (See description in SIM800x_Types.h)
 * @note        **Min array size for num is 20**
 * @retval      SIM800x_APIStatusType
 *
 *              - SIM800X_OK: success
 *              - SIM800X_TIME_OUT: no data received
 *              - SIM800X_CME_ERROR: invalid
 *              - SIM800X_INVALID_RESPONSE: unexpected response
 *
 */
extern SIM800x_APIStatusType SIM800x3GPPGetSubscriberNumber(char *num, uint16_t* errcode);
//-----------------------------------

#ifdef	__cplusplus
}
#endif

#endif	/* __SIM800X_3GPPTS270057_H */


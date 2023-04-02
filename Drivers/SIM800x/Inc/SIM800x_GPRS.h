/**
 ******************************************************************************
 * @file            SIM800x_GPRS.h
 * @author          Maxime  
 * @brief           Header file for SIM800 series modems GPRS application
 * @brief           This file provides function definitions that provide GPRS 
 *                  services.
 * 
 * @brief           Supported devices are listed in the include section.
 * @brief           See dependencies in the include section.
 * 
 * @note            History:
 *                   - March 6, 2023: Initial release
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

#ifndef __SIM800X_GPRS_H
#define	__SIM800X_GPRS_H

#ifdef	__cplusplus
extern "C" {
#endif

//-----------------------------------
#include <stdlib.h>
#include "SIM800x_Types.h"
//-----------------------------------

/**
  * @brief  GPRS status type definition
  */ 
typedef enum
{
    //---------
    GPRS_DETACHED                    	= 0,                                  	//!< GPRS service detached
    GPRS_ATTACHED                    	= 1,                                  	//!< GPRS service attached
    GPRS_DEACTIVATED                 	= 0,                                  	//!< PDP context deactivated
    GPRS_ACTIVATED                   	= 1,                                   	//!< PDP context activated
    GPRS_DISABLED                    	= 0,                                 	//!< Disabled
    GPRS_ENABLED                     	= 1,                                   	//!< Enabled
    GPRS_NOT_REGISTRED               	= 0,                                  	//!< Not registered
    GPRS_REGISTERED_HOME             	= 1,                                 	//!< Registered, home network
    GPRS_NOT_REGISTRED_SEARCHING     	= 2,                                  	//!< Not registered, searching
    GPRS_REGISTRATION_DENIED         	= 3,                                 	//!< Registration denied
    GPRS_UNKNOWN                     	= 4,                                   	//!< Unknown
    GPRS_REGISTRED_ROAMING           	= 5,                                   	//!< Registered, roaming
    GPRS_PACKET_DOMAIN               	= 0,                                 	//!< Packet Domain (GPRS)
    GPRS_CIRCUIT_SWITCHED            	= 1,                                 	//!< Circuit Switched Data Call (CSD)
    GPRS_PACKET_DOMAIN_PREFERRED     	= 2,                                	//!< Packet Domain preferred (CSD used if GPRS not available)
    GPRS_CIRCUIT_SWITCHED_PREFERRED  	= 3,                             		//!< Circuit Switched preferred (GPRS used if circuit switched not available)
    GPRS_TIME_OUT               		= 6,                                  	//!< Time-out
    GPRS_CME_ERROR              		= 7,                                   	//!< ME error
    //---------        
}SIM800xGPRSStatusType;
//-----------------------------------    

//-----------------------------------    
/**
 * @brief       Get GPRS service attachment state
 * @param       none      
 * @retval      SIM800xGPRSStatusType (See description). Supported values are:
 * 
 *              - GPRS_ATTACHED: GPRS attached
 *              - GPRS_DETACHED: GPRS detached
 *              - GPRS_TIME_OUT: No response
 *  
 */ 
extern SIM800xGPRSStatusType SIM800xGPRSGetAttachState(void);  
//-----------------------------------

//-----------------------------------    
/**
 * @brief       Attach GPRS service
 * @param[out]  errcode: CME_ERROR code (See description in SIM800x_Types.h)      
 * @retval      SIM800x_APIStatusType. Supported values are:
 * 
 *              - SIM800X_OK: success
 *              - SIM800X_TIME_OUT: time-out
 *              - SIM800X_ERROR: failed
 *              - SIM800X_CME_ERROR: ME error
 *  
 */ 
extern SIM800x_APIStatusType SIM800xGPRSAttach(uint16_t* errcode);
//-----------------------------------

//-----------------------------------    
/**
 * @brief       Detach GPRS service
 * @param[out]  errcode: CME_ERROR code (See description in SIM800x_Types.h)      
 * @retval      SIM800x_APIStatusType. Supported values are:
 * 
 *              - SIM800X_OK: success
 *              - SIM800X_TIME_OUT: time-out
 *              - SIM800X_CME_ERROR: ME error
 *  
 */ 
extern SIM800x_APIStatusType SIM800xGPRSDetach(uint16_t* errcode);
//-----------------------------------

//-----------------------------------    
/**
 * @brief       Set PDP context parameters
 * @param[in]   cid: PDP context id. Supported values are:
 *              - [1...3]   
 * 
 * @param[in]   apn: Access Point Name (null terminated string).
 * @note        **Maximum size for APN is 50 character.**
 * @retval      SIM800x_APIStatusType
 * 
 *              - SIM800X_OK: success
 *              - SIM800X_TIME_OUT: no response from the modem
 *              - SIM800X_ERROR: failed
 */ 
extern SIM800x_APIStatusType SIM800xGPRSSetPDPContext(uint8_t cid, const char* apn);
//-----------------------------------

//-----------------------------------    
/**
 * @brief       Set Quality of Service (QoS) minimum acceptable
 * @param[in]   cid:  PDP context id. Supported values are:
 *              - [1...3]
 * 
 * @param[out]  precedence: QoS precedence class. Supported values are:
 *              - [0...3]
 * 
 * @param[out]  delay: QoS delay. Supported values are:  
 *              - [0...4]
 *   
 * @param[out]  reliability: QoS reliability. Supported values are:
 *              - [0...5]
 *  
 * @param[out]  peak: QoS peak. Supported values are:
 *              - [0...9]
 * 
 * @param[out]  mean: QoS mean. Supported values are:
 *              - [0...18, 31] 
 * 
 * @param[out]  errcode: CME_ERROR code (See description in SIM800x_Types.h)
 *  
 * @retval      SIM800x_APIStatusType
 * 
 *              - SIM800X_OK: success
 *              - SIM800X_TIME_OUT: time-out
 *              - SIM800X_CME_ERROR: ME error
 *   
 */ 
extern SIM800x_APIStatusType SIM800xGPRSSetQoSMin(uint8_t cid, uint8_t precedence, uint8_t delay, uint8_t reliability, uint8_t peak, uint8_t mean, uint16_t* errcode);
//-----------------------------------

//-----------------------------------    
/**
 * @brief       Set Quality of Service (QoS) request 
 * @param[in]   cid:  PDP context id. Supported values are:
 *              - [1...3]
 * 
 * @param[out]  precedence: QoS precedence class. Supported values are:
 *              - [0...3]
 * 
 * @param[out]  delay: QoS delay. Supported values are:  
 *              - [0...4]
 *   
 * @param[out]  reliability: QoS reliability. Supported values are:
 *              - [0...5]
 *  
 * @param[out]  peak: QoS peak. Supported values are:
 *              - [0...9]
 * 
 * @param[out]  mean: QoS mean. Supported values are:
 *              - [0...18, 31] 
 * 
 * @param[out]  errcode: CME_ERROR code (See description in SIM800x_Types.h)
 *  
 * @retval      SIM800x_APIStatusType
 * 
 *              - SIM800X_OK: success
 *              - SIM800X_TIME_OUT: time-out
 *              - SIM800X_CME_ERROR: ME error
 *   
 */ 
extern SIM800x_APIStatusType SIM800xGPRSSetQoSRequest(uint8_t cid, uint8_t precedence, uint8_t delay, uint8_t reliability, uint8_t peak, uint8_t mean, uint16_t* errcode);
//-----------------------------------

//-----------------------------------    
/**
 * @brief       Get PDP context activation state
 * @param       cid:  PDP context id. Supported values are:
 *              - [1...3]  
 *     
 * @retval      SIM800xGPRSStatusType (See description). Supported values are:
 * 
 *              - GPRS_ACTIVATED: PDP context activated
 *              - GPRS_DEACTIVATED: PDP context deactivated
 *              - GPRS_TIME_OUT: No response
 *  
 */ 
extern SIM800xGPRSStatusType SIM800xGPRSGetPDPContextState(uint8_t cid);  
//-----------------------------------

//-----------------------------------    
/**
 * @brief       Activate PDP context
 * @param[in]   cid: PDP context id. Supported values are:
 *              - [1...3]
 * 
 * @param[out]  errcode: CME_ERROR code (See description in SIM800x_Types.h)
 *    
 * @retval      SIM800x_APIStatusType. Supported values are:
 * 
 *              - SIM800X_OK: success
 *              - SIM800X_TIME_OUT: time-out
 *              - SIM800X_ERROR: failed
 *              - SIM800X_CME_ERROR: ME error
 *  
 */ 
extern SIM800x_APIStatusType SIM800xGPRSPDPContextActivate(uint8_t cid, uint16_t* errcode);
//-----------------------------------

//-----------------------------------    
/**
 * @brief       Deactivate PDP context
 * @param[in]   cid: PDP context id. Supported values are:
 *              - [1...3]
 * 
 * @param[out]  errcode: CME_ERROR code (See description in SIM800x_Types.h)
 *       
 * @retval      SIM800x_APIStatusType. Supported values are:
 * 
 *              - SIM800X_OK: success
 *              - SIM800X_TIME_OUT: time-out
 *              - SIM800X_ERROR: failed
 *              - SIM800X_CME_ERROR: ME error
 *  
 */ 
extern SIM800x_APIStatusType SIM800xGPRSPDPContextDeactivate(uint8_t cid, uint16_t* errcode);
//-----------------------------------

//-----------------------------------    
/**
 * @brief       Enter data mode
 * @param[in]   cid:  PDP context id. Supported values are:
 *              - [1...3]
 * 
 * @param[out]  errcode: CME_ERROR code (See description in SIM800x_Types.h) 
 *  
 * @retval      SIM800x_APIStatusType
 * 
 *              - SIM800X_OK: Data mode set
 *              - SIM800X_TIME_OUT: no response
 *              - SIM800X_CME_ERROR: ME error
 *   
 */ 
extern SIM800x_APIStatusType SIM800xGPRSSetDataMode(uint8_t cid, uint16_t* errcode);
//-----------------------------------

//-----------------------------------    
/**
 * @brief       Get PDP address
 * @param       cid:  PDP context id. Supported values are:
 *              - [1...3]
 * 
 * @param[out]  ip: IP address (null terminated string).
 * @param       If the PDP context is not activated, a null address will be returned.     
 *    
 * @retval      SIM800x_APIStatusType
 * 
 *              - SIM800X_OK: success
 *              - SIM800X_TIME_OUT: no response
 *              - SIM800X_ERROR: failed
 *   
 */ 
extern SIM800x_APIStatusType SIM800xGPRSGetAddress(uint8_t cid, char* ip);
//-----------------------------------

//-----------------------------------    
/**
 * @brief       Get Mobile Station (MS) Class
 * @param[out]  mtclass: MS Class. Supported values are:
 *              - 1: MS Class B
 *              - 2: MS Class CG
 *              - 3: MS Class CC
 *       
 * @retval      SIM800x_APIStatusType. Supported values are:
 * 
 *              - SIM800X_OK: success
 *              - SIM800X_TIME_OUT: time-out
 *  
 */ 
extern SIM800x_APIStatusType SIM800xGPRSGetMTClass(uint8_t* mtclass);
//-----------------------------------

//-----------------------------------    
/**
 * @brief       Get Mobile Station (MS) Class
 * @param[in]   mtclass: MS Class. Supported values are:
 *              - 1: MS Class B
 *              - 2: MS Class CG
 *              - 3: MS Class CC
 * 
 * @param[out]  errcode: CME_ERROR code (See description in SIM800x_Types.h) 
 *      
 * @retval      SIM800x_APIStatusType. Supported values are:
 * 
 *              - SIM800X_OK: success
 *              - SIM800X_TIME_OUT: time-out
 *              - SIM800X_CME_ERROR: ME error
 *  
 */ 
extern SIM800x_APIStatusType SIM800xGPRSSetMTClass(uint8_t mtclass, uint16_t* errcode);
//-----------------------------------

//-----------------------------------    
/**
 * @brief       Get GPRS Unsolicited Event Reporting (UER) mode    
 *    
 * @retval      SIM800xGPRSStatusType
 * 
 *              - GPRS_ENABLED: GPRS UER enabled
 *              - GPRS_DISABLED: GPRS UER disabled
 *              - GPRS_TIME_OUT: time-out
 * 
 */ 
extern SIM800xGPRSStatusType SIM800xGPRSUERGetMode(void);  
//-----------------------------------

//-----------------------------------    
/**
 * @brief       Set GPRS Unsolicited Event Reporting (UER) state
 * @param[in]   cid: bearer profile id. Supported values are:
 *              - [1...3]   
 * 
 * @param[in]   mode: Supported values are:
 *              - 0: Disable
 *              - 1: Enable
 *   
 * @retval      SIM800x_APIStatusType
 * 
 *              - SIM800X_OK: success
 *              - SIM800X_TIME_OUT: no response
 *              - SIM800X_ERROR: failed
 * 
 */ 
extern SIM800x_APIStatusType SIM800xGPRSUERSetMode(uint8_t mode);
//-----------------------------------

//-----------------------------------    
/**
 * @brief       Get GPRS network registration status          
 * @param[out]  errcode: CME_ERROR code (See description in SIM800x_Types.h)
 *       
 * @retval      SIM800xGPRSStatusType. Supported values are:
 * 
 *              - GPRS_NOT_REGISTRED: not registered
 *              - GPRS_REGISTERED_HOME: registered, home network.
 *              - GPRS_NOT_REGISTRED_SEARCHING: searching for an operator to register to.
 *              - GPRS_REGISTRATION_DENIED: GPRS disabled. Attachment not allowed.
 *              - GPRS_UNKNOWN: unknown
 *              - GPRS_REGISTRED_ROAMING: roaming
 *              - GPRS_GPRS_TIME_OUT: time-out
 *              - GPRS_GPRS_CME_ERROR: ME error
 *  
 */ 
extern SIM800xGPRSStatusType SIM800xGPRSGetNRegState(uint16_t* errcode);   
//-----------------------------------

//-----------------------------------    
/**
 * @brief       Enable GPRS network registration Unsolicited Result Code (URC)
 * @param[in]   urc: URC enable setting. Supported values are:
 *              - 0: Disable network registration URC
 *              - 1: Enable network registration URC
 *              - 2: Enable network registration and location information URC
 *       
 * @retval      SIM800x_APIStatusType. Supported values are:
 * 
 *              - SIM800X_OK: success
 *              - SIM800X_TIME_OUT: no response
 *              - SIM800X_ERROR: failed
 *  
 */ 
extern SIM800x_APIStatusType SIM800xGPRSURCEnable(uint8_t urc);
//-----------------------------------

//-----------------------------------    
/**
 * @brief       Get GPRS service used for Mobile Originated (MO) Short Message Service (SMS)         
 * @param       none      
 * @retval      SIM800xGPRSStatusType. Supported values are:
 * 
 *              - GPRS_PACKET_DOMAIN: GPRS
 *              - GPRS_CIRCUIT_SWITCHED: CSD
 *              - GPRS_PACKET_DOMAIN_PREFERRED: GPRS preferred, CSD alternative
 *              - GPRS_CIRCUIT_SWITCHED_PREFERRED: CSD preferred, GPRS alternative
 *              - GPRS_TIME_OUT: time-out
 *  
 */ 
extern SIM800xGPRSStatusType SIM800xGPRSGetMOSMSService(void);   
//-----------------------------------

//-----------------------------------    
/**
 * @brief       Enable GPRS network registration Unsolicited Result Code (URC)
 * @param[in]   service: MO SMS service setting. Supported values are:
 *              - 0: Packet Domain
 *              - 1: Circuit Switched (CSD)
 *              - 2: Packet Domain preferred (CSD used if GPRS not available)
 *              - 3: Circuit Switched preferred (GPRS used if circuit switched not available)
 *          
 * @param[out]  errcode: CME_ERROR code (See description in SIM800x_Types.h)
 *       
 * @retval      SIM800x_APIStatusType. Supported values are:
 * 
 *              - SIM800X_OK: success
 *              - SIM800X_TIME_OUT: no response
 *              - SIM800X_CME_ERROR: ME error
 *  
 */ 
extern SIM800x_APIStatusType SIM800xGPRSSetMOSMSService(uint8_t service, uint16_t* errcode);
//-----------------------------------

#ifdef	__cplusplus
}
#endif

#endif	/* __SIM800X_GPRS_H */


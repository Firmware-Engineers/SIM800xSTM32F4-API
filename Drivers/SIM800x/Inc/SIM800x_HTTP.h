/**
 ******************************************************************************
 * @file            SIM800x_HTTP.h
 * @author          Maxime  
 * @brief           Header file for SIM800 series modems HTTP function
 * @brief           This file provides function definitions used for implementing
 *                  HTTP-based applications.
 * 
 * @brief           Supported devices are listed below.
 * @brief           See dependencies in the include section.
 * 
 * @note            History:
 *                   - March 9, 2023: Initial release
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


#ifndef __SIM800X_HTTP_H
#define	__SIM800X_HTTP_H

#ifdef	__cplusplus
extern "C" {
#endif

//-----------------------------------
#include <stdlib.h>
#include "SIM800x_Types.h"    
//-----------------------------------

//-----------------------------------    
/**
 * @brief       Initialized HTTP service
 * @param[out]  errcode: CME_ERROR code (See description in SIM800x_Types.h)        
 * @retval      SIM800x_APIStatusType. Supported values are:
 * 
 *              - SIM800X_OK: success
 *              - SIM800X_TIME_OUT: time-out
 *              - SIM800X_ERROR: failed
 *              - SIM800X_CME_ERROR: ME error
 *  
 */ 
extern SIM800x_APIStatusType SIM800xHTTPInit(uint16_t* errcode);
//-----------------------------------

//-----------------------------------    
/**
 * @brief       Terminate HTTP service
 * @param[out]  errcode: CME_ERROR code (See description in SIM800x_Types.h)        
 * @retval      SIM800x_APIStatusType. Supported values are:
 * 
 *              - SIM800X_OK: success
 *              - SIM800X_TIME_OUT: time-out
 *              - SIM800X_ERROR: failed
 *              - SIM800X_CME_ERROR: ME error
 *  
 */ 
extern SIM800x_APIStatusType SIM800xHTTPTerminate(uint16_t* errcode);
//-----------------------------------

//-----------------------------------    
/**
 * @brief       Set context id for the HTTP request
 * @param[in]   cid: context id number
 * @param[out]  errcode: CME_ERROR code (See description in SIM800x_Types.h)        
 * @retval      SIM800x_APIStatusType. Supported values are:
 * 
 *              - SIM800X_OK: success
 *              - SIM800X_TIME_OUT: time-out
 *              - SIM800X_ERROR: failed
 *              - SIM800X_CME_ERROR: ME error
 * 
 * @note        This function cannot be used when HTTP service is not initialized.
 *  
 */ 
extern SIM800x_APIStatusType SIM800xHTTPSetCID(uint8_t cid, uint16_t* errcode);
//-----------------------------------

//-----------------------------------    
/**
 * @brief       Set client URL
 * @param[in]   url: client URL (null terminated string).
 * @note        Maximum **URL size is 500 characters.**
 * @param[out]  errcode: CME_ERROR code (See description in SIM800x_Types.h)        
 * @retval      SIM800x_APIStatusType. Supported values are:
 * 
 *              - SIM800X_OK: success
 *              - SIM800X_TIME_OUT: time-out
 *              - SIM800X_ERROR: failed
 *              - SIM800X_CME_ERROR: ME error
 * 
 * 
 * @note        This function cannot be used when HTTP service is not initialized.
 *  
 */ 
extern SIM800x_APIStatusType SIM800xHTTPSetURL(const char* url, uint16_t* errcode);
//-----------------------------------

//-----------------------------------    
/**
 * @brief       Set User Agent (UA) string
 * @param[in]   ua: user agent (null terminated string).
 * @note        The UA is set by the application to identify the mobile device.
 * @note        Maximum UA size is 100 characters.
 * @param[out]  errcode: CME_ERROR code (See description in SIM800x_Types.h)        
 * @retval      SIM800x_APIStatusType. Supported values are:
 * 
 *              - SIM800X_OK: success
 *              - SIM800X_TIME_OUT: time-out
 *              - SIM800X_ERROR: failed
 *              - SIM800X_CME_ERROR: ME error
 * 
 * @note        This function cannot be used when HTTP service is not initialized.
 *  
 */ 
extern SIM800x_APIStatusType SIM800xHTTPSetUA(const char* ua, uint16_t* errcode);
//-----------------------------------

//-----------------------------------    
/**
 * @brief       Set proxy server IP address
 * @param[in]   proip: proxy server IP (null terminated string).
 * @note        **Maximum IP size is 15 characters.**
 * @param[out]  errcode: CME_ERROR code (See description in SIM800x_Types.h)        
 * @retval      SIM800x_APIStatusType. Supported values are:
 * 
 *              - SIM800X_OK: success
 *              - SIM800X_TIME_OUT: time-out
 *              - SIM800X_ERROR: failed
 *              - SIM800X_CME_ERROR: ME error
 * 
 * @note        This function cannot be used when HTTP service is not initialized.
 *  
 */ 
extern SIM800x_APIStatusType SIM800xHTTPSetIP(const char* proip, uint16_t* errcode);
//-----------------------------------

//-----------------------------------    
/**
 * @brief       Set proxy server PORT
 * @param[in]   proport: proxy server PORT
 * @param[out]  errcode: CME_ERROR code (See description in SIM800x_Types.h)        
 * @retval      SIM800x_APIStatusType. Supported values are:
 * 
 *              - SIM800X_OK: success
 *              - SIM800X_TIME_OUT: time-out
 *              - SIM800X_ERROR: failed
 *              - SIM800X_CME_ERROR: ME error
 * 
 * @note        This function cannot be used when HTTP service is not initialized.
 *  
 */ 
extern SIM800x_APIStatusType SIM800xHTTPSetPort(uint16_t proport, uint16_t* errcode);
//-----------------------------------

//-----------------------------------    
/**
 * @brief       Set "REDIR" flag parameter
 * @param[in]   redir: "REDIR" flag: Supported values are:
 *              - [0,1]
 * @note        Redirect flag. This flag when set, will send a new HTTP request 
 *              to the server if a redirect code (range 30x) is received.
 * 
 * @param[out]  errcode: CME_ERROR code (See description in SIM800x_Types.h)        
 * @retval      SIM800x_APIStatusType. Supported values are:
 * 
 *              - SIM800X_OK: success
 *              - SIM800X_TIME_OUT: time-out
 *              - SIM800X_ERROR: failed
 *              - SIM800X_CME_ERROR: ME error
 * 
 * @note        This function cannot be used when HTTP service is not initialized.
 *  
 */ 
extern SIM800x_APIStatusType SIM800xHTTPSetRedir(uint8_t redir, uint16_t* errcode);
//-----------------------------------

//-----------------------------------    
/**
 * @brief       Set "BREAK" parameter value
 * @param[in]   _break: break value
 * @param[out]  errcode: CME_ERROR code (See description in SIM800x_Types.h)        
 * @retval      SIM800x_APIStatusType. Supported values are:
 * 
 *              - SIM800X_OK: success
 *              - SIM800X_TIME_OUT: time-out
 *              - SIM800X_ERROR: failed
 *              - SIM800X_CME_ERROR: ME error
 * 
 * @note        This function cannot be used when HTTP service is not initialized.
 *  
 */ 
extern SIM800x_APIStatusType SIM800xHTTPSetBreak(uint32_t _break, uint16_t* errcode);
//-----------------------------------

//-----------------------------------    
/**
 * @brief       Set "BREAKEND" parameter value
 * @param[in]   breakend: breakend value
 * @param[out]  errcode: CME_ERROR code (See description in SIM800x_Types.h)        
 * @retval      SIM800x_APIStatusType. Supported values are:
 * 
 *              - SIM800X_OK: success
 *              - SIM800X_TIME_OUT: time-out
 *              - SIM800X_ERROR: failed
 *              - SIM800X_CME_ERROR: ME error
 * 
 * @note        This function cannot be used when HTTP service is not initialized.
 *  
 */ 
extern SIM800x_APIStatusType SIM800xHTTPSetBreakEnd(uint32_t breakend, uint16_t* errcode);
//-----------------------------------

//-----------------------------------    
/**
 * @brief       Set HTTP session timeout value 
 * @param[in]   timeout: timeout value in seconds. Supported values are:
 *              - [30-1000].
 * @note        Default value is 120.
 * @param[out]  errcode: CME_ERROR code (See description in SIM800x_Types.h)        
 * @retval      SIM800x_APIStatusType. Supported values are:
 * 
 *              - SIM800X_OK: success
 *              - SIM800X_TIME_OUT: time-out
 *              - SIM800X_ERROR: failed
 *              - SIM800X_CME_ERROR: ME error
 * 
 * @note        This function cannot be used when HTTP service is not initialized.
 *  
 */ 
extern SIM800x_APIStatusType SIM800xHTTPSetTimeout(uint16_t timeout, uint16_t* errcode);
//-----------------------------------

//-----------------------------------    
/**
 * @brief       Set HTTP content type
 * @param[in]   content: CONTENT type (null terminated string).
 * @note        Maximum size for content is 80 characters.  
 * @param[out]  errcode: CME_ERROR code (See description in SIM800x_Types.h)        
 * @retval      SIM800x_APIStatusType. Supported values are:
 * 
 *              - SIM800X_OK: success
 *              - SIM800X_TIME_OUT: time-out
 *              - SIM800X_ERROR: failed
 *              - SIM800X_CME_ERROR: ME error
 * 
 * @note        This function cannot be used when HTTP service is not initialized.
 *  
 */ 
extern SIM800x_APIStatusType SIM800xHTTPSetContent(const char* content, uint16_t* errcode);
//-----------------------------------

//-----------------------------------    
/**
 * @brief       Set "USERDATA" parameter
 * @param[in]   userdata: "USERDATA" parameter (null terminated string). 
 * @note        Maximum size for USERDATA is 1024 characters.
 * @param[out]  errcode: CME_ERROR code (See description in SIM800x_Types.h)        
 * @retval      SIM800x_APIStatusType. Supported values are:
 * 
 *              - SIM800X_OK: success
 *              - SIM800X_TIME_OUT: time-out
 *              - SIM800X_ERROR: failed
 *              - SIM800X_CME_ERROR: ME error
 * 
 * @note        This function cannot be used when HTTP service is not initialized.
 *  
 */ 
extern SIM800x_APIStatusType SIM800xHTTPSetUserData(const char* userdata, uint16_t* errcode);
//-----------------------------------

//-----------------------------------    
/**
 * @brief       Input data to be included in the POST request body.
 * @param[in]   data: data to send (null terminated string).
 * @param[in]   cnt: data size in bytes. Supported values are:
 *              - 0: delete all content
 *              - [1...319488]
 * 
 * @param[in]   timeout: maximum time in milliseconds, required to input data. Supported values are:
 *              - [1000...120000]
 * @note        timeout should be long enough to input all the "cnt" bytes of data.
 * @param[out]  errcode: CME_ERROR code (See description in SIM800x_Types.h)
 *       
 * @retval      SIM800x_APIStatusType. Supported values are:
 * 
 *              - SIM800X_OK: success
 *              - SIM800X_TIME_OUT: time-out
 *              - SIM800X_ERROR: failed
 *              - SIM800X_CME_ERROR: ME error
 * 
 * @note        This function cannot be used when HTTP service is not initialized.
 *  
 */ 
extern SIM800x_APIStatusType SIM800xHTTPInputData(char *data, uint32_t cnt, uint32_t timeout, uint16_t* errcode);
//-----------------------------------

//-----------------------------------    
/**
 * @brief       Send a method request.
 * @param[in]   method: method request. Supported values are:
 *              - 0: GET
 *              - 1: POST
 *              - 2: HEAD
 *              - 3: DELETE
 * 
 * @param[out]  statuscode: HTTP(S) status codes (See description in SIM800x_Types.h)
 * 
 * @param[out]  cnt: the length of data received from the server.
 * @param[out]  errcode: CME_ERROR code (See description in SIM800x_Types.h)
 * @param[in]   tout: maximum response time in milliseconds, that will be used to wait for response from the server.            
 *       
 * @retval      SIM800x_APIStatusType. Supported values are:
 * 
 *              - SIM800X_OK: success
 *              - SIM800X_TIME_OUT: time-out
 *              - SIM800X_ERROR: failed
 *              - SIM800X_CME_ERROR: ME error
 * 
 * @note        This function cannot be used when HTTP service is not initialized.
 *  
 */ 
extern SIM800x_APIStatusType SIM800xHTTPAction(uint8_t method, uint16_t* statuscode, uint32_t* cnt, uint32_t tout, uint16_t* errcode);
//-----------------------------------

//-----------------------------------    
/**
 * @brief       Read HTTP server response or inputted data via SIM800xHTTPInputData() function.
 * @param[in]   data: data read(null terminated string)
 * @warning     "data" should be large enough for the expected data size to fit in.
 * @param[in]   strindex: start index of data: Supported values are:
 *              - [0...319488]
 * 
 * @param[in]   size: size of data to read, starting at "strindex". Supported values are:
 *              - [1...319488]
 * @note        This function will not return more than the actual received data size.
 * 
 * @param[out]  cnt: actual read data size in bytes.
 * @param[out]  errcode: CME_ERROR code (See description in SIM800x_Types.h)
 *       
 * @retval      SIM800x_APIStatusType. Supported values are:
 * 
 *              - SIM800X_OK: success
 *              - SIM800X_TIME_OUT: time-out
 *              - SIM800X_ERROR: failed
 *              - SIM800X_CME_ERROR: ME error
 * 
 * @note        This function cannot be used when HTTP service is not initialized.
 *  
 */ 
extern SIM800x_APIStatusType SIM800xHTTPRead(char* data, uint32_t strindex, uint32_t size, uint32_t* cnt, uint16_t* errcode);
//-----------------------------------


//-----------------------------------    
/**
 * @brief       Save HTTP application context parameter in NVRAM.
 * @note        Parameters to be saved include:
 *              - Context ID
 *              - Client URL
 *              - User Agent string
 *              - Proxy server IP address
 *              - Proxy server PORT value
 *              - "REDIR" parameter
 *              - "BREAK" parameter
 *              - "BREAKEND" parameter
 *              - "USERDATA" parameter
 * 
 * @param[out]  errcode: CME_ERROR code (See description in SIM800x_Types.h)
 *       
 * @retval      SIM800x_APIStatusType. Supported values are:
 * 
 *              - SIM800X_OK: success
 *              - SIM800X_TIME_OUT: time-out
 *              - SIM800X_CME_ERROR: ME error
 * 
 * @note        This function cannot be used when HTTP service is not initialized.
 *  
 */ 
extern SIM800x_APIStatusType SIM800xHTTPSaveAppContext(uint16_t* errcode);
//-----------------------------------

//-----------------------------------    
/**
 * @brief       Read HTTP status.
 * @param[out]  method: HTTP method. Supported values are:
 *              - 0: GET
 *              - 1: POST
 *              - 2: HEAD
 * 
 * @param[out]  state: HTTP status. Supported values are:
 *              - 0: Idle
 *              - 1: Receiving
 *              - 2: Sending
 * 
 * @param[out]  finish: amount of data transmitted.
 * @param[out]  remain: amount of data remaining to be send/received.
 * @param[out]  errcode: CME_ERROR code (See description in SIM800x_Types.h)
 *       
 * @retval      SIM800x_APIStatusType. Supported values are:
 * 
 *              - SIM800X_OK: success
 *              - SIM800X_TIME_OUT: time-out
 *              - SIM800X_CME_ERROR: ME error
 * 
 * @note        This function cannot be used when HTTP service is not initialized.
 *  
 */ 
extern SIM800x_APIStatusType SIM800xHTTPReadState(uint8_t* method, uint8_t* state, uint32_t* finish, uint32_t* remain, uint16_t* errcode);
//-----------------------------------

//-----------------------------------    
/**
 * @brief       Read server response header information.
 * @param[out]  data: HTTP header data (null terminated string).
 * @param[out]  cnt: actual length for HTTP header data output.
 * @param[out]  errcode: CME_ERROR code (See description in SIM800x_Types.h)
 *       
 * @retval      SIM800x_APIStatusType. Supported values are:
 * 
 *              - SIM800X_OK: success
 *              - SIM800X_TIME_OUT: time-out
 *              - SIM800X_ERROR: failed
 *              - SIM800X_CME_ERROR: ME error
 * 
 * @note        This function cannot be used when HTTP service is not initialized.
 *  
 */ 
extern SIM800x_APIStatusType SIM800xHTTPReadHeader(char *data, uint32_t* cnt, uint16_t* errcode);
//-----------------------------------

//-----------------------------------    
/**
 * @brief       Set whether HTTP header information should be accessible using the SIM800xHTTPReadHeader() function.
 * @param[in]   option: HTTP header information accessibility option. Supported values are:
 *              - 0: Can't show HTTP header information
 *              - 1: show HTTP header information 
 * @param[out]  errcode: CME_ERROR code (See description in SIM800x_Types.h)    
 *     
 * @retval      SIM800x_APIStatusType. Supported values are:
 * 
 *              - SIM800X_OK: success
 *              - SIM800X_TIME_OUT: time-out
 *              - SIM800X_ERROR: failed
 *              - SIM800X_CME_ERROR: ME error
 * 
 * @note        This function cannot be used when HTTP service is not initialized.
 *  
 */ 
extern SIM800x_APIStatusType SIM800xHTTPShowHeader(uint8_t option, uint16_t* errcode);
//-----------------------------------

#ifdef	__cplusplus
}
#endif

#endif	/* __SIM800X_HTTP_H */


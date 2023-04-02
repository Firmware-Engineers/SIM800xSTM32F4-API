/**
 ******************************************************************************
 * @file            SIM800x_SDM.h
 * @author          Maxime  
 * @brief           Header file for SIM800 series Modem API Serial Data Manager (SDM)
 * @brief           This file provides macros and function definitions used to handle
 *                  serial data received by the Modem (DCE/TA), from the Controlling 
 *                  device (DTE/TE).
 * 
 * @note            **This driver is at the heart of the WWAN APIs operation, and is 
 *                  responsible for receiving and performing every parsing,  
 *                  and extracting operations on the data receive from the serial interface, 
 *                  so that the later can be used effectively by the API functions.**
 * 
 * @warning         This driver uses the target controller: 
 *                      - UART/USART module
 *                      - UART/USART instance x on STM32
 *                      - Interrupt on receive functionality
 *                  **Two functions, SIM800xSDMResume and SIM800xSDMSuspend, are implemented 
                    for enabling/disabling this driver.** 
 *                  
 * @warning         In order to prevent unpredictable or undesired behavior of 
 *                  the system, make sure to take all this into consideration when using 
 *                  the WWAN APIs.
 * 
 * @brief           Supported architectures are specified in the configuration
 *                  file (SIM800x_CONFIG.h).
 * @brief           See dependencies in the include section.
 * 
 * @note            History:
 *                   - Feb 18, 2023: Initial release
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

#ifndef __SIM800X_SDM_H
#define	__SIM800X_SDM_H

#ifdef	__cplusplus
extern "C" {
#endif

//-----------------------------------
#include "SIM800x_CONFIG.h" 
#if defined(CONFIG_TARGET_ARCH_PIC18)
#elif defined(CONFIG_TARGET_ARCH_AVRMEGA)
#elif defined(CONFIG_TARGET_ARCH_STM32F4)
#include "stdint.h"
#include "stm32f4xx_hal.h"
#include <string.h>
#endif
//----------------------------------- 
#if defined (CONFIG_TARGET_ARCH_PIC18)
#elif defined (CONFIG_TARGET_ARCH_AVRMEGA)
#elif defined (CONFIG_TARGET_ARCH_STM32F4)
extern UART_HandleTypeDef huart2;
#define MODEM_UART_HANDLE				huart2										//!< MODEM: USART handle used for modem communication channel, defined by default in main.c.
#define UARTSend(x)                     HAL_UART_Transmit(&MODEM_UART_HANDLE, (const uint8_t*)&x, 1, 100)		//!< Transmit one byte with time-out = 100ms (From stm32f4xx_hal_uart.c file)
#define UARTRead()																	//!< No longer needed with this architecture, handled by the callback function.
#define Tick()							HAL_GetTick()								//!< From stm32f4xx_hal.c file
#define TickInit()																	//!< Already done in the HAL_Init() (stm32f4xx_hal.c file) function
#define wait(x)							HAL_Delay(x)								//!< From stm32f4xx_hal.c file
/*!< Initialization is done by the MX_USARTx_UART_Init()(USART operation) and HAL_UART_MspInit() (Clock and GPIOs) functions.
	 This function should only be used outside the initialization sequence.*/
#define SetBr(x)						MODEM_UART_HANDLE.Init.BaudRate = x;\
										if (HAL_UART_Init(&MODEM_UART_HANDLE) != HAL_OK)\
										{\
											__disable_irq();\
											while(1){}\
										}
#define SetPin(x,y)                     HAL_GPIO_WritePin(x, y, GPIO_PIN_SET)		//!< From stm32f4xx_hal_gpio.c file
#define ClearPin(x,y)                   HAL_GPIO_WritePin(x, y, GPIO_PIN_RESET)		//!< From stm32f4xx_hal_gpio.c file
#define GPIOSetInput(x,y)															//!< Already done in the MX_GPIO_Init() (default location is main.c) function
#define GPIOSetOutput(x,y)															//!< Already done in the MX_GPIO_Init() (default location is main.c) function

#if (CONFIG_ENABLE_DBG_UART == 1)
extern UART_HandleTypeDef huart3;
#define DEBUG_UART_HANDLE				huart3										//!< DEBUG: USART handle used for DEBUG communication channel, defined by default in main.c.
#define DEBUG_UARTSend(x)           	HAL_UART_Transmit(&DEBUG_UART_HANDLE, (const uint8_t*)&x, 1, 100)		//!< Transmit one byte with time-out = 100 (From stm32f4xx_hal_uart.c file)
#define DEBUG_UARTInit()															//!< Already done in the MX_USARTx_UART_Init() (default location is main.c) function
#define DEBUG_UARTPrint(x)            	HAL_UART_Transmit(&DEBUG_UART_HANDLE, (const uint8_t*)x, (uint16_t)strlen((const char*)x), 500)
#endif
#endif    
//-----------------------------------    
/**
 * @brief   Initialize and enable the SDM driver
 * @note    This function will:
 *              - Enable all required device UART interrupt settings, depending on the architecture
 * @note	Other required initializations such as systemtick, UART, GPIO will be performed using HAL functions.
 *
 * @retval  none
 * 
 * @warning **When using the SDM on PIC18 devices, make sure not to let the RX pin floating. Use a pull-up instead.** 
 */ 
extern void SIM800xSDMInit(void);
//-----------------------------------    

//-----------------------------------
/**
 * @brief   Enable SDM data reception over the UART
 * @param   none
 * @retval  none
 * @note    **This function will enable the interrupt driven data reception (RXNE interrupt).**
 */
extern void SIM800xSDMResume(void);   
//-----------------------------------

//-----------------------------------
/**
 * @brief   Disable SDM data reception over the UART
 * @param   none
 * @retval  none
 * @note    This function will disable the interrupt driven data reception.
 * @note    **The SDM can send command to the modem, but cannot receive responses. (Disable RXNE interrupt)**
 */
extern void SIM800xSDMSuspend(void);   
//-----------------------------------

//-----------------------------------
/**
 * @brief   Checks if the SDM data reception over the UART is enabled
 * @param   none
 * @retval  
 *          - 1: suspended
 *          - 0: not suspended
 * 
 */
extern uint8_t SIM800xSDMIsSuspended(void);   
//-----------------------------------

//-----------------------------------
/**
 * @brief   Get the amount of data bytes available in the receive FIFO
 * @param   none
 * @retval  byte count
 *        
 */
extern uint16_t SIM800xSDMRxAvailable(void);                                          
//-----------------------------------

//-----------------------------------
/**
 * @brief   Send a byte to the modem via UART
 * @param   data: byte to send
 * @retval  none 
 * 
 */
extern void SIM800xSDMSendByte(uint8_t data);                                                                                 
//-----------------------------------

//-----------------------------------
/**
 * @brief       Send a series of bytes over the UART
 * @param[in]   data : data to send
 * @param[in]   cnt: number of bytes to write
 * @retval      none 
 * 
 */
extern void SIM800xSDMSendBytes(uint8_t *data, uint16_t cnt);                                         
//-----------------------------------

//-----------------------------------
/**
 * @brief   Sends a null-terminated string over the UART 
 * @param   str : string to send
 * @retval  none 
 * 
 */
extern void SIM800xSDMPrint(const char *str);                                         
//-----------------------------------

//-----------------------------------
/**
 * @brief   Read and remove the byte available at the current receive FIFO pointer index
 * @note    Make sure to check data availability using SIM800xSDMRxAvailable() before 
 *          calling this function.
 * @param   none
 * @retval          
 *              - byte read
 *              - 0xFF: No data available      
 */
extern uint8_t SIM800xSDMReadByte(void);   
//-----------------------------------

//-----------------------------------
/**
 * @brief       Read and remove the bytes available in the receive FIFO,
 *              starting at the current pointer index.
 * @param[out]  data: byte array to copy data to. 
 * @param[in]   cnt: number of bytes to read
 * @param[in]   tout: time-out value
 * @retval      number of bytes read
 *      
 */
extern uint16_t SIM800xSDMReadBytes(uint8_t *data, uint16_t cnt, uint32_t tout);   
//-----------------------------------

//-----------------------------------
/**
 * @brief   Read the byte available at the specified receive FIFO pointer index.
 *          Index is 0-based, starting at the current position to the index of the
 *          last byte available.
 *  
 * @param   idx: 0-based index
 * @retval  
 *              - byte read
 *              - 0xFF: No data available
 *      
 */
extern uint8_t SIM800xSDMPeek(uint8_t idx);   
//-----------------------------------

//-----------------------------------
/**
 * @brief       Extract the [DATA] portion of the next received packet from the 
 *              input FIFO, and remove the packet from the buffer.
 * @note        **packet format: [SOF] [DATA] [EOF]** 
 * @param[out]  data: byte array, to copy the [DATA] in. 
 * @retval  
 *          - size of [DATA]  
 *          - 0: no packet received
 *          - 0: invalid packet
 *          - -1: Time-out
 *       
 */
extern int SIM800xSDMReadF1Pkt(uint8_t *data);   
//-----------------------------------

//-----------------------------------
/**
 * @brief       Extract the [DATA] portion of the next received packet from the 
 *              input FIFO, and remove the packet from the buffer.
 * @note        **packet format:  [DATA] [SOF] [EOF]** 
 * @param[out]  data: byte array, to copy the [DATA] 
 * @retval  
 *          - size of [DATA] or  
 *          - 0: no packet received
 *          - 0: invalid packet
 *          - -1: Time-out
 *       
 */
extern int SIM800xSDMReadF2Pkt(uint8_t *data);   
//-----------------------------------

//-----------------------------------
/**
 * @brief       Flush receive FIFO
 * @param       none
 * @retval      none 
 */
extern void SIM800xSDMFlush(void);                                     
//-----------------------------------

//-----------------------------------
/**
 * @brief       Set SDM operation time-out
 * @param       tout: time-out value in ms
 * @warning     It is not recommend to use this function directly, unless
 *              explicitly specified by a given API.
 * 
 * @retval      none 
 */
extern void SIM800xSDMSetTimeOut(uint32_t tout);                                     
//-----------------------------------

//-----------------------------------
/**
 * @brief       Get SDM operation time-out
 * @param       none
 * @retval      time-out value 
 */
extern uint32_t SIM800xSDMGetTimeOut(void);                                     
//-----------------------------------

//-----------------------------------
/**
 * @brief   SDM interrupt call-back function
 * @param   none
 * @retval  none
 * @note:   This function should be inserted in the HAL_UART_RxCpltCallback() function.
 *          It is a week function that can be defined by user.
 *
 */
extern void SIM800xSDMCallBack(void);
//-----------------------------------

#ifdef	__cplusplus
}
#endif

#endif	/* __SIM800X_SDM_H */


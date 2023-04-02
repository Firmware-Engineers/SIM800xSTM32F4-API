/**
 ******************************************************************************
 * @file            ApplicationExample.h
 * @author          Maxime
 * @brief           Header file for SIM800 series Modem API demonstration
 * @note            This application uses a lightweight JSON parser for
 *                  Serializing/Deserializing messages. See JSON.h for more details.
 *
 * @brief           Supported devices are listed in the include section.
 * @brief           See dependencies in the include section.
 *
 * @note            History:
 *                  - April 2, 2023: Initial release
 *
 * @note            It has been successfully tested with:
 *                  - Cloud Service:
 *                      * https://thinger.io
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

#ifndef SIM800X_INC_APPLICATIONEXAMPLE_H_
#define SIM800X_INC_APPLICATIONEXAMPLE_H_

//-----------------------------------
#include "SIM800x.h"
#include "JSON.h"
#include <stdint.h>
//-----------------------------------

//-----------------------------------
/**
 * @brief   Initialize the system with baudrate = 9600bps
 * @note    This function will:
 *              -
 *              -
 * @retval
 *              - 0: success
 *              - 1: failed
 *
 * @warning  **initialization takes 5 to 10s to complete.**
 *
 */
extern uint8_t SysInit(void);
//-----------------------------------

//-----------------------------------
/**
 * @brief   Main system Task
 * @note    This Task wait for a start signal from the software UART, then sends
 *          a fixed to the server every 10 seconds.
 * @note    The Task will also forward received messages (@ref rxmsg) from the
 *          server to software UART and stop all operations if it receives a stop signal.
 *
 * @retval  none
 *
 */
extern void SystemTask(void);
//-----------------------------------

#endif /* SIM800X_INC_APPLICATIONEXAMPLE_H_ */

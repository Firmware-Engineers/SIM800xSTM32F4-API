//-----------------------------------
#include "ApplicationExample.h"
//-----------------------------------

extern UART_HandleTypeDef huart3;
#define DEBUG2_UART_HANDLE				huart3										//!< DEBUG: USART handle used for DEBUG communication channel, defined by default in main.c.
#define DEBUG2_UARTSend(x)           	HAL_UART_Transmit(&DEBUG2_UART_HANDLE, (const uint8_t*)&x, 1, 100)		//!< Transmit one byte with time-out = 100 (From stm32f4xx_hal_uart.c file)
#define DEBUG2_UARTPrint(x)            	HAL_UART_Transmit(&DEBUG2_UART_HANDLE, (const uint8_t*)x, (uint16_t)strlen((const char*)x), 500)


//-----------------------------------
/*
    {
       "Engine Temperature (C)":30,
       "RPM":3500,
       "Vehicle Speed (MPH)":35,
       "Fuel Level (%)":50
    }
*/
char txmessage[100];
//-----------------------------------

/*
    {
       "Success Code": 200
    }
*/
char rxmessage[30];
//-----------------------------------

uint16_t cpos = 0;
//-----------------------------------

//-----------------------------------
#define mkstr(x)                   #x
#define URL                         "http://backend.thinger.io/v3/users/FirmwareEngineers/devices/SIM800L/callback/data?authorization=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJleHAiOjE2ODA0ODE2MTQsImlhdCI6MTY4MDQ3NDQxNCwicm9sZSI6InVzZXIiLCJ1c3IiOiJGaXJtd2FyZUVuZ2luZWVycyJ9.yTYk7yOdBgbL6BXmaka1kMSrtC9dm6grNpS5xehnH2U"
//-----------------------------------

uint8_t SysInit(void)
{
    //---------    
    if(SIM800xInit(9600) == SIM800X_OK)
    {
    	DEBUG2_UARTPrint((const uint8_t*)"Modem Initialized.\r\n");
        //
        // Set IP configuration
        //
    	DEBUG2_UARTPrint((const uint8_t*)"Setting IP configurations...\r\n");
        if(SIM800xIPSetConnectionType(1, "GPRS") == SIM800X_OK)                 //!< Set bearer connection type
        {
            if(SIM800xIPSetAPN(1, "Internet") == SIM800X_OK)                    //!< Set APN = "Internet" for MTN Cameroon.                                 
            {
                if(SIM800xIPOpen(1) == SIM800X_OK)                              //!< Activate bearer profile [cid = 1, Contype = "GPRS", APN = Internet]
                {
                    char ip[20];
                    DEBUG2_UARTPrint((const uint8_t*)"Done.\r\n");
                    SIM800xIPGetState(1, ip);                                   //!< Get IP address
                    DEBUG2_UARTPrint((const uint8_t*)"Bearer profile Activated, IP: ");
                    DEBUG2_UARTPrint(ip);
                    DEBUG2_UARTPrint((const uint8_t*)"\r\n");
                    uint16_t err;
        //
        // Set HTTP settings
        //
                    DEBUG2_UARTPrint((const uint8_t*)"Setting HTTP configurations...\r\n");
                    if(SIM800xHTTPInit(&err) == SIM800X_OK)                     //!< Initialize HTTP service
                    {
                        if(SIM800xHTTPSetURL(URL, &err) == SIM800X_OK)          //!< Set HTTP server URL (Obtained on thinger.io, device name is SIM800L)
                        { 
                            if(SIM800xHTTPSetContent("application/json", &err) == SIM800X_OK)       //!< Set HTTP Conten-Type parameter to "application/json"
                            {
                            	DEBUG2_UARTPrint((const uint8_t*)"Done.\r\n");
        //
        // Serialize message to be sent into JSON format
        //
                                //---------                                                                          
                                AddEntryToJsonObject(txmessage, "Engine Temperature (C)", mkstr(30), &cpos);
                                AddEntryToJsonObject(txmessage, "RPM", mkstr(3500), &cpos);
                                AddEntryToJsonObject(txmessage, "Vehicle Speed (MPH)", mkstr(35), &cpos);
                                AddEntryToJsonObject(txmessage, "Fuel Level (%)", mkstr(50), &cpos);
                                //---------
        //
        // Serialize message to be sent into JSON format
        //
                                DEBUG2_UARTPrint((const uint8_t*)"System Initialization completed.\r\n");
                                DEBUG2_UARTPrint(txmessage);
                                return SIM800X_OK;
                            }   
                        }                          
                    }
                }
            }
        }
    }
    DEBUG2_UARTPrint((const uint8_t*)"System Initialization failed.\r\n");
    return 1;
    //---------
}
//-----------------------------------

void SystemTask(void)
{
    uint8_t cmd = 0;
    uint16_t scode = 0, errcode = 0;
    uint32_t cnt = 0;
    HAL_UART_Receive(&DEBUG2_UART_HANDLE, &cmd, 1, 100);
    if(cmd == '1')
    {
        //---------
    	DEBUG2_UARTPrint((const uint8_t*)"Sending message to thinger.io...\r\n");
        //---------
        SIM800xHTTPInputData(txmessage, (uint32_t)(cpos + 1), 5000, &errcode);  //!< Send data to modem buffer
        //---------
        if(SIM800xHTTPAction(1, &scode, &cnt, 10000, &errcode) == SIM800X_OK)   //!< Send a POST request to the server and wait response for 10s max.
        {
            if(SIM800xHTTPRead(rxmessage, 0, cnt, &cnt, &errcode) == SIM800X_OK)        //!< Read HTTP response from the server.
            {
                char msg[40];
                sprintf(msg, "HTTP response code: %u\r\n", scode);
                DEBUG2_UARTPrint(msg);
                sprintf(msg, "Received data length: %ld\r\n", cnt);
                DEBUG2_UARTPrint(msg);
                DEBUG2_UARTPrint((const uint8_t*)"Data: ");
                DEBUG2_UARTPrint(rxmessage);
                DEBUG2_UARTPrint((const uint8_t*)"\r\n");
            }
        }else
        {
        	DEBUG2_UARTPrint((const uint8_t*)"Sending failed.\r\n");
        }
        //---------
        cmd = 0;
    }
    
}
//-----------------------------------

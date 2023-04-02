# Description
The SIM800xSTM32F4 API, part of the **WWM (Wireless WAN Modems Access APIs package)** is very similar to the SIM800xPIC18 API, also part of #IoT Solution Demo initiative but targetted to STM32F4 controllers. Both APIs have the same functionalities and attributes, they have just been optimized and compiled for different architectures.
## Included functionalities 
The current version of this software includes the following APIs:
- HTTP
- GPRS
- IP
- Modem control
- ID number
- Some 3GPP TS 27.005/7 API functions 
## Notes 
The diagram below shows the API architecture.
![WWAN API Architecture](https://user-images.githubusercontent.com/56833496/228084512-9d896a2e-55bf-46ae-9788-7c86f418de86.png)
# Prerequisites
To use this software you need:
- To Install STM32Cube IDE or any other compatible IDE (ex. Keil uvision)
- An associated toolchain that can take care of compilation, debugging and code download to the target: I use GNU Tools for STM32 V10.3 and STLINK GDB Server
- Doxygen generator, to generate documentation from source code (optional): https://www.doxygen.nl/download.html
# Demonstration
This API has also been tested with the demo Data Logger application, using a SIM800L modem and the STM32F407-DISC1 board. Following is a simplified diagram of it's operation.
![Demo Diagram](https://user-images.githubusercontent.com/56833496/228093675-567eda01-144b-449e-a2c9-35b34626fe87.png)
## Additional requirements for the demo
### Hardware
- SIMCOM SIM800L-based board (ex. **SIM800L EVB**)
- STM32F4 based board (I used the **STM32F407-DISC1** board, which uses a **STM32F407VG** device)
- A USB to UART/USART converter (I used a **FTDI 232R** board) for monitoring data on a terminal
- It is possible to use directly the emulated serial port provided by the STM32F407-DISC1 board. More info can be found on the Discovery kit user manual **UM1472**.
## Software
- A Serial Terminal software: I used CuteCom, which I found very good since I'm working on Ubuntu.
## Software configurations
- **Debug channel**
  * Baudrate: **variable, see the initialization function in the main.c file.**
  * Transmit Pin: **PORTB[10]: PB10**
  * Receive Pin: **PORTB[11]: PB11**
  
- **Control channel**
  * Baudrate: **Also variable in the main.c file.**
  * Transmit Pin: **PORTA[2]: PA2**
  * Receive Pin: **PORTA[3]: PA3**
 More details are specified in the source files. 
 ## Demo Terminal view
 ![Terminal Debug](https://user-images.githubusercontent.com/56833496/228094534-d637de5d-9469-4758-b524-35de17d43ce1.PNG)
 ## Demo Bucket (Random Values)
 ![Thinger Bucket](https://user-images.githubusercontent.com/56833496/228094617-a2c5277d-f531-463f-9a83-45566c521523.PNG)
# Team
This file is currently being developed by the #Firmware-Engineers team. Contributions, recommendations and any sort of feedback are more than welcome.
# License







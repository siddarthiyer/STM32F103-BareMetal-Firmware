# Serial Print
STM32F103 driver used to print data to a serial port since printf does not work with STM32 UART. User has the ability to select USART Port and baud rate.

Functions Include:

Function: void serialPrint(USART_TypeDef *port, char *msg, ...) <br />
Purpose: Works exactly like printf, except for additional parameter to select the port  <br />
Example: serialPrint(USART1, "Hello World!");  <br />
				 serialPrint(USART1,"%d \r\n", temp);  <br />
				 
Function: void serialPrintInit(USART_TypeDef *port, int baud, int clk_freq) <br />
Purpose: Used to initialize USART and GPIO pins. Takes in USART port, baud rate, and clock frequency as parameters <br />
Example: serialPrintInit(USART1, 9600, 72000000)
	


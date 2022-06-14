# GPIO Driver
This driver contains various functions associated with the General-purpose and alternate-function I/Os (GPIO and AFIO).
Functions include:

Function: void GPIO_Pin_Init(GPIO_TypeDef *Port, uint8_t pin, Pin_Mode function) <br />
Purpose: Used to initialize GPIO pins. <br />
Example: GPIO_Pin_Init(GPIOA, 0, Floating_Input); <br />
  
Function: void GPIO_WritePin(GPIO_TypeDef *Port, uint8_t pin, Pin_State state) <br />
Purpose: Used to set a GPIO output pin to either HIGH or LOW. <br />
Example: GPIO_WritePin(GPIOA, 0, GPIO_PIN_SET); <br />
  
Function: Pin_State GPIO_ReadPin(GPIO_TypeDef *Port, uint16_t pin) <br />
Purpose: Reads the present state of an input GPIO pin, returns either GPIO_PIN_SET(1) or GPIO_PIN_RESET(0). <br />
Example: Pin_State cur_state = GPIO_ReadPin(GPIOA, 0) <br />

Function: void GPIO_Toggle(GPIO_TypeDef *Port, uint8_t pin) <br />
Purpose: Toggles an output pin i.e sets high to low and low to high. <br />
Example: GPIO_Toggle(GPIOA, 0) <br />

Function: void GPIO_Interrupt_Setup(int pin, Edge edge_select) <br />
Purpose: Used to initialize and enable GPIO interrupt. <br />
Callback function: void EXTI1_IRQHandler(void){} <br />



  
 

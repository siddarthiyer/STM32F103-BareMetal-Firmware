/*
 * GPIO.h
 *
 *  Created on: Jun 7, 2022
 *      Author: sidiyer27
 */

#ifndef GPIO_H_
#define GPIO_H_
#include "main.h"

typedef enum{
GEN_PUSH_PULL_OUTPUT = 0b0011,
GEN_OPEN_DRAIN_OUTPUT = 0b0111,
ALT_PUSH_PULL_OUTPUT = 0b1011,
ALT_OPEN_DRAIN_OUTPUT = 0b1111,
ANALOG_INPUT = 0b0000,
FLOATING_INPUT = 0b0100,
PULL_DOWN_INPUT = 0b1000,
PULL_UP_INPUT = 0b1000,
INPUT_MODE = 0b0100
} Pin_Mode;

typedef enum{
  GPIO_PIN_RESET,
  GPIO_PIN_SET
} Pin_State;

typedef enum{
	Rising,
	Falling,
	Rise_Fall,
} Edge;

void GPIO_Pin_Init(GPIO_TypeDef *Port, uint8_t pin, Pin_Mode function);
void GPIO_WritePin(GPIO_TypeDef *Port, uint8_t pin, Pin_State state);
Pin_State GPIO_ReadPin(GPIO_TypeDef *Port, uint16_t pin);
void GPIO_Toggle(GPIO_TypeDef *Port, uint8_t pin);
void GPIO_Interrupt_Setup(int pin, Edge edge_select);



#endif /* GPIO_H_ */

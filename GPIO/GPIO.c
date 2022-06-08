/*
 * GPIO.c
 *
 *  Created on: Jun 7, 2022
 *      Author: sidiyer27
 */


#include "GPIO.h"



void GPIO_Pin_Init(GPIO_TypeDef *Port, uint8_t pin, Pin_Mode function)
{
	if(Port == GPIOA){
		RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
	}
	else if(Port == GPIOB){
		RCC->APB2ENR |= RCC_APB2ENR_IOPBEN;
	}
	else if(Port == GPIOC){
		RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;
	}
	if((function == ALT_OPEN_DRAIN_OUTPUT) || (function == ALT_PUSH_PULL_OUTPUT)){
		RCC->APB2ENR |= RCC_APB2ENR_AFIOEN;
	}
	if(pin < 8){
		Port -> CRL |= function << (4*pin);
	}
	else{
		Port -> CRH |= function << (4*(pin - 8));
	}
}

void GPIO_WritePin(GPIO_TypeDef *Port, uint8_t pin, Pin_State state){

	if(state == GPIO_PIN_RESET){
	    Port->BSRR |= 1<<(pin+16);
	    Port->BSRR &= ~(1<<pin);
	}
	else{
		  Port->BSRR |= 1<<pin;
		  Port->BSRR &= ~(1<<(pin+16));
	}
}

Pin_State GPIO_ReadPin(GPIO_TypeDef *Port, uint16_t pin){

	  if ((Port->IDR & (1<<pin)) == 0){
		  return GPIO_PIN_RESET;
	  }

	  else{
		  return GPIO_PIN_SET;
	  }
}

void GPIO_Toggle(GPIO_TypeDef *Port, uint8_t pin){
	if((Port->ODR & (1<<pin)) == 0){
		GPIO_WritePin(Port, pin, GPIO_PIN_SET);
	}
	else{
		GPIO_WritePin(Port, pin, GPIO_PIN_RESET);
	}
}


void GPIO_Interrupt_Setup(int pin, Edge edge_select)
{
	EXTI ->IMR |= 1 << pin;
	if(edge_select == Rising){
		EXTI ->RTSR |= 1 << pin;
	}
	else if(edge_select == Falling){
		EXTI ->FTSR |= 1 << pin;
	}
	else{
		EXTI ->RTSR |= 1 << pin;
		EXTI ->FTSR |= 1 << pin;
	}
	NVIC_SetPriority(EXTI0_IRQn,0);
	NVIC_EnableIRQ(EXTI0_IRQn);
}




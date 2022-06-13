/*
 * serialPrint.c
 *
 *  Created on: 8-Jun-2022
 *      Author: sidiyer27
 */

#include "serialPrint.h"

// USART1 Tx: PA9
// USART2 Tx: PA2
// USART3 Tx: PB10

void serialPrint(USART_TypeDef *port, char *msg, ...){
	char buff[800];
	va_list args;
	va_start(args,msg);
	vsprintf(buff,msg,args);
	for(int i = 0; i < strlen(buff); i++)
	{
	port->DR = buff[i];
	while(!(port->SR & USART_SR_TXE)){;}
	}

}

void serialPrintInit(USART_TypeDef *port, int baud, int clk_freq){
	RCC->APB2ENR |= RCC_APB2ENR_AFIOEN;

	if(port == USART1){
		RCC->APB2ENR |= RCC_APB2ENR_IOPAEN | RCC_APB2ENR_USART1EN;
		GPIOA->CRH |= GPIO_CRH_CNF9_1 | GPIO_CRH_MODE9_0 | GPIO_CRH_MODE9_1;
		GPIOA->CRH &= ~(GPIO_CRH_CNF9_0);
		USART1->BRR = clk_freq/baud;
		}
	else if(port == USART2){
		RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
		RCC->APB1ENR |= RCC_APB1ENR_USART2EN;
		GPIOA->CRL |= GPIO_CRL_CNF2_1 | GPIO_CRL_MODE2_0 | GPIO_CRL_MODE2_1;
		GPIOA->CRL &= ~(GPIO_CRL_CNF2_0);
		USART2->BRR = (clk_freq/2)/baud;
		}
	else if(port == USART3){
		RCC->APB2ENR |= RCC_APB2ENR_IOPBEN;
		RCC->APB1ENR |= RCC_APB1ENR_USART3EN;
		GPIOB->CRH |= GPIO_CRH_CNF10_1 | GPIO_CRH_MODE10_0 | GPIO_CRH_MODE10_1;
		GPIOB->CRH &= ~(GPIO_CRH_CNF10_0);
		USART3->BRR = (clk_freq/2)/baud;
		}

	port->CR1 |= USART_CR1_TE;
	port->CR1 |= USART_CR1_UE;

}



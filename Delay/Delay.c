/*
 * Delay.c
 *
 *  Created on: Jul 6, 2022
 *      Author: sidiyer27
 */

#include "Delay.h"


void Delay_Config(void){
	SysTick->CTRL = 0;
	SysTick->LOAD = 0x00FFFFFF;
	SysTick->VAL = 0;
	SysTick->CTRL |= 5;
}


void Delay_us(float delay){
	SysTick->LOAD = (SystemCoreClock / 1000000) * delay;
	SysTick->VAL = 0;
	while((SysTick->CTRL & 0x00010000) == 0);\
	return;
}

void Delay_ms(float delay){
	SysTick->LOAD = (SystemCoreClock / 1000) * (delay);
	SysTick->VAL = 0;
	while((SysTick->CTRL & 0x00010000) == 0);
	return;
}


void Delay_s(float delay){
	SysTick->LOAD = SystemCoreClock * (delay);
	SysTick->VAL = 0;
	while((SysTick->CTRL & 0x00010000) == 0);
	return;

}



/*
 * RCC.c
 *
 *  Created on: Jun 1, 2022
 *      Author: sidiyer27
 */

#include "RCC.h"


void Ext_Clk_Init(){

	 RCC->CR |= RCC_CR_HSEON; // Enable HSE Clock (1<<16)
	 while((RCC->CR & RCC_CR_HSERDY) == 0){;} // Poll until HSE Clock ready flag is set to high (1<<17)
	 FLASH->ACR |= FLASH_ACR_PRFTBE|FLASH_ACR_LATENCY_2; // activate prefetch buffer and flash to wait state (1<<4),(1)
	 RCC->CFGR |= RCC_CFGR_PLLSRC; // Selects PLL clock source as Clock from PREDIV1 (1<<16)
	 RCC->CFGR |= RCC_CFGR_PLLMULL9; // Set PLL Multiplication factor to 9 (7<<18)
	 RCC->CFGR |= RCC_CFGR_PPRE1_DIV2; // Set APB1 Division factor to 2 (1<<10)
	 RCC->CR |= RCC_CR_PLLON; // Turn on PLL (1<<24)
	 while((RCC->CR & RCC_CR_PLLRDY) == 0){;} // Poll until PLL Clock ready flag is set to high (1<<25)
	 RCC->CFGR |= RCC_CFGR_SW_PLL; // Set PLL as System Clock (2)
	 while(!(RCC->CFGR & RCC_CFGR_SWS_PLL)){;} // Poll until System clock switch status is set to 10 (8)
	 SystemCoreClockUpdate();
}



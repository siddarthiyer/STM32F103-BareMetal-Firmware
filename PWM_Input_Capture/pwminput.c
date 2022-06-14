/*
 * pwminput.c
 *
 *  Created on: 14-Jun-2022
 *      Author: sidiyer27
 */

#include "pwminput.h"

void PWM_Input_Init(TIM_TypeDef *TIM, Channel channel){

	RCC->APB2ENR |= RCC_APB2ENR_AFIOEN;

	if(TIM == TIM1){
		RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
		RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;
	}
	else if(TIM == TIM2){
		RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
		RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
	}
	else if(TIM == TIM3){
		RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
		RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;
	}
	else if(TIM == TIM4){
		RCC->APB2ENR |= RCC_APB2ENR_IOPBEN;
		RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;
	}

	if(channel == Channel1){
		TIM->CCMR1 |= TIM_CCMR1_CC1S_0 | TIM_CCMR1_IC1F_0 | TIM_CCMR1_IC1F_1;
		TIM->CCMR1 |= TIM_CCMR1_CC2S_1 | TIM_CCMR1_IC2F_0 | TIM_CCMR1_IC2F_1;
		TIM->CCER |= TIM_CCER_CC2P | TIM_CCER_CC1E | TIM_CCER_CC2E;
		TIM->SMCR |= TIM_SMCR_TS_2 | TIM_SMCR_TS_0 | TIM_SMCR_SMS_2;
	}
	else if(channel == Channel2){
		TIM->CCMR1 |= TIM_CCMR1_CC1S_1 | TIM_CCMR1_IC1F_0 | TIM_CCMR1_IC1F_1;
		TIM->CCMR1 |= TIM_CCMR1_CC2S_0 | TIM_CCMR1_IC2F_0 | TIM_CCMR1_IC2F_1;
		TIM->CCER |= TIM_CCER_CC1P | TIM_CCER_CC1E | TIM_CCER_CC2E;
		TIM->SMCR |= TIM_SMCR_TS_2 | TIM_SMCR_TS_1 | TIM_SMCR_SMS_2;
	}
	TIM->PSC = 72-1;
	TIM->CR1 |= TIM_CR1_CEN;

}
uint32_t PWM_Input_DutyCyle(TIM_TypeDef *TIM, Channel channel){
	if(channel = Channel1){
		return TIM->CCR2;
	}
	else{
		return TIM->CCR1;
	}
}

uint32_t PWM_Input_Period(TIM_TypeDef *TIM, Channel channel){
	if(channel = Channel1){
		return TIM->CCR1;
		}
	else{
		return TIM->CCR2;
	}
}





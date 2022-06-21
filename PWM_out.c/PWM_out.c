/*
 * PWM_out.c
 *
 *  Created on: 20-Jun-2022
 *      Author: sidiyer27
 */

#include "PWM_out.h"


void PWM_Out_Init(TIM_TypeDef *TIM, int channel, int freq){
	if(TIM == TIM1){
		RCC ->APB2ENR |= RCC_APB2ENR_TIM1EN;
		TIM->PSC = ((TIM_CLOCK_ADVANCED) / ((frequency)*(100)))-1;
	}
	else if(TIM == TIM2){
		RCC -> APB1ENR |= RCC_APB1ENR_TIM2EN;
		TIM->PSC = ((TIM_CLOCK_GENERAL) / ((frequency)*(100)))-1;
	}
	else if(TIM == TIM3){
		RCC -> APB1ENR |= RCC_APB1ENR_TIM3EN;
		TIM->PSC = ((TIM_CLOCK_GENERAL) / ((frequency)*(100)))-1;
	}
	else if(TIM == TIM4){
		RCC -> APB1ENR |= RCC_APB1ENR_TIM4EN;
		TIM->PSC = ((TIM_CLOCK_GENERAL) / ((frequency)*(100)))-1;
	}

	if(channel == 1){
		 TIM -> CCMR1 |= TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1M_2|TIM_CCMR1_OC1PE;
		 TIM -> CCER |= TIM_CCER_CC1E;
	}
	else if(channel == 2){
		 TIM->CCMR1 |= TIM_CCMR1_OC2M_1 | TIM_CCMR1_OC2M_2|TIM_CCMR1_OC2PE;
		 TIM->CCER |= TIM_CCER_CC2E;
	}
	else if(channel == 3){
		 TIM->CCMR2 |= TIM_CCMR2_OC3M_1 | TIM_CCMR2_OC3M_2|TIM_CCMR2_OC3PE;
		 TIM->CCER |= TIM_CCER_CC3E;
	}
	else if(channel == 4){
		 TIM->CCMR2 |= TIM_CCMR2_OC4M_1 | TIM_CCMR2_OC4M_2|TIM_CCMR2_OC4PE;
		 TIM->CCER |= TIM_CCER_CC4E;
	}

	 TIM -> ARR = 100;
	 TIM -> BDTR |= TIM_BDTR_MOE;
	 TIM -> CR1 |= TIM_CR1_ARPE;
	 TIM -> EGR |= TIM_EGR_UG;
	 TIM -> CR1 |= TIM_CR1_CEN;



}





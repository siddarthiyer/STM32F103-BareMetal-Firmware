/*
 * pwminput.h
 *
 *  Created on: 14-Jun-2022
 *      Author: sidiyer27
 */

#ifndef PWMINPUT_H_
#define PWMINPUT_H_

#include "main.h"

typedef enum{
  Channel1,
  Channel2
} Channel;


void PWM_Input_Init(TIM_TypeDef *TIM, Channel channel);
uint32_t PWM_Input_DutyCyle(TIM_TypeDef *TIM, Channel channel);
uint32_t PWM_Input_Period(TIM_TypeDef *TIM, Channel channel);


#endif /* PWMINPUT_H_ */

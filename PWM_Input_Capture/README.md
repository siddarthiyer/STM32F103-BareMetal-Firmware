# PWM Input Capture
Driver used for PWM Input Capture. Used to measure duration of rising edge and period of PWM signal. <br />

Functions:  <br />

PWM_Input_Init(TIM_TypeDef *TIM, Channel channel): Initializes PWM Input Capture. Allows user to select Timer and Channel.<br />
uint32_t PWM_Input_DutyCyle(TIM_TypeDef *TIM, Channel channel): Returns the duration of rising edge for corresponding Timer and channel. <br />
uint32_t PWM_Input_Period(TIM_TypeDef *TIM, Channel channel): Returns period of the pwm signal for corresponding Timer and channel.  <br />

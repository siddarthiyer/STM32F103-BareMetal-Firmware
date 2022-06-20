/*
 * I2C_Driver.c
 *
 *  Created on: Jun 1, 2022
 *      Author: sidiyer27
 */

#include "I2C_Driver.h"


void I2C_Init(){

	RCC -> APB1ENR |= RCC_APB1ENR_I2C1EN ;
	GPIO_Pin_Setup(GPIOB, 6, ALT_OPEN_DRAIN_OUTPUT);
	GPIO_Pin_Setup(GPIOB, 7, ALT_OPEN_DRAIN_OUTPUT);
	I2C1->CR2 = 36;
	I2C1->CCR |= 1<<15 | 30;
	I2C1->TRISE = 11;
	I2C1->CR1 |= 1;
}



void I2C_Start(){
	I2C1->CR1 |= I2C_CR1_START;
	while((I2C1->SR1 & I2C_SR1_SB)==0){;}
}



void I2C_Address(uint8_t address,uint8_t RW){
	I2C1->DR = address | RW;
	while((I2C1->SR1 & I2C_SR1_ADDR) == 0){;}
	while(I2C1 -> SR1 & I2C_SR1_ADDR){
		READ_REG(I2C1->SR1);
		READ_REG(I2C1->SR2);
		if((I2C1 -> SR1 & I2C_SR1_ADDR)==0) break;
	}
}


void I2C_sendData(uint8_t data){
	while((I2C1->SR1 & I2C_SR1_TXE) == 0){;}
	I2C1->DR = data;
	while((I2C1-> SR1 & I2C_SR1_TXE) == 0){;}

}


uint8_t I2C_receiveData(){
	volatile int ret;
	I2C1->CR1 |= I2C_CR1_ACK;
	while((I2C1->SR1 & I2C_SR1_RXNE) == 0){;}
	ret = I2C1->DR;
	I2C1->CR1 &= ~I2C_CR1_ACK;
	return ret;

}


void I2C_Stop(){
	I2C1->CR1 |= I2C_CR1_STOP;
}



void I2C_Write_Register(uint8_t device_address, uint8_t reg_address, uint8_t data)
{
	I2C_Start();
	I2C_Address(device_address,0);
	I2C_sendData(reg_address);
	I2C_sendData(data);
	I2C_Stop();
}


int I2C_Read_Register(uint8_t device_address, uint8_t reg_address)
{
	int temp;
	I2C_Start();
	I2C_Address(device_address, 0);
	I2C_sendData(reg_address);
	I2C_Stop();
	Delay_us(100);
	I2C_Start();
	I2C_Address(device_address, 1);
	temp = I2C_receiveData();
	I2C_Stop();
	return temp;
}









/*
 * I2C_Driver.h
 *
 *  Created on: Jun 1, 2022
 *      Author: sidiyer27
 */

#ifndef I2C_DRIVER_H_
#define I2C_DRIVER_H_

#include "main.h"
#include "GPIO.h"

void I2C_Init();
void I2C_Start();
void I2C_Address(uint8_t address, uint8_t RW);
void I2C_sendData(uint8_t data);
uint8_t I2C_receiveData();
void I2C_Stop();
void I2C_Write_Register(uint8_t device_address, uint8_t reg_address, uint8_t data);
int I2C_Read_Register(uint8_t device_address, uint8_t reg_address);



#endif /* I2C_DRIVER_H_ */

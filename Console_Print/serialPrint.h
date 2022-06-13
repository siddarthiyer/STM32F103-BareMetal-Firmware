/*
 * serialPrint.h
 *
 *  Created on: 13-Jun-2022
 *      Author: sidiyer27
 */

#ifndef SERIALPRINT_H_
#define SERIALPRINT_H_

#include "string.h"
#include "stdlib.h"
#include "stdarg.h"
#include "stdint.h"
#include "main.h"

void serialPrintInit(USART_TypeDef *port, int baud, int clk_freq);
void serialPrint(USART_TypeDef *port, char *msg, ...);



#endif /* SERIALPRINT_H_ */

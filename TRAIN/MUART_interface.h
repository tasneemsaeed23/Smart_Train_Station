/*
 * MUART_interface.h
 *
 *  Created on: Sep 1, 2021
 *      Author: ncm
 */

#ifndef MCAL_DRIVERS_UART_MUART_INTERFACE_H_
#define MCAL_DRIVERS_UART_MUART_INTERFACE_H_

#include "LBIT_MATH.h"
#include "LSTD_TYPES.h"

void MUART_Init(void);

void MUART_Send_Data(u8_t data);

u8_t MUART_Recieve_Data(void);

#endif /* MCAL_DRIVERS_UART_MUART_INTERFACE_H_ */

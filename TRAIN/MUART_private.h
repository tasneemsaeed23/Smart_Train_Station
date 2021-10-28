/*
 * MUART_private.h
 *
 *  Created on: Sep 1, 2021
 *      Author: ncm
 */

#ifndef MCAL_DRIVERS_UART_MUART_PRIVATE_H_
#define MCAL_DRIVERS_UART_MUART_PRIVATE_H_

#include "LBIT_MATH.h"
#include "LSTD_TYPES.h"

/* USART Baud Rate Register Low */
#define UBRRL    (*(volatile u8_t *)0x29)

/* USART Control and Status Register B */
#define UCSRB   (*(volatile u8_t*)0x2A)

/* USART Control and Status Register A */
#define UCSRA    (*(volatile u8_t*)0x2B)

/* USART I/O Data Register */
#define UDR       (*(volatile u8_t*)0x2C)

/* USART Baud Rate Register High */
#define UBRRH    (*(volatile u8_t*)0x40)

/* USART Control and Status Register C */
#define UCSRC     (*(volatile u8_t *)0x40)

/* USART Register C */
#define    UMSEL        6
#define    UPM1         5
#define    UPM0         4
#define    USBS         3
#define    UCSZ1        2
#define    UCSZ0        1
#define    UCPOL        0

/* USART Status Register A  */
#define    RXC          7
#define    TXC          6
#define    UDRE         5
#define    FE           4
#define    DOR          3
#define    UPE          2
#define    U2X          1
#define    MPCM         0
/* USART Control Register B  */
#define    RXCIE        7
#define    TXCIE        6
#define    UDRIE        5
#define    RXEN         4
#define    TXEN         3
#define    UCSZ         2
#define    UCSZ2        2
#define    RXB8         1
#define    TXB8         0

/***********************Vectors of Uart******************/
#define USART_RXC_vect			__vector_13
/* USART Data Register Empty */
#define USART_UDRE_vect			__vector_14
/* USART, Tx Complete */
#define USART_TXC_vect			__vector_15

/********************************************************/
#  define ISR(vector)            \
void vector (void) __attribute__ ((signal)); \
void vector (void)*/


#endif /* MCAL_DRIVERS_UART_MUART_PRIVATE_H_ */

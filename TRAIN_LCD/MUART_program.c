/*
 * MUART_program.c
 *
 *  Created on: Sep 1, 2021
 *      Author: ncm
 */

#include "MUART_interface.h"
#include "MUART_private.h"
#include "LBIT_MATH.h"
#include "LSTD_TYPES.h"

void MUART_Init(void)
{

   u8_t local_UCSRC = 0x00 ;
   SET_BIT(local_UCSRC , 7 ) ;  //select UCSRC
    // one - stop bit
   CLEAR_BIT(local_UCSRC,USBS) ;
   //No parity
   CLEAR_BIT(local_UCSRC , UPM0) ;
   CLEAR_BIT(local_UCSRC , UPM1) ;
   // Asynchronous
   CLEAR_BIT(local_UCSRC , UMSEL);
   //8-bit data
   SET_BIT(local_UCSRC ,  UCSZ0 ) ;
   SET_BIT(local_UCSRC ,  UCSZ1 ) ;
   CLEAR_BIT(UCSRB , UCSZ2);
   //No interrupt
   UCSRB &= 0x04 ;
   //Setting UCSEC
   UCSRC = local_UCSRC ;
   local_UCSRC = 0x00 ;
   //baud rate 9600
   CLEAR_BIT(local_UCSRC , 7 );  //select UBRRH
   UBRRL = 51 ;
   //Enable UART Protocol
   SET_BIT(UCSRB , TXEN);
   SET_BIT(UCSRB , RXEN);
}


void MUART_Send_Data(u8_t data)
{
	 while(!GET_BIT(UCSRA , UDRE)) ;
	 UDR = data ;
   return ;
}


u8_t MUART_Recieve_Data(void)
{
	u8_t data ;
	while(!GET_BIT(UCSRA , RXC)) ;
	data = UDR ;
	return data ;
}



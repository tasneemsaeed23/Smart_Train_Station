/*
 * MTIMER0_private.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: ahmed
 */

#ifndef MTIMER0_PRIVATE_H_
#define MTIMER0_PRIVATE_H_


#define TCCR0  (*(volatile u8_t*) 0x53)
#define TCNT0  (*(volatile u8_t*) 0x5c)
#define TIMSK  (*(volatile u8_t*) 0x59)
#define TIFR   (*(volatile u8_t*) 0x58)


void __vector_11(void) __attribute__((signal));

#endif /* MTIMER0_PRIVATE_H_ */

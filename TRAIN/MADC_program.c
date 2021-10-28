/*
 * ADC_program.c
 *
 *  Created on: Aug 25, 2021
 *      Author: Gada
 */

#include "MADC_interface.h"
#include "MADC_private.h"
#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"

void madc_init(void)
{
	SET_BIT(ADMUX,7);
	CLEAR_BIT(ADMUX,6);

	CLEAR_BIT(ADMUX,5);

	SET_BIT(ADCSRA,0);
	SET_BIT(ADCSRA,1);
	SET_BIT(ADCSRA,2);

	SET_BIT(ADCSRA, 7);
	/*return from this function*/
		return;
}

u16_t madc_ReadAnalogPolling(u8_t au8_channel)
{

	ADMUX &= 0b11100000;
	ADMUX |= au8_channel;
	SET_BIT(ADCSRA, 6);

	while(GET_BIT(ADCSRA,4) == 0);

	SET_BIT(ADCSRA,4);

	/*return from this function*/
		return ADCL;
}

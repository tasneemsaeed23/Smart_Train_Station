/*
 * MTIMER0_projram.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: ahmed
 */

#include "LBIT_MATH.H"
#include "LSTD_TYPES.H"

#include "MTIMER0_private.h"
#include "MTIMER0_interface.h"


void (*FuncToSet)(void)=0;

void MTIMER0_VidInit(void)
{
	TCNT0=192;

	SET_BIT(TCCR0,3);
	SET_BIT(TCCR0,6);

	SET_BIT(TIMSK,0);

	CLEAR_BIT(TCCR0,0);
	SET_BIT(TCCR0,1);
	CLEAR_BIT(TCCR0,2);

}

void MTIMER0_CallBack(void (*func)(void))
{
	FuncToSet=func;
}

void __vector_11(void)
{
	if(FuncToSet !=0)
		FuncToSet();
}

/*
 * H7SEG_SECOND_program.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: ahmed
 */

#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "MDIO_interface.h"
#include "H7SEG_SECOND_private.h"
#include "H7SEG_SECOND_interface.h"

/************************************************************************************************/
/*                                    Functions' definitions                                    */
/************************************************************************************************/

void h7seg_second_init(void)
{
	/*Setting the seven segment pins status as output*/
	mdio_setPinStatus(H7SEG2_PORT, (H7SEG2_A | H7SEG2_B | H7SEG2_C | H7SEG2_D), OUTPUT);

	/*Return from this function*/
	return;
}

void h7seg_second_displayNumber(u8_t au8_number)
{
	/*Setting binary number form over DIO pins*/
	mdio_setPinValue(H7SEG2_PORT, H7SEG2_A, GET_BIT(au8_number, 0));
	mdio_setPinValue(H7SEG2_PORT, H7SEG2_B, GET_BIT(au8_number, 1));
	mdio_setPinValue(H7SEG2_PORT, H7SEG2_C, GET_BIT(au8_number, 2));
	mdio_setPinValue(H7SEG2_PORT, H7SEG2_D, GET_BIT(au8_number, 3));

	/*Return from this function*/
	return;
}

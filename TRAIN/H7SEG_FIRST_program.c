/*
 * H7SEG_FIRST_program.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: ahmed
 */


#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "MDIO_interface.h"
#include "H7SEG_FIRST_private.h"
#include "H7SEG_FIRST_interface.h"

/************************************************************************************************/
/*                                    Functions' definitions                                    */
/************************************************************************************************/

void h7seg_first_init(void)
{
	/*Setting the seven segment pins status as output*/
	mdio_setPinStatus(H7SEG_PORT, (H7SEG1_A | H7SEG1_B | H7SEG1_C | H7SEG1_D), OUTPUT);


}

void h7seg_first_displayNumber(u8_t au8_number)
{
	/*Setting binary number form over DIO pins*/
	mdio_setPinValue(H7SEG_PORT, H7SEG1_A, GET_BIT(au8_number, 0));
	mdio_setPinValue(H7SEG_PORT, H7SEG1_B, GET_BIT(au8_number, 1));
	mdio_setPinValue(H7SEG_PORT, H7SEG1_C, GET_BIT(au8_number, 2));
	mdio_setPinValue(H7SEG_PORT, H7SEG1_D, GET_BIT(au8_number, 3));

	/*Return from this function*/
	return;
}

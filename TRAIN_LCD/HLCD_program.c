/*
 *Name: HLCD_program.c
 *Author: Ghada Hussein
 *Version: v1.0
 */

/******************************************************************************************************************/
/*                        Includes                                                                                                 */
/******************************************************************************************************************/

#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "MDIO_interface.h"
#include "HLCD_private.h"
#include "HLCD_interface.h"


#define F_CPU   8000000UL
#include "util/delay.h"

/******************************************************************************************************************/
/*                                   Function                                                                                                */
/******************************************************************************************************************/

static void hlcd_sendData(u8_t au8_data)  /*0b11001100*/
{
	/*setting RS pin to high for sending data*/
	mdio_setPinValue(HLCD_CTRL_PORT, HLCD_RS_PIN, HIGH);

	/*setting RW pin to low for writing data/Cmd*/
	mdio_setPinValue(HLCD_CTRL_PORT, HLCD_RW_PIN, LOW);

	/*Passing data over data pins*/
	mdio_setPinValue(HLCD_DATA_PORT, HLCD_D0_PIN, GET_BIT(au8_data, 0));
	mdio_setPinValue(HLCD_DATA_PORT, HLCD_D1_PIN, GET_BIT(au8_data, 1));
	mdio_setPinValue(HLCD_DATA_PORT, HLCD_D2_PIN, GET_BIT(au8_data, 2));
	mdio_setPinValue(HLCD_DATA_PORT, HLCD_D3_PIN, GET_BIT(au8_data, 3));
	mdio_setPinValue(HLCD_DATA_PORT, HLCD_D4_PIN, GET_BIT(au8_data, 4));
	mdio_setPinValue(HLCD_DATA_PORT, HLCD_D5_PIN, GET_BIT(au8_data, 5));
	mdio_setPinValue(HLCD_DATA_PORT, HLCD_D6_PIN, GET_BIT(au8_data, 6));
	mdio_setPinValue(HLCD_DATA_PORT, HLCD_D7_PIN, GET_BIT(au8_data, 7));
    /*triggering data by enable signal*/
	mdio_setPinValue(HLCD_CTRL_PORT, HLCD_EN_PIN, LOW);
	 _delay_ms(50);
	 mdio_setPinValue(HLCD_CTRL_PORT, HLCD_EN_PIN, HIGH);


	/*return from this function*/
		return;
}

static void hlcd_sendCmd(u8_t au8_cmd)
{
	/*setting RS pin to high for sending data*/
			mdio_setPinValue(HLCD_CTRL_PORT, HLCD_RS_PIN, LOW);

			/*setting RW pin to low for writing data/cmd*/
			mdio_setPinValue(HLCD_CTRL_PORT, HLCD_RW_PIN, LOW);

			/*Passing data over data pins*/
			mdio_setPinValue(HLCD_DATA_PORT, HLCD_D0_PIN, GET_BIT(au8_cmd, 0));
			mdio_setPinValue(HLCD_DATA_PORT, HLCD_D1_PIN, GET_BIT(au8_cmd, 1));
			mdio_setPinValue(HLCD_DATA_PORT, HLCD_D2_PIN, GET_BIT(au8_cmd, 2));
			mdio_setPinValue(HLCD_DATA_PORT, HLCD_D3_PIN, GET_BIT(au8_cmd, 3));
			mdio_setPinValue(HLCD_DATA_PORT, HLCD_D4_PIN, GET_BIT(au8_cmd, 4));
			mdio_setPinValue(HLCD_DATA_PORT, HLCD_D5_PIN, GET_BIT(au8_cmd, 5));
			mdio_setPinValue(HLCD_DATA_PORT, HLCD_D6_PIN, GET_BIT(au8_cmd, 6));
			mdio_setPinValue(HLCD_DATA_PORT, HLCD_D7_PIN, GET_BIT(au8_cmd, 7));
            /*triggering data by enable signal*/
			mdio_setPinValue(HLCD_CTRL_PORT, HLCD_EN_PIN, LOW);
			 _delay_ms(50);
			 mdio_setPinValue(HLCD_CTRL_PORT, HLCD_EN_PIN, HIGH);


	/*return from this function*/
		return;
}


void hlcd_init(void)
{
	/*Setting control port pins to output*/
	mdio_setPinStatus(HLCD_CTRL_PORT, (HLCD_RS_PIN | HLCD_RW_PIN | HLCD_EN_PIN), OUTPUT);

	/*Setting data port pins to output*/
	mdio_setPinStatus(HLCD_DATA_PORT, (HLCD_D0_PIN | HLCD_D1_PIN | HLCD_D2_PIN | HLCD_D3_PIN |
                                       HLCD_D4_PIN | HLCD_D5_PIN | HLCD_D6_PIN | HLCD_D7_PIN ), OUTPUT);

	/*Setting enable pin to high*/
	mdio_setPinValue(HLCD_CTRL_PORT, HLCD_EN_PIN, HIGH);

	/*waiting for VDD to reach 4.5V*/
		_delay_ms(50);

	/*Sending function set command*/
		hlcd_sendCmd(0x3C);

	/*Delaying for 1ms*/
		_delay_ms(1);

	/*Sending display on/off command*/
	   hlcd_sendCmd(0x0F);

	/*Delaying for 1ms*/
		_delay_ms(1);

	/*Sending display clear command*/
		hlcd_sendCmd(0x01);

	/*Delaying for 2ms*/
		_delay_ms(2);

	/*Sending display mode set command*/
		hlcd_sendCmd(0x06);

	/*Delaying for 1ms*/
		_delay_ms(1);


	/*return from this function*/
	return;
}


void hlcd_displayCharacter(u8_t au8_charData)
{
	hlcd_sendData(au8_charData);

	/*return from this function*/
		return;
}


void hlcd_displayString(u8_t* pu8_strData)
{

   while(*pu8_strData != '\0')
   	   {
	       /*Sending character data*/
	           hlcd_sendData(*pu8_strData);
	       /*Incrementing pointer address*/
	           pu8_strData++;

   	   }

	/*return from this function*/
		return;
}


void hlcd_setCursor(u8_t au8_row, u8_t au8_col)
{
	/*Switching over LCD rows*/
	switch (au8_row)
	{
	/*in case of choosing row 0*/
		case ROW_0:
			/*sending set cursor command at line 1*/
			hlcd_sendCmd(( (0x80) | au8_col));

			/*break from this case*/
		  break;

	/*in case of choosing row 1*/
		case ROW_1:
			/*sending set cursor command at line 2*/
						hlcd_sendCmd(( (0xC0) | au8_col));
			/*break from this case*/
	      break;
    /*in case of default*/
		default:
			/*break from this case*/
			break;

	}

	/*return from this function*/
		return;
}

/*this function used to clear LCD*/
void hlcd_clear(void)
{
	hlcd_sendCmd(0x01);
	/*return from this function*/
	return;
}


#ifndef HLCD_PROGRAM_C_
#define HLCD_PROGRAM_C_



#endif /* HLCD_PROGRAM_C_ */

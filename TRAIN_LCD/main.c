/*

 * main.c
 *
 *  Created on: Sep 10, 2021
 *      Author: Ghada
 */

#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "MDIO_interface.h"
#include "HLCD_interface.h"
#include "MUART_interface.h"

#define F_CPU   8000000UL
#include "util/delay.h"


void lcd (void);

int main(void)
{
   while(1)
   {

	    hlcd_init();

	    	lcd();

   }

    return 0;

}

/*this function used to display train times on LCD*/
void lcd(void)
{
	/*Train times on LCD*/
			hlcd_setCursor(ROW_0,COL_3);
			hlcd_displayString((u8_t*) "Welcome to");
			hlcd_setCursor(ROW_1,COL_2);
			hlcd_displayString((u8_t*) "Our  Station");
		_delay_ms(1000);
		hlcd_clear();

			hlcd_setCursor(ROW_0,COL_1);
			hlcd_displayString((u8_t*) "MORNING Train");
			hlcd_setCursor(ROW_1,COL_4);
			hlcd_displayString((u8_t*) "Times ->");

		_delay_ms(1000);
		hlcd_clear();

			hlcd_setCursor(ROW_0,COL_0);
			hlcd_displayString((u8_t*) "6:30");
			hlcd_setCursor(ROW_0,COL_8);
			hlcd_displayString((u8_t*) "8:00");
			hlcd_setCursor(ROW_1,COL_0);
			hlcd_displayString((u8_t*) "9:30");
			hlcd_setCursor(ROW_1,COL_8);
			hlcd_displayString((u8_t*) "11:00");

	    _delay_ms(2000);
		hlcd_clear();

			hlcd_setCursor(ROW_0,COL_0);
			hlcd_displayString((u8_t*) "Afternoon Train");
			hlcd_setCursor(ROW_1,COL_4);
			hlcd_displayString((u8_t*) "Times ->");

		_delay_ms(1000);
		hlcd_clear();

			hlcd_setCursor(ROW_0,COL_0);
			hlcd_displayString((u8_t*) "12:30");
			hlcd_setCursor(ROW_0,COL_9);
			hlcd_displayString((u8_t*) "2:00");
			hlcd_setCursor(ROW_1,COL_0);
			hlcd_displayString((u8_t*) "3:30");
		    hlcd_setCursor(ROW_1,COL_9);
			hlcd_displayString((u8_t*) "5:00");

		_delay_ms(2000);
		hlcd_clear();

		        hlcd_setCursor(ROW_0,COL_0);
				hlcd_displayString((u8_t*) "EVENING Train");
				hlcd_setCursor(ROW_1,COL_4);
				hlcd_displayString((u8_t*) "Times ->");

		_delay_ms(1000);
		hlcd_clear();

				hlcd_setCursor(ROW_0,COL_0);
				hlcd_displayString((u8_t*) "7:00");
				hlcd_setCursor(ROW_0,COL_9);
				hlcd_displayString((u8_t*) "9:00");
				hlcd_setCursor(ROW_1,COL_0);
				hlcd_displayString((u8_t*) "10:00");
				hlcd_setCursor(ROW_1,COL_9);
				hlcd_displayString((u8_t*) "12:00");

		_delay_ms(2000);
		hlcd_clear();

	return;
}



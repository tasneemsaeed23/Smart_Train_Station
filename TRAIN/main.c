/*

 * main.c
 *
 *  Created on: Sep 8, 2021
 *      Author: Ghada
 */

#include "LBIT_MATH.h"
#include "LSTD_TYPES.h"
#include "MDIO_interface.h"
#include "MDIO_private.h"
#include "H7SEG_FIRST_interface.h"
#include "H7SEG_SECOND_interface.h"
#include "MUART_interface.h"
#include "MADC_interface.h"
#include "MTIMER0_interface.h"
#include "MGIE_Interface.h"

#define F_CPU   8000000UL
#include "util/delay.h"

u8_t flag=0;
/*this function used to initialize stepper motor*/
void stepper_init(void)
{
	mdio_setPinStatus(PORTC, (PIN4 | PIN5 | PIN6 | PIN7), OUTPUT);
	mdio_setPinValue(PORTC,  (PIN4 | PIN5 | PIN6 | PIN7), LOW);
			return;
}
/*this function used to make motor run in forward direction*/
void forward(void)
{
	    mdio_setPinValue(PORTC, PIN4, HIGH);
		mdio_setPinValue(PORTC, PIN5, LOW);
		mdio_setPinValue(PORTC, PIN6, LOW);
		mdio_setPinValue(PORTC, PIN7, LOW);
		_delay_ms(100);
		mdio_setPinValue(PORTC, PIN4, LOW);
		mdio_setPinValue(PORTC, PIN5, HIGH);
		mdio_setPinValue(PORTC, PIN6, LOW);
		mdio_setPinValue(PORTC, PIN7, LOW);
		_delay_ms(100);
		mdio_setPinValue(PORTC, PIN4, LOW);
		mdio_setPinValue(PORTC, PIN5, LOW);
		mdio_setPinValue(PORTC, PIN6, HIGH);
		mdio_setPinValue(PORTC, PIN7, LOW);
		_delay_ms(100);
		mdio_setPinValue(PORTC, PIN4, LOW);
		mdio_setPinValue(PORTC, PIN5, LOW);
		mdio_setPinValue(PORTC, PIN6, LOW);
		mdio_setPinValue(PORTC, PIN7, HIGH);
		_delay_ms(100);

   return;
}
/*this function used to make motor run in reverse direction*/
void reverse(void)
{
	    mdio_setPinValue(PORTC, PIN4, LOW);
		mdio_setPinValue(PORTC, PIN5, LOW);
		mdio_setPinValue(PORTC, PIN6, LOW);
		mdio_setPinValue(PORTC, PIN7, HIGH);
		_delay_ms(100);
		mdio_setPinValue(PORTC, PIN4, LOW);
		mdio_setPinValue(PORTC, PIN5, LOW);
		mdio_setPinValue(PORTC, PIN6, HIGH);
		mdio_setPinValue(PORTC, PIN7, LOW);
		_delay_ms(100);
		mdio_setPinValue(PORTC, PIN4, LOW);
		mdio_setPinValue(PORTC, PIN5, HIGH);
		mdio_setPinValue(PORTC, PIN6, LOW);
		mdio_setPinValue(PORTC, PIN7, LOW);
		_delay_ms(100);
		mdio_setPinValue(PORTC, PIN4, HIGH);
		mdio_setPinValue(PORTC, PIN5, LOW);
		mdio_setPinValue(PORTC, PIN6, LOW);
		mdio_setPinValue(PORTC, PIN7, LOW);
		_delay_ms(100);

	return;
}
/*this function used to count from 60 to zero*/
void seven_segg(void)
{
	volatile static u8_t i =0;
	volatile static u8_t j =0;

	for(i=0;i<=5;i++)
	 {
		 h7seg_first_displayNumber(5-i);
		 for(j=0;j<=9;j++)
		 {
			 h7seg_second_displayNumber(9-j);

			 _delay_ms(200);
			 /*turn on Buzzer*/
			 mdio_setPinValue(PORTD, PIN7,HIGH);
		 }

	 }
	/*edit*/
i=0;
j=0;
	return ;
}
void func (void)
{

	 static u16_t count1 =0;
	 static u16_t count2 =0;
	 static u16_t count3 =0;


	count1++;
	count2++;


	 if(count1 ==400)
	{
		count3 ++;

		if(count3 ==1)
		{
			/*Turn on led*/
			for(int i=0; i<5; i++)
			{
				mdio_setPinValue(PORTC, PIN3, HIGH);
				_delay_ms(100);
				mdio_setPinValue(PORTC, PIN3, LOW);
				_delay_ms(100);
			}
			_delay_ms(1000);
			/*open railway*/
			 forward();

			/*Turn on Buzzer */
			 seven_segg();
			 count1 =0;
		}
	}
	else if(count2 ==1000 && flag==0)
	{
		/*turn off led and Buzzer*/
		mdio_setPinValue(PORTD, PIN7,LOW);
		mdio_setPinValue(PORTC, PIN3, LOW);

		_delay_ms(1000);
		/*close railway*/
		reverse();

		 count3 =0;
		 count2 =0;
flag=1;
	}

}


int main(void)
{
	 flag=0;
	/*local variable for UART*/
	u8_t TX =0;

	/*local variable for ADC*/
    u16_t x =0;

    /*initialize 7SEG*/
    h7seg_first_init();
    h7seg_second_init();

    /*initialize UART*/
     MUART_Init();
     MUART_Send_Data(TX);
     _delay_ms(75);

	/*initialize Stepper Motor*/
	stepper_init();

	/*initialize ADC and LDR*/
	mdio_setPinStatus(PORTA , PIN0 , INPUT_FLOAT );
	mdio_setPinStatus(PORTD , PIN6 , OUTPUT);
	mdio_setPinValue(PORTD, PIN6, LOW);
	madc_init();

	/*initialize red-led*/
	mdio_setPinStatus(PORTC, PIN3,OUTPUT);
	mdio_setPinValue(PORTC,PIN3, LOW);

	/*initialize Buzzer*/
	mdio_setPinStatus(PORTD, PIN7,OUTPUT);
	mdio_setPinValue(PORTD,PIN7, LOW);

	/*TIMER0*/

		MTIMER0_CallBack(func);


	MTIMER0_VidInit();
    MGIE_VidEnableGIE();



       while(1)
		      {
		    	  x = madc_ReadAnalogPolling(0);
		    	  x = x * 5 /1023 ;

					  if(x < 3)
					  {
						  mdio_setPinValue(PORTD, PIN6, LOW);
					  }
					  else if (x>=3)
					  {
						  mdio_setPinValue(PORTD, PIN6, HIGH);
					  }
		      }



while(1);
	return 0;
}

/*
 * ADC_private.h
 *
 *  Created on: Aug 25, 2021
 *      Author: Gada
 */

#ifndef MADC_PRIVATE_H_
#define MADC_PRIVATE_H_

/*Registers*/
#define ADMUX                 (*(volatile u8_t *)(0x27))
#define ADCSRA				  (*(volatile u8_t *)(0x26))
#define ADCL                  (*(volatile u16_t *)(0x24))
#define ADCH                  (*(volatile u8_t *)(0x25))
#define SFIOR                 (*(volatile u8_t *)(0x50))







#endif /* MADC_PRIVATE_H_ */

/*
 * H7SEG_SECOND_interface.h
 *
 *  Created on: ??�/??�/????
 *      Author: ahmed
 */

#ifndef H7SEG_SECOND_INTERFACE_H_
#define H7SEG_SECOND_INTERFACE_H_

/*seven segment numbers*/
/*
#define NUMBER_0    (0)
#define NUMBER_1    (1)
#define NUMBER_2    (2)
#define NUMBER_3    (3)
#define NUMBER_4    (4)
#define NUMBER_5    (5)
#define NUMBER_6    (6)
#define NUMBER_7    (7)
#define NUMBER_8    (8)
#define NUMBER_9    (9)
*/
/************************************************************************************************/
/*                                    Functions' prototypes                                     */
/************************************************************************************************/

/*This function is used to initialize seven segment pins*/
void h7seg_second_init(void);

/*This function is used to display a specific number over seven segment [0 -> 9]*/
void h7seg_second_displayNumber(u8_t au8_number);



#endif /* H7SEG_SECOND_INTERFACE_H_ */

/*
 * Name: HLCD_interface.h
 *  Author: Ghada Hussein
 *  Version: v1.0
 */

#ifndef HLCD_INTERFACE_H_
#define HLCD_INTERFACE_H_
/******************************************************************************************************************/
/*                                            Interfacing macros                                                                    */
/******************************************************************************************************************/

/*LCD Rows*/
#define ROW_0  (0)
#define ROW_1  (1)

/*LCD Columns*/
#define COL_0        (0)
#define COL_1  		 (1)
#define COL_2  		 (2)
#define COL_3  		 (3)
#define COL_4 		 (4)
#define COL_5  		 (5)
#define COL_6  		 (6)
#define COL_7 		 (7)
#define COL_8  		 (8)
#define COL_9 		 (9)
#define COL_10 		(10)
#define COL_11 		(11)
#define COL_12 		(12)
#define COL_13 		(13)
#define COL_14 		(14)
#define COL_15 		(15)

/******************************************************************************************************************/
/*                                           Functions' prototypes                                                                  */
/******************************************************************************************************************/


/*this function is used to initialize LCD module*/
void hlcd_init(void);

/*this function is used to display a custom character from ASCII table*/
void hlcd_displayCharacter(u8_t au8_charData);

/*this function is used to display a custom series of characters from ASCII table*/
void hlcd_displayString(u8_t* pu8_stringData);

/*this function is used to set the cursor at specific location at LCD*/
void hlcd_setCursor(u8_t au8_row, u8_t au8_col);

/*this function is used to clear LCD*/
void hlcd_clear(void);

#endif /* HLCD_INTERFACE_H_ */

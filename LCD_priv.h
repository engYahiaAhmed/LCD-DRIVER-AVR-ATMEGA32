/************************************************/
/* Title       : LCD Private file               */
/* Author      : Yahia Ahmed                    */
/* Release     : 1.0                            */
/* Last Update : Aug 16, 2021                   */
/************************************************/

#ifndef LCD_PRIV_H_
#define LCD_PRIV_H_

static void LCD_SvidExecute(u8 Copy_u8DataCmd);

#define LCD_u8_4BitMode    			 			0
#define LCD_u8_8BitMode     					1
#define LCD_u8_CLR_SCREEN_COMMAND				0b00000001
#define LCD_U8_SHIFT_LEFT_CURSER_COMMAND   		0b00011000
#define LCD_U8_SHIFT_Right_CURSER_COMMAND	    0b00011100
#define LCD_u8_CURSER_ON_COMMAND   				0b00111000
#define LCD_u8_CURSER_OFF_COMMAND				0b00001100
#define LCD_U8_CURSER_DIR_COMMAND      	    	0b00000110
#define LCD_u8_FUNCTION_SET_COMMAND      	  	0b00111000
#define LCD_u8_RETURN_COMMAND 					0b10000000


#endif /* LCD_PRIV_H_ */

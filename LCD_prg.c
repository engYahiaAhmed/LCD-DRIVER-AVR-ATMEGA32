/************************************************/
/* Title       : LCD Program file               */
/* Author      : Yahia Ahmed                    */
/* Release     : 1.0                            */
/* Last Update : Aug 16, 2021                   */
/************************************************/

#include "BIT_math.h"
#include "STD_types.h"

#include <util/delay.h>

#include "DIO_int.h"
#include "LCD_int.h"
#include "LCD_config.h"
#include "LCD_priv.h"

void LCD_vidInit(void)
{
	_delay_ms(35);
	LCD_vidWriteCommand(0b00111000); // 2 lines and 5×7 matrix
	_delay_ms(1);
	LCD_vidWriteCommand(0b00001110); // Display on, cursor blinking
	_delay_ms(1);
	LCD_vidWriteCommand(0b00000001); // clear screen
	_delay_ms(2);
	LCD_vidWriteCommand(0b00000110); // Increment cursor (shift cursor to right)


}

void LCD_vidWriteCharacter(u8 Copy_u8data)
{
	DIO_vid_SetPinValue( LCD_u8_PIN_RS ,  DIO_u8_HIGH); // RS high for data 
	LCD_SvidExecute(Copy_u8data);

}

void LCD_vidWriteCommand(u8 Copy_u8cmd)
{
	DIO_vid_SetPinValue( LCD_u8_PIN_RS ,  DIO_u8_LOW); // RS low for commands 
	LCD_SvidExecute(Copy_u8cmd);
}

void LCD_vidWriteString(u8 * Copy_pString)
{
	u8 Local_u8Index = 0 ;
	while(Copy_pString[Local_u8Index]  != '\0' )
	{
		LCD_vidWriteCharacter(Copy_pString[Local_u8Index]);
		Local_u8Index++ ;
	}

}

void LCD_vidGoToRowCol(u8 Copy_u8Row , u8 Copy_u8Col )
{
	u8 Local_u8Address ;
	switch(Copy_u8Row)
	{
	case 0 :
		Local_u8Address = 0x00 + Copy_u8Col ; // first row address
		break ;
	case 1 :
		Local_u8Address = 0x40 + Copy_u8Col ; // second row address
		break ;
	}
	LCD_vidWriteCommand(0x80 | Local_u8Address ); // DDRAM address

}

void LCD_vidClearScreen(void)
{
	LCD_vidWriteCommand(LCD_u8_CLR_SCREEN_COMMAND);

}

static void LCD_SvidExecute(u8 Copy_u8DataCmd)
{

	DIO_vid_SetPinValue( LCD_u8_PIN_RW ,  DIO_u8_LOW ); // means write
	_delay_ms(1);
	DIO_vid_SetPinValue( LCD_u8_PIN_E ,  DIO_u8_HIGH);
	_delay_ms(1);
	DIO_vid_SetPORTValue(LCD_u8_PORT,Copy_u8DataCmd);
	_delay_ms(1);
	DIO_vid_SetPinValue( LCD_u8_PIN_E ,  DIO_u8_LOW);
	_delay_ms(1);


}

void LCD_vidCurserOff()
{
	LCD_vidWriteCommand(LCD_u8_CURSER_OFF_COMMAND);
}

void LCD_vidGoToLeft()
{
	LCD_vidWriteCommand(LCD_U8_SHIFT_LEFT_CURSER_COMMAND);
}

void LCD_vidGoToRight()
{
	LCD_vidWriteCommand(LCD_U8_SHIFT_Right_CURSER_COMMAND);
}
void LCD_vidSetFunction()
{
	LCD_vidWriteCommand(LCD_u8_FUNCTION_SET_COMMAND);
}

void LCD_vidReturn()
{
	LCD_vidWriteCommand(LCD_u8_RETURN_COMMAND);
}



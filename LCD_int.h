/************************************************/
/* Title       : LCD Interface file             */
/* Author      : Yahia Ahmed                    */
/* Release     : 1.0                            */
/* Last Update : Aug 16, 2021                   */
/************************************************/

#ifndef LCD_INT_H_
#define LCD_INT_H_


void LCD_vidInit(void);

void LCD_vidWriteCharacter(u8 Copy_u8data);

void LCD_vidWriteCommand(u8 Copy_u8cmd);

void LCD_vidWriteString(u8 * Copy_pString);

void LCD_vidGoToRowCol(u8 Copy_u8Row , u8 Copy_u8Col );

void LCD_vidClearScreen(void);

void LCD_vidGoToLeft();

void LCD_vidGoToRight();

void LCD_vidSetFunction();

void LCD_vidReturn();

void LCD_vidCurserOff();

#endif /* LCD_INT_H_ */

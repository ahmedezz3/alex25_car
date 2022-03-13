/*
 * lcd.c
 *
 * Created: 3/6/2022 11:11:10 PM
 *  Author: EL.EZZ
 */  
#include "lcd.h"

void init_LCD(void)
{
	LCD_cmd (0x38);
	_delay_ms(1);
	LCD_cmd (0x01);
	_delay_ms(1);
	LCD_cmd (0x02);
	_delay_ms(1);
	LCD_cmd (0x06);
	_delay_ms(1);
	LCD_cmd (0x80);
	_delay_ms(1);
}
void LCD_cmd (unsigned char cmd)
{
LCD_DATA = cmd;
PORTA &= ~(1<<rs);	
PORTA &= ~(1<<rw);	
PORTA |= (1<<en);
_delay_ms(2);
PORTA &= ~(1<<en);
}
void LCD_write(unsigned char data)
{
	LCD_DATA = data;
	PORTA |= (1<<rs);
	PORTA &= ~(1<<rw);
	PORTA |= (1<<en);
	_delay_ms(2);
	PORTA &= ~(1<<en);
	

}
/*
 * lcd.h
 *
 * Created: 3/6/2022 11:11:35 PM
 *  Author: EL.EZZ
 */ 


#ifndef LCD_H_
#define LCD_H_
#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#define LCD_DATA PORTB
#define en PA6
#define rw PA5
#define rs PA4
void init_LCD(void);
void LCD_cmd (unsigned char cmd);
void LCD_write(unsigned char data);
void LCD_str(char* str);



#endif /* LCD_H_ */
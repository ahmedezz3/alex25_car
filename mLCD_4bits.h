/* 
 * File:   mLCD_4bits.h
 * Author: hossa
 *
 * Created on December 3, 2021, 10:31 AM
 */


#ifndef MLCD_4BITS_H
#define	MLCD_4BITS_H

#define controlBits       _PB
#define controlBits_DIR   _PB

#define LCD_DATA          _PD
#define LCD_DATA_DIR      _PD
#define LCD_DATA_Half     PORTD

#define EN                0
#define RS                2
#define RW                1

void initLCD_4bits(void);
void LCD_write_4bits(char data);
void LCD_cmd_4bits(char cmd);

void LCD_str_4bits(char* str);
void LCD_num_4bits(int data);

void LCD_clear_4bits();
void LCD_goto_xy_4bits(int row, int coln);

void LCD_shiftRight_4bits(int);
void LCD_shiftLeft_4bits(int);

void LCD_EN_4bits();
#endif	/* MLCD_8BITS_H */


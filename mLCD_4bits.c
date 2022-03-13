
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
//#include "mLCD_8bits.h"
#include "mDIO.h"
#include "mLCD_4bits.h"
//#include "mLCD_8bits.h"
#include <stdlib.h>

void initLCD_4bits(void){
    
    // init DIO
    setPinOUT(LCD_DATA_DIR, 4);
    setPinOUT(LCD_DATA_DIR, 5);
    setPinOUT(LCD_DATA_DIR, 6);
    setPinOUT(LCD_DATA_DIR, 7);
//    DDRD |= 0xF0;
    _delay_ms(50);
    setPinOUT(controlBits_DIR, EN);
    setPinOUT(controlBits_DIR, RS);
    setPinOUT(controlBits_DIR, RW);
   
    // init LCD Controller
    resetPin(controlBits, RW); // Write Only
    
    LCD_clear_4bits();
    LCD_cmd_4bits(0x02); // 4-bits Mode
    LCD_cmd_4bits(0x28); // Two Line 
//    LCD_cmd_4bits(0x02); // Return Home
    LCD_cmd_4bits(0x06); // Entry mode
    LCD_cmd_4bits(0x80); // Force cursor to beginning of first line
    LCD_cmd_4bits(0x0C); // Display ON , Cursor OFF
    
    
    _delay_ms(50); //??????
    
}

void LCD_cmd_4bits(char cmd){
    resetPin(controlBits, RS);
    LCD_DATA_Half = (LCD_DATA_Half & 0x0F)|(cmd & 0xF0);
    LCD_EN_4bits();
    _delay_us(10);
    LCD_DATA_Half = (LCD_DATA_Half & 0x0F)|(cmd << 4);
    LCD_EN_4bits();
    _delay_us(10);
}

void LCD_write_4bits(char data){
    setPin(controlBits, RS);
    LCD_DATA_Half = (LCD_DATA_Half & 0x0F)|(data & 0xF0);
    LCD_EN_4bits();
    _delay_us(10);
    LCD_DATA_Half = (LCD_DATA_Half & 0x0F)|(data << 4);
    LCD_EN_4bits();
    _delay_us(10);
}

void LCD_EN_4bits(){
    setPin(controlBits, EN);
    _delay_ms(1);
    resetPin(controlBits, EN);
}

void LCD_clear_4bits(){
    LCD_cmd_4bits(0x01);
}

void LCD_str_4bits(char* str){
    for(int i=0 ; str[i]!= '\0' ; i++){
        LCD_write_4bits(str[i]);
    }
}

void LCD_num_4bits(int data){
    
    char buffer[11];
    itoa(data , buffer , 10);
    LCD_str_4bits(buffer);
           
    
}

void LCD_goto_xy_4bits(int row, int coln){
    if(row == 0){
            LCD_cmd_4bits(0x80 | coln);

    }
    else if(row == 1){
            LCD_cmd_4bits(0xC0 | coln);
    }
    else{
        
    }
}

void LCD_shiftRight_4bits(int shifts){
    for(int i =0 ; i < shifts; i++){
        LCD_cmd_4bits(0x18);
        _delay_ms(500);
    }
}
void LCD_shiftLeft_4bits(int shifts){
    for(int i =0 ; i < shifts; i++){
        LCD_cmd_4bits(0x1C);
        _delay_ms(500);

    }
}
/*
 * GccApplication1.c
 *
 * Created: 3/6/2022 9:57:37 PM
 * Author : EL.EZZ
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
unsigned char USART_DATA;
#include "lcd.h"


ISR(USART_RXC_vect)
{
    USART_DATA = UDR;
    switch (USART_DATA)
    {
        case 'R':
            PORTC |= (1 << 0) | (1 << 3);
            PORTC &= ~((1 << 1) | (1 << 2));
            OCR1B = 5000;
            OCR1A = 5000;
			LCD_write('R');
            break;
        case 'L':
            PORTC |= (1 << 1) | (1 << 2);
            PORTC &= ~((1 << 0) | (1 << 3));
            OCR1B = 5000;
            OCR1A = 5000;
			LCD_write('L');
            break;
        case 'm':
            PORTC |= (1 << 1) | (1 << 0) | (1 << 2) | (1 << 3);
            OCR1B = 0;
            OCR1A = 0;
			LCD_write('0');
            break;
        case 'f':
            PORTC |= (1 << 0) | (1 << 2);
            PORTC &= ~((1 << 1) | (1 << 3));
            OCR1B = 5000;
            OCR1A = 5000; 
			LCD_write('f');
            break;
        case 'b':
            PORTC |= (1 << 1) | (1 << 3);
            PORTC &= ~((1 << 0) | (1 << 2));
            OCR1B = 5000;
            OCR1A = 5000;
			LCD_write('b');
            break;
        case 's':
            PORTC |= (1 << 1) | (1 << 0) | (1 << 2) | (1 << 3);
            OCR1B = 5000;
            OCR1A = 5000;
            LCD_write('s');
			break;
        default:
            PORTA = 0x00;
    }    
}

int main(void) 
{
    DDRA = 0xff;
    DDRC = 0xff;
    DDRD |= (1 << 4) | (1 << 5);
    UCSRC |= (1 << URSEL) | (1 << UCSZ1) | (1 << UCSZ0);
    UBRRL = 103;
    UCSRB |= (1 << RXEN) | (1 << RXCIE);
    ICR1 = 10000;
    OCR1A = ICR1;
    OCR1B = ICR1;
    TCCR1A |= (1 << COM1A1) | (1 << COM1A0) |  (1 << COM1B1) | (1 << COM1B0) | (1 << WGM11);
    TCCR1B |= (1 << WGM12) | (1 << WGM13) | (1 << CS11);
    sei();
	init_LCD();
	{
    while(1)
    {
        
    }
    return 0;

	}
}


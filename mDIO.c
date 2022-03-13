#include <avr/io.h>
#include "mDIO.h"

// Direction

void setPortOUT(int PORT_No) {
    switch (PORT_No) {
        case _PA:
            DDRA = 0xFF;
            break;

        case _PB:
            DDRB = 0xFF;
            break;

        case _PC:
            DDRC = 0xFF;
            break;

        case _PD:
            DDRD = 0xFF;
            break;

    }
}

void setPortIN(int PORT_No) {
    switch (PORT_No) {
        case _PA:
            DDRA = 0x00;
            break;

        case _PB:
            DDRB = 0x00;
            break;

        case _PC:
            DDRC = 0x00;
            break;

        case _PD:
            DDRD = 0x00;
            break;

    }
}

void setPinOUT(int PORT_No, int PIN_No) {
    switch (PORT_No) {
        case _PA:
            DDRA |= (1 << PIN_No);
            break;

        case _PB:
            DDRB |= (1 << PIN_No);
            break;

        case _PC:
            DDRC |= (1 << PIN_No);
            break;

        case _PD:
            DDRD |= (1 << PIN_No);
            break;

    }
}

void setPinIN(int PORT_No, int PIN_No) {
    switch (PORT_No) {
        case _PA:
            DDRA &= ~(1 << PIN_No);
            break;

        case _PB:
            DDRB &= ~(1 << PIN_No);
            break;

        case _PC:
            DDRC &= ~(1 << PIN_No);
            break;

        case _PD:
            DDRD &= ~(1 << PIN_No);
            break;

    }
}

void setPin(int PORT_No, int PIN_No) {
    switch (PORT_No) {
        case _PA:
            PORTA |= (1 << PIN_No);
            break;

        case _PB:
            PORTB |= (1 << PIN_No);
            break;

        case _PC:
            PORTC |= (1 << PIN_No);
            break;

        case _PD:
            PORTD |= (1 << PIN_No);
            break;

    }
}

void resetPin(int PORT_No, int PIN_No) {
    switch (PORT_No) {
        case _PA:
            PORTA &= ~(1 << PIN_No);
            break;

        case _PB:
            PORTB &= ~(1 << PIN_No);
            break;

        case _PC:
            PORTC &= ~(1 << PIN_No);
            break;

        case _PD:
            PORTD &= ~(1 << PIN_No);
            break;

    }
}



void setPortData(int PORT_No, unsigned char data){
     switch (PORT_No) {
        case _PA:
            PORTA = data;
            break;

        case _PB:
            PORTB = data;
            break;

        case _PC:
            PORTC = data;
            break;

        case _PD:
            PORTD = data;
            break;

    }
}
void togglePortData(int PORT_No){
     switch (PORT_No) {
        case _PA:
            PORTA ^= 0xFF;
            break;  
        case _PB:
            PORTB ^= 0xFF;
            break;
        case _PC:
            PORTC ^= 0xFF;
            break;
        case _PD:
            PORTD ^= 0xFF;
            break;
    }
}
    
                                                  
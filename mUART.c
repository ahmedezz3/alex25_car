

#include "config.h"

void init_UART(unsigned int BaudRate){
    
    // Configure BaudRate
    unsigned short res =  (F_CPU/16.0/BaudRate)-1;
    UBRRL = (char) res;
    UBRRH = (char) (res>>8);
    
    // Configuration for RXEN , TXEN
    UCSRB |= (1<<RXEN)|(1<<TXEN);
    
    // Enable Interrupt TX
    UCSRB |= (1<<RXCIE);
    
}



char UART_read(){
    //while(!(UCSRA & (1<<RXC)));
    return UDR;
}
void UART_send(char data){
    // Check UDR is Empty or Not!!
    while(!(UCSRA & (1<<UDRE)));
    
    UDR = data; 
}

void UART_str(char *str){
    for(int i =0 ; str[i]!='\0'; i++){
        UART_send(str[i]);
    }
}

void UART_NUM(int Num){
    char Buffer[11];
    itoa(Num, Buffer, 10);
    UART_str(Buffer);
}

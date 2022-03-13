/* 
 * File:   mUART.h
 * Author: hossa
 *
 * Created on December 25, 2021, 9:51 AM
 */

#ifndef MUART_H
#define	MUART_H


void init_UART(unsigned int BaudRate);

char UART_read();
void UART_send(char data);
void UART_str(char *str);
void UART_NUM(int Num);
#endif	/* MUART_H */


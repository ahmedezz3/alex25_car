#include <avr/io.h>

#include "config.h"

int main(void)
{
	 ADC_ConfigType adcconfig={AREF_INTERNAL_VREF,FCPU_16};
	ADC_init(&adcconfig);
	init_UART(4800);
    while (1) 
    {
		UART_send('R');
		UART_send(ADC_readChannel(0));
		_delay_ms(500);
		
		UART_send('L');
		UART_send(ADC_readChannel(1));
		_delay_ms(500);

        UART_send('m');
       UART_send(ADC_readChannel(2));
       _delay_ms(500);

		UART_send('f');
		UART_send(ADC_readChannel(3));
		_delay_ms(500);

		UART_send('b');
		UART_send(ADC_readChannel(4));
		_delay_ms(500);
	
		UART_send('s');
		UART_send(ADC_readChannel(5));
		_delay_ms(500);

		
    }
	
}


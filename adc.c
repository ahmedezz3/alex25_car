
#include <avr/io.h>
#include "common_macros.h"
#include "std_types.h"
#include "adc.h"
void ADC_init(const ADC_ConfigType * Config_Ptr)
{

	ADMUX = ((Config_Ptr->ref_volt)<<6);

    CLEAR_BIT(ADCSRA,ADIE); 
    ADCSRA = (ADCSRA & 0XF8) | (Config_Ptr->prescaler);
    SET_BIT(ADCSRA,ADEN);

}

uint16 ADC_readChannel(uint8 Ch_num)
{
	uint16 data;
	ADMUX = (ADMUX & 0xF0) | Ch_num; 
    SET_BIT(ADCSRA,ADSC);
    while(BIT_IS_CLEAR(ADCSRA,ADIF));
    SET_BIT(ADCSRA,ADIF);  
    data = ADC;
    return data;

}

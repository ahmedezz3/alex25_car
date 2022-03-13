
#include <avr/io.h>
#include "mExternalINT.h"

void init_INT(char INT_no, unsigned char senseMode) {
    if (senseMode <= RisingMode) {
        switch (INT_no) {
            case INT0:
                MCUCR |= senseMode;
                break;
            case INT1:
                MCUCR |= (senseMode << 2);
                break;
            case INT2:
                MCUCSR |= ((senseMode == RisingMode ? 1 : 0) << ISC2);
                break;
        }
        // Enable Individual INT
        GICR |= (1 << INT_no);
    }
}

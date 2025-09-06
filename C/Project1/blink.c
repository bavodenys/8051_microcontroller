#include <8051.h>  

void delay(void) {
    unsigned int i, j;
    for (i = 0; i < 500; i++) {
        for (j = 0; j < 1000; j++) {
            // simple software delay
        }
    }
}

void main(void) {
    while (1) {
        P1 = 0xFF;   // Turn LEDs on (assuming LEDs on Port 1)
        delay();
        P1 = 0x00;   // Turn LEDs off
        delay();
    }
}

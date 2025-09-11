#include <8051.h>

#define BTN1 0x04   // P3.2 → K3
#define BTN2 0x08   // P3.3 → K4
#define BTN3 0x10   // P3.4 → K5
#define BTN4 0x20   // P3.5 → K6


#define LED1 0x01   // P1.0
#define LED2 0x02   // P1.1
#define LED3 0x04   // P1.2
#define LED4 0x08   // P1.3

void delay(unsigned int ms) {
    unsigned int i, j;
    for (i = 0; i < ms; i++)
        for (j = 0; j < 120; j++);
}

void main(void) {
    while(1) {
        // Button 1
        if ((P3 & BTN1) == 0) {
            P1 &= ~LED1;             
        } else {
            P1 |= LED1; 
        }
        // Button 2
        if ((P3 & BTN2) == 0) {
            P1 &= ~LED2;             
        } else {
            P1 |= LED2; 
        }
        // Button 3
        if ((P3 & BTN3) == 0) {
            P1 &= ~LED3;             
        } else {
            P1 |= LED3; 
        }
        // Button 4
        if ((P3 & BTN4) == 0) {
            P1 &= ~LED4;             
        } else {
            P1 |= LED4; 
        }

        delay(10); // simple debounce
    }
}

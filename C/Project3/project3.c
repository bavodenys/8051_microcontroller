#include <stdint.h>

// Remove the jumper J3

__sfr __at (0x80) P0;  // Segment lines (a–g, DP)
__sfr __at (0xA0) P2;  // T1–T4 digit select lines

const uint8_t num[10] = {0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};

void delay(unsigned int ms) {
    unsigned int i,j;
    for(i=0;i<ms;i++)
        for(j=0;j<600;j++);
}

// Display one digit on position 0–3 (T1–T4)
void display_digit(uint8_t digit, uint8_t position) {
    P0 = num[digit];           // Segment pattern
    P2 = ~(1 << position);     // Activate digit (T1–T4)
    delay(1);                  // Short delay for multiplexing
    P2 = 0xFF;                 // Turn off all digits
}

void main() {
    uint8_t digits[4] = {1,2,3,4};  // Example: display "1234"

    while(1) {
        for(uint16_t i=0;i<50;i++) {  // Repeat to keep display stable
            display_digit(digits[0], 0); // T1
            display_digit(digits[1], 1); // T2
            display_digit(digits[2], 2); // T3
            display_digit(digits[3], 3); // T4
        }
    }
}

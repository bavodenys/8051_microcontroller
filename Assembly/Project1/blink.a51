; blink.a51 - 8051 LED blink for SDCC / sdas8051
; Toggle P1.0 LED with delay

; Define SFRs and bits
P1      EQU 0x90       ; Port 1
P1_0    BIT 0x90       ; Bit 0 of Port 1


START:
    ; Turn LED ON
    SETB P1_0
    LCALL DELAY

    ; Turn LED OFF
    CLR P1_0
    LCALL DELAY

    SJMP START          ; Repeat forever

; Simple delay routine
DELAY:
    MOV R2,#0xFF
D1:
    MOV R1,#0xFF
D2:
    DJNZ R1,D2
    DJNZ R2,D1
    RET

# C Exercises
## Project 1
A simple project to learn how to setup my laptop, the 8051 development board. So that I'm ready for other projects. 
You find a guide on how to do this in this project. 

## Project 2
A simple project using the 4 buttons to control the leds

## Project 3
A project using the the segment LED display. Remove jumper J3. The segment are addressed

```
   a
  ---
f|   |b
  ---  <- g
e|   |c
  ---
   d    •DP

```


| Digit | Hex Code | Binary    | Segments ON (a–g, DP) |
|-------|----------|-----------|------------------------|
| 0     | 0xC0     | 1100 0000 | a, b, c, d, e, f      |
| 1     | 0xF9     | 1111 1001 | b, c                  |
| 2     | 0xA4     | 1010 0100 | a, b, d, e, g         |
| 3     | 0xB0     | 1011 0000 | a, b, c, d, g         |
| 4     | 0x99     | 1001 1001 | b, c, f, g            |
| 5     | 0x92     | 1001 0010 | a, c, d, f, g         |
| 6     | 0x82     | 1000 0010 | a, c, d, e, f, g      |
| 7     | 0xF8     | 1111 1000 | a, b, c               |
| 8     | 0x80     | 1000 0000 | a, b, c, d, e, f, g   |
| 9     | 0x90     | 1001 0000 | a, b, c, d, f, g      |





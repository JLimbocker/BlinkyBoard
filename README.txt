=========================================================
Blink

This library was written by Jeff Limbocker, Spring 2014.
Release Version 1.0
=========================================================

Notes:
=========================================================
This library is designed for use with the MSP430g2553 IC. 
Support for other MSP430 MCUs is not guaranteed.

Support for the analog breakout is not yet developed.



To use the library:
=========================================================
Include the library in your Energia Project:

#include "Blink.h"

Declare a Blink object:

Blink blinky;

Tell it to blink:

blinky.set(LED, COLOR);



Details:
=========================================================
Below is a summary of the public functions in the library:

    void set(int LED, int Color)
      This function allows the user to set the LED to one of seven input colors,
        R G B C Y M W, or Off 'O'
      The LED is selected by the number it is labeled by on the PCB.
      
    void chaser(int color)
      This function is a basic chaser pattern.  The color is provided as a parameter.
      
    void strobe(int color)
      This function is a basic strobe pattern.  The color is provided as a parameter.
      
    void SMU()
      This function blinks the LEDs in a diagonal Red/Blue pattern.
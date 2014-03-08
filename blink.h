#ifndef blink_h
#define blink_h

#include "msp430g2553.h"
#define O 0
#define R 1
#define Y 2
#define G 3
#define C 4
#define B 5
#define M 6
#define W 7
/*This library provides an easy to use interface for the SMU Innovation Gym Blinky Board.
  Author: Jeff Limbocker
  Date:   03/08/2014
  
  Summary:
    void set(int LED, int Color)
      This function allows the user to set the LED to one of seven input colors, R G B C Y M W, or Off 'O'
      The LED is selected by the number it is labeled by on the PCB.
      
    void chaser(int color)
      This function is a basic chaser pattern.  The color is provided as a parameter.
      
    void strobe(int color)
      This function is a basic strobe pattern.  The color is provided as a parameter.
      
    void SMU()
      This function blinks the LEDs in a diagonal Red/Blue pattern.
/*
Pinout:
LED2 B  2
     R  18
     G  19
LED4 B  5
     G  6
     R  7
Led3 B  8
     G  9
     R  10
LED1 R  11
     G  12
     B  13
*/
class Blink
{
  public:
    Blink();
    void init();    
    void set(int, int);
    void chaser(int);
    void strobe(int);
    void SMU();
  private:   
    void setLED1(int);
    void setLED2(int);
    void setLED3(int);
    void setLED4(int);    
};
#endif

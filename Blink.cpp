#include "Blink.h"
#include "Arduino.h"
Blink::Blink()
  {
    P1DIR |= 0xFF;
    P2DIR |= 0xFF;  
    P1SEL &= ~0xFF;
    P2SEL &= ~0xFF;  
    P1SEL2 &= ~0xFF;
    P2SEL2 &= ~0xFF;
    P1OUT &= ~0xFF;
    P2OUT &= ~0xFF;    
  }
  void Blink::init()
  {
    P1OUT &= ~0x00;
    P2OUT &= ~0x00;
  }
  void Blink::set(int LED, int color)
  {
    switch(LED)
    {
      case 1 : setLED1(color);
        break;
      case 2 : setLED2(color);
        break;
      case 3 : setLED3(color);
        break;
      case 4 : setLED4(color);
        break;
    }
  }
  void Blink::chaser(int color)
  {
    setLED1(color);
    delay(60);
    setLED1(0);
    setLED2(color);
    delay(60);
    setLED2(0);
    setLED4(color);
    delay(60);
    setLED4(0);
    setLED3(color);
    delay(60);
    setLED3(0);
  }
  void Blink::strobe(int color)
  {
    setLED1(color);
    setLED2(color);
    setLED3(color);
    setLED4(color);
    delay(60);
    setLED1(O);
    setLED2(O);
    setLED3(O);
    setLED4(O); 
    delay(120);
  }
  void Blink::SMU()
  {
    setLED1(R);
    setLED2(B);
    setLED3(B);
    setLED4(R);
    delay(150);
    setLED1(B);
    setLED2(R);
    setLED3(R);
    setLED4(B);
    delay(150);
  }
    
  void Blink::setLED4(int color)
  {
    switch(color)
    {
      case 0 : P1OUT &= ~0x38;  //Off
               break;
      case 1 : P1OUT &= ~0x38;  //Red
               P1OUT |= 0x20;
               break; 
      case 2 : P1OUT &= ~0x38; //Yellow
               P1OUT |= 0x30;
               break;
      case 3 : P1OUT &= ~0x38;  //Green
               P1OUT |= 0x10;
               break;
      case 4 : P1OUT &= ~0x38;
               P1OUT |= 0x18;  //Cyan
               break;
      case 5 : P1OUT &= ~0x38;
               P1OUT |= 0x08;  //Blue
               break;
      case 6 : P1OUT &= ~0x38;
               P1OUT |= 0x28;  //Magenta
               break;
      case 7 : P1OUT |= 0x38;
               break;
    }
  }

  void Blink::setLED2(int color)
  {
    switch(color)
    {
      case 0 : P1OUT &= ~0x01;  //Off
               P2OUT &= ~0xC0;
               break;
      case 1 : P1OUT &= ~0x01;  //RED
               P2OUT &= ~0xC0;
               P2OUT |= 0x80;
               break; 
      case 2 : P1OUT &= ~0x01;  
               P2OUT &= ~0xC0;//Yellow
               P2OUT |= 0xC0;
               break;
      case 3 : P1OUT &= ~0x01;  //Green
               P2OUT &= ~0xC0;
               P2OUT |= 0x40;
               break;
      case 4 : P1OUT &= ~0x01;  
               P2OUT &= ~0xC0; 
               P1OUT |= 0x01;  //Cyan
               P2OUT |= 0x40;
               break;
      case 5 : P1OUT &= ~0x01;  
               P2OUT &= ~0xC0;
               P1OUT |= 0x01;  //Blue
               break;
      case 6 : P1OUT &= ~0x01;  
               P2OUT &= ~0xC0;
               P1OUT |= 0x01;  //Magenta
               P2OUT |= 0x80;
               break;
      case 7 : P1OUT |= 0x01;
               P2OUT |= 0xC0;
               break;
    }
  }

  void Blink::setLED3(int color)
  {
    switch(color)
    {
      case 0 : P2OUT &= ~0x07;  //Off
               break;
      case 1 : P2OUT &= ~0x07;  //Red
               P2OUT |= 0x04;
               break; 
      case 2 : P2OUT &= ~0x07; //Yellow
               P2OUT |= 0x06;
               break;
      case 3 : P2OUT &= ~0x07;  //Green
               P2OUT |= 0x02;
               break;
      case 4 : P2OUT &= ~0x07;
               P2OUT |= 0x03;  //Cyan
               break;
      case 5 : P2OUT &= ~0x07;
               P2OUT |= 0x01;  //Blue
               break;
      case 6 : P2OUT &= ~0x07;
               P2OUT |= 0x05;  //Magenta
               break;
      case 7 : P2OUT |= 0x07;  //White
               break;
    }
  }


  void Blink::setLED1(int color)
  {
    switch(color)
    {
      case 0 : P2OUT &= ~0x38;  //Off
               break;
      case 1 : P2OUT &= ~0x38;  //Red
               P2OUT |= 0x08; 
               break; 
      case 2 : P2OUT &= ~0x38; //Yellow
               P2OUT |= 0x18;
               break;
      case 3 : P2OUT &= ~0x38;  //Green
               P2OUT |= 0x10;
               break;
      case 4 : P2OUT &= ~0x38;
               P2OUT |= 0x30;  //Cyan
               break;
      case 5 : P2OUT &= ~0x38;
               P2OUT |= 0x20; //Blue
               break;
      case 6 : P2OUT &= ~0x38;
               P2OUT |= 0x28;  //Magenta
               break;
      case 7 : P2OUT |= 0x38;
               break;
    }
  }

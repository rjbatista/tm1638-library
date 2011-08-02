#include "TM1638.h"

unsigned char hello[] = { 
  0b00000000, 0b01110110, 0b01111001, 0b00111000, 0b00111000, 0b00111111, 0b00000000, 0b00000000
};

TM1638 module1(2, 3, 4);
TM1638 module2(2, 3, 5);

unsigned long value = 87654321L;

void setup()
{  
  module1.setDisplay(helloLCD);	  
  module2.setDisplay(helloLCD);	  
 
  module1.setLEDs(0b00011111 | 0b11111000 << 8);

  module2.setLED(TM1638_COLOR_RED, 3);
  module2.setLED(TM1638_COLOR_GREEN, 5);
  module2.setLED(TM1638_COLOR_RED | TM1638_COLOR_GREEN, 7);
}


void loop()
{
  byte key1, key2;

  key1 = module1.getButtons();
  key2 = module2.getButtons();

  // both pressed
  if (key1 != 0 && key2 != 0) {
    value = 0;

    module1.setDisplayToHexNumber(value, 0b10101010);
    module2.setDisplayToDecNumber(value, 0b01010101);
  } else {
    if (key1 != 0) {
      value += key1;
  
      module2.setDisplayToBinNumber(key1, 0);

      module1.setLEDs(key1);
    }

    if (key2 != 0) {
      value += key2;
  
      module1.setDisplayToHexNumber(value, 0b10101010);
      module2.setDisplayToDecNumber(value, 0b01010101);

      module2.setLEDs(key2 << 8);
    }
  }
}


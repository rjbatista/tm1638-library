/*
Library examples for TM1638.

Copyright (C) 2011 Ricardo Batista <rjbatista at gmail dot com>

This program is free software: you can redistribute it and/or modify
it under the terms of the version 3 GNU General Public License as
published by the Free Software Foundation.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "TM1638.h"

// hello segments for display
const byte hello[] = {
  0b00000000, 0b01110110, 0b01111001, 0b00111000, 0b00111000, 0b00111111, 0b00000000, 0b00000000
};

// define the first module
TM1638 module1(8, 9, 7);
// to chain modules, use the same clk and data - just specify a different strobe pin
TM1638 module2(8, 9, 6);

unsigned long value = 0L;
boolean state = true;

void setup()
{
  // display the hello segments on module 1
  module1.setDisplay(hello);	
  // display the hello segments on module 2
  module2.setDisplay(hello);	

  // light the lower 5 red LEDs and the top 5 green LEDs
  module1.setLEDs(0b00011111 | 0b11111000 << 8);

  // light the 3rd red LED
  module2.setLED(TM1638_COLOR_RED, 3);
  // light the 5th green LED
  module2.setLED(TM1638_COLOR_GREEN, 5);
  // light the 7th red and green LEDs
  module2.setLED(TM1638_COLOR_RED | TM1638_COLOR_GREEN, 7);
}

void loop()
{
  byte key1, key2;

  // read the buttons from the first module
  key1 = module1.getButtons();
  // read the buttons from the second module
  key2 = module2.getButtons();

  // both pressed
  if (key1 != 0 && key2 != 0) {
    value = 0;

	// set the display to 0 on both modules if they have buttons pressed simultaneously
    module1.setDisplayToHexNumber(value, 0b10101010);
    module2.setDisplayToDecNumber(value, 0b01010101);
  } else {
	// check the first module buttons
    if (key1 != 0) {
      // show the pressed buttons of the first module on its display
      module2.setDisplayToBinNumber(key1, 0);
      // and on the LEDs
      module1.setLEDs(key1);

	  // check to see if it's the last button pressed
      if (key1 & 128) {
      	// toggle the display state on/off
        state = !state;
        delay(200); // just wait for button up
      }

	  // set the intensity and display state
      module1.setupDisplay(state, key1 >> 1);
    }

	// check the second module buttons
    if (key2 != 0) {
      // just add it to the display value
      value += key2;

      // display it as an hexadecimal on the first module
      module1.setDisplayToHexNumber(value, 0b10101010);
      // and as a decimal on the second module
      module2.setDisplayToDecNumber(value, 0b01010101);

	  // light the LEDs
      module2.setLEDs(key2 << 8);
    }
  }
}

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

#include <TM1638.h>
#include <InvertedTM1638.h>

#define NO_MODULES  2

// define a regular module and a inverted module
TM1638 module1(3, 2, 4);
InvertedTM1638 module2(3, 2, 5);
TM1638* modules[NO_MODULES] = {
  &module1,
  &module2
};
byte modes[NO_MODULES];

unsigned long startTime;

void setup() {
  startTime = millis();
  
  for (int i = 0; i < NO_MODULES; i++) {
    modules[i]->setupDisplay(true, 7);
    modes[i] = 0;
  }
}

void update(TM1638* module, byte* mode) {
  byte buttons = module->getButtons();
  unsigned long runningSecs = (millis() - startTime) / 1000;
  
  // button pressed - change mode
  if (buttons != 0) {
    *mode = buttons >> 1;
    module->clearDisplay();
    module->setLEDs(0);
  }

  switch (*mode) {
    case 0:
      module->setDisplayToDecNumber(runningSecs, 1 << 7);
      break;
    case 1:
      module->setDisplayToDecNumber(runningSecs, 1 << 6, false);
      break;
    case 2:
      module->setDisplayToHexNumber(runningSecs, 1 << 5);
      break;
    case 4:
      module->setDisplayToHexNumber(runningSecs, 1 << 4, false);
      break;
    case 8:
      module->setDisplayToBinNumber(runningSecs, 1 << 3);
      break;
    case 16:
      module->clearDisplayDigit((runningSecs - 1) % 8, 0);
      module->setDisplayDigit(runningSecs % 8, runningSecs % 8, 0);
      break;
    case 32:
      char s[8];
      sprintf(s, "Secs %03d", runningSecs % 999);
      module->setDisplayToString(s);
      break;
    case 64:
      if (runningSecs % 2 == 0) {
        module->setDisplayToString("TM1638  ");
      } else {
        module->setDisplayToString("LIBRARY ");
      }

      module->setLED(0, (runningSecs - 1) % 8);
      module->setLED(1 + runningSecs % 3, runningSecs % 8);
      break;
    case 65:
      module->setDisplayToError();
      break;

  }
}

void loop() {
  for (int i = 0; i < NO_MODULES; i++) {
    update(modules[i], &modes[i]);
  }
}


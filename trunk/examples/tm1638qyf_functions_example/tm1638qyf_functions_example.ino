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
#include <TM1638QYF.h>

TM1638QYF module(3, 2, 5);
word mode;

unsigned long startTime;

void setup() {
  startTime = millis();

  module.setupDisplay(true, 7);
  mode = 0;
}

void update(TM1638QYF* module, word* mode) {
  word buttons = module->getButtons();
  unsigned long runningSecs = (millis() - startTime) / 1000;

  // button pressed - change mode
  if (buttons != 0) {
    *mode = buttons >> 1;

    if (*mode < 128) {
      module->clearDisplay();
      delay(100);
    }
  }

  switch (*mode) {
    case 0:
      module->setDisplayToDecNumber(runningSecs, 1 << 6);
      break;
    case 1:
      module->setDisplayToDecNumber(runningSecs, 1 << 5, false);
      break;
    case 2:
      module->setDisplayToHexNumber(runningSecs, 1 << 4);
      break;
    case 4:
      module->setDisplayToHexNumber(runningSecs, 1 << 3, false);
      break;
    case 8:
      module->setDisplayToBinNumber(runningSecs, 1 << 2);
      break;
    case 16:
      char s[9];
      sprintf(s, "Secs %03d", runningSecs % 999);
      module->setDisplayToString(s, 1 << 1);
      break;
    case 32:
      if (runningSecs % 2 == 0) {
        module->setDisplayToString("TM1638QY", 1);
      } else {
        module->setDisplayToString(String("LIBRARY "), 1);
      }

      break;
    case 64:
      module->setDisplayToError();
      break;
    case 128:
      module->setDisplayToDecNumber(*mode, 0);
      break;
    case 256:
      module->setDisplayToString("ABCDE", 1 << (runningSecs % 8));
      break;
    default:
      module->setDisplayToBinNumber(buttons & 0xF, buttons >> 8);
  }
}

void loop() {
  update(&module, &mode);
}

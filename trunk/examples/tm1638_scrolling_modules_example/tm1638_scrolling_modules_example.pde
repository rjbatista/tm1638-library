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

#define MODULES 4

// define a modules
TM1638 modules[] = {
	TM1638(8, 9, 7),
	TM1638(8, 9, 6),
	TM1638(8, 9, 5),
	TM1638(8, 9, 4)
};

void setup() {
}

const char string[] = "       SEE LIBRARY PROJECT AT CODE.GOOGLE.COM        ";
int base = 0;

void loop() {
  for (int i = 0; i < MODULES; i++) {
    const char* pos = string + base + (i * 8);

    if (pos >= string && pos + 8 < string + sizeof(string)) {
      modules[i].setDisplayToString(pos);
    } else {
      modules[i].clearDisplay();
    }
  }

  base++;

  if (base == sizeof(string) - 8) {
    base = -MODULES * 8;
  }

  delay(100);
}


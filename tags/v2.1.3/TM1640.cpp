/*
TM1640.cpp - Library implementation for TM1640.

Copyright (C) 2011 Ricardo Batista (rjbatista <at> gmail <dot> com)

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

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#include "TM1640.h"
#include "string.h"


TM1640::TM1640(byte dataPin, byte clockPin, boolean activateDisplay, byte intensity)
	: TM16XX(dataPin, clockPin, dataPin, 16, activateDisplay, intensity)
{
  // nothing else to do - calling super is enough
}

void TM1640::sendChar(byte pos, byte data, boolean dot)
{
  sendData(pos, data | (dot ? 0b10000000 : 0));
  
  // necessary for the TM1640
  digitalWrite(strobePin, LOW);
  digitalWrite(clockPin, LOW);
  digitalWrite(clockPin, HIGH);
  digitalWrite(strobePin, HIGH);
}

void TM1640::clearDisplay()
{
  digitalWrite(strobePin, LOW);
  send(0xC0);
  for (int i = 0; i < 16; i++) {
    send(0x00);
  }
  digitalWrite(strobePin, HIGH);
}

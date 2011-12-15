/*
TM1638.cpp - Library implementation for TM1638.

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

#include "TM1638.h"
#include "string.h"

TM1638::TM1638(byte dataPin, byte clockPin, byte strobePin, boolean activateDisplay, byte intensity)
{
  this->dataPin = dataPin;
  this->clockPin = clockPin;
  this->strobePin = strobePin;

  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(strobePin, OUTPUT);

  digitalWrite(strobePin, HIGH);
  digitalWrite(clockPin, HIGH);

  sendCommand(0x40);
  sendCommand(0x80 | (activateDisplay ? 8 : 0) | min(7, intensity));

  digitalWrite(strobePin, LOW);
  send(0xC0);
  for (int i = 0; i < 16; i++) {
    send(0x00);
  }
  digitalWrite(strobePin, HIGH);
}

void TM1638::setupDisplay(boolean active, byte intensity)
{
  sendCommand(0x80 | (active ? 8 : 0) | min(7, intensity));
}

void TM1638::setDisplayToHexNumber(unsigned long number, byte dots, boolean leadingZeros,
	const byte numberFont[])
{
  for (int i = 0; i < 8; i++) {
	if (!leadingZeros && number == 0) {
		clearDisplayDigit(7 - i, (dots & (1 << i)) != 0);
	} else {
		setDisplayDigit(number & 0xF, 7 - i, (dots & (1 << i)) != 0, numberFont);
		number >>= 4;
    }
  }
}

void TM1638::setDisplayToDecNumber(unsigned long number, byte dots, boolean leadingZeros,
	const byte numberFont[])
{
  if (number > 99999999L) {
    setDisplayToError();
  } else {
    for (int i = 0; i < 8; i++) {
      if (number != 0) {
        setDisplayDigit(number % 10, 7 - i, (dots & (1 << i)) != 0, numberFont);
        number /= 10;
      } else {
		  if (leadingZeros) {
		  setDisplayDigit(0, 7 - i, (dots & (1 << i)) != 0, numberFont);
		} else {
		  clearDisplayDigit(7 - i, (dots & (1 << i)) != 0);
		}
      }
    }
  }
}

void TM1638::setDisplayToBinNumber(byte number, byte dots, const byte numberFont[])
{
  for (int i = 0; i < 8; i++) {
    setDisplayDigit((number & (1 << i)) == 0 ? 0 : 1, 7 - i, (dots & (1 << i)) != 0, numberFont);
  }
}

void TM1638::setDisplayDigit(byte digit, byte pos, boolean dot, const byte numberFont[])
{
  sendChar(pos, numberFont[digit & 0xF], dot);
}

void TM1638::setDisplayToError()
{
    setDisplay(ERROR_DATA);
}

void TM1638::clearDisplayDigit(byte pos, boolean dot)
{
  sendChar(pos, 0, dot);
}

void TM1638::setDisplay(const byte values[])
{
  for (int i = 0; i < 8; i++) {
    sendChar(i, values[i], 0);
  }
}

void TM1638::clearDisplay()
{
  for (int i = 0; i < 8; i++) {
    sendData(i << 1, 0);
  }
}

void TM1638::setDisplayToString(const char* string, const byte dots, const byte pos, const byte font[])
{
  for (int i = 0; i < 8 - pos; i++) {
  	if (string[i] != '\0') {
	  sendChar(i + pos, font[string[i] - 32], dots & (1 << (7 - i)));
	} else {
	  break;
	}
  }
}

void TM1638::setDisplayToString(const String string, const byte dots, const byte pos, const byte font[])
{
  int stringLength = string.length();

  for (int i = 0; i < 8 - pos; i++) {
    if (i < stringLength) {
      sendChar(i + pos, font[string.charAt(i) - 32], dots & (1 << (7 - i)));
    } else {
      break;
    }
  }
}

void TM1638::setLED(byte color, byte pos)
{
    sendData((pos << 1) + 1, color);
}

void TM1638::setLEDs(word leds)
{
  for (int i = 0; i < 8; i++) {
    byte color = 0;

    if (leds & (1 << i)) {
      color |= TM1638_COLOR_RED;
    }

    if (leds & (1 << (i + 8))) {
      color |= TM1638_COLOR_GREEN;
    }

    setLED(color, i);
  }
}

byte TM1638::getButtons(void)
{
  byte keys = 0;

  digitalWrite(strobePin, LOW);
  send(0x42);
  for (int i = 0; i < 4; i++) {
    keys |= receive() << i;
  }
  digitalWrite(strobePin, HIGH);

  return keys;
}

void TM1638::sendChar(byte pos, byte data, boolean dot)
{
	sendData(pos << 1, data | (dot ? 0b10000000 : 0));
}

void TM1638::sendCommand(byte cmd)
{
  digitalWrite(strobePin, LOW);
  send(cmd);
  digitalWrite(strobePin, HIGH);
}

void TM1638::sendData(byte add, byte data)
{
  sendCommand(0x44);
  digitalWrite(strobePin, LOW);
  send(0xc0 | add);
  send(data);
  digitalWrite(strobePin, HIGH);
}

void TM1638::send(byte data)
{
  for (int i = 0; i < 8; i++) {
    digitalWrite(clockPin, LOW);
    digitalWrite(dataPin, data & 1 ? HIGH : LOW);
    data >>= 1;
    digitalWrite(clockPin, HIGH);
  }
}

byte TM1638::receive()
{
  byte temp = 0;

  // Pull-up on
  pinMode(dataPin, INPUT);
  digitalWrite(dataPin, HIGH);

  for (int i = 0; i < 8; i++) {
    temp >>= 1;

    digitalWrite(clockPin, LOW);

    if (digitalRead(dataPin)) {
      temp |= 0x80;
    }

    digitalWrite(clockPin, HIGH);
  }

  // Pull-up off
  pinMode(dataPin, OUTPUT);
  digitalWrite(dataPin, LOW);

  return temp;
}

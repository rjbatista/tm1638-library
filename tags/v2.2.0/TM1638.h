/*
TM1638.h - Library for TM1638.

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

#ifndef TM1638_h
#define TM1638_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#include "TM16XX.h"
#include "TM16XXFonts.h"

#define TM1638_COLOR_NONE   0
#define TM1638_COLOR_RED    1
#define TM1638_COLOR_GREEN  2

class TM1638 : public TM16XX
{
  public:
    /** Instantiate a tm1638 module specifying the display state, the starting intensity (0-7) data, clock and stobe pins. */
    TM1638(byte dataPin, byte clockPin, byte strobePin, boolean activateDisplay = true, byte intensity = 7);

    /** Set the display to a unsigned hexadecimal number (with or without leading zeros) */
    void setDisplayToHexNumber(unsigned long number, byte dots, boolean leadingZeros = true,
		const byte numberFont[] = NUMBER_FONT);
    /** Set the display to a unsigned decimal number (with or without leading zeros) */
    void setDisplayToDecNumber(unsigned long number, byte dots, boolean leadingZeros = true,
		const byte numberFont[] = NUMBER_FONT);
    /** Set the display to a signed decimal number (with or without leading zeros) */
    void setDisplayToSignedDecNumber(signed long number, byte dots, boolean leadingZeros = true,
		const byte numberFont[] = NUMBER_FONT);
    /** Set the display to a unsigned binary number */
    void setDisplayToBinNumber(byte number, byte dots,
		const byte numberFont[] = NUMBER_FONT);

    /** Set the LED at pos to color (TM1638_COLOR_RED, TM1638_COLOR_GREEN or both) */
    virtual void setLED(byte color, byte pos);
    /** Set the LEDs. MSB byte for the green LEDs, LSB for the red LEDs */
    void setLEDs(word led);

    /** Returns the pressed buttons as a bit set (left to right). */
    virtual byte getButtons();

  protected:
    virtual void sendChar(byte pos, byte data, boolean dot);
    void setDisplayToDecNumberAt(unsigned long number, byte dots, byte startingPos,
    	boolean leadingZeros, const byte numberFont[]);
};

#endif

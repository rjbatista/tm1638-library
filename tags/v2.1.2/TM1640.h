/*
TM1640.h - Library for TM1640.

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

#ifndef TM1640_h
#define TM1640_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#include "TM16XX.h"
#include "TM16XXFonts.h"

class TM1640 : public TM16XX
{
  public:
	/** Instantiate a tm1640 module specifying the display state, the starting intensity (0-7) data and clock pins. */
  	TM1640(byte dataPin, byte clockPin, boolean activateDisplay = true, byte intensity = 7);
    /** Clear the display */
	virtual void clearDisplay();

  protected:
    virtual void sendChar(byte pos, byte data, boolean dot);
};

#endif

/*
Library examples for TM1640.

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
#include <TM1638.h> // required because the way arduino deals with libraries
#include <TM1640.h>

// define a module on data pin 3, clock pin 2
TM1640 module(3, 2);

void setup()
{
  // nothing to do here
}

void loop()
{
  char text[17];

  sprintf(text, "testing %u", millis());

  module.setDisplayToString(text);
}

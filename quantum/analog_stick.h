/*
Copyright 2018 Rob Rogers <r2d2rogers+qmk@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef ANALOG_STICK_H
#define ANALOG_STICK_H

uint16_t analogX;
uint16_t analogY;
bool buttonPressed;
uint16_t analogValue;
int16_t axis_value;
uint8_t deadzone;

void analog_stick_init(void);
uint16_t readaxis(uint8_t analogPin);
int8_t parseaxis(uint16_t analogValue);

#endif

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

#include <stdint.h>
#include <stdbool.h>
#include "analog.h"
#include "analog_stick.h"

uint16_t analogX;
uint16_t analogY;
bool buttonPressed;

int16_t readaxis(uint16_t analog_pin){
  int16_t axis_value = (analogRead(analog_pin) - 512);
  uint8_t deadzone = ANALOG_DEADZONE;
  if(axis_value < 0){
    if(axis_value < - deadzone ){
      return axis_value + deadzone;
    }else{
      return 0;
    }
  }else if(axis_value > 0){
    if(axis_value > deadzone ){
      return axis_value - deadzone;
    }else{
      return 0;
    }
  }
  return 0;
}

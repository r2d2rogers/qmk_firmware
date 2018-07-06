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

#include "analog_stick.h"

int8_t readaxis(uint16_t analogValue){
  int8_t axisValue = ((analogValue - 16) >> 5) - 15;
  uint8_t deadzone = ANALOG_DEADZONE;
  if(axisValue < 0){
    if(axisValue < - deadzone ){
      return axisValue + deadzone;
    }else{
      return 0;
    }
  }else if(axisValue > 0){
    if(axisValue > deadzone ){
      return axisValue - deadzone;
    }else{
      return 0;
    }
  }
  return 0;
}


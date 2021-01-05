/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

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

#pragma once

//#define USE_MATRIX_I2C

/* Select hand configuration */

// #define MASTER_LEFT
// #define MASTER_RIGHT
#define EE_HANDS

#define USE_SERIAL_PD2

#ifdef OLED_DRIVER_ENABLE
    #define OLED_FONT_H "keyboards/crkbd/lib/glcdfont.c"
    //#define OLED_FONT_H "drivers/oled/glcdfont.c"
    //#define OLED_DISPLAY_128X32
    //#define OLED_TIMEOUT 300000
#endif

//#define TAPPING_FORCE_HOLD

#ifdef AUDIO_ENABLE
#define B5_AUDIO
//#define C6_AUDIO // Not open on crkbd
#define NO_MUSIC_MODE
#endif

#ifdef RGBLIGHT_ENABLE
#undef RGBLED_NUM
#define RGBLIGHT_ANIMATIONS
#define RGBLED_NUM 27
#define RGBLIGHT_LIMIT_VAL 120
#define RGBLIGHT_HUE_STEP 10
#define RGBLIGHT_SAT_STEP 17
#define RGBLIGHT_VAL_STEP 17
#endif

#ifdef RGB_MATRIX_ENABLE
#define RGBLED_SPLIT { 27, 27 }
#define RGB_MATRIX_KEYPRESSES
#endif

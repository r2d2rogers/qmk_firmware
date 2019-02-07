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

#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

#define SSD1306OLED

#define USE_SERIAL_PD2

#define TAPPING_FORCE_HOLD
#define TAPPING_TERM 100


#define ONESHOT_TAP_TOGGLE 2
#define ONESHOT_TIMEOUT 3000

#ifdef RGBLIGHT_ENABLE
#define RGBLIGHT_SLEEP

#undef RGBLIGHT_ANIMATIONS
//#define RGBLIGHT_EFFECT_BREATHING // 1972
//#define RGBLIGHT_EFFECT_SNAKE // 270
//#define RGBLIGHT_EFFECT_KNIGHT // 246
//#define RGBLIGHT_EFFECT_ALTERNATING // 180
#define RGBLIGHT_EFFECT_RAINBOW_SWIRL // 173
//#define RGBLIGHT_EFFECT_RGB_TEST // 132
#define RGBLIGHT_EFFECT_RAINBOW_MOOD // 126
//#define RGBLIGHT_EFFECT_CHRISTMAS // 120
#define RGBLIGHT_EFFECT_STATIC_GRADIENT // 0

#undef RGBLED_NUM
#define RGBLED_NUM 27

#define RGBLIGHT_LIMIT_VAL 120
#define RGBLIGHT_HUE_STEP 10
#define RGBLIGHT_SAT_STEP 17
#define RGBLIGHT_VAL_STEP 17

#endif // RGBLIGHT_ENABLE

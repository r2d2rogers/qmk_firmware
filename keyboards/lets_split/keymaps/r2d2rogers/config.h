/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert
Copyright 2017 Art Ortenburger

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

#ifndef CONFIG_USER_H
#define CONFIG_USER_H

#include QMK_KEYBOARD_CONFIG_H

#undef TAPPING_TERM
#define TAPPING_TERM 170

/* Use I2C or Serial, not both */

#undef USE_SERIAL
#define USE_I2C

/* Select hand configuration */

// #define MASTER_LEFT
// #define MASTER_RIGHT
#define EE_HANDS


/* key combination for command */
#ifdef IS_COMMAND
#undef IS_COMMAND
#endif
#define IS_COMMAND() ( \
    keyboard_report->mods == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_LALT)) \
)


#ifdef RGBLIGHT_ENABLE
//#define RGB_DI_PIN D3
#undef RGBLED_NUM
#define RGBLED_NUM 24
#define RGBLIGHT_ANIMATIONS
#endif

#ifdef RGBLIGHT_ANIMATIONS
#define RGBLIGHT_HUE_STEP 12
#define RGBLIGHT_SAT_STEP 12
#define RGBLIGHT_VAL_STEP 12
#define RGBLIGHT_EFFECT_KNIGHT_LENGTH 3
#define RGBLIGHT_EFFECT_KNIGHT_OFFSET 4
#define RGBLIGHT_EFFECT_KNIGHT_LED_NUM 16
#define RGBLIGHT_EFFECT_SNAKE_LENGTH 4
//#define RGBLIGHT_EFFECT_BREATHE_CENTER 1
#define RGBLIGHT_EFFECT_CHRISTMAS_INTERVAL 500
#define RGBLIGHT_EFFECT_CHRISTMAS_STEP 3
#endif

#ifdef AUDIO_ENABLE
//#define B5_AUDIO
#define C6_AUDIO
#ifdef RGBLIGHT_ENABLE
#define NO_MUSIC_MODE
#endif //RGBLIGHT_ENABLE
#endif //AUDIO_ENABLE

#undef PRODUCT
#ifdef KEYBOARD_lets_split_rev2
#define PRODUCT         r2d2rogers Hacked Lets Split Rev.2


#endif

#define QMK_ESC_OUTPUT D7 // usually COL
#define QMK_ESC_INPUT D4 // usually ROW
#define QMK_LED B0
#define QMK_SPEAKER C6


#define SHFT_LED1 5
#define SHFT_LED2 10

#define CTRL_LED1 6
#define CTRL_LED2 9

#define GUI_LED1 7
#define GUI_LED2 8

#ifdef RGB_MATRIX_ENABLE

#define DRIVER_ADDR_1 0b1110100
#define DRIVER_ADDR_2 0b1110110

#define DRIVER_COUNT 2
#define DRIVER_1_LED_TOTAL 18
#define DRIVER_2_LED_TOTAL 0

#define DRIVER_LED_TOTAL DRIVER_1_LED_TOTAL + DRIVER_2_LED_TOTAL
//#define DRIVER_LED_TOTAL DRIVER_1_LED_TOTAL

#endif

#ifdef ANALOG_STICK_ENABLE

#define ANALOG_X_PIN 3
#define ANALOG_Y_PIN 2
#define ANALOG_DEADZONE 2

//#define ANALOG_SEL_PIN 2

#endif

#endif

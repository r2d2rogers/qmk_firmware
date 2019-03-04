/*
This is the keymap for the keyboard

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

#include QMK_KEYBOARD_H
#include "r2d2rogers.h"
#include "eeconfig.h"
#ifdef AUDIO_ENABLE
#include "audio.h"
#endif

#ifdef INDICATOR_LIGHTS
extern userspace_config_t userspace_config;

uint8_t last_mod;
uint8_t last_led;
uint8_t last_osm;
#endif

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

enum custom_keycodes
{
  PLACEHOLDER = SAFE_RANGE, // can always be here
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_wrapper(
//┌────────┬────────┬────────┬────────┬────────┬────────┐                                                             ┌────────┬────────┬────────┬────────┬────────┬────────┐
    KC_TAB , _________________QWERTY_L1_________________,                                                               _________________QWERTY_R1_________________, KC_BSLS,
//├────────┼────────┼────────┼────────┼────────┼────────┤        ┌────────┬────────┐       ┌────────┬────────┐        ├────────┼────────┼────────┼────────┼────────┼────────┤
    KC_ESCC, _________________QWERTY_L2_________________,          ___________ORTHODOX_THUMP_TOP_____________,          _________________QWERTY_R2_________________, KC_QUOT,
//├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤       ├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
    KC_LSFT, _________________QWERTY_L3_________________, ___________________ORTHODOX_THUMB_BOTTOM____________________, _________________QWERTY_R3_________________, KC_RSFT
//└────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┘       └────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┘
  ),

  [_LOWER] = LAYOUT_wrapper(
//┌────────┬────────┬────────┬────────┬────────┬────────┐                                                             ┌────────┬────────┬────────┬────────┬────────┬────────┐
    KC_GRV , _________________LOWER_L1__________________,                                                               _________________LOWER_R1__________________, KC_BSPC,
//├────────┼────────┼────────┼────────┼────────┼────────┤        ┌────────┬────────┐       ┌────────┬────────┐        ├────────┼────────┼────────┼────────┼────────┼────────┤
    KC_F11 , _________________LOWER_L2__________________,          _______, _______,         _______, _______,          _________________LOWER_R2__________________, _______,
//├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤       ├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
    KC_F12 , _________________LOWER_L3__________________, _______, _______, _______,         _______, _______, _______, _________________LOWER_R3__________________, _______
//└────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┘       └────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┘
  ),

  [_RAISE] = LAYOUT_wrapper(
//┌────────┬────────┬────────┬────────┬────────┬────────┐                                                             ┌────────┬────────┬────────┬────────┬────────┬────────┐
    KC_TILD, _________________RAISE_L1__________________,                                                               _________________RAISE_R1__________________, KC_BSPC,
//├────────┼────────┼────────┼────────┼────────┼────────┤        ┌────────┬────────┐       ┌────────┬────────┐        ├────────┼────────┼────────┼────────┼────────┼────────┤
    _______, _________________RAISE_L2__________________,          _______, _______,         _______, _______,          _________________RAISE_R2__________________, KC_PIPE,
//├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤       ├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
    _______, _________________RAISE_L3__________________, _______, _______, _______,         _______, _______, _______, _________________RAISE_R3__________________, _______
//└────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┘       └────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┘
  ),

  [_SPACEFN] = LAYOUT_wrapper(
//┌────────┬────────┬────────┬────────┬────────┬────────┐                                                             ┌────────┬────────┬────────┬────────┬────────┬────────┐
    RESET  , ________________SPACEFN_L1_________________,                                                               ________________SPACEFN_R1_________________,  KC_DEL,
//├────────┼────────┼────────┼────────┼────────┼────────┤        ┌────────┬────────┐       ┌────────┬────────┐        ├────────┼────────┼────────┼────────┼────────┼────────┤
    EPRM   , ________________SPACEFN_L2_________________,          _______,   RESET,           RESET, _______,          ________________SPACEFN_R2_________________, _______,
//├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤       ├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
    _______, ________________SPACEFN_L3_________________, _______, _______, _______,         _______, _______, _______, ________________SPACEFN_R3_________________, _______
//└────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┘       └────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┘
  ),

  [_ADJUST] = LAYOUT_wrapper(
//┌────────┬────────┬────────┬────────┬────────┬────────┐                                                             ┌────────┬────────┬────────┬────────┬────────┬────────┐
    KC_MAKE, _________________ADJUST_L1_________________,                                                               _________________ADJUST_R1_________________,    USER,
//├────────┼────────┼────────┼────────┼────────┼────────┤        ┌────────┬────────┐       ┌────────┬────────┐        ├────────┼────────┼────────┼────────┼────────┼────────┤
    VRSN   , _________________ADJUST_L2_________________,          _______,   RESET,           RESET, _______,          _________________ADJUST_R2_________________,    EPRM,
//├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤       ├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
    VLK_TOG, _________________ADJUST_L3_________________, _______, _______, _______,         _______, _______, _______, _________________ADJUST_R3_________________, KC_MPLY
//└────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┘       └────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┘
  )
};


bool indicator_is_this_led_used(uint8_t index) {
  switch (index) {
#ifdef INDICATOR_LIGHTS
    case SHFT_LED1:
    case SHFT_LED2:
    case CTRL_LED1:
    case CTRL_LED2:
    case GUI_LED1:
    case GUI_LED2:
      return true;
      break;
#endif
    default:
    return false;
  }
}

// Runs just one time when the keyboard initializes.
void matrix_init_keymap(void){
    //debug_enable=true;
    //debug_matrix=true;
    //debug_keyboard=true;
};

// Runs constantly in the background, in a loop.
void matrix_scan_keymap(void)
{

  uint8_t layer = biton32(layer_state);

  switch (layer)
  {
  // TODO: Make this relevant to the ErgoDox EZ.
  case 0:
    break;
  case 1:
    break;
  case 2:
    break;
  case 3:
    break;
  case 4:
    break;
  case 5:
    break;
  case 6:
    break;
  default:
    break;
  }
}
bool process_record_keymap(uint16_t keycode, keyrecord_t *record)
{
  return true;
};

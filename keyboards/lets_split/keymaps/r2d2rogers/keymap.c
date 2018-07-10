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

#ifdef POINTING_DEVICE_ENABLE
#include "pointing_device.h"
#include "report.h"
#endif

#ifdef ANALOG_STICK_ENABLE
extern uint16_t analogX;
extern uint16_t analogY;
extern bool buttonPressed;

#include "analog_stick.h"
#include "analog.h"
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

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO


enum custom_keycodes
{
  PLACEHOLDER = SAFE_RANGE, // can always be here
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Layer 0: _QWERTY
     * ------------------------------------------------------     ------------------------------------------------------
     * |  TAB  ||   Q   ||   W   ||   E   ||   R   ||   T   |     |   Y   ||   U   ||   I   ||   O   ||   P   ||   \   |
     * ------------------------------------------------------     ------------------------------------------------------
     * |  ESCC || A/Flip||   S   ||   D   ||   F   || G/Flip|     | H/Flip||   J   ||   K   ||   L   ||   ;   || '/Flip|
     * ------------------------------------------------------     ------------------------------------------------------
     * | LSHIFT||   Z   ||   X   ||   C   ||   V   ||   B   |     |   N   ||   M   ||   ,   ||   .   ||   /   ||RSHIFT |
     * ------------------------------------------------------     ------------------------------------------------------
     * | GUI   ||  CTRL ||  ALT  ||  INS  || SPACE || LOWER |     | RAISE || SPACE ||  LEFT ||  DOWN ||  UP   || RIGHT |
     * ------------------------------------------------------     ------------------------------------------------------
     */

    [_QWERTY] =  LAYOUT_wrapper(
        KC_TAB,  _________________QWERTY_L1_________________,      _________________QWERTY_R1_________________, KC_BSLS,
        KC_ESCC, _________________QWERTY_L2_________________,      _________________QWERTY_R2_________________, SH_T(KC_QUOT),
        KC_LSFT, _________________QWERTY_L3_________________,      _________________QWERTY_R3_________________, RSFTENT,
                 ___________GENERAL_BOTTOM_LEFT_____________,      ___________GENERAL_BOTTOM_RIGHT____________        ),

    [_COLEMAK] =  LAYOUT_wrapper(
        KC_TAB,  _________________COLEMAK_L1________________,      _________________COLEMAK_R1________________, KC_BSLS,
        KC_ESCC, _________________COLEMAK_L2________________,      _________________COLEMAK_R2________________, KC_QUOT,
        KC_LSFT, _________________COLEMAK_L3________________,      _________________COLEMAK_R3________________, RSFTENT,
                 ___________GENERAL_BOTTOM_LEFT_____________,      ___________GENERAL_BOTTOM_RIGHT____________        ),

    [_DVORAK] =  LAYOUT_wrapper(
        KC_TAB,  _________________DVORAK_L1_________________,      _________________DVORAK_R1_________________, KC_BSLS,
        KC_ESCC, _________________DVORAK_L2_________________,      _________________DVORAK_R2_________________, KC_QUOT,
        KC_LSFT, _________________DVORAK_L3_________________,      _________________DVORAK_R3_________________, RSFTENT,
                 ___________GENERAL_BOTTOM_LEFT_____________,      ___________GENERAL_BOTTOM_RIGHT____________        ),

    [_WORKMAN] =  LAYOUT_wrapper(
        KC_TAB,  _________________WORKMAN_L1________________,      _________________WORKMAN_R1________________, KC_BSLS,
        KC_ESCC, _________________WORKMAN_L2________________,      _________________WORKMAN_R2________________, KC_QUOT,
        KC_LSFT, _________________WORKMAN_L3________________,      _________________WORKMAN_R3________________, RSFTENT,
                 ___________GENERAL_BOTTOM_LEFT_____________,      ___________GENERAL_BOTTOM_RIGHT____________        ),

    /* Layer 1: _RAISE
     * ------------------------------------------------------     ------------------------------------------------------
     * |   `   ||   1   ||   2   ||   3   ||   4   ||   5   |     |   6   ||   7   ||   8   ||   9   ||   0   ||       |
     * ------------------------------------------------------     ------------------------------------------------------
     * |       ||   4   ||   5   ||   6   ||   .   ||       |     |       ||   -   ||   =   ||   [   ||   ]   ||   \   |
     * ------------------------------------------------------     ------------------------------------------------------
     * |       ||   7   ||   8   ||   9   ||   0   ||       |     |       ||       ||       ||   .   ||       || DEBUG |
     * ------------------------------------------------------     ------------------------------------------------------
     * |       || HYPER ||       ||       ||       ||       |     |       ||       || PLYMT || VOLDN || VOLUP ||  MFFD |
     * ------------------------------------------------------     ------------------------------------------------------
     */

    [_RAISE] = LAYOUT(
        KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,      KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , _______,
        _______, KC_4   , KC_5   , KC_6   , KC_DOT , _______,      _______, KC_MINS, KC_EQL , KC_LBRC, KC_RBRC, KC_BSLS,
        _______, KC_7   , KC_8   , KC_9   , KC_0   , _______,      _______, _______, _______, KC_DOT , _______, DEBUG  ,
        _______, KC_HYPR, _______, _______, _______, _______,      _______, _______, KC_MPLY, KC_VOLD, KC_VOLU, KC_MFFD),

    /* Layer 2: _LOWER
     * ------------------------------------------------------     ------------------------------------------------------
     * |   ~   ||   !   ||   @   ||   #   ||   $   ||   %   |     |   ^   ||   &   ||   *   ||   (   ||   )   ||       |
     * ------------------------------------------------------     ------------------------------------------------------
     * |       ||  F1   ||  F2   ||  F3   ||  F4   ||  F5   |     |  F11  ||   _   ||   +   ||   {   ||   }   ||   |   |
     * ------------------------------------------------------     ------------------------------------------------------
     * |       ||  F6   ||  F7   ||  F8   ||  F9   ||  F10  |     |  F12  ||Secret1||Secret2||Secret3||Secret4||Secret5|
     * ------------------------------------------------------     ------------------------------------------------------
     * | 10KEY || HYPER ||       ||       ||       ||       |     |       ||       ||  HOME ||  PGDN ||  PGUP ||  END  |
     * ------------------------------------------------------     ------------------------------------------------------
     */

    [_LOWER] = LAYOUT_wrapper(
        KC_TILD, KC_EXLM, KC_AT,  KC_HASH,  KC_DLR,  KC_PERC,      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
        TKEY,    _________________FUNC_LEFT_________________,      KC_F11 , KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
      TG(MUSIC), _________________FUNC_RIGHT________________,      KC_F12 , KC_SEC1, KC_SEC2, KC_SEC3, KC_SEC4, KC_SEC5,
        _______, KC_HYPR, _______, _______, _______, _______,      _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END),

    /* Layer 3: _SPACEFN
     * ------------------------------------------------------     ------------------------------------------------------
     * | CLEAR ||       ||MsRtClk||MsMdClk||MsLtClk|| UNAME |     |ScrollL||ScrollD||ScrollU||ScrollR||       || DELETE|
     * ------------------------------------------------------     ------------------------------------------------------
     * |VERSION||       ||MseLeft|| MseUp ||MseDown||MseRght|     |  LEFT ||  DOWN ||  UP   || RIGHT ||       || DEBUG |
     * ------------------------------------------------------     ------------------------------------------------------
     * | RESET ||       ||ScrollL||ScrollU||ScrollD||ScrollR|     |  HOME ||  PGDN ||  PGUP ||  END  ||       || RESET |
     * ------------------------------------------------------     ------------------------------------------------------
     * | MAKE  ||       ||       ||       ||       ||       |     |       ||       ||       ||       ||       || MAKE  |
     * ------------------------------------------------------     ------------------------------------------------------
     */

    [_SPACEFN] = LAYOUT(
        EPRM   , _______, KC_BTN2, KC_BTN3, KC_BTN1, USER   ,      KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, _______, KC_DEL ,
        VRSN   , _______, KC_MS_L, KC_MS_U, KC_MS_D, KC_MS_R,      KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, _______, DEBUG  ,
        RESET  , _______, KC_WH_L, KC_WH_U, KC_WH_D, KC_WH_R,      KC_HOME, KC_PGDN, KC_PGUP, KC_END , _______, RESET  ,
        KC_MAKE, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, KC_MAKE),

    /* Layer 4: _ADJUST
     * ------------------------------------------------------     ------------------------------------------------------
     * |BL_INC ||RGB_MOD||RGB_HUI||RGB_SAI||RGB_VAI||AU_ON  |     |AU_ON  ||RGB_MOD||RGB_HUI||RGB_SAI||RGB_VAI||BL_INC |
     * ------------------------------------------------------     ------------------------------------------------------
     * |BL_DEC ||RGB_TOG||RGB_HUD||RGB_SAD||RGB_VAD||AU_OFF |     |AU_OFF ||RGB_TOG||RGB_HUD||RGB_SAD||RGB_VAD||BL_DEC |
     * ------------------------------------------------------     ------------------------------------------------------
     * |BL_STEP|| Plain ||Rainbow|| Snake ||Chrstms||MU_TOG |     |MU_MOD || Plain ||Rainbow|| Snake ||Chrstms||BL_STEP|
     * ------------------------------------------------------     ------------------------------------------------------
     * |       ||Breathe|| Swirl || Knight||Grdient||_______|     |_______||Breathe|| Swirl || Knight||Grdient||BL_TOGG|
     * ------------------------------------------------------     ------------------------------------------------------
     */

    [_ADJUST] = LAYOUT(
        BL_INC , RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, AU_ON  ,      AU_ON  , RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, BL_INC ,
        BL_DEC , RGB_TOG, RGB_HUD, RGB_SAD, RGB_VAD, AU_OFF ,      AU_OFF , RGB_TOG, RGB_HUD, RGB_SAD, RGB_VAD, BL_DEC ,
        BL_STEP, RGB_M_P, RGB_M_R, RGB_M_SN,RGB_M_X, MU_TOG ,      MU_MOD , RGB_M_P, RGB_M_R, RGB_M_SN,RGB_M_X, BL_STEP,
        _______, RGB_M_B, RGB_M_SW,RGB_M_K, RGB_M_G, _______,      _______, RGB_M_B, RGB_M_SW,RGB_M_K, RGB_M_G, BL_TOGG),

    [_MUSIC] = LAYOUT(
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO),

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
    debug_enable=true;
    debug_matrix=true;
    debug_keyboard=true;
};

void matrix_slave_scan_user(void){
  analogX = readaxis(ANALOG_X_PIN);
  analogY = readaxis(ANALOG_Y_PIN);
}

#ifdef POINTING_DEVICE_ENABLE
#ifdef ANALOG_STICK_ENABLE
void pointing_device_task(void){
  report_mouse_t currentReport = {};

  currentReport = pointing_device_get_report();
  //shifting and transferring the info to the mouse report varaible

  //mouseReport.x = 127 max -127 min
  //currentReport.x = readaxis(analogRead(ANALOG_X_PIN));
  //currentReport.x = parseaxis(readaxis(ANALOG_X_PIN));
  currentReport.x = 0;

  //mouseReport.y = 127 max -127 min
  //currentReport.y = readaxis(analogRead(ANALOG_Y_PIN)) * -1;
  //currentReport.y = parseaxis(readaxis(ANALOG_Y_PIN)) * -1;
  currentReport.y = 0;

  //mouseReport.v = 127 max -127 min (scroll vertical)
  //currentReport.v = parseaxis(analogY);
  currentReport.v = 0;

  //mouseReport.h = 127 max -127 min (scroll horizontal)
  //currentReport.h = parseaxis(analogX);
  currentReport.h = 0;

  //currentReport.buttons = 0x00;
  currentReport.buttons = buttonPressed;

  xprintf("PD Master: %d,   %d Slave: %d,   %d \n", readaxis(ANALOG_X_PIN), readaxis(ANALOG_Y_PIN), analogX, analogY);
  xprintf("PD      x: %d y: %d v:     %d h: %d \n", currentReport.x, currentReport.y, currentReport.v, currentReport.h);

  pointing_device_set_report(currentReport);

  pointing_device_send();
}
#endif
#endif

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

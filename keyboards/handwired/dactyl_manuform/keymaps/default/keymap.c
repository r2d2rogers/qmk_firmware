#include "dactyl_manuform.h"
#include "action_layer.h"
#include "eeconfig.h"
#include "report.h"
#include "pointing_device.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _SPACEFN 3
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  MS_BTN1,
  MS_BTN2,
  MS_BTN3,
};

#define LONGPRESS_COUNT 4

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,------------------------------------------------   ------------------------------------------------.
 * |    `  |   1   |   2   |   3   |   4   |   5   |   |   6   |   7   |   8   |   9   |   0   |   -   |
 * |-------+-------+-------+-------+-------+-------+   +-------+-------+-------+-------+-------+-------|
 * |  Tab  |   Q   |   W   |   E   |   R   |   T   |   |   Y   |   U   |   I   |   O   |   P   |   \   |
 * |-------+-------+-------+-------+-------+--------   +-------+-------+-------+-------+-------+-------|
 * | CtlEsc|   A   |   S   |   D   |   F   |   G   |   |   H   |   J   |   K   |   L   |   ;   |   "   |
 * |-------+-------+-------+-------+-------+-------|   +-------+-------+-------+-------+-------+-------|
 * |  Shift|   Z   |   X   |   C   |   V   |   B   |   |   N   |   M   |   ,   |   .   |   /   | Shift |
 * |-------+-------+-------+-------+-------+-------+   +-------+-------+-------+-------+-------+-------|
 *                 | L_ALT | L_GUI |                                   |   ,   |   .   |
 *                 `-------+-------'                                   `-------+-------'
 *                 +-------+-------+-------+-------+   +-------+-------+-------+-------+
 *                 | Lower |SpaceFn|Backspc| Raise |   | Lower | Enter |SpaceFn| Raise |
 *                 `-------+-------+-------+-------+   +-------+-------+-------+-------'
 *                                 | JyStk | Adjust|   | Adjust| JyStk |
 *                                 `----------------   ----------------'
 */
  [_QWERTY] = KEYMAP( \
    KC_GRV, KC_1,   KC_2,   KC_3,   KC_4,   KC_5,       KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS, \

    KC_TAB, KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,       KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_BSLS, \

    CTL_T(KC_ESC),
            KC_A,   KC_S,   KC_D,   KC_F,   KC_G,       KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT, \

    KC_LSFT,KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,       KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,KC_RSFT, \

    XXXXXXX,XXXXXXX,KC_LALT,KC_LGUI,LOWER,  F(0),       F(0),   RAISE,  KC_COMM,KC_DOT, XXXXXXX,XXXXXXX, \

    XXXXXXX,ADJUST, XXXXXXX,XXXXXXX,RAISE,  KC_BSPC,    KC_ENT, LOWER,  XXXXXXX,XXXXXXX,ADJUST, XXXXXXX  \
  ),

/* Lower
 * ,------------------------------------------------   ------------------------------------------------.
 * |   ~   |   !   |   @   |   #   |   $   |   %   |   |   ^   |   &   |   *   |   (   |   )   | Bksp  |
 * |-------+-------+-------+-------+-------+--------   +-------+-------+-------+-------+-------+-------|
 * |   ~   |   !   |   @   |   #   |   $   |   %   |   |   ^   |   &   |   *   |   (   |   )   | Del   |
 * |-------+-------+-------+-------+-------+--------   +-------+-------+-------+-------+-------+-------|
 * | Del   |  F1   |  F2   |  F3   |  F4   |  F5   |   |  F6   |   _   |   +   |     |     \   |  |    |
 * |-------+-------+-------+-------+-------+-------|   +-------+-------+-------+-------+-------+-------|
 * |       |  F7   |  F8   |  F9   |  F10  |  F11  |   |  F12  |ISO ~  |ISO |  |       |       |Enter  |
 * |-------+-------+-------+-------+-------+-------+   +-------+-------+-------+-------+-------+-------|
 *                 |       |       |                                   |       |       |
 *                 `-------+-------'                                   `-------+-------'
 *                 +-------+-------+-------+-------+   +-------+-------+-------+-------+
 *                 |       |       |       |       |   |       |       |       |       |
 *                 `-------+-------+-------+-------+   +-------+-------+-------+-------'
 *                                 |       |       |   |       |       |
 *                                 `----------------   ----------------'
 */
  [_LOWER] = KEYMAP( \
    KC_TILD,KC_EXLM,KC_AT,  KC_HASH,KC_DLR, KC_PERC,    KC_CIRC,KC_AMPR,KC_ASTR,KC_LPRN,KC_RPRN,KC_BSPC, \

    KC_TILD,KC_EXLM,KC_AT,  KC_HASH,KC_DLR, KC_PERC,    KC_CIRC,KC_AMPR,KC_ASTR,KC_LPRN,KC_RPRN,KC_DEL, \

    KC_DEL, KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,      KC_F6,  KC_UNDS,KC_PLUS,KC_LCBR,KC_RCBR,KC_PIPE, \

    _______,KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11,     KC_F12,S(KC_NUHS),
                                                                     S(KC_NUBS),_______,_______,_______, \

    _______,KC_F7,  KC_F8,  KC_F9,  _______,_______,    _______,_______,_______,_______,_______,_______, \

    _______,_______,_______,_______,_______,_______,    _______,_______,_______,_______,_______,_______ \
  ),

/* Raise
 * ,------------------------------------------------   ------------------------------------------------.
 * |   `   |   1   |   2   |   3   |   4   |   5   |   |   6   |   7   |   8   |   9   |   0   | Bksp  |
 * |-------+-------+-------+-------+-------+--------   +-------+-------+-------+-------+-------+-------|
 * |   `   |   1   |   2   |   3   |   4   |   5   |   |   6   |   7   |   8   |   9   |   0   | Del   |
 * |-------+-------+-------+-------+-------+--------   +-------+-------+-------+-------+-------+-------|
 * | Del   |  F1   |  F2   |  F3   |  F4   |  F5   |   |  F6   |   -   |   =   |   [   |   ]   |  \    |
 * |-------+-------+-------+-------+-------+-------|   +-------+-------+-------+-------+-------+-------|
 * |       |  F7   |  F8   |  F9   |  F10  |  F11  |   |  F12  |ISO #  |ISO /  |       |       |Enter  |
 * |-------+-------+-------+-------+-------+-------+   +-------+-------+-------+-------+-------+-------|
 *                 |       |       |                                   |       |       |
 *                 `-------+-------'                                   `-------+-------'
 *                 +-------+-------+-------+-------+   +-------+-------+-------+-------+
 *                 |       |       |       |       |   |       |       |       |       |
 *                 `-------+-------+-------+-------+   +-------+-------+-------+-------'
 *                                 |       |       |   |       |       |
 *                                 `----------------   ----------------'
 */
  [_RAISE] = KEYMAP( \
    KC_GRV, KC_1,   KC_2,   KC_3,   KC_4,   KC_5,       KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_BSPC, \

    KC_GRV, KC_1,   KC_2,   KC_3,   KC_4,   KC_5,       KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_DEL, \

    KC_DEL, KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,      KC_F6,  KC_MINS,KC_EQL, KC_LBRC,KC_RBRC,KC_BSLS, \

    _______,KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11,     KC_F12, KC_NUHS,KC_NUBS,_______,_______,_______, \

    _______,KC_F7,  KC_F8,  KC_F9,  _______,_______,    _______,_______,KC_NUBS,_______,_______,_______, \

    _______,_______,_______,_______,_______,_______,    _______,_______,_______,_______,_______,_______ \
  ),

/* Space Function
 * ,------------------------------------------------   ------------------------------------------------.
 * |       |       |       |       |       |       |   |       |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------+   +-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |   |       |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------+   +-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |   |       |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------+   +-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |   |       |       |       |       |       |       |
 * `-------+-------+-------+-------+-------+-------+   +-------+-------+-------+-------+-------+-------|
 *                 |       |       |                                   |       |       |
 *                 `-------+-------'                                   `-------+-------'
 *                 +-------+-------+-------+-------+   +-------+-------+-------+-------+
 *                 |       |       |       |       |   |       |       |       |       |
 *                 `-------+-------+-------+-------+   +-------+-------+-------+-------'
 *                                 |       |       |   |       |       |
 *                                 `----------------   ----------------'
 */
  [_SPACEFN] =  KEYMAP( \
    _______,_______,_______,_______,_______,_______,    _______,_______,_______,_______,_______,_______, \

    _______,_______,_______,_______,_______,_______,    _______,_______,_______,_______,_______,_______, \

    _______,_______,_______,_______,_______,_______,    KC_LEFT,KC_DOWN,KC_UP,  KC_RGHT,_______,_______, \

    _______,_______,MS_BTN3,MS_BTN2,MS_BTN1,_______,    KC_HOME,KC_PGDN,KC_PGUP,KC_END, _______,_______, \

    _______,_______,_______,_______,_______,_______,    _______,_______,_______,_______,_______,_______, \

    _______,_______,_______,_______,_______,_______,    _______,_______,_______,_______,_______,_______ \
  ),

/* Adjust (Lower + Raise)
 * ,------------------------------------------------   ------------------------------------------------.
 * |  F12  |  F1   |  F2   |  F3   |  F4   |  F5   |   |  F6   |  F7   |  F8   |  F9   |  F10  |  F11  |
 * |-------+-------+-------+-------+-------+-------+   +-------+-------+-------+-------+-------+-------|
 * |       | Reset |RGB_TOG|RGB_MOD|Hue Dwn|Hue Up |   |Sat Dwn|Sat Up |Val Dwn|Val Up |       |Delete |
 * |-------+-------+-------+-------+-------+-------+   +-------+-------+-------+-------+-------+-------|
 * |       |       |       |Aud on |Aud Off|AG_NORM|   |AG_SWAP|       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------+   +-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |   |       |       |       |       |       |       |
 * `-------+-------+-------+-------+-------+-------+   +-------+-------+-------+-------+-------+-------|
 *                 |       |       |                                   |       |       |
 *                 `-------+-------'                                   `-------+-------'
 *                 +-------+-------+-------+-------+   +-------+-------+-------+-------+
 *                 |       |       |       |       |   |       |       |       |       |
 *                 `-------+-------+-------+-------+   +-------+-------+-------+-------'
 *                                 |       |       |   |       |       |
 *                                 `----------------   ----------------'
 */
  [_ADJUST] =  KEYMAP( \
    KC_F12, KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,      KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11, \

    _______,RESET  ,RGB_TOG,RGB_MOD,RGB_HUD,RGB_HUI,    RGB_SAD,RGB_SAI,RGB_VAD,RGB_VAI,_______,KC_DEL, \

    _______,_______,_______,AU_ON,  AU_OFF, AG_NORM,    AG_SWAP,_______,_______,_______,_______,_______, \

    _______,_______,_______,_______,_______,_______,    _______,_______,_______,_______,_______,_______, \

    _______,_______,_______,_______,_______,_______,    _______,_______,_______,_______,_______,_______, \


    _______,_______,_______,_______,_______,_______,    _______,_______,_______,_______,_______,_______ \
  )

/* Template
 * ,------------------------------------------------   ------------------------------------------------.
 * |       |       |       |       |       |       |   |       |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------+   +-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |   |       |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------+   +-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |   |       |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------+   +-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |   |       |       |       |       |       |       |
 * `-------+-------+-------+-------+-------+-------+   +-------+-------+-------+-------+-------+-------|
 *                 |       |       |                                   |       |       |
 *                 `-------+-------'                                   `-------+-------'
 *                 +-------+-------+-------+-------+   +-------+-------+-------+-------+
 *                 |       |       |       |       |   |       |       |       |       |
 *                 `-------+-------+-------+-------+   +-------+-------+-------+-------'
 *                                 |       |       |   |       |       |
 *                                 `----------------   ----------------'
 */
};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float tone_dvorak[][2]     = SONG(DVORAK_SOUND);
float tone_colemak[][2]    = SONG(COLEMAK_SOUND);
#endif

const uint16_t PROGMEM fn_actions[] = {
    [0]  = ACTION_LAYER_TAP_KEY(_SPACEFN, KC_SPC),
};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

//static uint16_t special_timers[LONGPRESS_COUNT] = {0xFFFF,0xFFFF,0xFFFF,0xFFFF};
//static bool special_key_states[LONGPRESS_COUNT] = {0,0,0,0};

//static uint16_t shift_timer;
//static uint16_t num_timer;
//static uint16_t mouse_timer;

//static bool shift_singular_key = false;
//static bool number_singular_key = false;
//static bool mouse_singular_key = false;

static bool shift_held = false;
static bool shift_suspended = false;
report_mouse_t currentReport = {};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_qwerty);
        #endif
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
      //mouse buttons, for 1-3, to update the mouse report:
    case MS_BTN1:
      currentReport = pointing_device_get_report();
      if (record->event.pressed) {
              if (shift_held && shift_suspended){
                      register_code(KC_LSFT);
                      shift_suspended = false;
              }
              //update mouse report here
              currentReport.buttons |= MOUSE_BTN1; //MOUSE_BTN1 is a const defined in report.h
      } else {
              //update mouse report here
              currentReport.buttons &= ~MOUSE_BTN1;
      }
      pointing_device_set_report(currentReport);
      break;
    case MS_BTN2:
      currentReport = pointing_device_get_report();
      if (record->event.pressed) {
              if (shift_held && shift_suspended){
                      register_code(KC_LSFT);
                      shift_suspended = false;
              }
              //update mouse report here
              currentReport.buttons |= MOUSE_BTN2; //MOUSE_BTN2 is a const defined in report.h
      } else {
              //update mouse report here
      }
      pointing_device_set_report(currentReport);
      break;
      //there is a case for button 3, but that's handled in dichotemy.c, and this is being
      //disabled to avoid any conflict.
    case MS_BTN3:
      currentReport = pointing_device_get_report();
      if (record->event.pressed) {
              if (shift_held && shift_suspended){
                      register_code(KC_LSFT);
                      shift_suspended = false;
              }
              //update mouse report here
              currentReport.buttons |= MOUSE_BTN3; //MOUSE_BTN2 is a const defined in report.h
      } else {
              //update mouse report here
      }
      pointing_device_set_report(currentReport);
		break;
  }
  return true;
}

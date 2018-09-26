
#include QMK_KEYBOARD_H
#include "r2d2rogers.h"

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_ergodox_pretty_wrapper(  // layer 0 :default
    KC_GRV,  ________________NUMBER_LEFT________________, KC_EQL,           TKEY,    ________________NUMBER_RIGHT_______________, KC_MINS,
    KC_TAB,  _________________QWERTY_L1_________________, KC_LBRC,          KC_RBRC, _________________QWERTY_R1_________________, KC_BSLS,
    KC_ESCC, _________________QWERTY_L2_________________,                            _________________QWERTY_R2_________________, KC_QUOT,
    KC_LSFT, _________________QWERTY_L3_________________, ADJUST,           ADJUST,  _________________QWERTY_R3_________________, KC_RSFT,
    KC_LGUI, ___________ERGODOX_BOTTOM_LEFT_____________,                            ___________ERGODOX_BOTTOM_RIGHT____________, KC_RGUI,
                                                 KC_LCTL, KC_LALT,          KC_RALT, KC_RCTL,
                                                          KC_HOME,          KC_PGUP,
                                         KC_SPC, LOWER,   KC_END,           KC_PGDN, RAISE,   SPACEFN
  ),

  [_COLEMAK] = LAYOUT_ergodox_pretty_wrapper(  // layer 0 : default
    KC_GRV,  ________________NUMBER_LEFT________________, KC_EQL,           TKEY,    ________________NUMBER_RIGHT_______________, KC_MINS,
    KC_TAB,  _________________COLEMAK_L1________________, KC_LBRC,          KC_RBRC, _________________COLEMAK_R1________________, KC_BSLS,
    KC_ESCC, _________________COLEMAK_L2________________,                            _________________COLEMAK_R2________________, KC_QUOT,
    KC_LSFT, _________________COLEMAK_L3________________, ADJUST,           ADJUST,  _________________COLEMAK_R3________________, KC_RSFT,
    KC_LGUI, ___________ERGODOX_BOTTOM_LEFT_____________,                            ___________ERGODOX_BOTTOM_RIGHT____________, KC_RGUI,
                                                 KC_LCTL, KC_LALT,          KC_RALT, KC_RCTL,
                                                          KC_HOME,          KC_PGUP,
                                         KC_SPC, LOWER,   KC_END,           KC_PGDN, RAISE,   SPACEFN
  ),

  [_DVORAK] = LAYOUT_ergodox_pretty_wrapper(  // layer 0 : default
    KC_GRV,  ________________NUMBER_LEFT________________, KC_EQL,           TKEY,    ________________NUMBER_RIGHT_______________, KC_MINS,
    KC_TAB,  _________________DVORAK_L1_________________, KC_LBRC,          KC_RBRC, _________________DVORAK_R1_________________, KC_BSLS,
    KC_ESCC, _________________DVORAK_L2_________________,                            _________________DVORAK_R2_________________, KC_QUOT,
    KC_LSFT, _________________DVORAK_L3_________________, ADJUST,           ADJUST,  _________________DVORAK_R3_________________, KC_RSFT,
    KC_LGUI, ___________ERGODOX_BOTTOM_LEFT_____________,                            ___________ERGODOX_BOTTOM_RIGHT____________, KC_RGUI,
                                                 KC_LCTL, KC_LALT,          KC_RALT, KC_RCTL,
                                                          KC_HOME,          KC_PGUP,
                                         KC_SPC, LOWER,   KC_END,           KC_PGDN, RAISE,   SPACEFN
  ),

  [_WORKMAN] = LAYOUT_ergodox_pretty_wrapper(  // layer 0 : default
    KC_GRV,  ________________NUMBER_LEFT________________, KC_EQL,           TKEY,    ________________NUMBER_RIGHT_______________, KC_MINS,
    KC_TAB,  _________________WORKMAN_L1________________, KC_LBRC,          KC_RBRC, _________________WORKMAN_R1________________, KC_BSLS,
    KC_ESCC, _________________WORKMAN_L2________________,                            _________________WORKMAN_R2________________, KC_QUOT,
    KC_LSFT, _________________WORKMAN_L3________________, ADJUST,           ADJUST,  _________________WORKMAN_R3________________, KC_RSFT,
    KC_LGUI, ___________ERGODOX_BOTTOM_LEFT_____________,                            ___________ERGODOX_BOTTOM_RIGHT____________, KC_RGUI,
                                                 KC_LCTL, KC_LALT,          KC_RALT, KC_RCTL,
                                                          KC_HOME,          KC_PGUP,
                                         KC_SPC, LOWER,   KC_END,           KC_PGDN, RAISE,   SPACEFN
  ),

  [_RAISE] = LAYOUT_ergodox_pretty_wrapper(  // layer 1 : Keymap Template
    _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
    KC_GRV , ________________NUMBER_LEFT________________, _______,          _______, ________________NUMBER_RIGHT_______________, _______,
    _______, KC_4   , KC_5   , KC_6   , KC_DOT , _______,                            _______, KC_MINS, KC_EQL , KC_LBRC, KC_RBRC, KC_BSLS,
    _______, KC_7   , KC_8   , KC_9   , KC_0   , _______, _______,          _______, _______, _______, _______, KC_DOT , _______, _______,
    _______, KC_HYPR, _______, _______, _______,                                              _______, KC_MPLY, KC_VOLD, KC_VOLU, KC_MFFD,
                                                 _______, _______,          _______, _______,
                                                          _______,          _______,
                                        _______, _______, _______,          _______, _______, _______
  ),

  [_LOWER] = LAYOUT_ergodox_pretty_wrapper(  // layer 2 : Keymap Template
    _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
    KC_TILD, KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC, _______,          _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
    _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,                            KC_F11 , KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
    _______, KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , _______,          _______, KC_F12 , _______, _______, _______, _______, _______,
    TKEY,    KC_HYPR, _______, _______, _______,                                              _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END ,
                                                 _______, _______,          _______, _______,
                                                          _______,          _______,
                                        _______, _______, _______,          _______, _______, _______
  ),

  [_SPACEFN] = LAYOUT_ergodox_pretty_wrapper(  // layer 3 : Right Space
    _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
    _______, _______, KC_BTN2, KC_MS_U, KC_BTN1, KC_WH_U, _______,          _______, _______, KC_BTN1, KC_BTN3, KC_BTN2, _______, _______,
    _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D,                            KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
    _______, _______, _______, KC_BTN3, KC_WH_L, KC_WH_R, _______,          _______, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, _______, _______,
    _______, _______, _______, _______, _______,                                              _______, _______, _______, _______, _______,
                                                 _______, _______,          _______, _______,
                                                          _______,          _______,
                                        _______, KC_DEL,  _______,          _______, _______, _______
  ),

  [_ADJUST] = LAYOUT_ergodox_pretty_wrapper(  // layer 4 : function and symbol keys
    BL_TOGG, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F11,           KC_F12,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  BL_TOGG,
    BL_INC,  KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,  _______,          _______, KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20,  BL_INC,
    BL_DEC,  _______, _______, _______, _______, _______,                            _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, BL_DEC,
    BL_STEP, _______, _______, _______, _______, _______, _______,          _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, _______, BL_STEP,
    UTIL,    _______, _______, _______, _______,                                              _______, _______, _______, _______, UTIL,
                                                 _______, _______,          _______, _______,
                                                          _______,          _______,
                                        _______, _______, _______,          _______, _______, _______
  ),

  [_TKEY] = LAYOUT_ergodox_pretty_wrapper(  // layer 5: numpad
    KC_BSPC, KC_CALC, KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS, _______,          _______, KC_CALC, KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS, KC_BSPC,
    _______, XXXXXXX, KC_P7,   KC_P8,   KC_P9,   KC_PPLS, _______,          _______, XXXXXXX, KC_P7,   KC_P8,   KC_P9,   KC_PPLS, KC_TAB,
    _______, XXXXXXX, KC_P4,   KC_P5,   KC_P6,   KC_PPLS,                            XXXXXXX, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, KC_PENT,
    KC_PENT, XXXXXXX, KC_P1,   KC_P2,   KC_P3,   KC_PENT, _______,          _______, XXXXXXX, KC_P1,   KC_P2,   KC_P3,   KC_PENT, KC_PENT,
    KC_PENT, XXXXXXX, KC_P0,   KC_P0,   KC_PDOT,                                              KC_P0,   KC_P0,   KC_PDOT, KC_PENT, KC_PENT,
                                                 _______, _______,          _______, _______,
                                                          _______,          _______,
                                        _______, _______, _______,          _______, _______, _______
  ),

  [_UTIL] = LAYOUT_ergodox_pretty_wrapper(  // layer 5 : keyboard utility functions
    RESET,   _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, RESET,
    DEBUG,   _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, DEBUG,
    _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,                                              _______, _______, _______, _______, _______,
                                                 _______, _______,          _______, _______,
                                                          _______,          _______,
                                        _______, _______, _______,          _______, _______, _______
  ) ,

};

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_keymap(void) {
    //debug_enable=true;
    //debug_matrix=true;
    //debug_keyboard=true;

    //start_keyframe_animation(&led_test_animation);
};

// Runs constantly in the background, in a loop.
void matrix_scan_keymap(void) {

    uint8_t layer = biton32(layer_state);

    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 0:
#ifdef SUBPROJECT_infinity
      lcd_backlight_hal_color(5000, 0, 0);
#endif
      break;
        case 1:
#ifdef SUBPROJECT_infinity
      lcd_backlight_hal_color(5000, 0, 0);
#endif
      break;
        case 2:
            ergodox_right_led_1_on();
#ifdef SUBPROJECT_infinity
      lcd_backlight_hal_color(5000, 0, 0);
#endif
            break;
        case 3:
            ergodox_right_led_2_on();
#ifdef SUBPROJECT_infinity
      lcd_backlight_hal_color(5000, 0, 0);
#endif
            break;
        case 4:
            ergodox_right_led_3_on();
#ifdef SUBPROJECT_infinity
      lcd_backlight_hal_color(5000, 0, 0);
#endif
            break;
        default:
            ergodox_board_led_off();
            ergodox_right_led_1_off();
            ergodox_right_led_2_off();
            ergodox_right_led_3_off();
            break;
    }
};

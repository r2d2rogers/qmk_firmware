#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
    KC_ESC , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                   KC_6   , KC_7   , KC_8    , KC_9   , KC_0   , KC_GRV  ,
    KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                   KC_Y   , KC_U   , KC_I    , KC_O   , KC_P   , KC_BSPC ,
    MO(1)  , KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,                   KC_H   , KC_J   , KC_K    , KC_L   , KC_SCLN, KC_QUOT ,
    KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , TG(2)  , KC_RGUI, KC_N   , KC_M   , KC_COMM , KC_DOT , KC_SLSH, KC_BSLS ,
                                        KC_LALT, KC_LCTL, KC_SPC , KC_ENT , KC_LBRC, KC_RBRC
  ),
  [1] = LAYOUT(
    KC_F12 , KC_F1  , KC_F2  , KC_F3  , KC_F4  ,                   KC_F5  , KC_F6  , KC_F7  , KC_F8   , KC_F9  , KC_F10 , KC_F11  ,
    KC_MUTE, KC_VOLD, KC_UP  , KC_VOLU, KC_PMNS,                   KC_PPLS, KC_NO  , KC_BTN1, KC_MS_U , KC_BTN2, KC_PSCR, KC_DEL  ,
    KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_UNDS,                   KC_PEQL, KC_PGUP, KC_MS_L, KC_MS_D , KC_MS_R, KC_NO  , KC_NO   ,
    KC_NO  , KC_MPRV, KC_MNXT, KC_MPLY, KC_LCBR, KC_RCBR, KC_NO  , KC_NO  , KC_PGDN, KC_HOME, KC_END  , KC_NO  , KC_NLCK, KC_CAPS ,
                                        KC_LPRN, KC_RPRN, KC_ENT , KC_NO  , KC_NO  , KC_NO
  ),
  [2] = LAYOUT(
    KC_ESC , KC_UNDS, KC_PSLS, KC_PAST, KC_PMNS,                   KC_BSPC, KC_NO  , KC_NO  , KC_NO   , KC_NO  , KC_NO  , KC_NO   ,
    KC_CALC, KC_DLR , KC_P7  , KC_P8  , KC_P9  ,                   KC_PPLS, KC_NO  , KC_NO  , KC_NO   , KC_NO  , KC_NO  , KC_NO   ,
    KC_LT  , KC_GT  , KC_P4  , KC_P5  , KC_P6  ,                   KC_PEQL, KC_NO  , KC_NO  , KC_NO   , KC_NO  , KC_NO  , KC_NO   ,
    KC_LPRN, KC_RPRN, KC_P1  , KC_P2  , KC_P3  , KC_PCMM, KC_TRNS, MO(3)  , KC_NO  , KC_NO  , KC_NO   , KC_NO  , KC_NO  , KC_NO   ,
                                        KC_P0  , KC_PDOT, KC_ENT , KC_NO  , KC_NO  , KC_NO
  ),
  [3] = LAYOUT(
    KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,                   KC_NO  , BL_TOGG, BL_STEP, RGB_TOG , RGB_HUI, RGB_VAI, RGB_M_G ,
    KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,                   KC_NO  , BL_INC , BL_ON  , RGB_MOD , RGB_HUD, RGB_VAD, RGB_M_P ,
    KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,                   KC_NO  , BL_DEC , BL_OFF , RGB_RMOD, RGB_SAI, RGB_SPI, RGB_M_R ,
    KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_TRNS, KC_NO  , KC_NO  , KC_NO   , RGB_SAD, RGB_SPD, RGB_M_SW,
                                        KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO
  )
};

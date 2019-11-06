#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[0] = LAYOUT_lefty(
    KC_7   , KC_8   , KC_9   , KC_HOME, KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_LBRC , KC_BSPC  ,
    KC_4   , KC_5   , KC_6   , KC_END , MO(1)  , KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN,           KC_QUOT  ,
    KC_1   , KC_2   , KC_3   , KC_PGUP, KC_LSFT,          KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH , KC_BSLS  ,
    KC_GRV , KC_0   , KC_PDOT, KC_PGDN, MO(2)  , KC_LALT, KC_LCTL,                   KC_SPC ,          KC_SPC , KC_ENT , KC_LGUI, KC_GRV , KC_LBRC , KC_RBRC) ,
[1] = LAYOUT_lefty(
    KC_TILD, KC_EXLM, KC_AT  , KC_HASH, KC_ESC , KC_VOLD, KC_UP  , KC_VOLU, KC_MUTE, KC_NO  , KC_PGUP, KC_BTN1, KC_WH_U, KC_BTN2, KC_PSCR, KC_NO   , KC_DEL   ,
    KC_DLR , KC_PERC, KC_CIRC, KC_AMPR, KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_NO  , KC_NO  , KC_PGDN, KC_WH_L, KC_WH_D, KC_WH_R, KC_NO  ,           KC_MYCM  ,
    KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS, KC_LSFT,          KC_MPRV, KC_MNXT, KC_MPLY, KC_NO  , KC_NO  , KC_HOME, KC_END , KC_CAPS, KC_NLCK, KC_NO   , KC_CALC  ,
    KC_PLUS, KC_LCBR, KC_RCBR, KC_PEQL, KC_NO  , KC_LCTL, KC_LALT,                   KC_LPRN,          KC_LPRN, KC_RPRN, KC_LGUI, KC_NO  , KC_LBRC , KC_RBRC) ,
[2] = LAYOUT_lefty(
    KC_P7  , KC_P8  , KC_P9  , KC_PSLS, KC_ESC , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_NO  , RGB_SPI, RGB_VAI, RGB_SAI, RGB_HUI, RGB_MOD , RGB_TOG  ,
    KC_P4  , KC_P5  , KC_P6  , KC_PAST, MO(3)  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_NO  , RGB_SPD, RGB_VAD, RGB_SAD, RGB_HUD,           RGB_RMOD ,
    KC_P1  , KC_P2  , KC_P3  , KC_PMNS, KC_NO  ,          KC_F11 , KC_F12 , KC_NO  , KC_NO  , KC_NO  , KC_NO  , RGB_M_P, RGB_M_G, RGB_M_R, RGB_M_SW, KC_TRNS  ,
    KC_PENT, KC_P0  , KC_PDOT, KC_PPLS, KC_TRNS, KC_NO  , KC_NO  ,                   KC_NO  ,          KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO   , KC_NO   ),
[3] = LAYOUT_lefty(
    KC_NO  , KC_NO  , KC_NO  , RESET  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO   , KC_NO    ,
    KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_TRNS, KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,           KC_NO    ,
    KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,          KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO   , KC_NO    ,
    KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,                   KC_NO  ,          KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO   , KC_NO   )
};

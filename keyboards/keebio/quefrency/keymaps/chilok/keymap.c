#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BASE 0
#define _FN1 1

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_ESC , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6    , KC_7   , KC_8    , KC_9   , KC_0   , KC_MINS, KC_EQL , KC_BSLS, KC_GRV ,
        KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_Y    , KC_U   , KC_I    , KC_O   , KC_P   , KC_LBRC, KC_RBRC, KC_BSPC,
        MO(1)  , KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_H    , KC_J   , KC_K    , KC_L   , KC_SCLN, KC_QUOT, KC_ENT ,
        KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_N    , KC_M   , KC_COMM , KC_DOT , KC_SLSH, KC_LSFT, MO(2)  ,
        KC_LCTL, KC_LGUI, KC_LALT, KC_LCTL, KC_SPC , KC_ENT , KC_ENT  , KC_RALT, KC_RGUI , KC_APP , KC_RCTL, KC_RCTL
        ),
    [1] = LAYOUT(
        KC_ESC , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6   , KC_F7  , KC_F8   , KC_F9  , KC_F10 , KC_F11 , KC_F12 , KC_NLCK, KC_CAPS,
        KC_TAB , KC_VOLD, KC_UP  , KC_VOLU, KC_NO  , RGB_TOG, KC_MYCM , KC_BTN1, KC_MS_U , KC_BTN2, KC_PSCR, KC_NO  , KC_NO  , KC_DEL ,
        KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_NO  , KC_NO  , KC_PGUP , KC_MS_L, KC_MS_D , KC_MS_R, KC_NO  , KC_NO  , KC_NO  ,
        KC_LSFT, KC_MPRV, KC_MNXT, KC_MPLY, KC_NO  , KC_MUTE, KC_PGDN , KC_HOME, KC_END  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
        KC_LCTL, KC_NO  , KC_LALT, KC_LCTL, KC_NO  , KC_NO  , KC_NO   , KC_NO  , KC_NO   , KC_NO  , KC_NO  , KC_NO
        ),
    [2] = LAYOUT(
        KC_ESC , KC_NO  , KC_PERC, KC_HASH, KC_DLR , KC_PSLS, KC_BSPC , RGB_TOG, RGB_HUI , RGB_SAI, RGB_VAI, RGB_SPI, KC_NO  , KC_NO  , KC_NO  ,
        KC_NO  , KC_NO  , KC_P7  , KC_P8  , KC_P9  , KC_PAST, RGB_MOD , RGB_HUD, RGB_SAD , RGB_VAD, RGB_SPD, KC_NO  , KC_NO  , KC_NO  ,
        KC_CALC, KC_NO  , KC_P4  , KC_P5  , KC_P6  , KC_PMNS, RGB_RMOD, RGB_M_R, RGB_M_SW, RGB_M_P, RGB_M_G, KC_NO  , KC_NO  ,
        KC_NO  , KC_P0  , KC_P1  , KC_P2  , KC_P3  , KC_PPLS, KC_NO   , KC_NO  , KC_NO   , KC_NO  , KC_NO  , KC_NO  , KC_TRNS,
        KC_NO  , KC_PCMM, KC_P0  , KC_PDOT, KC_PENT, KC_NO  , KC_NO   , KC_NO  , KC_NO   , KC_NO  , KC_NO  , KC_NO
        )

};

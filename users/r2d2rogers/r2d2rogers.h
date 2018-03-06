#ifndef USERSPACE
#define USERSPACE

#include "quantum.h"

// Layers
enum layers {
_QWERTY = 0, 
_COLEMAK, 
_DVORAK, 
_WORKMAN, 
_RAISE, 
_LOWER, 
_SPACEFN, 
_TKEY, 
_ADJUST, 
_MUSIC,
_UTIL
};

#ifndef RGBLIGHT_ANIMATIONS // add "EXTRA_FLADS=-DDRASHNA_SETRGB" to enable this ... but don't
#define rgblight_set_blue        rgblight_setrgb (0x00, 0x00, 0xFF);
#define rgblight_set_red         rgblight_setrgb (0xFF, 0x00, 0x00);
#define rgblight_set_green       rgblight_setrgb (0x00, 0xFF, 0x00);
#define rgblight_set_orange      rgblight_setrgb (0xFF, 0x80, 0x00);
#define rgblight_set_teal        rgblight_setrgb (0x00, 0xFF, 0xFF);
#define rgblight_set_magenta     rgblight_setrgb (0xFF, 0x00, 0xFF);
#define rgblight_set_yellow      rgblight_setrgb (0xFF, 0xFF, 0x00);
#define rgblight_set_purple      rgblight_setrgb (0x7A, 0x00, 0xFF);
#define rgblight_set_white       rgblight_setrgb (0xFF, 0xFF, 0xFF);
#else
#define rgblight_set_white       rgblight_sethsv (   0, 0x00,  255);
#define rgblight_set_red         rgblight_sethsv (   0,  255,  255);
#define rgblight_set_coral       rgblight_sethsv (  16,  176,  255);
#define rgblight_set_orange      rgblight_sethsv (  39,  255,  255);
#define rgblight_set_goldenrod   rgblight_sethsv (  43,  218,  218);
#define rgblight_set_gold        rgblight_sethsv (  51,  255,  255);
#define rgblight_set_yellow      rgblight_sethsv (  60,  255,  255);
#define rgblight_set_chartreuse  rgblight_sethsv (  90,  255,  255);
#define rgblight_set_green       rgblight_sethsv ( 120,  255,  255);
#define rgblight_set_springgreen rgblight_sethsv ( 150,  255,  255);
#define rgblight_set_turquoise   rgblight_sethsv ( 174,   90,  112);
#define rgblight_set_teal        rgblight_sethsv ( 180,  255,  128);
#define rgblight_set_cyan        rgblight_sethsv ( 180,  255,  255);
#define rgblight_set_azure       rgblight_sethsv ( 186,  102,  255);
#define rgblight_set_blue        rgblight_sethsv ( 240,  255,  255);
#define rgblight_set_purple      rgblight_sethsv ( 270,  255,  255);
#define rgblight_set_magenta     rgblight_sethsv ( 300,  255,  255);
#define rgblight_set_pink        rgblight_sethsv ( 330,  128,  255);

//#define rgblight_set_        rgblight_sethsv (0, 255, 255);
#endif // DRASHNA_SETRGB

extern bool rgb_layer_change;

enum userspace_custom_keycodes {
        KC_QWERTY = SAFE_RANGE, // can always be here
        KC_COLEMAK,
        KC_DVORAK,
        KC_WORKMAN,
        //LOWER,
        //RAISE,
        //ADJUST,
        //SPACEFN,
        MUSIC,
        TKEY,
        KC_MAKE,
        KC_RESET,
        KC_SECRET_1,
        KC_SECRET_2,
        KC_SECRET_3,
        KC_SECRET_4,
        KC_SECRET_5,
        EPRM,
        USER,
        VRSN,
        KC_SW_A,
        KC_SW_G,
        KC_SW_H,
        KC_SW_QT,
        KC_RGB_T,
        NEW_SAFE_RANGE // use "NEWPLACEHOLDER" for keymap specific codes
};

#ifdef TAP_DANCE_ENABLE
enum {
        TD_D3_1 = 0,
        TD_D3_2,
        TD_D3_3,
        TD_D3_4
};
#endif

#ifdef TAP_DANCE_ENABLE
#define KC_D3_1 TD(TD_D3_1)
#define KC_D3_2 TD(TD_D3_2)
#define KC_D3_3 TD(TD_D3_3)
#define KC_D3_4 TD(TD_D3_4)
#else
#define KC_D3_1 KC_1
#define KC_D3_2 KC_2
#define KC_D3_3 KC_3
#define KC_D3_4 KC_4
#endif

#define KC_ESCC MT(MOD_LCTL, KC_ESC)
#define SPACEFN LT(_SPACEFN, KC_SPC)
#define RAISE LT(_RAISE, KC_ENT)
#define LOWER LT(_LOWER, KC_BSPC)
#define ADJUST MO(_ADJUST)
#define TKEY TT(_TKEY)
#define UTIL OSL(_UTIL)
#define RSFTENT MT(KC_RSFT, KC_ENT)
#define GUIRGHT MT(MOD_RGUI, KC_RGHT)

// Since our quirky block definitions are basically a list of comma separated
// arguments, we need a wrapper in order for these definitions to be
// expanded before being used as arguments to the LAYOUT_xxx macro.
#define LAYOUT_ergodox_wrapper(...)   LAYOUT_ergodox(__VA_ARGS__)
#define KEYMAP_wrapper(...)           KEYMAP(__VA_ARGS__)

// Blocks for each of the four major keyboard layouts
// Organized so we can quickly adapt and modify all of them
// at once, rather than for each keyboard, one at a time.
// And this allows wor much cleaner blocks in the keymaps.
// For instance Tap/Hold for Control on all of the layouts

#define _________________QWERTY_L1_________________        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T
#define _________________QWERTY_L2_________________        KC_A,    KC_S,    KC_D,    KC_F,    KC_G
#define _________________QWERTY_L3_________________        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B

#define _________________QWERTY_R1_________________        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P
#define _________________QWERTY_R2_________________        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN
#define _________________QWERTY_R3_________________        KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH


#define _________________COLEMAK_L1________________        KC_Q,    KC_W,    KC_F,    KC_P,    KC_G
#define _________________COLEMAK_L2________________        KC_A,    KC_R,    KC_S,    KC_T,    KC_D
#define _________________COLEMAK_L3________________        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B

#define _________________COLEMAK_R1________________        KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN
#define _________________COLEMAK_R2________________        KC_H,    KC_N,    KC_E,    KC_I,    KC_O
#define _________________COLEMAK_R3________________        KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH


#define _________________DVORAK_L1_________________        KC_QUOT, KC_COMM, KC_DOT, KC_P,     KC_Y
#define _________________DVORAK_L2_________________        KC_A,    KC_O,    KC_E,   KC_U,     KC_I
#define _________________DVORAK_L3_________________        KC_SCLN, KC_Q,    KC_J,   KC_K,     KC_X

#define _________________DVORAK_R1_________________        KC_F,    KC_G,    KC_C,    KC_R,    KC_L
#define _________________DVORAK_R2_________________        KC_D,    KC_H,    KC_T,    KC_N,    KC_S
#define _________________DVORAK_R3_________________        KC_B,    KC_M,    KC_W,    KC_V,    KC_Z


#define _________________WORKMAN_L1________________        KC_QUOT, KC_COMM, KC_DOT, KC_P,     KC_Y
#define _________________WORKMAN_L2________________        KC_A,    KC_O,    KC_E,   KC_U,     KC_I
#define _________________WORKMAN_L3________________        KC_SCLN, KC_Q,    KC_J,   KC_K,     KC_X

#define _________________WORKMAN_R1________________        KC_F,    KC_G,    KC_C,    KC_R,    KC_L
#define _________________WORKMAN_R2________________        KC_D,    KC_H,    KC_T,    KC_N,    KC_S
#define _________________WORKMAN_R3________________        KC_B,    KC_M,    KC_W,    KC_V,    KC_Z



// Since we have 4 default layouts (QWERTY, DVORAK, COLEMAK and WORKMAN),
// this allows us to quickly modify the bottom row for all of the layouts
// so we don't have to alter it 4 times and hope that we haven't missed
// anything
#define ___________ERGODOX_BOTTOM_LEFT_____________        KC_LALT, KC_INS,  KC_LBRC, KC_RBRC
#define ___________ERGODOX_BOTTOM_RIGHT____________        KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT

#define ___________GENERAL_BOTTOM_LEFT_____________        ADJUST,  KC_MEH,  KC_LALT, KC_LGUI, SPACEFN, LOWER
#define ___________GENERAL_BOTTOM_RIGHT____________        RAISE,   SPACEFN, KC_LEFT, KC_DOWN, KC_UP,   GUIRGHT

#endif

#include "ergodox.h"
#include "debug.h"
#include "action_layer.h"
#include "action_util.h"
#include "version.h"

#define BASE 0 // default layer
#define FKEY 1 // function key layer
#define UTIL 2 // keyboard utility layer
#define NPAD 3 // numpad layer
#define LEFT 4 // left space fn layer
#define RGHT 5 // right space fn layer
#define TEMP 6 // Template for new layers

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Keymap 0: Basic layer
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   `    |   1  |   2  |   3  |   4  |   5  |   =  |           | NPAD |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |  [   |           |   ]  |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |Ctrl/Esc|   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   '    |
 * |--------+------+------+------+------+------| ~FKEY|           | ~FKEY|------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | LGui | LAlt |  Ins |   [  |   ]  |                                       | Left | Down |  Up  | Right| RGui |
 *   `----------------------------------'                                       `----------------------------------'
 *                                       ,-------------.         ,-------------.
 *                                       | Ctrl |  Alt |         | Alt  | Ctrl |
 *                                ,------|------|------|         |------+------+------.
 *                                | Space|      | Home |         | PgUp |      |Space |
 *                                |   /  | Back |------|         |------|Enter |  /   |
 *                                | LEFT | Space| End  |         | PgDn |      | RGHT |
 *                                `--------------------'         `--------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
    [BASE] = KEYMAP(  // layer 0 : default
        // left hand
        KC_GRV, KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_EQL,
        KC_TAB, KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_LBRC,
        MT(MOD_LCTL, KC_ESC), KC_A,   KC_S,   KC_D,   KC_F,   KC_G,
        KC_LSFT,KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_FN0,
        KC_LGUI,KC_LALT,KC_INS, KC_LBRC,KC_RBRC,
                                                KC_LCTL,KC_LALT,
                                                        KC_HOME,
                                        KC_SPC, KC_BSPC,KC_END,
        // right hand
        KC_FN2, KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,
        KC_RBRC,KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_BSLS,
                KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,
        KC_FN0, KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,KC_RSFT,
                        KC_LEFT,KC_DOWN,KC_UP,  KC_RGHT,KC_RGUI,
        KC_RALT,KC_RCTL,
        KC_PGUP,
        KC_PGDN,KC_ENT, LT(RGHT,KC_SPC)
    ),

/* Keymap 1: Function key layer
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  POWER |  F1  |  F2  |  F3  |  F4  |  F5  |  F11 |           |  F12 |  F6  |  F7  |  F8  |  F9  | F10  |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  SLEEP |      |      |      |      |      |      |           |      | MPRV | MPLY | MNXT |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  WAKE  |      |      |      |      |      |------|           |------| MUTE | VOLD | VOLU |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  UTIL  |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        |      |      |       |      |        |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |      |       |      |        |      |
 *                                 |      |      |------|       |------|        |      |
 *                                 |      |      |      |       |      |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
    [FKEY] = KEYMAP(  // layer 1 : function and symbol keys
        // left hand
        KC_PWR, KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F11,
        KC_SLEP,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
        KC_WAKE,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
        KC_FN1, KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                                KC_TRNS,KC_TRNS,
                                                        KC_TRNS,
                                        KC_TRNS,KC_TRNS,KC_TRNS,
        // right hand
        KC_F12, KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_TRNS,
        KC_TRNS,KC_MPRV,KC_MPLY,KC_MNXT,KC_TRNS,KC_TRNS,KC_TRNS,
                KC_MUTE,KC_VOLD,KC_VOLU,KC_TRNS,KC_TRNS,KC_TRNS,
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
        KC_TRNS,KC_TRNS,
        KC_TRNS,
        KC_TRNS,KC_TRNS,KC_TRNS
    ),

/* Keymap 2: Keyboard utility layer
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | FLASH  |      |      |      |      |      |      |           |      |      |      |      |      |      | FLASH  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | DEBUG  |      |      |      |      |      |      |           |      |      |      |      |      |      | DEBUG  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                       ,-------------.         ,-------------.
 *                                       |      |      |         |      |      |
 *                                ,------|------|------|         |------+------+------.
 *                                |      |      |      |         |      |      |      |
 *                                |      |      |------|         |------|      |      |
 *                                |      |      |      |         |      |      |      |
 *                                `--------------------'         `--------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
    [UTIL] = KEYMAP(  // layer 2 : keyboard utility functions
        // left hand
        RESET,  KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
        DEBUG,  KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_FN3,
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                                KC_TRNS,KC_TRNS,
                                                        KC_TRNS,
                                        KC_TRNS,KC_TRNS,KC_TRNS,
        // right hand
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,RESET,
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,DEBUG,
                KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
        KC_TRNS,KC_TRNS,
        KC_TRNS,
        KC_TRNS,KC_TRNS,KC_TRNS
    ),

/* Keymap 3: Numpad layer
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           | BASE | Nmlk |  /   |  *   |  *   |  -   | Bksp   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      | CALC |  7   |  8   |  9   |  -   | Bksp   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|  NO  |  4   |  5   |  6   |  +   | Enter  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |  NO  |  1   |  2   |  3   |  +   | Enter  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |  0   |  .   |  /   | Enter| Enter|
 *   `----------------------------------'                                       `----------------------------------'
 *                                       ,-------------.         ,-------------.
 *                                       |      |      |         |      |      |
 *                                ,------|------|------|         |------+------+------.
 *                                |      |      |      |         |      |      |      |
 *                                |      |      |------|         |------|      |      |
 *                                |      |      |      |         |      |      |      |
 *                                `--------------------'         `--------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
    [NPAD] = KEYMAP(  // layer 3: numpad
        // left hand
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                                KC_TRNS,KC_TRNS,
                                                        KC_TRNS,
                                        KC_TRNS,KC_TRNS,KC_TRNS,
        // right hand
        KC_TRNS,KC_NLCK,KC_PSLS,KC_PAST,KC_PAST,KC_PMNS,KC_BSPC,
        KC_TRNS,KC_CALC,KC_P7,  KC_P8,  KC_P9,  KC_PMNS,KC_BSPC,
                KC_NO,  KC_P4,  KC_P5,  KC_P6,  KC_PPLS,KC_PENT,
        KC_TRNS,KC_NO,  KC_P1,  KC_P2,  KC_P3,  KC_PPLS,KC_PENT,
                        KC_P0,  KC_PDOT,KC_SLSH,KC_PENT,KC_PENT,
        KC_TRNS,KC_TRNS,
        KC_TRNS,
        KC_TRNS,KC_TRNS,KC_TRNS
    ),

/* Keymap 4: Left hand shift fn layer
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                       ,-------------.         ,-------------.
 *                                       |      |      |         |      |      |
 *                                ,------|------|------|         |------+------+------.
 *                                |      |      |      |         |      |      | Back |
 *                                |      |Delete|------|         |------|      | Space|
 *                                |      |      |      |         |      |      |      |
 *                                `--------------------'         `--------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
    [LEFT] = KEYMAP(  // layer 4 : Left Space
        // left hand
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                                KC_TRNS,KC_TRNS,
                                                        KC_TRNS,
                                        KC_TRNS,KC_DEL, KC_TRNS,
        // right hand
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
        KC_TRNS,KC_TRNS,
        KC_TRNS,
        KC_TRNS,KC_TRNS,KC_BSPC
    ),
    
/* Keymap 5: Right hand shift fn layer
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      | MRC  |  MU  | MLC  | MSU  |      |           |      |      | MLC  | MMC  | MRC  |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |  ML  |  MD  |  MR  | MSD  |------|           |------| Left | Down | Up   | Right|      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      | MMC  | MSL  | MSR  |      |           |      | MSL  | MSD  | MSU  | MSR  |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                       ,-------------.         ,-------------.
 *                                       |      |      |         |      |      |
 *                                ,------|------|------|         |------+------+------.
 *                                | Back |      |      |         |      |      |      |
 *                                | Space|Delete|------|         |------|      |      |
 *                                |      |      |      |         |      |      |      |
 *                                `--------------------'         `--------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
    [RGHT] = KEYMAP(  // layer 5 : Right Space
        // left hand
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
        KC_TRNS,KC_TRNS,KC_BTN2,KC_MS_U,KC_BTN1,KC_WH_U,KC_TRNS,
        KC_TRNS,KC_TRNS,KC_MS_L,KC_MS_D,KC_MS_R,KC_WH_D,
        KC_TRNS,KC_TRNS,KC_TRNS,KC_BTN3,KC_WH_L,KC_WH_R,KC_TRNS,
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                                KC_TRNS,KC_TRNS,
                                                        KC_TRNS,
                                        KC_BSPC,KC_DEL, KC_TRNS,
        // right hand
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
        KC_TRNS,KC_TRNS,KC_BTN1,KC_BTN3,KC_BTN2,KC_TRNS,KC_TRNS,
                KC_LEFT,KC_DOWN,KC_UP,  KC_RGHT,KC_TRNS,KC_TRNS,
        KC_TRNS,KC_WH_L,KC_WH_D,KC_WH_U,KC_WH_R,KC_TRNS,KC_TRNS,
                        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
        KC_TRNS,KC_TRNS,
        KC_TRNS,
        KC_TRNS,KC_TRNS,KC_TRNS
    ),

/* Keymap ?: Keymap Template
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                       ,-------------.         ,-------------.
 *                                       |      |      |         |      |      |
 *                                ,------|------|------|         |------+------+------.
 *                                |      |      |      |         |      |      |      |
 *                                |      |      |------|         |------|      |      |
 *                                |      |      |      |         |      |      |      |
 *                                `--------------------'         `--------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
    [TEMP] = KEYMAP(  // layer 6 : Keymap Template
        // left hand
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                                KC_TRNS,KC_TRNS,
                                                        KC_TRNS,
                                        KC_TRNS,KC_TRNS,KC_TRNS,
        // right hand
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
        KC_TRNS,KC_TRNS,
        KC_TRNS,
        KC_TRNS,KC_TRNS,KC_TRNS
    ),

};
const uint16_t fn_actions[] = {
    ACTION_LAYER_MOMENTARY(1),                      // FN0 - switch to Layer1
    ACTION_LAYER_SET(2, ON_PRESS),                  // FN1 - set Layer2
    ACTION_LAYER_TOGGLE(3),                         // FN2 - toggle Layer3 aka Numpad layer
    ACTION_LAYER_SET(0, ON_PRESS),                  // FN3 - set Layer0
};

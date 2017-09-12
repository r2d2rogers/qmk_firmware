#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "action_util.h"
#include "version.h"

#define BASE 0 // default layer
#define FKEY 1 // function key layer
#define NPAD 2 // numpad layer
#define RGHT 3 // right space fn layer
#define LEFT 4 // left space fn layer
#define UTIL 5 // keyboard utility layer
#define TEMP 6 // Template for new layers

// Tap Dance
enum {
  SFT_CAPS = 0,
  MPLY_MUTE = 2,
};

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD
};

// Macros
enum macro_id {
  M_USERNAME,
  M_RANDDIGIT,
  M_RANDLETTER,
};
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Keymap 0: Basic layer
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   `    |   1  |   2  |   3  |   4  |   5  |   =  |           | NPAD |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |  [   |           |   ]  |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |Ctrl/Esc|   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   '    |
 * |--------+------+------+------+------+------| ^FKEY|           | ^FKEY|------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | LGui | LAlt |  Ins |   [  |   ]  |                                       | Left | Down |  Up  | Right| RGui |
 *   `----------------------------------'                                       `----------------------------------'
 *                                       ,-------------.         ,-------------.
 *                                       | Ctrl |  Alt |         | Alt  | Ctrl |
 *                                ,------|------|------|         |------+------+------.
 *                                |      | LEFT/| Home |         | PgUp | Enter|Space |
 *                                | SPACE| Back |------|         |------|   /  |  /   |
 *                                |      | Space| End  |         | PgDn | LEFT | RGHT |
 *                                `--------------------'         `--------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*

    [BASE] = KEYMAP(  // layer 0 : default
        // left hand
        KC_GRV, KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_EQL,
        KC_TAB, KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_LBRC,
MT(MOD_LCTL, KC_ESC),   KC_FN0, KC_S,   KC_D,   KC_F,   KC_FN1,
   TD(SFT_CAPS),KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   TT(FKEY),
        KC_LGUI,KC_LALT,KC_INS, KC_LBRC,KC_RBRC,
                                                KC_LCTL,KC_LALT,
                                                        KC_HOME,
                                        KC_SPC, KC_BSPC,KC_END,
        // right hand
        TT(NPAD),KC_6,  KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,
        KC_RBRC, KC_Y,  KC_U,   KC_I,   KC_O,   KC_P,   KC_BSLS,
                 KC_H,  KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,
        TT(FKEY),KC_N,  KC_M,   KC_COMM,KC_DOT, KC_SLSH,KC_RSFT,
                        KC_LEFT,KC_DOWN,KC_UP,  KC_RGHT,KC_RGUI,
        KC_RALT,KC_RCTL,
        KC_PGUP,
        KC_PGDN,LT(LEFT,KC_ENT), LT(RGHT,KC_SPC)
    ),

/* Keymap 1: Function key layer
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | BL_TOGG|  F1  |  F2  |  F3  |  F4  |  F5  |  F11 |           |  F12 |  F6  |  F7  |  F8  |  F9  | F10  | BL_TOGG|
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | BL_INC |  F11 |  F12 |  F13 |  F14 |  F15 |      |           |      | F16  | F17  | F18  | F19  | F20  | BL_INC |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | BL_DEC |      |      |      |      |      |------|           |------|      | MPRV | MPLY | MNXT |      | BL_DEC |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | BL_STEP|      |      |      |      |      |      |           |      |      | MUTE | VOLD | VOLU |      | BL_STEP|
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | UTIL1|      |      |      |      |                                       |      |      |      |      | UTIL1|
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
        BL_TOGG,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F11,
        BL_INC, KC_F11, KC_F12, KC_F13, KC_F14, KC_F15, KC_TRNS,
        BL_DEC, KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
        BL_STEP,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
        OSL(UTIL),KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                                KC_TRNS,KC_TRNS,
                                                        KC_TRNS,
                                        KC_TRNS,KC_TRNS,KC_TRNS,
        // right hand
        KC_F12, KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, BL_TOGG,
        KC_TRNS,KC_F16, KC_F17, KC_F18, KC_F19, KC_F20, BL_INC, 
                KC_TRNS,KC_MPRV,TD(MPLY_MUTE),KC_MNXT,KC_TRNS,BL_DEC,
        KC_TRNS,KC_TRNS,KC_MUTE,KC_VOLD,KC_VOLU,KC_TRNS,BL_STEP,
                        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,OSL(UTIL),
        KC_TRNS,KC_TRNS,
        KC_TRNS,
        KC_TRNS,KC_TRNS,KC_TRNS
    ),

/* Keymap 2: Numpad layer
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  Bksp  | CALC | Nlck |   /  |  *   |  -   |      |           | BASE | CALC | Nlck |  /   |  *   |  -   | Bksp   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |  NO  |  P7  |  P8  |  P9  |  +   |      |           |      |  NO  |  P7  |  P8  |  P9  |  +   | Tab    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  NO  |  P4  |  P5  |  P6  |  +   |------|           |------|  NO  |  P4  |  P5  |  P6  |  +   | Enter  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |   Enter|  NO  |  P1  |  P2  |  P3  | Enter|      |           |      |  NO  |  P1  |  P2  |  P3  | Enter| Enter  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | Enter|  NO  |  P0  |  P0  |   .  |                                       |  P0  |  P0  |  .   | Enter| Enter|
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
        KC_BSPC,KC_CALC,KC_NLCK,KC_PSLS,KC_PAST,KC_PMNS,KC_TRNS,
        KC_TRNS,KC_NO,  KC_P7,  KC_P8,  KC_P9,  KC_PPLS,KC_TRNS,
        KC_TRNS,KC_NO,  KC_P4,  KC_P5,  KC_P6,  KC_PPLS,
        KC_PENT,KC_NO,  KC_P1,  KC_P2,  KC_P3,  KC_PENT,KC_TRNS,
        KC_PENT,KC_NO,  KC_P0,  KC_P0,  KC_PDOT,
                                                KC_TRNS,KC_TRNS,
                                                        KC_TRNS,
                                        KC_TRNS,KC_TRNS,KC_TRNS,
        // right hand
        KC_TRNS,KC_CALC,KC_NLCK,KC_PSLS,KC_PAST,KC_PMNS,KC_BSPC,
        KC_TRNS,KC_NO,  KC_P7,  KC_P8,  KC_P9,  KC_PPLS,KC_TAB, 
                KC_NO,  KC_P4,  KC_P5,  KC_P6,  KC_PPLS,KC_PENT,
        KC_TRNS,KC_NO,  KC_P1,  KC_P2,  KC_P3,  KC_PENT,KC_PENT,
                        KC_P0,  KC_P0,  KC_PDOT,KC_PENT,KC_PENT,
        KC_TRNS,KC_TRNS,
        KC_TRNS,
        KC_TRNS,KC_TRNS,KC_TRNS
    ),

/* Keymap 3: Right hand shift fn layer
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
 *                                |      |      |      |         |      |      |      |
 *                                |      |      |------|         |------|      |      |
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
                                        KC_TRNS,KC_TRNS,KC_TRNS,
        // right hand
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
        KC_TRNS,KC_TRNS,
        KC_TRNS,
        KC_TRNS,KC_TRNS,KC_DEL
    ),
    
/* Keymap 5: Keyboard utility layer
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
        RESET,  KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,TO(BASE),
        DEBUG,  KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
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

const uint16_t PROGMEM fn_actions[] = {
  ACTION_SWAP_HANDS_TAP_KEY(KC_A),
  ACTION_SWAP_HANDS_TAP_KEY(KC_G)
};

qk_tap_dance_action_t tap_dance_actions[] = {
  [SFT_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
  [MPLY_MUTE] = ACTION_TAP_DANCE_DOUBLE(KC_MPLY, KC_MUTE)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
  switch(id) {
    case M_USERNAME:
      if (record->event.pressed) {
        SEND_STRING("r2d2rogers");
      }
      break;
        case 1:
        if (record->event.pressed) {
          SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        }
        break;
        case 2:
        if (record->event.pressed) { // For resetting EEPROM
          eeconfig_init();
        }
        break;
      }
    return MACRO_NONE;
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
        //printf("action_function() called\n");
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_mode(1);
        #endif
      }
      return false;
      break;
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
    debug_enable=true;
    //debug_matrix=true;
    debug_keyboard=true;

    //start_keyframe_animation(&led_test_animation);
    //start_keyframe_animation(&led_short_test_animation);
};


// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 0:
#ifdef SUBPROJECT_infinity
      lcd_backlight_hal_color(5000, 0, 0);
#endif
        case 1:
#ifdef SUBPROJECT_infinity
      lcd_backlight_hal_color(5000, 0, 0);
#endif
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

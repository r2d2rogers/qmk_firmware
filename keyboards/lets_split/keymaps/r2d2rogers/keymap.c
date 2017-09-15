#include "lets_split.h"
#ifdef AUDIO_ENABLE
	#include "audio.h"
#endif
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

#define QWERTY 0
#define LOWER 1
#define UPPER 2
#define SPACEFN 3
#define TKEY 4
#define ADJUST 5

// Tap Dance
enum {
  SFT_CAPS = 0,
  MPLY_MUTE = 1,
};

// Macros
enum macro_id {
  M_UN,
  M_RD,
  M_RL,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Layer 3: QWERTY
 * -------------------------------------------------     -------------------------------------------------
 * |  TAB  |   Q   |   W   |   E   |   R   |   T   |     |   Y   |   U   |   I   |   O   |   P   |  BKSP |
 * -------------------------------------------------     -------------------------------------------------
 * |  ESC  |   A   |   S   |   D   |   F   |   G   |     |   H   |   J   |   K   |   L   |   ;   |   '   |
 * -------------------------------------------------     -------------------------------------------------
 * | SHIFT |   Z   |   X   |   C   |   V   |   B   |     |   N   |   M   |   ,   |   .   |   /   | SHIFT |
 * -------------------------------------------------     -------------------------------------------------
 * | ADJST |  CTRL |  ALT  |  GUI  | SPACE | LOWER |     | RAISE | SPACE |  LEFT |  DOWN |  UP   | RIGHT |
 * -------------------------------------------------     -------------------------------------------------
 */

[QWERTY] = KEYMAP( \
    KC_TAB , KC_Q  , KC_W  , KC_E  , KC_R  , KC_T  ,      KC_Y   , KC_U  , KC_I  , KC_O  , KC_P  ,KC_BSPC, \
CTL_T(KC_ESC), KC_A, KC_S  , KC_D  , KC_F  , KC_G  ,      F(5)   , KC_J  , KC_K  , KC_L  ,KC_SCLN, F(4)  , \
TD(SFT_CAPS) , KC_Z, KC_X  , KC_C  , KC_V  , KC_B  ,      KC_N   , KC_M  ,KC_COMM, KC_DOT,KC_SLSH,MT(MOD_RSFT, KC_ENT), \
 MO(ADJUST), KC_MEH,KC_LALT,KC_LGUI, F(3)  , F(1)  ,      F(2)   , F(3)  ,
                                                            MT(MOD_RGUI, KC_LEFT),KC_DOWN, KC_UP ,KC_RGHT \
),

/* Layer 3: UPPER
 * -------------------------------------------------     -------------------------------------------------
 * |   `   |   1   |   2   |   3   |   4   |   5   |     |   6   |   7   |   8   |   9   |   0   |       |
 * -------------------------------------------------     -------------------------------------------------
 * |       |   4   |   5   |   6   |   .   |       |     |       |   -   |   =   |   [   |   ]   |   \   |
 * -------------------------------------------------     -------------------------------------------------
 * |       |   7   |   8   |   9   |   0   |       |     |       |       |       |   .   |       |       |
 * -------------------------------------------------     -------------------------------------------------
 * |       | HYPER |       |       |       |       |     |       |       | PLYMT | VOLDN | VOLUP |  MFFD |
 * -------------------------------------------------     -------------------------------------------------
 */

[UPPER] = KEYMAP( \
    KC_GRV ,KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5   ,      KC_6   ,KC_7   ,KC_8   ,KC_9   ,KC_0   ,_______, \
    _______,KC_4   ,KC_5   ,KC_6   ,KC_DOT ,_______,      _______,KC_MINS,KC_EQL ,KC_LBRC,KC_RBRC,KC_BSLS, \
    _______,KC_7   ,KC_8   ,KC_9   ,KC_0   ,_______,      _______,_______,_______,KC_DOT ,_______,_______, \
    _______,KC_HYPR,_______,_______,_______,_______,      _______,_______,TD(MPLY_MUTE), KC_VOLD, KC_VOLU, KC_MFFD \
),

/* Layer 3: LOWER
 * -------------------------------------------------     -------------------------------------------------
 * |   ~   |   !   |   @   |   #   |   $   |   %   |     |   ^   |   &   |   *   |   (   |   )   |       |
 * -------------------------------------------------     -------------------------------------------------
 * |       |  F1   |  F2   |  F3   |  F4   |  F5   |     |  F6   |   _   |   +   |   {   |   }   |   |   |
 * -------------------------------------------------     -------------------------------------------------
 * |       |  F7   |  F8   |  F9   |  F10  |  F11  |     |  F12  |       |       |       |       |       |
 * -------------------------------------------------     -------------------------------------------------
 * | 10KEY | HYPER |       |       |       |       |     |       |       |  HOME |  PGDN |  PGUP |  END  |
 * -------------------------------------------------     -------------------------------------------------
 */

[LOWER] = KEYMAP( \
    KC_TILD,KC_EXLM,KC_AT  ,KC_HASH,KC_DLR ,KC_PERC,      KC_CIRC,KC_AMPR,KC_ASTR,KC_LPRN,KC_RPRN,_______, \
    _______,KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,      KC_F6  ,KC_UNDS,KC_PLUS,KC_LCBR,KC_RCBR,KC_PIPE, \
    _______,KC_F7  ,KC_F8  ,KC_F9  ,KC_F10 ,KC_F11 ,      KC_F12 ,_______,_______,_______,_______,_______, \
   TG(TKEY),KC_HYPR,_______,_______,_______,_______,      _______,_______,KC_HOME,KC_PGDN,KC_PGUP,KC_END \
),

/* Layer 3: SPACEFN
 * -------------------------------------------------     -------------------------------------------------
 * |       |       |       |       | UNAME |       |     |       |       |       |       |       | DELETE|
 * -------------------------------------------------     -------------------------------------------------
 * |       |       |       |       | RANDD |       |     |  LEFT |  DOWN |  UP   | RIGHT |       |       |
 * -------------------------------------------------     -------------------------------------------------
 * |       |       |       |       | RANDL |       |     |  HOME |  PGDN |  PGUP |  END  |       | RESET |
 * -------------------------------------------------     -------------------------------------------------
 * |       |       |       |       |       |       |     |       |       |       |       |       |       |
 * -------------------------------------------------     -------------------------------------------------
 */

[SPACEFN] = KEYMAP( \
    _______,_______,_______,_______,M(M_UN),_______,      _______,_______,_______,_______,_______,KC_DELETE, \
    _______,_______,_______,_______,M(M_RD),_______,      KC_LEFT,KC_DOWN,KC_UP  ,KC_RGHT,_______,_______, \
    _______,_______,_______,_______,M(M_RL),_______,      KC_HOME,KC_PGDN,KC_PGUP,KC_END ,_______,RESET, \
    _______,_______,_______,_______,_______,_______,      _______,_______,_______,_______,_______,_______ \
),

/*
 * -------------------------------------------------     -------------------------------------------------
 * |       |       |       |       |       |       |     |       | KP 7  | KP 8  | KP 9  | KP -  |BACKSPC|
 * -------------------------------------------------     -------------------------------------------------
 * |       |       |       |       |       |       |     |       | KP 4  | KP 5  | KP 6  | KP +  | NMLCK |
 * -------------------------------------------------     -------------------------------------------------
 * |       |       |       |       |       |       |     |       | KP 1  | KP 2  | KP 3  | KP .  | KP ENT|
 * -------------------------------------------------     -------------------------------------------------
 * |       |       |       |       |       |       |     |       | KP 0  |       |       |       |       |
 * -------------------------------------------------     -------------------------------------------------
 */

[TKEY] = KEYMAP( \
    _______,_______,_______,_______,_______,_______,      _______,KC_KP_7,KC_KP_8,KC_KP_9,KC_PMNS,KC_BSPC,\
    _______,_______,_______,_______,_______,_______,      _______,KC_KP_4,KC_KP_5,KC_KP_6,KC_PPLS,KC_NLCK,\
    _______,_______,_______,_______,_______,_______,      _______,KC_KP_1,KC_KP_2,KC_KP_3,KC_PDOT,KC_ENT, \
    _______,_______,_______,_______,_______,_______,      _______,KC_KP_0,_______,_______,_______,_______ \
),

/* Layer 5: ADJUST
 * --------------------------------------------------    --------------------------------------------------
 * |AU_ON  |BL_INC |RGB_MOD|RGB_HUI|RGB_SAI|RGB_VAI |    |BL_INC |RGB_MOD|RGB_HUI|RGB_SAI|RGB_VAI |AU_ON  |
 * --------------------------------------------------    --------------------------------------------------
 * |AU_OFF |BL_DEC |RGB_TOG|RGB_HUD|RGB_SAD|RGB_VAD |    |BL_DEC |RGB_TOG|RGB_HUD|RGB_SAD|RGB_VAD |AU_OFF |
 * --------------------------------------------------    --------------------------------------------------
 * |_______|BL_STEP|RGB_M_P|RGB_M_R|RGB_M_SN|RGB_M_X|    |BL_STEP|RGB_M_P|RGB_M_R|RGB_M_SN|RGB_M_X|_______|
 * --------------------------------------------------    --------------------------------------------------
 * |_______|BL_TOGG|RGB_M_B|RGB_M_SW|RGB_M_K|RGB_M_G|    |BL_TOGG|RGB_M_B|RGB_M_SW|RGB_M_K|RGB_M_G|_______|
 * --------------------------------------------------    --------------------------------------------------
 */

[ADJUST] = KEYMAP( \
    AU_ON  ,BL_INC ,RGB_MOD,RGB_HUI,RGB_SAI,RGB_VAI,      BL_INC ,RGB_MOD,RGB_HUI,RGB_SAI,RGB_VAI, AU_ON  ,\
    AU_OFF ,BL_DEC ,RGB_TOG,RGB_HUD,RGB_SAD,RGB_VAD,      BL_DEC ,RGB_TOG,RGB_HUD,RGB_SAD,RGB_VAD, AU_OFF ,\
    _______,BL_STEP,RGB_M_P,RGB_M_R,RGB_M_SN,RGB_M_X,     BL_STEP,RGB_M_P,RGB_M_R,RGB_M_SN,RGB_M_X,_______, \
    _______,BL_TOGG,RGB_M_B,RGB_M_SW,RGB_M_K,RGB_M_G,     BL_TOGG,RGB_M_B,RGB_M_SW,RGB_M_K,RGB_M_G,_______\
),

};
  
const uint16_t PROGMEM fn_actions[] = {
    [0] = ACTION_DEFAULT_LAYER_SET(QWERTY),

    // Tap for backspace, hold for LOWER
    [1] = ACTION_LAYER_TAP_KEY(LOWER, KC_BSPC),

    // Tap for enter, hold for RAISE
    [2] = ACTION_LAYER_TAP_KEY(UPPER, KC_ENT),

    // Tap for space, hold for SpaceFN
    [3] = ACTION_LAYER_TAP_KEY(SPACEFN, KC_SPC),
    [4] = ACTION_SWAP_HANDS_TAP_KEY(KC_QUOT),
    [5] = ACTION_SWAP_HANDS_TAP_KEY(KC_H)
};

qk_tap_dance_action_t tap_dance_actions[] = {
  [SFT_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
  [MPLY_MUTE] = ACTION_TAP_DANCE_DOUBLE(KC_MPLY, KC_MUTE)
};

// This bit of logic seeds a wee linear congruential random number generator
// lots of prime numbers everywhere...
static uint16_t random_value = 157;

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  uint8_t clockbyte=0;
  clockbyte = TCNT1 % 256;
  uint8_t rval;

  // MACRODOWN only works in this function
  switch(id) {
    case M_UN:
      if (record->event.pressed) {
        SEND_STRING("r2d2rogers");
      }
      break;

    case M_RD:
      // Generate, based on random number generator, a keystroke for
      // a numeric digit chosen at random
      random_value = ((random_value + randadd) * randmul) % randmod;
      if (record->event.pressed) {
        // Here, we mix the LCRNG with low bits from one of the system
        // clocks via XOR in the theory that this may be more random
        // than either separately
        rval = (random_value ^ clockbyte) % 10;
        // Note that KC_1 thru KC_0 are a contiguous range
        register_code (KC_1 + rval);
        unregister_code (KC_1 + rval);
      }
      break;

    case M_RL:
      // Generate, based on random number generator, a keystroke for
      // a letter chosen at random
      // Here, we mix the LCRNG with low bits from one of the system
      // clocks via XOR in the theory that this may be more random
      // than either separately
      random_value = ((random_value + randadd) * randmul) % randmod;
      if (record->event.pressed) {
        rval = (random_value ^ clockbyte) % 26;
        register_code (KC_A + rval);
        unregister_code (KC_A + rval);
      }
      break;
  }

  return MACRO_NONE;
};

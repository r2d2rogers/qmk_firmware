#include "lets_split.h"
#include "action_layer.h"
#include "eeconfig.h"
#include "version.h"
#ifdef AUDIO_ENABLE
  #include "audio.h"
#endif

#define QWERTY 0
#define UPPER 1
#define LOWER 2
#define SPACEFN 3
#define TKEY 4
#define ADJUST 5
#define MUSIC 6

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
};

// Tap Dance
enum {
  SFT_CAPS = 0,
  MPLY_MUTE = 1,
};

// Macros
enum macro_id {
  M_UN,
  M_VN,
  M_RE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Layer 0: QWERTY
 * -------------------------------------------------     -------------------------------------------------
 * |  TAB  |   Q   |   W   |   E   |   R   |   T   |     |   Y   |   U   |   I   |   O   |   P   |   \   |
 * -------------------------------------------------     -------------------------------------------------
 * |  ESC  | A/Flip|   S   |   D   |   F   | G/Flip|     | H/Flip|   J   |   K   |   L   |   ;   | '/Flip|
 * -------------------------------------------------     -------------------------------------------------
 * | LSHIFT|   Z   |   X   |   C   |   V   |   B   |     |   N   |   M   |   ,   |   .   |   /   |RSHIFT |
 * -------------------------------------------------     -------------------------------------------------
 * | ADJST |  CTRL |  ALT  |  GUI  | SPACE | LOWER |     | RAISE | SPACE |  LEFT |  DOWN |  UP   | RIGHT |
 * -------------------------------------------------     -------------------------------------------------
 */

[QWERTY] = KEYMAP( \
    KC_TAB , KC_Q  , KC_W  , KC_E  , KC_R  , KC_T  ,      KC_Y   , KC_U  , KC_I  , KC_O  , KC_P  ,KC_BSLS, \
CTL_T(KC_ESC), F(3), KC_S  , KC_D  , KC_F  , F(4)  ,      F(5)   , KC_J  , KC_K  , KC_L  ,KC_SCLN, F(6)  , \
TD(SFT_CAPS) , KC_Z, KC_X  , KC_C  , KC_V  , KC_B  ,      KC_N   , KC_M  ,KC_COMM, KC_DOT,KC_SLSH,         \
                                                                                     MT(MOD_RSFT, KC_ENT), \
 MO(ADJUST), KC_MEH,KC_LALT,KC_LGUI, F(0)  , F(1)  ,      F(2)   , F(0)  ,                                 \
                                                            MT(MOD_RGUI, KC_LEFT),KC_DOWN, KC_UP ,KC_RGHT  \
),

/* Layer 1: UPPER
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
    _______,KC_HYPR,_______,_______,_______,_______,      _______,_______,                                 \
                                                                    TD(MPLY_MUTE),KC_VOLD,KC_VOLU,KC_MFFD  \
),

/* Layer 2: LOWER
 * -------------------------------------------------     -------------------------------------------------
 * |   ~   |   !   |   @   |   #   |   $   |   %   |     |   ^   |   &   |   *   |   (   |   )   |       |
 * -------------------------------------------------     -------------------------------------------------
 * |       |  F1   |  F2   |  F3   |  F4   |  F5   |     |  F11  |   _   |   +   |   {   |   }   |   |   |
 * -------------------------------------------------     -------------------------------------------------
 * |       |  F6   |  F7   |  F8   |  F9   |  F10  |     |  F12  |       |       |       |       |       |
 * -------------------------------------------------     -------------------------------------------------
 * | 10KEY | HYPER |       |       |       |       |     |       |       |  HOME |  PGDN |  PGUP |  END  |
 * -------------------------------------------------     -------------------------------------------------
 */

[LOWER] = KEYMAP( \
    KC_TILD,KC_EXLM,KC_AT  ,KC_HASH,KC_DLR ,KC_PERC,      KC_CIRC,KC_AMPR,KC_ASTR,KC_LPRN,KC_RPRN,_______, \
    _______,KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,      KC_F11 ,KC_UNDS,KC_PLUS,KC_LCBR,KC_RCBR,KC_PIPE, \
  TG(MUSIC),KC_F7  ,KC_F7  ,KC_F8  ,KC_F9  ,KC_F10 ,      KC_F12 ,_______,_______,_______,_______,_______, \
   TG(TKEY),KC_HYPR,_______,_______,_______,_______,      _______,_______,KC_HOME,KC_PGDN,KC_PGUP,KC_END   \
),

/* Layer 3: SPACEFN
 * -------------------------------------------------     -------------------------------------------------
 * |       |       |MsRtClk|MsMdClk|MsLtClk| UNAME |     |ScrollL|ScrollD|ScrollU|ScrollR|       | DELETE|
 * -------------------------------------------------     -------------------------------------------------
 * |       |       |MseLeft| MseUp |MseDown|MseRght|     |  LEFT |  DOWN |  UP   | RIGHT |       |       |
 * -------------------------------------------------     -------------------------------------------------
 * |       |       |ScrollL|ScrollU|ScrollD|ScrollR|     |  HOME |  PGDN |  PGUP |  END  |       | RESET |
 * -------------------------------------------------     -------------------------------------------------
 * |       |       |       |       |       |       |     |       |       |       |       |       |       |
 * -------------------------------------------------     -------------------------------------------------
 */

[SPACEFN] = KEYMAP( \
    _______,_______,KC_BTN2,KC_BTN3,KC_BTN1,M(M_UN),      KC_WH_L,KC_WH_D,KC_WH_U,KC_WH_R,_______,KC_DELE, \
    _______,_______,KC_MS_L,KC_MS_U,KC_MS_D,KC_MS_R,      KC_LEFT,KC_DOWN,KC_UP  ,KC_RGHT,_______,_______, \
    _______,_______,KC_WH_L,KC_WH_U,KC_WH_D,KC_WH_R,      KC_HOME,KC_PGDN,KC_PGUP,KC_END ,_______,RESET  , \
    _______,_______,_______,_______,_______,_______,      _______,_______,_______,_______,_______,_______  \
),

/* Layer 4: ADJUST
 * --------------------------------------------------    --------------------------------------------------
 * |BL_INC |RGB_MOD|RGB_HUI|RGB_SAI|RGB_VAI |AU_ON  |    |AU_ON  |RGB_MOD|RGB_HUI|RGB_SAI|RGB_VAI |BL_INC |
 * --------------------------------------------------    --------------------------------------------------
 * |BL_DEC |RGB_TOG|RGB_HUD|RGB_SAD|RGB_VAD |AU_OFF |    |AU_OFF |RGB_TOG|RGB_HUD|RGB_SAD|RGB_VAD |BL_DEC |
 * --------------------------------------------------    --------------------------------------------------
 * |BL_STEP| Plain |Rainbow| Snake |Christms|MU_TOG |    |MU_MOD | Plain |Rainbow| Snake |Christms|BL_STEP|
 * --------------------------------------------------    --------------------------------------------------
 * |BL_TOGG|Breathe| Swirl | Knight|Gradient|_______|    |_______|Breathe| Swirl | Knight|Gradient|BL_TOGG|
 * --------------------------------------------------    --------------------------------------------------
 */

[ADJUST] = KEYMAP( \
    BL_INC ,RGB_MOD,RGB_HUI,RGB_SAI,RGB_VAI, AU_ON  ,     AU_ON  ,RGB_MOD,RGB_HUI,RGB_SAI,RGB_VAI ,BL_INC , \
    BL_DEC ,RGB_TOG,RGB_HUD,RGB_SAD,RGB_VAD, AU_OFF ,     AU_OFF ,RGB_TOG,RGB_HUD,RGB_SAD,RGB_VAD ,BL_DEC , \
    BL_STEP,RGB_M_P,RGB_M_R,RGB_M_SN,RGB_M_X,MU_TOG ,     MU_MOD ,RGB_M_P,RGB_M_R,RGB_M_SN,RGB_M_X,BL_STEP, \
    BL_TOGG,RGB_M_B,RGB_M_SW,RGB_M_K,RGB_M_G,_______,     _______,RGB_M_B,RGB_M_SW,RGB_M_K,RGB_M_G,BL_TOGG  \
),

[MUSIC] = KEYMAP(\
    KC_NO  ,KC_NO  ,KC_NO  ,KC_NO  , KC_NO  ,KC_NO  ,     KC_NO  ,KC_NO  , KC_NO  ,KC_NO  ,KC_NO  ,KC_NO  , \
    KC_NO  ,KC_NO  ,KC_NO  ,KC_NO  , KC_NO  ,KC_NO  ,     KC_NO  ,KC_NO  , KC_NO  ,KC_NO  ,KC_NO  ,KC_NO  , \
    KC_NO  ,KC_NO  ,KC_NO  ,KC_NO  , KC_NO  ,KC_NO  ,     KC_NO  ,KC_NO  , KC_NO  ,KC_NO  ,KC_NO  ,KC_NO  , \
    KC_NO  ,KC_NO  ,KC_NO  ,KC_NO  , KC_NO  ,KC_NO  ,     KC_NO  ,KC_NO  , KC_NO  ,KC_NO  ,KC_NO  ,KC_NO    \
),

};
  
const uint16_t PROGMEM fn_actions[] = {
  // Tap for space, hold for SpaceFN
  [0] = ACTION_LAYER_TAP_KEY(SPACEFN, KC_SPC),
  // Tap for backspace, hold for LOWER
  [1] = ACTION_LAYER_TAP_KEY(LOWER, KC_BSPC),
  // Tap for enter, hold for RAISE
  [2] = ACTION_LAYER_TAP_KEY(UPPER, KC_ENT),

  [3] = ACTION_SWAP_HANDS_TAP_KEY(KC_A),
  [4] = ACTION_SWAP_HANDS_TAP_KEY(KC_G),
  [5] = ACTION_SWAP_HANDS_TAP_KEY(KC_H),
  [6] = ACTION_SWAP_HANDS_TAP_KEY(KC_QUOT)
};

qk_tap_dance_action_t tap_dance_actions[] = {
  [SFT_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
  [MPLY_MUTE] = ACTION_TAP_DANCE_DOUBLE(KC_MPLY, KC_MUTE)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
  // MACRODOWN only works in this function
  switch(id) {
    case M_UN:
      if (record->event.pressed) {
        SEND_STRING("r2d2rogers");
      }
      break;
    case M_VN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      break;
    case M_RE:
      if (record->event.pressed) { // For resetting EEPROM
        eeconfig_init();
      }
      break;
  }
  return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
    //debug_enable=true;
    //debug_matrix=true;
    //debug_keyboard=true;
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    switch (layer) {
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
};

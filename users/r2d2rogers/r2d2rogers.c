#include "r2d2rogers.h"
#include "quantum.h"
#include "action.h"
#include "version.h"


#if __has_include("secrets.h")
#include "secrets.h"
#else
// `PROGMEM const char secret[][x]` may work better, but it takes up more space in the firmware
// And I'm not familar enough to know which is better or why...
PROGMEM const char secret[][64] = {
  "test1",
  "test2",
  "test3",
  "test4",
  "test5"
};
#endif

/* IDEAS
 *
 * Macros, Tapdance,
 * Username short cut
 * make command, shift for make and flash
 * Layers, names purpose?
 * sounds
 * lights
 * joystick
 *
 */

// Add reconfigurable functions here, for keymap customization
// This allows for a global, userspace functions, and continued
// customization of the keymap.  Use _keymap instead of _user
// functions in the keymaps
__attribute__ ((weak))
void matrix_init_keymap(void) {}

__attribute__ ((weak))
void matrix_scan_keymap(void) {}

__attribute__ ((weak))
bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  return true;
}
__attribute__ ((weak))
uint32_t layer_state_set_keymap (uint32_t state) {
  return state;
}

<<<<<<< HEAD
bool is_overwatch = false;
=======
__attribute__ ((weak))
void led_set_keymap(uint8_t usb_led) {}
>>>>>>> r2d2rogers

// Call user matrix init, set default RGB colors and then
// call the keymap's init function
void matrix_init_user(void) {
#ifdef RGBLIGHT_ENABLE
  uint8_t default_layer = eeconfig_read_default_layer();

  rgblight_enable();

  if (true) {
    if (default_layer & (1UL << _COLEMAK)) {
      rgblight_set_magenta;
    }
    else if (default_layer & (1UL << _DVORAK)) {
      rgblight_set_green;
    }
    else if (default_layer & (1UL << _WORKMAN)) {
      rgblight_set_purple;
    }
    else {
      rgblight_set_teal;
    }
  }
  else
  {
    rgblight_set_red;
    rgblight_mode(5);
  }
#endif
<<<<<<< HEAD
  matrix_init_keymap();
}

// No global matrix scan code, so just run keymap's matix
// scan function
void matrix_scan_user(void) {
  matrix_scan_keymap();
}

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float tone_dvorak[][2]     = SONG(DVORAK_SOUND);
float tone_colemak[][2]    = SONG(COLEMAK_SOUND);
float tone_workman[][2]    = SONG(PLOVER_SOUND);
#endif


void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

// Defines actions tor my global custom keycodes. Defined in r2d2rogers.h file
// Then runs the _keymap's recod handier if not processed here
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  
=======
#ifdef AUDIO_ENABLE
//  wait_ms(21); // gets rid of tick
//  stop_all_notes();
//  PLAY_SONG(tone_hackstartup);
#endif
  matrix_init_keymap();
}


void led_set_user(uint8_t usb_led) {
  led_set_keymap(usb_led);
}


// Defines actions tor my global custom keycodes. Defined in r2d2rogers.h file
// Then runs the _keymap's recod handier if not processed here
bool process_record_user(uint16_t keycode, keyrecord_t *record) {

>>>>>>> r2d2rogers
#ifdef CONSOLE_ENABLE
  xprintf("KL: row: %u, column: %u, pressed: %u\n", record->event.key.col, record->event.key.row, record->event.pressed);
#endif

  switch (keycode) {
  case KC_QWERTY:
    if (record->event.pressed) {
#ifdef AUDIO_ENABLE
      PLAY_SONG(tone_qwerty);
#endif
      persistent_default_layer_set(1UL << _QWERTY);
    }
    return false;
    break;
  case KC_COLEMAK:
    if (record->event.pressed) {
#ifdef AUDIO_ENABLE
      PLAY_SONG(tone_colemak);
#endif
      persistent_default_layer_set(1UL << _COLEMAK);
    }
    return false;
    break;
  case KC_DVORAK:
    if (record->event.pressed) {
#ifdef AUDIO_ENABLE
      PLAY_SONG(tone_dvorak);
#endif
      persistent_default_layer_set(1UL << _DVORAK);
    }
    return false;
    break;
  case KC_WORKMAN:
    if (record->event.pressed) {
#ifdef AUDIO_ENABLE
      PLAY_SONG(tone_workman);
#endif
      persistent_default_layer_set(1UL << _WORKMAN);
    }
    return false;
    break;
  case LOWER:
    if (record->event.pressed) {
      layer_on(_LOWER);
      update_tri_layer(_LOWER, _RAISE, _ADJUST);
    }
    else {
      layer_off(_LOWER);
      update_tri_layer(_LOWER, _RAISE, _ADJUST);
    }
    return false;
    break;
  case RAISE:
    if (record->event.pressed) {
      layer_on(_RAISE);
      update_tri_layer(_LOWER, _RAISE, _ADJUST);
    }
    else {
      layer_off(_RAISE);
      update_tri_layer(_LOWER, _RAISE, _ADJUST);
    }
    return false;
    break;
  case ADJUST:
    if (record->event.pressed) {
      layer_on(_ADJUST);
    }
    else {
      layer_off(_ADJUST);
    }
    return false;
    break;
<<<<<<< HEAD
#if !(defined(KEYBOARD_orthodox_rev1) || defined(KEYBOARD_ergodox_ez))
  case KC_OVERWATCH:
    if (record->event.pressed) {
      is_overwatch = !is_overwatch;
    }
#ifdef RGBLIGHT_ENABLE
    is_overwatch ? rgblight_mode(17) : rgblight_mode(18);
#endif
    return false;
    break;
  case KC_SALT:
    if (!record->event.pressed) {
      register_code(is_overwatch ? KC_BSPC : KC_ENTER);
      unregister_code(is_overwatch ? KC_BSPC : KC_ENTER);
      _delay_ms(50);
      SEND_STRING("Salt, salt, salt...");
      register_code(KC_ENTER);
      unregister_code(KC_ENTER);
    }
    return false;
    break;
  case KC_MORESALT:
    if (!record->event.pressed) {
      register_code(is_overwatch ? KC_BSPC : KC_ENTER);
      unregister_code(is_overwatch ? KC_BSPC : KC_ENTER);
      _delay_ms(50);
      SEND_STRING("Please sir, can I have some more salt?!");
      register_code(KC_ENTER);
      unregister_code(KC_ENTER);
    }
    return false;
    break;
  case KC_SALTHARD:
    if (!record->event.pressed) {
      register_code(is_overwatch ? KC_BSPC : KC_ENTER);
      unregister_code(is_overwatch ? KC_BSPC : KC_ENTER);
      _delay_ms(50);
      SEND_STRING("Your salt only makes me harder, and even more aggressive!");
      register_code(KC_ENTER);
      unregister_code(KC_ENTER);
    }
    return false;
    break;
  case KC_GOODGAME:
    if (!record->event.pressed) {
      register_code(is_overwatch ? KC_BSPC : KC_ENTER);
      unregister_code(is_overwatch ? KC_BSPC : KC_ENTER);
      _delay_ms(50);
      SEND_STRING("Good game, everyone!");
      register_code(KC_ENTER);
      unregister_code(KC_ENTER);
  }
    return false;
    break;
  case KC_GLHF:
    if (!record->event.pressed) {
      register_code(is_overwatch ? KC_BSPC : KC_ENTER);
      unregister_code(is_overwatch ? KC_BSPC : KC_ENTER);
      _delay_ms(50);
      SEND_STRING("Good luck, have fun!!!");
      register_code(KC_ENTER);
      unregister_code(KC_ENTER);
    }
    return false;
    break;
  case KC_SYMM:
    if (!record->event.pressed) {
      register_code(is_overwatch ? KC_BSPC : KC_ENTER);
      unregister_code(is_overwatch ? KC_BSPC : KC_ENTER);
      _delay_ms(50);
      SEND_STRING("Left click to win!");
      register_code(KC_ENTER);
      unregister_code(KC_ENTER);
    }
    return false;
    break;
  case KC_JUSTGAME:
    if (!record->event.pressed) {
      register_code(is_overwatch ? KC_BSPC : KC_ENTER);
      unregister_code(is_overwatch ? KC_BSPC : KC_ENTER);
      _delay_ms(50);
      SEND_STRING("It may be a game, but if you don't want to actually try, please go play AI, so that people that actually want to take the game seriously and \"get good\" have a place to do so without trolls like you throwing games.");
      register_code(KC_ENTER);
      unregister_code(KC_ENTER);
    }
    return false;
    break;
  case KC_TORB:
    if (!record->event.pressed) {
      register_code(is_overwatch ? KC_BSPC : KC_ENTER);
      unregister_code(is_overwatch ? KC_BSPC : KC_ENTER);
      _delay_ms(50);
      SEND_STRING("That was positively riveting!");
      register_code(KC_ENTER);
      unregister_code(KC_ENTER);
    }
    return false;
    break;
  case KC_AIM:
    if (!record->event.pressed) {
      register_code(is_overwatch ? KC_BSPC : KC_ENTER);
      unregister_code(is_overwatch ? KC_BSPC : KC_ENTER);
      _delay_ms(50);
      SEND_STRING("That aim is absolutely amazing. It's almost like you're a machine!" SS_TAP(X_ENTER));
      _delay_ms(50);
      SEND_STRING("Wait! That aim is TOO good!  You're clearly using an aim hack! CHEATER!" SS_TAP(X_ENTER));
    }
    return false;
    break;
#endif
  case KC_MAKE:
    if (!record->event.pressed) {
      SEND_STRING("make " QMK_KEYBOARD ":" QMK_KEYMAP);
#ifndef CATERINA_BOOTLOADER
      SEND_STRING(":teensy ");
#else
      SEND_STRING(" ");
#endif
#ifdef RGBLIGHT_ENABLE
      SEND_STRING("RGBLIGHT_ENABLE=yes ");
#else
      SEND_STRING("RGBLIGHT_ENABLE=no ");
#endif
#ifdef AUDIO_ENABLE
      SEND_STRING("AUDIO_ENABLE=yes ");
#else
      SEND_STRING("AUDIO_ENABLE=no ");
#endif
#ifdef FAUXCLICKY_ENABLE
      SEND_STRING("FAUXCLICKY_ENABLE=yes ");
#else
      SEND_STRING("FAUXCLICKY_ENABLE=no ");
#endif
      SEND_STRING(SS_TAP(X_ENTER));
=======
  case KC_MAKE:
    if (!record->event.pressed) {
      SEND_STRING("make " QMK_KEYBOARD ":" QMK_KEYMAP
#if  (defined(BOOTLOADER_DFU) || defined(BOOTLOADER_LUFA_DFU) || defined(BOOTLOADER_QMK_DFU))
       ":dfu"
#elif defined(BOOTLOADER_HALFKAY)
      ":teensy"
//#elif defined(BOOTLOADER_CATERINA)
//       ":avrdude"
#endif
        SS_TAP(X_ENTER));
>>>>>>> r2d2rogers
    }
    return false;
    break;
  case KC_RESET:
    if (!record->event.pressed) {
#ifdef RGBLIGHT_ENABLE
      rgblight_enable();
      rgblight_mode(1);
      rgblight_setrgb(0xff, 0x00, 0x00);
#endif
      reset_keyboard();
    }
    return false;
    break;
  case EPRM:
    if (record->event.pressed) {
      eeconfig_init();
    }
    return false;
    break;
  case VRSN:
    if (record->event.pressed) {
      SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
    }
    return false;
    break;
  case USER:
    if (record->event.pressed) {
      SEND_STRING("r2d2rogers");
    }
    return false;
    break;
  case KC_SECRET_1 ... KC_SECRET_5:
    if (!record->event.pressed) {
      send_string_P(secret[keycode - KC_SECRET_1]);
    }
    return false;
    break;
  case KC_RGB_T:  // Because I want the option to go back to normal RGB mode rather than always layer indication
#ifdef RGBLIGHT_ENABLE
    if (record->event.pressed) {
      rgb_layer_change = !rgb_layer_change;
    }
#endif
    return false;
    break;
#ifdef RGBLIGHT_ENABLE
  case RGB_MODE_FORWARD ... RGB_MODE_GRADIENT: // quantum_keycodes.h L400 for definitions
    if (record->event.pressed) { //This disrables layer indication, as it's assumed that if you're changing this ... you want that disabled
      rgb_layer_change = false;
    }
    return true;
    break;
#endif
#ifdef TAP_DANCE_ENABLE
#endif
  }
  return process_record_keymap(keycode, record);
}

// Runs state check and changes underglow color and animation
// on layer change, no matter where the change was initiated
// Then runs keymap's layer change check
uint32_t layer_state_set_user(uint32_t state) {
#ifdef RGBLIGHT_ENABLE
  uint8_t default_layer = eeconfig_read_default_layer();
  if (rgb_layer_change) {
    switch (biton32(state)) {
    case _RAISE:
      rgblight_set_yellow;
      rgblight_mode(5);
      break;
    case _LOWER:
      rgblight_set_orange;
      rgblight_mode(5);
      break;
    case _ADJUST:
      rgblight_set_red;
      rgblight_mode(23);
      break;
    default:
      if (default_layer & (1UL << _COLEMAK)) {
        rgblight_set_magenta;
      }
      else if (default_layer & (1UL << _DVORAK)) {
        rgblight_set_green;
      }
      else if (default_layer & (1UL << _WORKMAN)) {
        rgblight_set_goldenrod;
      }
      else {
        rgblight_set_teal;
      }
      break;
    }
  }
#endif
  return layer_state_set_keymap (state);
}

#include "r2d2rogers.h"
#include "version.h"

/*
 * Macros, Tapdance,
 * Username short cut
 * make command, shift for make and flash
 * Layers, names purpose?
 * sounds
 * lights
 * joystick
 *
 */

#if (__has_include("secrets.h") && !defined(NO_SECRETS))
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


float tone_copy[][2]            = SONG(SCROLL_LOCK_ON_SOUND);
float tone_paste[][2]           = SONG(SCROLL_LOCK_OFF_SOUND);


userspace_config_t userspace_config;

//  Helper Functions
void tap(uint16_t keycode){ register_code(keycode); unregister_code(keycode); };

#ifdef RGBLIGHT_ENABLE
void rgblight_sethsv_default_helper(uint8_t index) {
  uint8_t default_layer = eeconfig_read_default_layer();
  if (default_layer & (1UL << _COLEMAK)) {
    rgblight_sethsv_at(300, 255, 255, index);
    rgblight_sethsv_at(300, 255, 255, index);
  }
  else if (default_layer & (1UL << _DVORAK)) {
    rgblight_sethsv_at(120, 255, 255, index);
    rgblight_sethsv_at(120, 255, 255, index);
  }
  else if (default_layer & (1UL << _WORKMAN)) {
    rgblight_sethsv_at(43, 255, 255, index);
    rgblight_sethsv_at(43, 255, 255, index);
  }
  else {
    rgblight_sethsv_at(180, 255, 255, index);
    rgblight_sethsv_at(180, 255, 255, index);
  }
}
#endif // RGBLIGHT_ENABLE



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

__attribute__ ((weak))
void led_set_keymap(uint8_t usb_led) {}


// Call user matrix init, set default RGB colors and then
// call the keymap's init function
void matrix_init_user(void) {
  uint8_t default_layer = eeconfig_read_default_layer();
  userspace_config.raw = eeprom_read_byte(EECONFIG_USERSPACE);

#ifdef BOOTLOADER_CATERINA
  DDRD &= ~(1<<5);
  PORTD &= ~(1<<5);

  DDRB &= ~(1<<0);
  PORTB &= ~(1<<0);
#endif

  if (userspace_config.rgb_layer_change) {
#ifdef RGBLIGHT_ENABLE
    rgblight_enable();
#endif // RGBLIGHT_ENABLE
    if (default_layer & (1UL << _COLEMAK)) {
  #ifdef RGBLIGHT_ENABLE
      rgblight_sethsv_magenta();
  #endif // RGBLIGHT_ENABLE
    } else if (default_layer & (1UL << _DVORAK)) {
  #ifdef RGBLIGHT_ENABLE
      rgblight_sethsv_green();
  #endif // RGBLIGHT_ENABLE
    } else if (default_layer & (1UL << _WORKMAN)) {
  #ifdef RGBLIGHT_ENABLE
      rgblight_sethsv_goldenrod();
  #endif // RGBLIGHT_ENABLE
    } else {
  #ifdef RGBLIGHT_ENABLE
      rgblight_sethsv_teal();
  #endif // RGBLIGHT_ENABLE
    }
  }

}
// No global matrix scan code, so just run keymap's matrix
// scan function
void matrix_scan_user(void) {

  matrix_scan_keymap();
}



// Defines actions tor my global custom keycodes. Defined in r2d2rogers.h file
// Then runs the _keymap's recod handier if not processed here
bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  // If console is enabled, it will print the matrix position and status of each key pressed
#ifdef CONSOLE_ENABLE
  xprintf("KL: row: %u, column: %u, pressed: %u\n", record->event.key.col, record->event.key.row, record->event.pressed);
#endif //CONSOLE_ENABLE


  switch (keycode) {
  case KC_QWERTY:
    if (record->event.pressed) {
      set_single_persistent_default_layer(_QWERTY);
    }
    return false;
    break;
  case KC_COLEMAK:
    if (record->event.pressed) {
      set_single_persistent_default_layer(_COLEMAK);
    }
    return false;
    break;
  case KC_DVORAK:
    if (record->event.pressed) {
      set_single_persistent_default_layer(_DVORAK);
    }
    return false;
    break;
  case KC_WORKMAN:
    if (record->event.pressed) {
      set_single_persistent_default_layer(_WORKMAN);
    }
    return false;
    break;


  case KC_MAKE:  // Compiles the firmware, and adds the flash command based on keyboard bootloader
    if (!record->event.pressed) {
      SEND_STRING("make " QMK_KEYBOARD ":" QMK_KEYMAP
#if  (defined(BOOTLOADER_DFU) || defined(BOOTLOADER_LUFA_DFU) || defined(BOOTLOADER_QMK_DFU))
                   ":dfu"
#elif defined(BOOTLOADER_HALFKAY)
                   ":teensy"
#elif defined(BOOTLOADER_CATERINA)
                   ":avrdude"
#endif // bootloader options
                   SS_TAP(X_ENTER));
    }
    return false;
    break;


  case KC_RESET: // Custom RESET code that sets RGBLights to RED
    if (!record->event.pressed) {
#ifdef RGBLIGHT_ENABLE
      rgblight_enable();
      rgblight_mode(1);
      rgblight_setrgb_red();
#endif // RGBLIGHT_ENABLE
      reset_keyboard();
    }
    return false;
    break;


  case EPRM: // Resets EEPROM
    if (record->event.pressed) {
      eeconfig_init();
    }
    return false;
    break;
  case VRSN: // Prints firmware version
    if (record->event.pressed) {
      SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION ", Built on: " QMK_BUILDDATE);
    }
    return false;
    break;


  case KC_SECRET_1 ... KC_SECRET_5: // Secrets!  Externally defined strings, not stored in repo
    if (!record->event.pressed) {
      clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
      send_string_P(secret[keycode - KC_SECRET_1]);
      }
    return false;
     break;


    case USER:
      if (record->event.pressed) {
        SEND_STRING(QMK_KEYBOARD);
      }
      return false;
      break;
#ifdef RGBLIGHT_ENABLE
   case RGB_MODE_FORWARD ... RGB_MODE_GRADIENT: // quantum_keycodes.h L400 for definitions
      if (record->event.pressed) { //This disables layer indication, as it's assumed that if you're changing this ... you want that disabled
        userspace_config.rgb_layer_change = false;
        eeprom_update_byte(EECONFIG_USERSPACE, userspace_config.raw);
      }
      return true; break;
#endif
  }
  return process_record_keymap(keycode, record);
}

// Runs state check and changes underglow color and animation
// on layer change, no matter where the change was initiated
// Then runs keymap's layer change check
uint32_t layer_state_set_user(uint32_t state) {
  uint8_t default_layer = eeconfig_read_default_layer();
  state = update_tri_layer_state(state, _RAISE, _LOWER, _ADJUST);

  switch (biton32(state)) {
    case _RAISE:
#ifdef RGBLIGHT_ENABLE
      if (userspace_config.rgb_layer_change) {
        rgblight_sethsv_yellow();
        rgblight_mode(5);
      }
#endif // RGBLIGHT_ENABLE

      break;
    case _LOWER:
#ifdef RGBLIGHT_ENABLE
      if (userspace_config.rgb_layer_change) {
        rgblight_sethsv_orange();
        rgblight_mode(5);
      }
#endif // RGBLIGHT_ENABLE

      break;
    case _ADJUST:
#ifdef RGBLIGHT_ENABLE
      if (userspace_config.rgb_layer_change) {
        rgblight_sethsv_red();
        rgblight_mode(23);
      }
#endif // RGBLIGHT_ENABLE

      break;
    default: //  for any other layers, or the default layer
      if (default_layer & (1UL << _COLEMAK)) {
#ifdef RGBLIGHT_ENABLE
        if (userspace_config.rgb_layer_change) { rgblight_sethsv_magenta(); }
#endif // RGBLIGHT_ENABLE

      }
      else if (default_layer & (1UL << _DVORAK)) {
#ifdef RGBLIGHT_ENABLE
        if (userspace_config.rgb_layer_change) { rgblight_sethsv_green(); }
#endif // RGBLIGHT_ENABLE

      }
      else if (default_layer & (1UL << _WORKMAN)) {
#ifdef RGBLIGHT_ENABLE
        if (userspace_config.rgb_layer_change) { rgblight_sethsv_goldenrod(); }
#endif // RGBLIGHT_ENABLE

      }
      else {
#ifdef RGBLIGHT_ENABLE
        if (userspace_config.rgb_layer_change) { rgblight_sethsv_teal(); }
#endif // RGBLIGHT_ENABLE

      }
#ifdef RGBLIGHT_ENABLE
      if (userspace_config.rgb_layer_change) { rgblight_mode(1); }
#endif // RGBLIGHT_ENABLE

      break;
  }
  return layer_state_set_keymap (state);
}


// Any custom LED code goes here.
// So far, I only have keyboard specific code,
// So nothing goes here.
void led_set_user(uint8_t usb_led) {
  led_set_keymap(usb_led);
}

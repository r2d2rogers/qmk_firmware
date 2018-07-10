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

#include "r2d2rogers.h"
#include "version.h"
#include "eeprom.h"
#include "tap_dances.h"
#include "rgb_stuff.h"


float tone_copy[][2]            = SONG(SCROLL_LOCK_ON_SOUND);
float tone_paste[][2]           = SONG(SCROLL_LOCK_OFF_SOUND);

// static uint16_t copy_paste_timer;
userspace_config_t userspace_config;

//  Helper Functions


void tap(uint16_t keycode){ register_code(keycode); unregister_code(keycode); };


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
bool process_record_secrets(uint16_t keycode, keyrecord_t *record) {
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
  userspace_config.raw = eeprom_read_byte(EECONFIG_USERSPACE);

#ifdef AUDIO_CLICKY
  clicky_enable = userspace_config.clicky_enable;
#endif

#ifdef BOOTLOADER_CATERINA
  DDRD &= ~(1<<5);
  PORTD &= ~(1<<5);

  DDRB &= ~(1<<0);
  PORTB &= ~(1<<0);
#endif


  matrix_init_rgb();
  matrix_init_keymap();
}


// No global matrix scan code, so just run keymap's matrix
// scan function
void matrix_scan_user(void) {

#ifdef RGBLIGHT_ENABLE
  matrix_scan_rgb();
#endif // RGBLIGHT_ENABLE

  matrix_scan_keymap();
}


//void matrix_slave_scan_user(void){
  //matrix_slave_scan_keymap();
//}

//__attribute__ ((weak))
//void matrix_slave_scan_keymap(void){
//}


// Defines actions tor my global custom keycodes. Defined in r2d2rogers.h file
// Then runs the _keymap's record handier if not processed here
bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  // If console is enabled, it will print the matrix position and status of each key pressed
#ifdef KEYLOGGER_ENABLE
  xprintf("KL: row: %u, column: %u, pressed: %u\n", record->event.key.col, record->event.key.row, record->event.pressed);
#endif //KEYLOGGER_ENABLE

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
      rgblight_enable_noeeprom();
      rgblight_mode_noeeprom(1);
      rgblight_setrgb_red();
#endif // RGBLIGHT_ENABLE
      reset_keyboard();
    }
    return false;
    break;


  case EPRM: // Resets EEPROM
    if (record->event.pressed) {
      eeconfig_init();
      default_layer_set(1UL<<eeconfig_read_default_layer());
      layer_state_set(layer_state);
    }
    return false;
    break;
  case VRSN: // Prints firmware version
    if (record->event.pressed) {
      SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION ", Built on: " QMK_BUILDDATE);
    }
    return false;
    break;

    case USER:
      if (record->event.pressed) {
        SEND_STRING(QMK_KEYMAP);
      }
      return false;
      break;
  }
  return process_record_keymap(keycode, record) && process_record_secrets(keycode, record) && process_record_user_rgb(keycode, record);
}



// Runs state check and changes underglow color and animation
// on layer change, no matter where the change was initiated
// Then runs keymap's layer change check
uint32_t layer_state_set_user(uint32_t state) {
  state = update_tri_layer_state(state, _RAISE, _LOWER, _ADJUST);
#ifdef RGBLIGHT_ENABLE
  state = layer_state_set_rgb(state);
#endif // RGBLIGHT_ENABLE
  return layer_state_set_keymap (state);
}


// Any custom LED code goes here.
// So far, I only have keyboard specific code,
// So nothing goes here.
void led_set_user(uint8_t usb_led) {
  led_set_keymap(usb_led);
}

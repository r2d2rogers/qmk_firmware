#include QMK_KEYBOARD_H
#include "r2d2rogers.h"
#include "bootloader.h"
#ifdef PROTOCOL_LUFA
  #include "lufa.h"
  #include "split_util.h"
#endif

#ifdef OLED_DRIVER_ENABLE
  #include "oled_driver.h"
#endif

extern keymap_config_t keymap_config;

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

enum custom_keycodes {
  BACKLIT = SAFE_RANGE,
  RGBRST
};

enum macro_keycodes {
  KC_SAMPLEMACRO,
};

#define KC_LRST  RGBRST
#define KC_LTOG  RGB_TOG
#define KC_LHUI  RGB_HUI
#define KC_LHUD  RGB_HUD
#define KC_LSAI  RGB_SAI
#define KC_LSAD  RGB_SAD
#define KC_LVAI  RGB_VAI
#define KC_LVAD  RGB_VAD
#define KC_LSMOD RGB_SMOD

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_wrapper(
//┌────────┬────────┬────────┬────────┬────────┬────────┐                  ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_TAB, _________________QWERTY_L1_________________,                    _________________QWERTY_R1_________________, KC_BSLS,
//├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
    KC_ESCC, _________________QWERTY_L2_________________,                    _________________QWERTY_R2_________________, KC_QUOT,
//├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
    KC_LSFT, _________________QWERTY_L3_________________,                    _________________QWERTY_R3_________________, KC_RSFT,
//└────────┴────────┴────────┴────────┼────────┼────────┼────────┐┌────────┼────────┼────────┼────────┴────────┴────────┴────────┘
                                        KC_LALT, SPACEFN,   LOWER,    RAISE, SPACEFN, KC_RGUI
//                                    └────────┴────────┴────────┘└────────┴────────┴────────┘
  ),

  [_LOWER] = LAYOUT_wrapper(
//┌────────┬────────┬────────┬────────┬────────┬────────┐                  ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_GRV, _________________LOWER_L1__________________,                    _________________LOWER_R1__________________, KC_BSPC,
//├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_F11, _________________LOWER_L2__________________,                    _________________LOWER_R2__________________, _______,
//├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_F12, _________________LOWER_L3__________________,                    _________________LOWER_R3__________________, _______,
//└────────┴────────┴────────┴────────┼────────┼────────┼────────┐┌────────┼────────┼────────┼────────┴────────┴────────┴────────┘
                                        _______, _______, _______,  _______, _______, _______
//                                    └────────┴────────┴────────┘└────────┴────────┴────────┘
  ),

  [_RAISE] = LAYOUT_wrapper(
//┌────────┬────────┬────────┬────────┬────────┬────────┐                  ┌────────┬────────┬────────┬────────┬────────┬────────┐
    KC_TILD, _________________RAISE_L1__________________,                    _________________RAISE_R1__________________, KC_BSPC,
//├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
    _______, _________________RAISE_L2__________________,                    _________________RAISE_R2__________________, KC_PIPE,
//├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
    _______, _________________RAISE_L3__________________,                    _________________RAISE_R3__________________, _______,
//└────────┴────────┴────────┴────────┼────────┼────────┼────────┐┌────────┼────────┼────────┼────────┴────────┴────────┴────────┘
                                        _______, _______, _______,  _______, _______, _______
//                                    └────────┴────────┴────────┘└────────┴────────┴────────┘
  ),

  [_SPACEFN] = LAYOUT_wrapper(
//┌────────┬────────┬────────┬────────┬────────┬────────┐                  ┌────────┬────────┬────────┬────────┬────────┬────────┐
      RESET, ________________SPACEFN_L1_________________,                    ________________SPACEFN_R1_________________,  KC_DEL,
//├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
       EPRM, ________________SPACEFN_L2_________________,                    ________________SPACEFN_R2_________________, _______,
//├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
    _______, ________________SPACEFN_L3_________________,                    ________________SPACEFN_R3_________________, _______,
//└────────┴────────┴────────┴────────┼────────┼────────┼────────┐┌────────┼────────┼────────┼────────┴────────┴────────┴────────┘
                                        _______, _______, _______,  _______, _______, _______
//                                    └────────┴────────┴────────┘└────────┴────────┴────────┘
  ),

  [_ADJUST] = LAYOUT_wrapper(
//┌────────┬────────┬────────┬────────┬────────┬────────┐                  ┌────────┬────────┬────────┬────────┬────────┬────────┐
    KC_MAKE, _________________ADJUST_L1_________________,                    _________________ADJUST_R1_________________,    USER,
//├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
       VRSN, _________________ADJUST_L2_________________,                    _________________ADJUST_R2_________________,    EPRM,
//├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
    VLK_TOG, _________________ADJUST_L3_________________,                    _________________ADJUST_R3_________________, KC_MPLY,
//└────────┴────────┴────────┴────────┼────────┼────────┼────────┐┌────────┼────────┼────────┼────────┴────────┴────────┴────────┘
                                        _______, _______, _______,  _______, _______, _______
//                                    └────────┴────────┴────────┘└────────┴────────┴────────┘
  )

};

int RGB_current_mode;

void matrix_init_keymap(void) {
    #ifdef RGBLIGHT_ENABLE
      RGB_current_mode = rgblight_config.mode;
    #endif
    //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
    #ifdef OLED_DRIVER_ENABLE
        oled_init(!has_usb());   // turns on the display
    #endif //OLED_DRIVER_ENABLE
}

//SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
#ifdef OLED_DRIVER_ENABLE

// When add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (is_master) {
    return OLED_ROTATION_270;
  } else {
    return rotation;
  }
}

void matrix_scan_keymap(void) {
   oled_task();
}

void matrix_render_user(void) {
  if (is_master) {
    // If you want to change the display of OLED, you need to change here
    oled_write_ln(read_layer_state(), false);
    oled_write_ln(read_keylog(), false);
    oled_write_ln(read_keylogs(), false);
    //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    //oled_write_ln(read_host_led_state(), false);
    //oled_write_ln(read_timelog(), false);
  } else {
    oled_write(read_logo(), false);
  }
}

void oled_task_user(void) {
  matrix_render_user();
}
#endif //OLED_DRIVER_ENABLE

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef OLED_DRIVER_ENABLE
    set_keylog(keycode, record);
    oled_on();
#endif //OLED_DRIVER_ENABLE
    // set_timelog();
  }

  return true;
}


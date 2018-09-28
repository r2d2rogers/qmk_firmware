#include QMK_KEYBOARD_H
#include "r2d2rogers.h"
#include "bootloader.h"
#ifdef PROTOCOL_LUFA
  #include "lufa.h"
  #include "split_util.h"
#endif
#ifdef SSD1306OLED
  #include "ssd1306.h"
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
  [_QWERTY] = LAYOUT_wrapper( \
//,-----------------------------------------------------.                        ,-----------------------------------------------------.
     KC_TAB, _________________QWERTY_L1_________________,                          _________________QWERTY_R1_________________, KC_BSPC,\
//|--------+--------+--------+--------+--------+--------|                        |--------+--------+--------+--------+--------+--------|
    KC_ESCC, _________________QWERTY_L2_________________,                          _________________QWERTY_R2_________________, KC_QUOT,\
//|--------+--------+--------+--------+--------+--------|                        |--------+--------+--------+--------+--------+--------|
    KC_LSFT, _________________QWERTY_L3_________________,                          _________________QWERTY_R3_________________, KC_RSFT,\
//|--------+--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+--------+--------|
                                       ___________________ORTHODOX_THUMB_BOTTOM____________________ \
                                    //`--------------------------'      `--------------------------'
  ),

  [_LOWER] = LAYOUT_wrapper( \
//,-----------------------------------------------------.                        ,-----------------------------------------------------.
    _______, ________________NUMBER_LEFT________________,                          ________________NUMBER_RIGHT_______________, KC_BSPC,\
//|--------+--------+--------+--------+--------+--------|                        |--------+--------+--------+--------+--------+--------|
    _______, _________________FUNC_LEFT_________________,                          _________________FUNC_RIGHT________________, XXXXXXX,\
//|--------+--------+--------+--------+--------+--------|                        |--------+--------+--------+--------+--------+--------|
    _______, _________________FUNC2_LEFT________________,                          _________________FUNC2_RIGHT_______________, XXXXXXX,\
//|--------+--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+--------+--------|
                                       ___________________ORTHODOX_THUMB_BOTTOM____________________ \
                                    //`--------------------------'      `--------------------------'
  ),

  [_RAISE] = LAYOUT_wrapper( \
//,-----------------------------------------------------.                        ,-----------------------------------------------------.
    _______, _________________LOWER_L1__________________,                          _________________LOWER_R1__________________, _______,\
//|--------+--------+--------+--------+--------+--------|                        |--------+--------+--------+--------+--------+--------|
    _______, _________________RAISE_L2__________________,                          _________________RAISE_R2__________________, _______,\
//|--------+--------+--------+--------+--------+--------|                        |--------+--------+--------+--------+--------+--------|
    _______, _________________RAISE_L3__________________,                          _________________ADJUST_R3_________________, _______,\
//|--------+--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+--------+--------|
                                       ___________________ORTHODOX_THUMB_BOTTOM____________________ \
                                    //`--------------------------'      `--------------------------'
  ),

  [_SPACEFN] = LAYOUT_wrapper( \
//,-----------------------------------------------------.                        ,-----------------------------------------------------.
      RESET, ________________SPACEFN_L1_________________,                          ________________SPACEFN_R1_________________, _______,\
//|--------+--------+--------+--------+--------+--------|                        |--------+--------+--------+--------+--------+--------|
    _______, ________________SPACEFN_L2_________________,                          ________________SPACEFN_R2_________________, _______,\
//|--------+--------+--------+--------+--------+--------|                        |--------+--------+--------+--------+--------+--------|
    _______, ________________SPACEFN_L3_________________,                          ________________SPACEFN_R3_________________, _______,\
//|--------+--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+--------+--------|
                                       ___________________ORTHODOX_THUMB_BOTTOM____________________ \
                                    //`--------------------------'      `--------------------------'
  ),

  [_ADJUST] = LAYOUT_wrapper( \
//,-----------------------------------------------------.                        ,-----------------------------------------------------.
      RESET, _________________ADJUST_L1_________________,                          _________________ADJUST_R1_________________, _______,\
//|--------+--------+--------+--------+--------+--------|                        |--------+--------+--------+--------+--------+--------|
    _______, _________________ADJUST_L2_________________,                          _________________ADJUST_R2_________________, _______,\
//|--------+--------+--------+--------+--------+--------|                        |--------+--------+--------+--------+--------+--------|
    _______, _________________ADJUST_L3_________________,                          _________________ADJUST_R3_________________, _______,\
//|--------+--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+--------+--------|
                                       ___________________ORTHODOX_THUMB_BOTTOM____________________ \
                                    //`--------------------------'      `--------------------------'
  )
};

int RGB_current_mode;

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}

void matrix_init_keymap(void) {
    #ifdef RGBLIGHT_ENABLE
      RGB_current_mode = rgblight_config.mode;
    #endif
    //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
    #ifdef SSD1306OLED
        iota_gfx_init(!has_usb());   // turns on the display
    #endif
}

//SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED

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

void matrix_scan_keymap(void) {
   iota_gfx_task();
}

void matrix_render_user(struct CharacterMatrix *matrix) {
  if (is_master) {
    // If you want to change the display of OLED, you need to change here
    matrix_write_ln(matrix, read_layer_state());
    matrix_write_ln(matrix, read_keylog());
    matrix_write_ln(matrix, read_keylogs());
    //matrix_write_ln(matrix, read_mode_icon(keymap_config.swap_lalt_lgui));
    //matrix_write_ln(matrix, read_host_led_state());
    //matrix_write_ln(matrix, read_timelog());
  } else {
    matrix_write(matrix, read_logo());
  }
}

void matrix_update(struct CharacterMatrix *dest, const struct CharacterMatrix *source) {
  if (memcmp(dest->display, source->display, sizeof(dest->display))) {
    memcpy(dest->display, source->display, sizeof(dest->display));
    dest->dirty = true;
  }
}

void iota_gfx_task_user(void) {
  struct CharacterMatrix matrix;
  matrix_clear(&matrix);
  matrix_render_user(&matrix);
  matrix_update(&display, &matrix);
}

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    set_keylog(keycode, record);
    // set_timelog();
  }

  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
        if (record->event.pressed) {
          layer_on(_ADJUST);
        } else {
          layer_off(_ADJUST);
        }
        return false;
        break;
    case RGB_MOD:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          rgblight_mode(RGB_current_mode);
          rgblight_step();
          RGB_current_mode = rgblight_config.mode;
        }
      #endif
      return false;
      break;
    case RGBRST:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          eeconfig_update_rgblight_default();
          rgblight_enable();
          RGB_current_mode = rgblight_config.mode;
        }
      #endif
      break;
  }
  return true;
}

#endif

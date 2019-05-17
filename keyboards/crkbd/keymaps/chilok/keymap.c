#include QMK_KEYBOARD_H
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

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  BACKLIT,
  RGBRST
};

enum macro_keycodes {
  KC_SAMPLEMACRO,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(
    //┌────────┬────────┬────────┬────────┬────────┬─────────┐┌────────┬────────┬────────┬────────┬────────┬────────┐
        KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T    , KC_Y    , KC_U   , KC_I   , KC_O   , KC_P   , KC_BSPC,
    //├────────┼────────┼────────┼────────┼────────┼─────────┤├────────┼────────┼────────┼────────┼────────┼────────┤
        MO(1)  , KC_A   , KC_S   , KC_D   , KC_F   , KC_G    , KC_H    , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT,
    //├────────┼────────┼────────┼────────┼────────┼─────────┤├────────┼────────┼────────┼────────┼────────┼────────┤
        KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B    , KC_N    , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_BSLS,
    //└────────┴────────┴────────┼────────┼────────┼─────────┤├────────┼────────┼────────┼────────┴────────┴────────┘
                                   KC_LALT, KC_LCTL, KC_SPC  ,   KC_ENT, KC_RGUI, TT(2)
    //                           └────────┴────────┴─────────┘└────────┴────────┴────────┘
      ),
  [_LOWER] = LAYOUT( \
    //┌────────┬────────┬────────┬────────┬────────┬─────────┐┌────────┬────────┬────────┬────────┬────────┬────────┐
        KC_ESC , KC_VOLD, KC_UP  , KC_VOLU, KC_NO  , RGB_TOG ,  KC_NO  , KC_BTN1, KC_MS_U, KC_BTN2, KC_PSCR, KC_DEL ,
    //├────────┼────────┼────────┼────────┼────────┼─────────┤├────────┼────────┼────────┼────────┼────────┼────────┤
        KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_NO  , RGB_M_SW,  KC_PGUP, KC_MS_L, KC_MS_D, KC_MS_R, KC_NO  , KC_CAPS,
    //├────────┼────────┼────────┼────────┼────────┼─────────┤├────────┼────────┼────────┼────────┼────────┼────────┤
        KC_LSFT, KC_MPRV, KC_MNXT, KC_MPLY, KC_NO  , KC_MUTE ,  KC_PGDN, KC_HOME, KC_END , KC_NO  , KC_NO  , KC_NLCK,
    //└────────┴────────┴────────┼────────┼────────┼─────────┤├────────┼────────┼────────┼────────┴────────┴────────┘
                                   KC_MINS, KC_EQL , KC_LPRN ,  KC_RPRN, KC_LBRC, KC_RBRC
    //                           └────────┴────────┴─────────┘└────────┴────────┴────────┘
      ),
  [_RAISE] = LAYOUT( \
    //┌────────┬────────┬────────┬────────┬────────┬─────────┐┌────────┬────────┬────────┬────────┬────────┬────────┐
        KC_ESC,  KC_NO  , KC_P7  , KC_P8  , KC_P9  , KC_PSLS ,  KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC, KC_BSPC,
    //├────────┼────────┼────────┼────────┼────────┼─────────┤├────────┼────────┼────────┼────────┼────────┼────────┤
        KC_BSPC, KC_PCMM, KC_P4  , KC_P5  , KC_P6  , KC_PAST ,  KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_TILD,
    //├────────┼────────┼────────┼────────┼────────┼─────────┤├────────┼────────┼────────┼────────┼────────┼────────┤
        KC_PENT, KC_P0  , KC_P1  , KC_P2  , KC_P3  , KC_PMNS ,  KC_UNDS, KC_PLUS, KC_PIPE, KC_LCBR, KC_RCBR, KC_CALC,
    //└────────┴────────┴────────┼────────┼────────┼─────────┤├────────┼────────┼────────┼────────┴────────┴────────┘
                                   KC_PDOT, KC_PPLS, KC_SPC  ,  KC_ENT , TG(3) , KC_TRNS
    //                           └────────┴────────┴─────────┘└────────┴────────┴────────┘
      ),
  [_ADJUST] = LAYOUT( \
    //┌────────┬────────┬────────┬────────┬────────┬─────────┐┌────────┬────────┬────────┬────────┬────────┬────────┐
          KC_NO, KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,   RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, RGB_MOD,
    //├────────┼────────┼────────┼────────┼────────┼─────────┤├────────┼────────┼────────┼────────┼────────┼────────┤
          KC_NO, KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,   KC_NO  , RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD, RGB_RMOD,
    //├────────┼────────┼────────┼────────┼────────┼─────────┤├────────┼────────┼────────┼────────┼────────┼────────┤
          KC_NO, KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO   ,  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
    //└────────┴────────┴────────┼────────┼────────┼─────────┤├────────┼────────┼────────┼────────┴────────┴────────┘
                                   KC_NO  , KC_NO  , KC_NO   ,  RGB_MOD, TG(3) , KC_TRNS
    //                           └────────┴────────┴─────────┘└────────┴────────┴────────┘
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

void matrix_init_user(void) {
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

void matrix_scan_user(void) {
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

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
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

uint32_t layer_state_set_rgb_user(uint32_t state) {
#ifdef RGBLIGHT_ENABLE
    switch (biton32(state)) {
    case _RAISE:
      rgblight_sethsv_noeeprom_orange();
      rgblight_mode_noeeprom(5);
      break;
    case _LOWER:
      rgblight_sethsv_noeeprom_green();
      rgblight_mode_noeeprom(5);
      break;
    case _ADJUST:
      rgblight_sethsv_noeeprom_red();
      rgblight_mode_noeeprom(23);
      break;
    default: //  for any other layers, or the default layer
      rgblight_sethsv_noeeprom_cyan();
      break;
  }
#endif // RGBLIGHT_ENABLE

  return state;
}


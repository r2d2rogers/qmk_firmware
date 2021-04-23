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

char wpm_str[10];

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

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
                                        KC_LGUI,LSPACEFN,   LOWER,    RAISE,RSPACEFN, KC_RALT
//                                    └────────┴────────┴────────┘└────────┴────────┴────────┘
  ),

  [_LOWER] = LAYOUT_wrapper(
//┌────────┬────────┬────────┬────────┬────────┬────────┐                  ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_GRV, _________________LOWER_L1__________________,                    _________________LOWER_R1__________________,  KC_DEL,
//├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_F11, _________________LOWER_L2__________________,                    _________________LOWER_R2__________________, KC_PAST,
//├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_F12, _________________LOWER_L3__________________,                    _________________LOWER_R3__________________, KC_PSLS,
//└────────┴────────┴────────┴────────┼────────┼────────┼────────┐┌────────┼────────┼────────┼────────┴────────┴────────┴────────┘
                                        _______, _______, _______,  _______, _______, _______
//                                    └────────┴────────┴────────┘└────────┴────────┴────────┘
  ),

  [_RAISE] = LAYOUT_wrapper(
//┌────────┬────────┬────────┬────────┬────────┬────────┐                  ┌────────┬────────┬────────┬────────┬────────┬────────┐
    KC_TILD, _________________RAISE_L1__________________,                    _________________RAISE_R1__________________, KC_BSPC,
//├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
    _______, _________________RAISE_L2__________________,                    _________________RAISE_R2__________________, KC_GRV,
//├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
    _______, _________________RAISE_L3__________________,                    _________________RAISE_R3__________________, KC_TILD,
//└────────┴────────┴────────┴────────┼────────┼────────┼────────┐┌────────┼────────┼────────┼────────┴────────┴────────┴────────┘
                                        _______, _______, _______,  _______, _______, _______
//                                    └────────┴────────┴────────┘└────────┴────────┴────────┘
  ),

  [_SPACEFN] = LAYOUT_wrapper(
//┌────────┬────────┬────────┬────────┬────────┬────────┐                  ┌────────┬────────┬────────┬────────┬────────┬────────┐
      RESET, ________________SPACEFN_L1_________________,                    ________________SPACEFN_R1_________________, KC_PSCR,
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
        oled_init(!eeconfig_read_handedness());   // turns on the display
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

// WPM-responsive animation stuff here
#define IDLE_FRAMES 5
#define IDLE_SPEED 40 // below this wpm value your animation will idle

// #define PREP_FRAMES 1 // uncomment if >1

#define TAP_FRAMES 2
#define TAP_SPEED 60 // above this wpm value typing animation to triggere

#define ANIM_FRAME_DURATION 200 // how long each frame lasts in ms
// #define SLEEP_TIMER 60000 // should sleep after this period of 0 wpm, needs fixing
#define ANIM_SIZE 636 // number of bytes in array, minimize for adequate firmware size, max is 1024

uint32_t anim_timer = 0;
uint32_t anim_sleep = 0;
uint8_t current_idle_frame = 0;
// uint8_t current_prep_frame = 0; // uncomment if PREP_FRAMES >1
uint8_t current_tap_frame = 0;

// Images credit j-inc(/James Incandenza) and pixelbenny. Credit to obosob for initial animation approach.
static void render_anim(void) {
    static const char PROGMEM idle[IDLE_FRAMES][ANIM_SIZE] = {
        {
          0,   0, 126, 126,  24,  60, 102,  66,   0,  12,  28, 112, 112,  28,  12,   0, 116, 116,  20,  20, 124, 104,   0, 124, 124,   0, 112, 120,  44,  36, 124, 124,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 128,  64,  64,  32,  32,  32,  32,  16,  16,  16,  16,  16,   8,   8,   4,   4,   4,   8,  48,  64, 128,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 128, 128, 128,   0,   0,   0,   0, 192,  96,  48,  24,  12, 132, 198,  98,  35,  51,  17, 145, 113, 241, 113, 145,  17,  51,  35,  98, 198, 132,  12,  24,  48,  96, 192,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  24, 100, 130,   2,   2,   2,   2,   2,   1,   0,   0,   0,   0, 128, 128,   0,   0,   0,   0,   0,   0,   0,   0,   0, 128,   0,  48,  48,   0, 192, 193, 193, 194,   4,   8,  16,  32,  64, 128,   0,   0,   0, 128, 128, 128, 128,  64,  64,  64,  64,  32,  32,  32,  32,  16,  16,  16,  16,   8,   8,   8,   8,   8, 196,   4, 196,   4, 196,   2, 194,   2, 194,   1,   1,   1,   1,   0,   0,   0,   0,   0, 252,  15,   1,   0, 248,  14,  31, 109, 140, 148, 148, 164, 166, 249, 224, 255, 224, 249, 166, 164, 148, 148, 140, 109,  31,  14, 248,   0,   1,  15, 252,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 192,  56,   4,   3,   0,   0,   0,   0,   0,   0,   0,  12,  12,  12,  13,   1,   0,  64, 160,  33,  34,  18,  17,  17,  17,   9,   8,   8,   8,   8,   4,   4,   8,   8,  16,  16,  16,  16,  16,  17,  15,   1,   1,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 170, 170, 255, 255, 195, 191, 127,   3, 127, 191, 195, 255, 255, 170, 170,   0,   0,   0,   0,   0,   0,  31, 120, 192,   0,  15,  56, 124, 219, 152,  20,  20,  18,  50, 207,   3, 255,   3, 207,  50,  18,  20,  20, 152, 219, 124,  56,  15,   0, 192, 120,  31,  16,  16,  16,  16,   8,   8,   8,   8,   8,   4,   4,   4,   4,   4,   2,   3,   2,   2,   1,   1,   1,   1,   1,   1,   2,   2,   4,   4,   8,   8,   8,   8,   8,   7,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   2, 130, 135,  31,   7, 159,   7,  28,   7, 159,   7, 159,   7,   2, 130,   0,   0,   0,   0,  32,  16,  16,  16,  17,  11,  14,  12,  24,  16,  49,  35,  98, 102,  68,  68,  71,  71,  71,  68,  68, 102,  98,  35,  49,  16,  24,  12,   6,   3,   1,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 0
        },
        {
          0,   0, 126, 126,  24,  60, 102,  66,   0,  12,  28, 112, 112,  28,  12,   0, 116, 116,  20,  20, 124, 104,   0, 124, 124,   0, 112, 120,  44,  36, 124, 124,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 128,  64,  64,  32,  32,  32,  32,  16,  16,  16,  16,  16,   8,   8,   4,   4,   4,   8,  48,  64, 128,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 128, 128, 128,   0,   0,   0,   0, 192,  96,  48,  24,  12, 132, 198,  98,  35,  51,  17, 145, 113, 241, 113, 145,  17,  51,  35,  98, 198, 132,  12,  24,  48,  96, 192,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  24, 100, 130,   2,   2,   2,   2,   2,   1,   0,   0,   0,   0, 128, 128,   0,   0,   0,   0,   0,   0,   0,   0,   0, 128,   0,  48,  48,   0, 192, 193, 193, 194,   4,   8,  16,  32,  64, 128,   0,   0,   0, 128, 128, 128, 128,  64,  64,  64,  64,  32,  32,  32,  32,  16,  16,  16,  16,   8,   8,   8,   8,   8, 196,   4, 196,   4, 196,   2, 194,   2, 194,   1,   1,   1,   1,   0,   0,   0,   0,   0, 252,  15,   1,   0, 248,  14,  31, 109, 140, 148, 148, 164, 166, 249, 224, 255, 224, 249, 166, 164, 148, 148, 140, 109,  31,  14, 248,   0,   1,  15, 252,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 192,  56,   4,   3,   0,   0,   0,   0,   0,   0,   0,  12,  12,  12,  13,   1,   0,  64, 160,  33,  34,  18,  17,  17,  17,   9,   8,   8,   8,   8,   4,   4,   8,   8,  16,  16,  16,  16,  16,  17,  15,   1,   1,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 170, 170, 255, 255, 195, 191, 127,   3, 127, 191, 195, 255, 255, 170, 170,   0,   0,   0,   0,   0,   0,  31, 120, 192,   0,  15,  56, 124, 219, 152,  20,  20,  18,  50, 207,   3, 255,   3, 207,  50,  18,  20,  20, 152, 219, 124,  56,  15,   0, 192, 120,  31,  16,  16,  16,  16,   8,   8,   8,   8,   8,   4,   4,   4,   4,   4,   2,   3,   2,   2,   1,   1,   1,   1,   1,   1,   2,   2,   4,   4,   8,   8,   8,   8,   8,   7,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   2, 130, 135,  31,   7, 159,   7,  28,   7, 159,   7, 159,   7,   2, 130,   0,   0,   0,   0,  32,  16,  16,  16,  17,  11,  14,  12,  24,  16,  49,  35,  98, 102,  68,  68,  71,  71,  71,  68,  68, 102,  98,  35,  49,  16,  24,  12,   6,   3,   1,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 0
        },
        {
          0,   0, 126, 126,  24,  60, 102,  66,   0,  12,  28, 112, 112,  28,  12,   0, 116, 116,  20,  20, 124, 104,   0, 124, 124,   0, 112, 120,  44,  36, 124, 124,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 128, 128,  64,  64,  64,  64,  32,  32,  32,  32,  16,   8,   4,   2,   2,   4,  24,  96, 128,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 128, 128, 128,   0,   0,   0,   0, 192,  96,  48,  24,  12, 132, 198,  98,  35,  51,  17, 145, 113, 241, 113, 145,  17,  51,  35,  98, 198, 132,  12,  24,  48,  96, 192,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  60, 194,   1,   1,   2,   2,   4,   4,   2,   1,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  96,  96,   0, 129, 130, 130, 132,   8,  16,  32,  64, 128,   0,   0,   0,   0, 128, 128, 128, 128,  64,  64,  64,  64,  32,  32,  32,  32,  16,  16,  16,  16,   8,   8,   8,   8,   8, 196,   4, 196,   4, 196,   2, 194,   2, 194,   1,   1,   1,   1,   0,   0,   0,   0,   0, 252,  15,   1,   0, 248,  14,  31, 109, 140, 148, 148, 164, 166, 249, 224, 255, 224, 249, 166, 164, 148, 148, 140, 109,  31,  14, 248,   0,   1,  15, 252,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 128, 112,  25,   6,   0,   0,   0,   0,   0,   0,   0,  24,  24,  24,  27,   3,   0,  64, 160,  34,  36,  20,  18,  18,  18,  11,   8,   8,   8,   8,   5,   5,   9,   9,  16,  16,  16,  16,  16,  17,  15,   1,   1,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 170, 170, 255, 255, 195, 191, 127,   3, 127, 191, 195, 255, 255, 170, 170,   0,   0,   0,   0,   0,   0,  31, 120, 192,   0,  15,  56, 124, 219, 152,  20,  20,  18,  50, 207,   3, 255,   3, 207,  50,  18,  20,  20, 152, 219, 124,  56,  15,   0, 192, 120,  31,  16,  16,  16,  16,   8,   8,   8,   8,   8,   4,   4,   4,   4,   4,   2,   3,   2,   2,   1,   1,   1,   1,   1,   1,   2,   2,   4,   4,   8,   8,   8,   8,   8,   7,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   2, 130, 135,  31,   7, 159,   7,  28,   7, 159,   7, 159,   7,   2, 130,   0,   0,   0,   0,  32,  16,  16,  16,  17,  11,  14,  12,  24,  16,  49,  35,  98, 102,  68,  68,  71,  71,  71,  68,  68, 102,  98,  35,  49,  16,  24,  12,   6,   3,   1,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 0
        },
        {
          0,   0, 126, 126,  24,  60, 102,  66,   0,  12,  28, 112, 112,  28,  12,   0, 116, 116,  20,  20, 124, 104,   0, 124, 124,   0, 112, 120,  44,  36, 124, 124,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 128, 128,   0,   0,   0,   0,   0, 128,  64,  64,  32,  32,  32,  32,  16,  16,  16,  16,   8,   4,   2,   1,   1,   2,  12,  48,  64, 128,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 128, 128, 128,   0,   0,   0,   0, 192,  96,  48,  24,  12, 132, 198,  98,  35,  51,  17, 145, 113, 241, 113, 145,  17,  51,  35,  98, 198, 132,  12,  24,  48,  96, 192,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  30, 225,   0,   0,   1,   1,   2,   2,   1,   0,   0,   0,   0, 128, 128,   0,   0,   0,   0,   0,   0,   0,   0,   0, 128,   0,  48,  48,   0, 192, 193, 193, 194,   4,   8,  16,  32,  64, 128,   0,   0,   0, 128, 128, 128, 128,  64,  64,  64,  64,  32,  32,  32,  32,  16,  16,  16,  16,   8,   8,   8,   8,   8, 196,   4, 196,   4, 196,   2, 194,   2, 194,   1,   1,   1,   1,   0,   0,   0,   0,   0, 252,  15,   1,   0, 248,  14,  31, 109, 140, 148, 148, 164, 166, 249, 224, 255, 224, 249, 166, 164, 148, 148, 140, 109,  31,  14, 248,   0,   1,  15, 252,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 128, 112,  12,   3,   0,   0,   0,   0,   0,   0,   0,  12,  12,  12,  13,   1,   0,  64, 160,  33,  34,  18,  17,  17,  17,   9,   8,   8,   8,   8,   4,   4,   8,   8,  16,  16,  16,  16,  16,  17,  15,   1,   1,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 170, 170, 255, 255, 195, 191, 127,   3, 127, 191, 195, 255, 255, 170, 170,   0,   0,   0,   0,   0,   0,  31, 120, 192,   0,  15,  56, 124, 219, 152,  20,  20,  18,  50, 207,   3, 255,   3, 207,  50,  18,  20,  20, 152, 219, 124,  56,  15,   0, 192, 120,  31,  16,  16,  16,  16,   8,   8,   8,   8,   8,   4,   4,   4,   4,   4,   2,   3,   2,   2,   1,   1,   1,   1,   1,   1,   2,   2,   4,   4,   8,   8,   8,   8,   8,   7,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   2, 130, 135,  31,   7, 159,   7,  28,   7, 159,   7, 159,   7,   2, 130,   0,   0,   0,   0,  32,  16,  16,  16,  17,  11,  14,  12,  24,  16,  49,  35,  98, 102,  68,  68,  71,  71,  71,  68,  68, 102,  98,  35,  49,  16,  24,  12,   6,   3,   1,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 0
        },
        {
          0,   0, 126, 126,  24,  60, 102,  66,   0,  12,  28, 112, 112,  28,  12,   0, 116, 116,  20,  20, 124, 104,   0, 124, 124,   0, 112, 120,  44,  36, 124, 124,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 128,  64,  64,  32,  32,  32,  32,  16,  16,  16,  16,   8,   8,   4,   2,   2,   2,   4,  56,  64, 128,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 128, 128, 128,   0,   0,   0,   0, 192,  96,  48,  24,  12, 132, 198,  98,  35,  51,  17, 145, 113, 241, 113, 145,  17,  51,  35,  98, 198, 132,  12,  24,  48,  96, 192,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  28, 226,   1,   1,   2,   2,   2,   2,   1,   0,   0,   0,   0, 128, 128,   0,   0,   0,   0,   0,   0,   0,   0,   0, 128,   0,  48,  48,   0, 192, 193, 193, 194,   4,   8,  16,  32,  64, 128,   0,   0,   0, 128, 128, 128, 128,  64,  64,  64,  64,  32,  32,  32,  32,  16,  16,  16,  16,   8,   8,   8,   8,   8, 196,   4, 196,   4, 196,   2, 194,   2, 194,   1,   1,   1,   1,   0,   0,   0,   0,   0, 252,  15,   1,   0, 248,  14,  31, 109, 140, 148, 148, 164, 166, 249, 224, 255, 224, 249, 166, 164, 148, 148, 140, 109,  31,  14, 248,   0,   1,  15, 252,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 128, 112,  12,   3,   0,   0,   0,   0,   0,   0,   0,  12,  12,  12,  13,   1,   0,  64, 160,  33,  34,  18,  17,  17,  17,   9,   8,   8,   8,   8,   4,   4,   8,   8,  16,  16,  16,  16,  16,  17,  15,   1,   1,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 170, 170, 255, 255, 195, 191, 127,   3, 127, 191, 195, 255, 255, 170, 170,   0,   0,   0,   0,   0,   0,  31, 120, 192,   0,  15,  56, 124, 219, 152,  20,  20,  18,  50, 207,   3, 255,   3, 207,  50,  18,  20,  20, 152, 219, 124,  56,  15,   0, 192, 120,  31,  16,  16,  16,  16,   8,   8,   8,   8,   8,   4,   4,   4,   4,   4,   2,   3,   2,   2,   1,   1,   1,   1,   1,   1,   2,   2,   4,   4,   8,   8,   8,   8,   8,   7,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   2, 130, 135,  31,   7, 159,   7,  28,   7, 159,   7, 159,   7,   2, 130,   0,   0,   0,   0,  32,  16,  16,  16,  17,  11,  14,  12,  24,  16,  49,  35,  98, 102,  68,  68,  71,  71,  71,  68,  68, 102,  98,  35,  49,  16,  24,  12,   6,   3,   1,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 0
        }
        };
        static const char PROGMEM prep[][ANIM_SIZE] = {
        {
          0,   0, 126, 126,  24,  60, 102,  66,   0,  12,  28, 112, 112,  28,  12,   0, 116, 116,  20,  20, 124, 104,   0, 124, 124,   0, 112, 120,  44,  36, 124, 124,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 128, 128,   0,   0,   0,   0,   0, 128,  64,  64,  32,  32,  32,  32,  16,  16,  16,  16,   8,   4,   2,   1,   1,   2,  12,  48,  64, 128,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 128, 128, 128,   0,   0,   0,   0, 192,  96,  48,  24,  12, 132, 198,  98,  35,  51,  17, 145, 113, 241, 113, 145,  17,  51,  35,  98, 198, 132,  12,  24,  48,  96, 192,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  30, 225,   0,   0,   1,   1,   2,   2, 129, 128, 128,   0,   0, 128, 128,   0,   0,   0,   0,   0,   0,   0,   0,   0, 128,   0,  48,  48,   0,   0,   1, 225,  26,   6,   9,  49,  53,   1, 138, 124,   0,   0, 128, 128, 128, 128,  64,  64,  64,  64,  32,  32,  32,  32,  16,  16,  16,  16,   8,   8,   8,   8,   8, 196,   4, 196,   4, 196,   2, 194,   2, 194,   1,   1,   1,   1,   0,   0,   0,   0,   0, 252,  15,   1,   0, 248,  14,  31, 109, 140, 148, 148, 164, 166, 249, 224, 255, 224, 249, 166, 164, 148, 148, 140, 109,  31,  14, 248,   0,   1,  15, 252,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 128, 112,  12,   3,   0,   0,  24,   6,   5, 152, 153, 132, 195, 124,  65,  65,  64,  64,  32,  33,  34,  18,  17,  17,  17,   9,   8,   8,   8,   8,   4,   4,   4,   4,   4,   4,   2,   2,   2,   1,   1,   1,   1,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 170, 170, 255, 255, 195, 191, 127,   3, 127, 191, 195, 255, 255, 170, 170,   0,   0,   0,   0,   0,   0,  31, 120, 192,   0,  15,  56, 124, 219, 152,  20,  20,  18,  50, 207,   3, 255,   3, 207,  50,  18,  20,  20, 152, 219, 124,  56,  15,   0, 192, 120,  31,  16,  16,  16,  16,   8,   8,   8,   8,   8,   4,   4,   4,   4,   4,   2,   3,   2,   2,   1,   1,   1,   1,   1,   1,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   2, 130, 135,  31,   7, 159,   7,  28,   7, 159,   7, 159,   7,   2, 130,   0,   0,   0,   0,  32,  16,  16,  16,  17,  11,  14,  12,  24,  16,  49,  35,  98, 102,  68,  68,  71,  71,  71,  68,  68, 102,  98,  35,  49,  16,  24,  12,   6,   3,   1,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 0
        }
        };
        static const char PROGMEM tap[TAP_FRAMES][ANIM_SIZE] = {
        {
          0,   0, 126, 126,  24,  60, 102,  66,   0,  12,  28, 112, 112,  28,  12,   0,
        116, 116,  20,  20, 124, 104,   0, 124, 124,   0, 112, 120,  44,  36, 124, 124,
          0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
          0,   0,   0, 128, 128,   0,   0,   0,   0,   0, 128,  64,  64,  32,  32,  32,
         32,  16,  16,  16,  16,   8,   4,   2,   1,   1,   2,  12,  48,  64, 128,   0,
          0,   0,   0,   0,   0,   0, 248, 248, 248, 248,   0,   0,   0,   0,   0, 128,
        128,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
          0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 128, 128, 128,
          0,   0,   0,   0, 192,  96,  48,  24,  12, 132, 198,  98,  35,  51,  17, 145,
        113, 241, 113, 145,  17,  51,  35,  98, 198, 132,  12,  24,  48,  96, 192,   0,
          0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
          0,  30, 225,   0,   0,   1,   1,   2,   2, 129, 128, 128,   0,   0, 128, 128,
          0,   0,   0,   0,   0,   0,   0,   0,   0, 128,   0,  48,  48,   0,   0,   1,
          1,   2,   4,   8,  16,  32,  67, 135,   7,   1,   0, 184, 188, 190, 159,  95,
         95,  79,  76,  32,  32,  32,  32,  16,  16,  16,  16,   8,   8,   8,   8,   8,
        196,   4, 196,   4, 196,   2, 194,   2, 194,   1,   1,   1,   1,   0,   0,   0,
          0,   0, 252,  15,   1,   0, 248,  14,  31, 109, 140, 148, 148, 164, 166, 249,
        224, 255, 224, 249, 166, 164, 148, 148, 140, 109,  31,  14, 248,   0,   1,  15,
        252,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
        128, 112,  12,   3,   0,   0,  24,   6,   5, 152, 153, 132,  67, 124,  65,  65,
         64,  64,  32,  33,  34,  18,  17,  17,  17,   9,   8,   8,   8,   8,   4,   4,
          8,   8,  16,  16,  16,  16,  16,  17,  15,   1,  61, 124, 252, 252, 252, 252,
        252,  60,  12,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 170, 170, 255,
        255, 195, 191, 127,   3, 127, 191, 195, 255, 255, 170, 170,   0,   0,   0,   0,
          0,   0,  31, 120, 192,   0,  15,  56, 124, 219, 152,  20,  20,  18,  50, 207,
          3, 255,   3, 207,  50,  18,  20,  20, 152, 219, 124,  56,  15,   0, 192, 120,
         63,  16,  16,  16,  16,   8,   8,   8,   8,   8,   4,   4,   4,   4,   4,   2,
          3,   2,   2,   1,   1,   1,   1,   1,   1,   0,   0,   0,   0,   0,   0,   0,
          0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
          0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   1,   3,   3,
          0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   2, 130, 135,
         31,   7, 159,   7,  28,   7, 159,   7, 159,   7,   2, 130,   0,   0,   0,   0,
         32,  16,  16,  16,  17,  11,  14,  12,  24,  16,  49,  35,  98, 102,  68,  68,
         71,  71,  71,  68,  68, 102,  98,  35,  49,  16,  24,  12,   6,   3,   1,   0,
          0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
          0,   0,   0,   0,   0,   0,   0,   0,   0
        },
        {
  0,   0, 126, 126,  24,  60, 102,  66,   0,  12,  28, 112, 112,  28,  12,   0,
116, 116,  20,  20, 124, 104,   0, 124, 124,   0, 112, 120,  44,  36, 124, 124,
  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
  0,   0,   0, 128, 128,   0,   0,   0,   0,   0, 128,  64,  64,  32,  32,  32,
 32,  16,  16,  16,  16,   8,   4,   2,   1,   1,   2,  12,  48,  64, 128,   0,
  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 128, 128, 128,
  0,   0,   0,   0, 192,  96,  48,  24,  12, 132, 198,  98,  35,  51,  17, 145,
113, 241, 113, 145,  17,  51,  35,  98, 198, 132,  12,  24,  48,  96, 192,   0,
  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
  0,  30, 225,   0,   0,   1,   1,   2,   2,   1,   0,   0,   0,   0, 128, 128,
  0,   0,   0,   0,   0,   0,   0,   0,   0, 128,   0,  48,  48,   0,   0,   1,
225,  26,   6,   9,  49,  53,   1, 138, 124,   0,   0, 128, 128, 128, 128,  64,
 64,  64,  64,  32,  32,  32,  32,  16,  16,  16,  16,   8,   8,   8,   8,   8,
196,   4, 196,   4, 196,   2, 194,   2, 194,   1,   1,   1,   1,   0,   0,   0,
  0,   0, 252,  15,   1,   0, 248,  14,  31, 109, 140, 148, 148, 164, 166, 249,
224, 255, 224, 249, 166, 164, 148, 148, 140, 109,  31,  14, 248,   0,   1,  15,
252,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
128, 112,  12,   3,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   1,   1,
  0,  64, 160,  33,  34,  18,  17,  17,  17,   9,   8,   8,   8,   8,   4,   4,
  4,   4,   4,   4,   2,   2,   2,   1,   1,   1,   1,   0,   0,   0,   0,   0,
  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 170, 170, 255,
255, 195, 191, 127,   3, 127, 191, 195, 255, 255, 170, 170,   0,   0,   0,   0,
  0,   0,  31, 120, 192,   0,  15,  56, 124, 219, 152,  20,  20,  18,  50, 207,
  3, 255,   3, 207,  50,  18,  20,  20, 152, 219, 124,  56,  15,   0, 192, 120,
 31,  16,  16,  16,  16,   8,   8,   8,   8,   8,   4,   4,   4,   4,   4,   2,
  3, 122, 122, 121, 121, 121, 121,  57,  49,   2,   2,   4,   4,   8,   8,   8,
136, 136, 135, 128,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   2, 130, 135,
 31,   7, 159,   7,  28,   7, 159,   7, 159,   7,   2, 130,   0,   0,   0,   0,
 32,  16,  16,  16,  17,  11,  14,  12,  24,  16,  49,  35,  98, 102,  68,  68,
 71,  71,  71,  68,  68, 102,  98,  35,  49,  16,  24,  12,   6,   3,   1,   0,
  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
  0,   0,   0,   0,   0,  48, 120, 124, 254
        },
    };

    //assumes 1 frame prep stage
    void animation_phase(void) {
        if(get_current_wpm() <=IDLE_SPEED){
            current_idle_frame = (current_idle_frame + 1) % IDLE_FRAMES;
            oled_write_raw_P(idle[abs((IDLE_FRAMES-1)-current_idle_frame)], ANIM_SIZE);
         }
         if(get_current_wpm() >IDLE_SPEED && get_current_wpm() <TAP_SPEED){
             // oled_write_raw_P(prep[abs((PREP_FRAMES-1)-current_prep_frame)], ANIM_SIZE); // uncomment if IDLE_FRAMES >1
             oled_write_raw_P(prep[0], ANIM_SIZE);  // remove if IDLE_FRAMES >1
         }
         if(get_current_wpm() >=TAP_SPEED){
             current_tap_frame = (current_tap_frame + 1) % TAP_FRAMES;
             oled_write_raw_P(tap[abs((TAP_FRAMES-1)-current_tap_frame)], ANIM_SIZE);
         }
    }
    if(get_current_wpm() != 000) {
        oled_on(); // not essential but turns on animation OLED with any alpha keypress
        if(timer_elapsed32(anim_timer) > ANIM_FRAME_DURATION) {
            anim_timer = timer_read32();
            animation_phase();
        }
        anim_sleep = timer_read32();
    } else {
        if(timer_elapsed32(anim_sleep) > OLED_TIMEOUT) {
            oled_off();
        } else {
            if(timer_elapsed32(anim_timer) > ANIM_FRAME_DURATION) {
                anim_timer = timer_read32();
                animation_phase();
            }
        }
    }
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (is_master) {
    return OLED_ROTATION_0;
  } else {
    return OLED_ROTATION_0;
    //return rotation;
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
  //matrix_render_user();
   if (is_keyboard_master()) {
        render_anim();
        oled_set_cursor(0,6);
        sprintf(wpm_str, "       WPM: %03d", get_current_wpm());
        oled_write(wpm_str, false);
    } else {
        //render_skull();
        //oled_set_cursor(7,6);
    //    render_status();
     // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    }
}
#endif //OLED_DRIVER_ENABLE

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef OLED_DRIVER_ENABLE
//   set_keylog(keycode, record);
    oled_on();
#endif //OLED_DRIVER_ENABLE
    // set_timelog();
  }

  return true;
}



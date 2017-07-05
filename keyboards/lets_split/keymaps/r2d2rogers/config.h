#ifndef CONFIG_USER_H
#define CONFIG_USER_H

#include "../../config.h"

#undef RGBLED_NUM
#define RGBLED_NUM 32

#define BACKLIGHT_LEVELS 10
#define RGBLIGHT_ANIMATIONS
#define RGBLIGHT_EFFECT_KNIGHT_OFFSET 32
#define RGBLIGHT_EFFECT_DUALKNIGHT_LENGTH 6
#define RGBLIGHT_HUE_STEP 10
#define RGBLIGHT_SAT_STEP 17
#define RGBLIGHT_VAL_STEP 17

#define USE_SERIAL
#define EE_HANDS

#define C6_AUDIO

#define randadd 53
#define randmul 181
#define randmod 167

#define _______ KC_TRNS
#define XXXXXXX KC_NO

#define TAPPING_TERM 200

#endif

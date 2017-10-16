#ifndef CONFIG_USER_H
#define CONFIG_USER_H

#include "../../config.h"

#undef TAPPING_TERM
#define TAPPING_TERM 180

/* Use I2C or Serial, not both */

#define USE_SERIAL
// #define USE_I2C

/* Select hand configuration */

// #define MASTER_LEFT
// #define _MASTER_RIGHT
#define EE_HANDS


#ifdef RGBLIGHT_ENABLE
#undef RGBLED_NUM
#define RGBLED_NUM 32
#define RGBLIGHT_ANIMATIONS
#define RGBLIGHT_EFFECT_SNAKE_LENGTH 4
#define RGBLIGHT_EFFECT_KNIGHT_LENGTH 3
#define RGBLIGHT_EFFECT_KNIGHT_OFFSET 8
#define RGBLIGHT_EFFECT_KNIGHT_LED_NUM 16
#define RGBLIGHT_EFFECT_CHRISTMAS_INTERVAL 500
#define RGBLIGHT_EFFECT_CHRISTMAS_STEP 3
#endif

#define _______ KC_TRNS
#define XXXXXXX KC_NO

#define randadd 53
#define randmul 181
#define randmod 167

#ifdef AUDIO_ENABLE
#define C6_AUDIO
#endif

#endif

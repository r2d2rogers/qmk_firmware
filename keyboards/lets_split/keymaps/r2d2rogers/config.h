#ifndef CONFIG_USER_H
        #define CONFIG_USER_H

        #include "../../config.h"

        #define TAPPING_TERM 100

        #define USE_SERIAL
        #define EE_HANDS

        #undef RGBLED_NUM
        #define RGBLED_NUM 32
        #define RGBLIGHT_ANIMATIONS
        #define RGBLIGHT_EFFECT_KNIGHT_OFFSET 32
        #define RGBLIGHT_EFFECT_DUALKNIGHT_LENGTH 6

        #define _______ KC_TRNS
        #define XXXXXXX KC_NO

        #define randadd 53
        #define randmul 181
        #define randmod 167

        #ifdef AUDIO_ENABLE
                #define C6_AUDIO
        #endif

#endif

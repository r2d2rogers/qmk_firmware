#include "lets_split.h"

#ifdef RGB_MATRIX_ENABLE

const is31_led g_is31_leds[DRIVER_LED_TOTAL] = {
/* Refer to IS31 manual for these locations
 *   driver
 *   |  R location
 *   |  |      G location
 *   |  |      |      B location
 *   |  |      |      | */
    {0, C1_4,  C2_4,  C3_4},
    {0, C1_5,  C2_5,  C3_5},
    {0, C1_6,  C2_6,  C3_6},
    {0, C1_7,  C2_7,  C3_7},
    {0, C1_8,  C2_8,  C3_8},
    {0, C1_9,  C2_9,  C3_9},

    {0, C4_1,  C5_1,  C6_1},
    {0, C4_2,  C5_2,  C6_2},
    {0, C4_3,  C5_3,  C6_3},
    {0, C4_7,  C5_7,  C6_7},
    {0, C4_8,  C5_8,  C6_8},
    {0, C4_9,  C5_9,  C6_9},

    {0, C7_1,  C8_1,  C9_1},
    {0, C7_2,  C8_2,  C9_2},
    {0, C7_3,  C8_3,  C9_3},
    {0, C7_4,  C8_4,  C9_4},
    {0, C7_5,  C8_5,  C9_5},
    {0, C7_6,  C8_6,  C9_6}
};

#endif

#ifdef SSD1306OLED

void led_set_kb(uint8_t usb_led) {
    // put your keyboard LED indicator (ex: Caps Lock LED) toggling code here
    led_set_user(usb_led);
};

#endif

void matrix_init_kb(void) {

    // // green led on
    // DDRD |= (1<<5);
    // PORTD &= ~(1<<5);

    // // orange led on
    // DDRB |= (1<<0);
    // PORTB &= ~(1<<0);

	matrix_init_user();
};


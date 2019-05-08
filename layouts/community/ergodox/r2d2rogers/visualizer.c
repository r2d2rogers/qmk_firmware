/*
Copyright 2017 Fred Sundvik

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "simple_visualizer.h"

// This function should be implemented by the keymap visualizer
// Don't change anything else than state->target_lcd_color and state->layer_text as that's the only thing
// that the simple_visualizer assumes that you are updating
// Also make sure that the buffer passed to state->layer_text remains valid until the previous animation is
// stopped. This can be done by either double buffering it or by using constant strings

static void get_visualizer_layer_and_color(visualizer_state_t* state) {
//    uint8_t saturation = 188;
    //if (state->status.leds & (1u << USB_LED_CAPS_LOCK)) {
        //saturation = 255;
    //}
    if (state->status.layer & 0x8000) {
        state->target_lcd_color = LCD_COLOR(0,255,255);
        state->layer_text = "15";
    }
    else if (state->status.layer & 0x4000) {
        state->target_lcd_color = LCD_COLOR(0,255,255);
        state->layer_text = "14";
    }
    else if (state->status.layer & 0x2000) {
        state->target_lcd_color = LCD_COLOR(0,255,255);
        state->layer_text = "13";
    }
    else if (state->status.layer & 0x1000) {
        state->target_lcd_color = LCD_COLOR(0,255,255);
        state->layer_text = "12";
    }
    else if (state->status.layer & 0x800) {
        state->target_lcd_color = LCD_COLOR(0,255,255);
        state->layer_text = "ADJUST";
    }
    else if (state->status.layer & 0x400) {
        state->target_lcd_color = LCD_COLOR(60,255,255);
        state->layer_text = "MUSIC";
    }
    else if (state->status.layer & 0x200) {
        state->target_lcd_color = LCD_COLOR(300,255,255);
        state->layer_text = "TKEY";
    }
    else if (state->status.layer & 0x100) {
        state->target_lcd_color = LCD_COLOR(51,255,255);
        state->layer_text = "UTIL";
    }
    else if (state->status.layer & 0x80) {
        state->target_lcd_color = LCD_COLOR(16,176,255);
        state->layer_text = "SPACEFN";
    }
    else if (state->status.layer & 0x40) {
        state->target_lcd_color = LCD_COLOR(270,255,255);
        state->layer_text = "RAISE";
    }
    else if (state->status.layer & 0x20) {
        state->target_lcd_color = LCD_COLOR(39,255,255);
        state->layer_text = "LOWER";
    }
    else if (state->status.layer & 0x10) {
        state->target_lcd_color = LCD_COLOR(174,90,112);
        state->layer_text = "NORMAN";
    }
    else if (state->status.layer & 0x8) {
        state->target_lcd_color = LCD_COLOR(174,90,112);
        state->layer_text = "WORKMAN";
    }
    else if (state->status.layer & 0x4) {
        state->target_lcd_color = LCD_COLOR(180,255,255);
        state->layer_text = "DVORAK";
    }
    else if (state->status.layer & 0x2) {
        state->target_lcd_color = LCD_COLOR(186,102,255);
        state->layer_text = "COLEMAK";
    }
    else {
        state->target_lcd_color = LCD_COLOR(0,0,0);
        state->layer_text = "QWERTY";
    }
}

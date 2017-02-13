# Build Options
#   change to "no" to disable the options, or define them in the Makefile in 
#   the appropriate keymap folder that will get included automatically
#
SUBPROJECT_DEFAULT = infinity
BOOTMAGIC_ENABLE  = no       # Virtual DIP switch configuration(+1000)
MOUSEKEY_ENABLE   = yes      # Mouse keys(+4700)
EXTRAKEY_ENABLE   = yes      # Audio control and System control(+450)
CONSOLE_ENABLE    = no       # Console for debug(+400)
COMMAND_ENABLE    = yes      # Commands for debug and configuration
CUSTOM_MATRIX     = yes      # Custom matrix file for the ErgoDox Infinity
SLEEP_LED_ENABLE  = no       # Breathing sleep LED during USB suspend
NKRO_ENABLE       = yes      # USB Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
MIDI_ENABLE       = no       # MIDI controls
UNICODE_ENABLE    = yes      # Unicode.
ONEHAND_ENABLE    = yes      # Allow swapping hands of keyboard
AUDIO_ENABLE      = no       # Audio output on port C6
BACKLIGHT_ENABLE  = no       # Enable keyboard backlight functionality
BLUETOOTH_ENABLE  = no       # Enable Bluetooth with the Adafruit EZ-Key HID
RGBLIGHT_ENABLE   = no       # Enable WS2812 RGB underlight.  Do not enable this with audio at the same time.

ifeq (${SUBPROJECT},infinity)
       VISUALIZER_ENABLE = yes	
endif

ifndef QUANTUM_DIR
	include ../../../../Makefile
endif

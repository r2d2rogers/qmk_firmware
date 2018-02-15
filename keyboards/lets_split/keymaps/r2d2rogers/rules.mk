# Build Options
#   change to "no" to disable the options, or define them in the Makefile in 
#   the appropriate keymap folder that will get included automatically

NKRO_ENABLE      = yes # Nkey Rollover - see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
TAP_DANCE_ENABLE = yes
ONEHAND_ENABLE   = yes # Allow swapping hands of keyboard
EXTRAKEY_ENABLE  = yes # Audio control and System control(+450)
MOUSEKEY_ENABLE  = yes # Mouse keys(+4700)
AUDIO_ENABLE     = no  # Audio output on port C6
RGBLIGHT_ENABLE  = yes # Enable WS2812 RGB underlight.
POINTING_DEVICE_ENABLE = no
USE_I2C          = no

ifndef QUANTUM_DIR
	include ../../../../Makefile
endif

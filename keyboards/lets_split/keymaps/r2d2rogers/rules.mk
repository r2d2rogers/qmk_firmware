# Build Options
#   change to "no" to disable the options, or define them in the Makefile in 
#   the appropriate keymap folder that will get included automatically

NKRO_ENABLE      = yes # Nkey Rollover - see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
ONEHAND_ENABLE   = yes # Allow swapping hands of keyboard
EXTRAKEY_ENABLE  = yes # Audio control and System control(+450)
AUDIO_ENABLE     = yes # Audio output on port C6
MOUSEKEY_ENABLE  = no  # Mouse keys(+4700)
POINTING_DEVICE_ENABLE = no
TAP_DANCE_ENABLE = no
USE_I2C          = yes
RGBLIGHT_ENABLE  = no # Enable WS2812 RGB underlight.
RGB_MATRIX_ENABLE= yes

ifndef QUANTUM_DIR
	include ../../../../Makefile
endif

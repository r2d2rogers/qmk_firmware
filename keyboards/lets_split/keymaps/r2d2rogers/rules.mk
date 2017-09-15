NKRO_ENABLE = yes           # Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
AUDIO_ENABLE = no           # Audio output on port C6
RGBLIGHT_ENABLE = yes       # Enable WS2812 RGB underlight.
TAP_DANCE_ENABLE = yes
ONEHAND_ENABLE = yes
USE_I2C = no

ifndef QUANTUM_DIR
	include ../../../../Makefile
endif

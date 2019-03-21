# Build Options
#   change to "no" to disable the options, or define them in the Makefile in
#   the appropriate keymap folder that will get included automatically

BOOTLOADER             = qmk-dfu
AUDIO_ENABLE           = yes # Audio output on port C6
CONSOLE_ENABLE         = no  # Console for debug(+400)
COMMAND_ENABLE         = no  # Commands for debug and configuration
EXTRAKEY_ENABLE        = yes # Audio control and System control(+450)
MOUSEKEY_ENABLE        = no  # Mouse keys(+4700)
NKRO_ENABLE            = yes # Nkey Rollover - see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
ONEHAND_ENABLE         = yes # Allow swapping hands of keyboard
POINTING_DEVICE_ENABLE = no
INDICATOR_LIGHTS       = no
RGBLIGHT_ENABLE        = no  # Enable WS2812 RGB underlight.
RGBLIGHT_TWINKLE       = no
RGB_MATRIX_ENABLE      = no  # IS31FL3731


# Build Options
#   change to "no" to disable the options, or define them in the Makefile in
#   the appropriate keymap folder that will get included automatically

BOOTLOADER        = qmk-dfu
BOOTMAGIC_ENABLE  = no       # Virtual DIP switch configuration(+1000)
MOUSEKEY_ENABLE   = no       # Mouse keys(+4700)
EXTRAKEY_ENABLE   = yes       # Audio control and System control(+450)
CONSOLE_ENABLE    = no         # Console for debug(+400)
COMMAND_ENABLE    = no        # Commands for debug and configuration
TAP_DANCE_ENABLE  = no
RGBLIGHT_ENABLE   = yes
AUDIO_ENABLE      = no
NKRO_ENABLE       = yes
VELOCIKEY_ENABLE = yes

ONEHAND_ENABLE    = yes # Allow swapping hands of keyboard
INDICATOR_LIGHTS  = no
MACROS_ENABLED    = no
RGBLIGHT_TWINKLE  = no

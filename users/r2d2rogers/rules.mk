
SRC += r2d2rogers.c rgb_stuff.c

ifneq ("$(wildcard $(USER_PATH)/secrets.c)","")
  SRC += secrets.c
endif

ifeq ($(strip $(TAP_DANCE_ENABLE)), yes)
  SRC += tap_dances.c
endif

EXTRAFLAGS        += -flto

ifeq ($(strip $(NO_SECRETS)), yes)
    OPT_DEFS += -DNO_SECRETS
endif

ifdef RGBLIGHT_ENABLE
  ifeq ($(strip $(INDICATOR_LIGHTS)), yes)
      OPT_DEFS += -DINDICATOR_LIGHTS
  endif
  ifeq ($(strip $(RGBLIGHT_TWINKLE)), yes)
    OPT_DEFS += -DRGBLIGHT_TWINKLE
  endif
  ifeq ($(strip $(RGBLIGHT_NOEEPROM)), yes)
    OPT_DEFS += -DRGBLIGHT_NOEEPROM
  endif
endif

ifeq ($(strip $(MACROS_ENABLED)), yes)
    OPT_DEFS += -DMACROS_ENABLED
endif

ifdef CONSOLE_ENABLE
  ifeq ($(strip $(KEYLOGGER_ENABLE)), yes)
    OPT_DEFS += -DKEYLOGGER_ENABLE
  endif
endif

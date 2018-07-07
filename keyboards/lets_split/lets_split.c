#include "lets_split.h"

#ifdef POINTING_DEVICE_ENABLE
#ifdef ANALOG_STICK_ENABLE
#include "pointing_device.h"
#include "report.h"
#include "analog.h"

extern uint16_t analogX;
extern uint16_t analogY;
extern bool buttonPressed;

#include "analog_stick.h"
#include "analog.h"

void pointing_device_task(void){
  report_mouse_t currentReport = {};

  currentReport = pointing_device_get_report();
  //shifting and transferring the info to the mouse report varaible

  //mouseReport.x = 127 max -127 min
  //currentReport.x = readaxis(analogRead(ANALOG_X_PIN));
  currentReport.x = parseaxis(readaxis(ANALOG_X_PIN));

  //mouseReport.y = 127 max -127 min
  //currentReport.y = readaxis(analogRead(ANALOG_Y_PIN)) * -1;
  currentReport.y = parseaxis(readaxis(ANALOG_Y_PIN));

  //mouseReport.v = 127 max -127 min (scroll vertical)
  currentReport.v = parseaxis(analogY);
  //mouseReport.h = 127 max -127 min (scroll horizontal)
  currentReport.h = parseaxis(analogX);

  //currentReport.buttons = 0x00;
  currentReport.buttons = buttonPressed;

  pointing_device_set_report(currentReport);

  pointing_device_send();
}
#endif
#endif

#ifdef SWAP_HANDS_ENABLE
__attribute__ ((weak))
const keypos_t hand_swap_config[MATRIX_ROWS][MATRIX_COLS] = {

  {{0, 4}, {1, 4}, {2, 4}, {3, 4}, {4, 4}, {5, 4}},
  {{0, 5}, {1, 5}, {2, 5}, {3, 5}, {4, 5}, {5, 5}},
  {{0, 6}, {1, 6}, {2, 6}, {3, 6}, {4, 6}, {5, 6}},
  {{0, 7}, {1, 7}, {2, 7}, {3, 7}, {4, 7}, {5, 7}},
  {{0, 0}, {1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}},
  {{0, 1}, {1, 1}, {2, 1}, {3, 1}, {4, 1}, {5, 1}},
  {{0, 2}, {1, 2}, {2, 2}, {3, 2}, {4, 2}, {5, 2}},
  {{0, 3}, {1, 3}, {2, 3}, {3, 3}, {4, 3}, {5, 3}},
};
#endif

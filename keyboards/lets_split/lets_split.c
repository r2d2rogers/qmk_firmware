#include "lets_split.h"
#include "pointing_device.h"
#include "report.h"
#include "analog.h"

int8_t readaxis(uint16_t axis){
    int8_t reaxis = ((axis - 16) >> 3) - 63;
    if(reaxis < 0){
            if(reaxis < -10 ){
                    return reaxis + 10;
            }else{
                    return 0;
            }
    }else if(reaxis > 0){
            if(reaxis > 10 ){
                    return reaxis - 10;
            }else{
                    return 0;
            }
    }
    return 0;

}

void pointing_device_task(void){
        uprint("Pointing Device: Let's Split: task start\n");
        report_mouse_t currentReport = {};

        xprintf("Pointing Device: Let's Split: raw x is %d\n",analogRead(2));
        xprintf("Pointing Device: Let's Split: raw y is %d\n",analogRead(3));

        currentReport = pointing_device_get_report();
//shifting and transferring the info to the mouse report varaible

//mouseReport.x = 127 max -127 min
        currentReport.x = readaxis(analogRead(3));

//mouseReport.y = 127 max -127 min
        currentReport.y = readaxis(analogRead(2)) * -1;

//mouseReport.v = 127 max -127 min (scroll vertical)
        currentReport.v = 0;
//mouseReport.h = 127 max -127 min (scroll horizontal)
        currentReport.h = 0;

        currentReport.buttons = 0x00;

    pointing_device_set_report(currentReport);

    pointing_device_send();
        uprint("Pointing Device: Let's Split: task end\n");
}

#ifdef ONEHAND_ENABLE
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

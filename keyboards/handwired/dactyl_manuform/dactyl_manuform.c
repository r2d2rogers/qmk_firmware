#include "dactyl_manuform.h"
#include "pointing_device.h"
#include "report.h"
#include "analog.h"
#include "math.h"


int8_t readaxis(uint16_t axis){
    int8_t reaxis = ((axis - 16) >> 5) - 15;
    uint8_t deadzone = 2;    
    if(reaxis < 0){
            if(reaxis < - deadzone ){
                    return reaxis + deadzone;
            }else{
                    return 0;
            }
    }else if(reaxis > 0){
            if(reaxis > deadzone ){
                    return reaxis - deadzone;
            }else{
                    return 0;
            }
    }
    return 0;
}


/*
	{
float deadzone = 0.25f;
    Vector2 stickInput = new Vector2(Input.GetAxis(“Horizontal”), Input.GetAxis(“Vertical”));
    if(stickInput.magnitude < deadzone)
        stickInput = Vector2.zero;
    else
        stickInput = stickInput.normalized * ((stickInput.magnitude - deadzone) / (1 - deadzone));

}
*/

void pointing_device_task(void){
        report_mouse_t currentReport = {};


        currentReport = pointing_device_get_report();
//shifting and transferring the info to the mouse report varaible

        //mouseReport.x = 127 max -127 min
        currentReport.x = readaxis(analogRead(2));
        //currentReport.x = 0;

        //mouseReport.y = 127 max -127 min
        currentReport.y = readaxis(analogRead(3)) * -1;
        //currentReport.y = 0;

        //mouseReport.v = 127 max -127 min (scroll vertical)
        currentReport.v = 0;
        //currentReport.v = readaxis(analogRead(2));

        //mouseReport.h = 127 max -127 min (scroll horizontal)
        //currentReport.h = readaxis(analogRead(3));
        currentReport.h = 0;

        currentReport.buttons = 0x00;

        pointing_device_set_report(currentReport);

        pointing_device_send();
}


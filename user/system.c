/*
 * system.c
 *
 *  Created on: 2023Äê12ÔÂ3ÈÕ
 *      Author: Aki_Tomoya
 */
#include "zf_common_headfile.h"


void Smartcar_Init(void)
{

    Buzzer_init();

    SW_Init();

    Screen_Init();

    IMU_Init();

    Flywheel_Init();

    PID_Controller_Init();

    pit_ms_init(PIT0, 1);

    beep(50);
    //Encoder_Init();


    //Forwardwheel_Init();

    beep(1000);
}

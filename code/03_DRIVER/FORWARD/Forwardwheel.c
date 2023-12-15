/*
 * Forwardwheel.c
 *
 *  Created on: 2023Äê12ÔÂ7ÈÕ
 *      Author: Aki Tomoya
 */
#include <code/03_DRIVER/FORWARD/Forwardwheel.h>
#include "zf_driver_pwm.h"

forwardwheel_status wheel;

void Forwardwheel_Init(void)
{
    pwm_init(PWM_GO  ,FORWARD_FRE,0);
    pwm_init(PWM_BACK,FORWARD_FRE,0);

    wheel.speed = 0;
}

void Forwardwheel_Output(void)
{
    if(wheel.speed>=0)
    {
        pwm_set_duty(PWM_GO,wheel.speed);
        pwm_set_duty(PWM_BACK,0);
    }
    else
    {
        pwm_set_duty(PWM_GO,0);
        pwm_set_duty(PWM_BACK,(-wheel.speed));
    }
}



/*
 * Motor.c
 *
 *  Created on: 2023Äê12ÔÂ3ÈÕ
 *      Author: Aki Tomoya
 */

#include <code/03_DRIVER/FLYWHEEL/Flywheel.h>
#include "zf_driver_pwm.h"
#include "zf_driver_gpio.h"

flywheel_status wheel_l,wheel_r;

void Flywheel_Init(void)
{
    pwm_init(PWM_CH1,MOTOR_FRE,10000);
    pwm_init(PWM_CH2,MOTOR_FRE,10000);

    gpio_init(DIR_CH1,GPO,0,GPO_PUSH_PULL);
    gpio_init(DIR_CH2,GPO,0,GPO_PUSH_PULL);

    wheel_l.speed = 0;
    wheel_r.speed = 0;

}


void Flywheel_Output(void)
{
    int16 duty_l,duty_r;
    uint8 dir_l,dir_r;

    if(wheel_l.speed>8000)     wheel_l.speed= 8000;
    if(wheel_r.speed>8000)     wheel_r.speed= 8000;
    if(wheel_l.speed<-8000)    wheel_l.speed=-8000;
    if(wheel_r.speed<-8000)    wheel_r.speed=-8000;

    if(wheel_l.speed >=0)
    {
        duty_l = 10000-wheel_l.speed;
        dir_l  = 1;
    }
    else
    {
        duty_l = 10000+wheel_l.speed;
        dir_l  = 0;
    }

    if(wheel_r.speed >=0)
    {
        duty_r = 10000-wheel_r.speed;
        dir_r  = 1;
    }
    else
    {
        duty_r = 10000+wheel_r.speed;
        dir_r  = 0;
    }



    gpio_set_level(DIR_CH1,dir_l);
    gpio_set_level(DIR_CH2,dir_r);
    pwm_set_duty(PWM_CH1, duty_l);
    pwm_set_duty(PWM_CH2, duty_r);

}

















/************************************
 * Control.c
 *
 *  Created on: 2023Äê12ÔÂ3ÈÕ
 *      Author: Aki_Tomoya
 **********************************/

#include <code/01_COMPUTATION/PID/PID.h>
#include <code/03_DRIVER/FLYWHEEL/Flywheel.h>
#include <code/04_CONTROL/BALANCE/Balance.h>
#include <Code/02_SENSOR/ENCODER/Encoder.h>
#include <Code/02_SENSOR/IMU/IMU.h>
#include <User/include.h>

PID_status Angle,Speed,Direct;

void PID_Controller_Init(void)
{
    Angle.Err_last  = 0;
    Speed.Err_last  = 0;
    Direct.Err_last = 0;

    Angle.Err_pre   = 0;
    Speed.Err_pre   = 0;
    Direct.Err_pre  = 0;

    Angle.Param.Kp  = 800;
    Angle.Param.Ki  = 0;
    Angle.Param.Kd  = 3200;
    Speed.Param.Kp  = Speed.Param.Ki  = Speed.Param.Kd  = 0;
    Direct.Param.Kp = Direct.Param.Ki = Direct.Param.Kd = 0;

}


void Balance_Control(void)
{

    wheel_l.speed = -PID_Pos( &Angle , 90.0, (imu.Angle.x));
    wheel_r.speed =  PID_Pos( &Angle , 90.0, (imu.Angle.x));

}

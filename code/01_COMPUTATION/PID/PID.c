/*
 * PID.c
 *
 *  Created on: 2023Äê12ÔÂ3ÈÕ
 *      Author: Aki Tomoya
 */

#include <code/01_COMPUTATION/PID/PID.h>

struct PID_status;

void PID_Init(PID_status* pid, float kp, float ki, float kd)
{
    pid->Err_last = 0;
    pid->Err_pre  = 0;

    pid->Param.Kp = kp;
    pid->Param.Ki = ki;
    pid->Param.Kd = kd;

    pid->OUT = 0;

}

float PID_Inc(PID_status *pid, float SetValue, float ActualValue)
{

    pid->Err_now  = SetValue - ActualValue;

    pid->OUT +=pid->Param.Ki *  pid->Err_now
             + pid->Param.Kp * (pid->Err_now-pid->Err_last)
             + pid->Param.Kd * (pid->Err_now-pid->Err_last*2+pid->Err_pre);

    pid->Err_pre  = pid->Err_last;
    pid->Err_last = pid->Err_now ;

    return pid->OUT;
}

float PID_Pos(PID_status *pid, float SetValue, float ActualValue)
{

    pid->Err_now = SetValue - ActualValue;

    pid->OUT = pid->Param.Kp *  pid->Err_now
             + pid->Param.Kd * (pid->Err_now-pid->Err_last)
             + pid->Param.Ki * (pid->Err_now-pid->Err_last*2+pid->Err_pre);

    pid->Err_pre  = pid->Err_last;
    pid->Err_last = pid->Err_now ;

    return pid->OUT;
}

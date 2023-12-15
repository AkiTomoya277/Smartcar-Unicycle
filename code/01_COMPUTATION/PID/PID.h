/*
 * PID.h
 *
 *  Created on: 2023��12��3��
 *      Author: Aki Tomoya
 */

#ifndef CODE_MOTOR_PID_H_
#define CODE_MOTOR_PID_H_

#include "../../../User/include.h"

/****************************************************
 * @ name: PID����ṹ��
 * @
 *
 *****************************************************/


typedef struct{

        pid_f_t Param;
        float Err_now,Err_last,Err_pre;
        float OUT;
}PID_status;

void PID_Init( PID_status *pid, float kp, float ki, float kd);
float PID_Inc( PID_status *pid, float SetValue, float ActualValue);
float PID_Pos( PID_status *pid, float SetValue, float ActualValue);

extern struct PID_status;


#endif /* CODE_MOTOR_PID_H_ */

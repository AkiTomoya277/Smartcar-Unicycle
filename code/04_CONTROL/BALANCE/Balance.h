/*
 * Control.h
 *
 *  Created on: 2023��12��3��
 *      Author: Aki Tomoya
 */

#ifndef CODE_MOTOR_BALANCE_H_
#define CODE_MOTOR_BALANCE_H_


extern struct PID_status ;

void PID_Controller_Init(void);

void Balance_Control(void);

#endif /* CODE_MOTOR_BALANCE_H_ */

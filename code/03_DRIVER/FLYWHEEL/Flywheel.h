/*
 * Motor.h
 *
 *  Created on: 2023��12��3��
 *      Author: Aki_Tomoya
 */
#ifndef _BRUSHLSS_MOTOR_
#define _BRUSHLESS_MOTOR_

#include "zf_common_typedef.h"

#define BACK                (0  )
#define GO                  (1  )

#define MAX_DUTY            (30 )              // ���ռ�ձ��������

#define MOTOR_FRE           (17000 )

#define DIR_CH1             (P02_6)             //��������з�������
#define PWM_CH1             (ATOM0_CH7_P02_7)   //����������ٶ�����

#define DIR_CH2             (P02_4)             //�Ҳ������з�������
#define PWM_CH2             (ATOM0_CH5_P02_5)   //�Ҳ��������ٶ�����


typedef struct{

        int16 speed;

}flywheel_status;

extern flywheel_status wheel_l,wheel_r;

void Flywheel_Init(void);
void Flywheel_Output(void);



#endif /* CODE_CONTROL_MOTOR_H_ */

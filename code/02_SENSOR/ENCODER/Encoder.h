/*
 * Encoder.h
 *
 *  Created on: 2023��12��3��
 *      Author: Aki_Tomoya
 */

#ifndef CODE_ENCODER_ENCODER_H_
#define CODE_ENCODER_ENCODER_H_

#include "../../01_COMPUTATION/PID/PID.h"

#define PIT0                            (CCU60_CH0 )                            // ʹ�õ������жϱ��

#define ENCODER_1                 (TIM5_ENCODER)                         // ������������Ӧʹ�õı������ӿ�
#define ENCODER_A_1               (TIM5_ENCODER_CH1_P10_3)               // A ���Ӧ������
#define ENCODER_B_1               (TIM5_ENCODER_CH2_P10_1)               // B ���Ӧ������

#define ENCODER_2                 (TIM2_ENCODER)
#define ENCODER_A_2               (TIM2_ENCODER_CH1_P33_7)
#define ENCODER_B_2               (TIM2_ENCODER_CH2_P33_6)

#define ENCODER                   (TIM4_ENCODER)
#define ENCODER_A                 (TIM4_ENCODER_CH1_P02_8)
#define ENCODER_B                 (TIM4_ENCODER_CH2_P00_9)


typedef struct{

        PID_status encoder_l;
        PID_status encoder_r;
        PID_status encoder;

        int speed_l,data_l;
        int speed_r,data_r;
        int speed  ,data;
}encoder_status;

extern encoder_status Encoder;

void Encoder_Init(void);
void Encoder_Read_update(void);



#endif /* CODE_ENCODER_ENCODER_H_ */

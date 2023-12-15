/*
 * Filtering.h
 *
 *  Created on: 2023��12��4��
 *      Author: Aki Tomoya
 */

#ifndef CODE_FILTER_FILTERING_H_
#define CODE_FILTER_FILTERING_H_

#include "zf_common_typedef.h"


/* @ name: �������˲��ṹ��
 * @
 *
 */
typedef struct{

        //������

        float dt; //����ʱ��

        //�����

        float Angle;    //���Ź��ƵĽǶ�
        float Gyro_x;   //���й��ƵĽ��ٶ�

        //�̶�����
        float Q_Angle;  //����������Э�鷽��
        float Q_Gyro;   //������Ʈ������Э�鷽��
        float R_Angle;  //���ٶȼ�����Э�鷽��

        char C_0;       //H�����һ���۲����

        //�м���
        float Q_Bias;       //������Ư��Ԥ��ֵ
        float Angle_err;    //Ԥ��ֵ��۲�ֵ��ƫ�Ԥ��-�۲⣩

        float PCt_0,    //�����м�ֵ
              PCt_1,
              E,
              t_0,      //�����м����
              t_1;
        float K_0,      //����������
              K_1;

        float Pdot[4];      //����P������м����
        float PP[2][2];     //P����X (Angle)��Э����

}kanman_status;

/* @ name: �����˲��ṹ��
 * @
 *
 */
typedef struct{

        int16 index;            //�±�
        float data_buffer[10];    //������
        float data_sum;         //���ݺ�
        float data_average;     //����ƽ��ֵ
}moving_status;



void Kanman_Init(kanman_status* kalman);
void Kanman_Filter(kanman_status* kalman, float Gyro, float Accel, uint32 dt);

void Moving_Init(moving_status* moving);
float Moving_Filter(moving_status* moving, float new_data);

extern struct moving_status;
extern struct kanman_status;

#endif /* CODE_FILTER_FILTERING_H_ */

/*
 * Filtering.c
 *
 *  Created on: 2023��12��4��
 *      Author: Aki Tomoya
 */

#include <code/01_COMPUTATION/FILTER/Filtering.h>

struct kanman_status;
struct moving_status;

void Kanman_Init(kanman_status * kalman)
{
    int i;

    //���ֵ
    (*kalman).Angle = 0.0;
    (*kalman).Gyro_x = 0.0;

    //�̶�����
    (*kalman).Q_Angle = 0.001;
    (*kalman).Q_Gyro  = 0.003;
    (*kalman).R_Angle = 0.5;

    (*kalman).C_0   = 1;

    //�м���
    (*kalman).Q_Bias    = 0;
    (*kalman).Angle_err = 0;

    (*kalman).PCt_0 = 0;
    (*kalman).PCt_1 = 0;
    (*kalman).E     = 0;
    (*kalman).t_0   = 0;
    (*kalman).t_1   = 0;

    (*kalman).K_0   = 0;
    (*kalman).K_1   = 0;

    for(i=0;i<4;i++)
    {
        (*kalman).Pdot[i] = 0;
    }

    (*kalman).PP[0][0] = 1;
    (*kalman).PP[0][1] = 0;
    (*kalman).PP[1][0] = 0;
    (*kalman).PP[1][1] = 1;

}

/********************************************************************************
* @ ������:    Kanman_Filter(kanman_status *kalman, float Gyro, float Accel, uint32 dt)
* @ ����:      Aki_Tomoya
* @ ��������:  ʵ�ֿ������˲�
* @ �������壺 Gyro: �����ǵĲ���ֵ Accel: ���ٶȼƵĲ���ֵ dt: ʱ��΢Ԫ
* @ ʹ��˵��:
*     ��ϵ��ʽ: x����ǰ��y������
*     �������: �Ը�����Ϊ����y����ٶȺ�y�����Ǽ��ٶȼƵĹ���ֵ
*     �Ƕȹ���ֵ:  ��һ�����ŽǶ� +�����ٶȲ���ֵ-��һ��������Ʈ����Ĭ����Ʈ�㶨
*
***********************************************************************************/

void Kanman_Filter(kanman_status * kalman, float Gyro, float Accel, uint32 dt)
{
    float dt_f;

    // ��dt(ms)ת��λdt_f(s)

    dt_f = (float)dt;
    dt_f = dt_f /1000;

    // ���ƽǶ�

    kalman->Angle += (Gyro - kalman->Q_Bias) * dt_f;

    // ����ģ�͵ķ���

    kalman->Pdot[0] = kalman->Q_Angle - kalman->PP[0][1] - kalman->PP[1][0];
    kalman->Pdot[1] = -kalman->PP[1][1];
    kalman->Pdot[2] = -kalman->PP[1][1];
    kalman->Pdot[3] = kalman->Q_Gyro;

    kalman->PP[0][0] += kalman->Pdot[0] * dt_f;
    kalman->PP[0][1] += kalman->Pdot[1] * dt_f;
    kalman->PP[1][0] += kalman->Pdot[2] * dt_f;
    kalman->PP[1][1] += kalman->Pdot[3] * dt_f;

    // ���㿨��������

    kalman->PCt_0 = kalman->C_0 * kalman->PP[0][0];
    kalman->PCt_1 = kalman->C_0 * kalman->PP[0][1];
    kalman->E     = kalman->R_Angle + kalman->C_0 * kalman->PCt_0;
    kalman->K_0   = kalman->PCt_0 / kalman->E;
    kalman->K_1   = kalman->PCt_1 / kalman->E;

    // �������ŽǶȡ�������Ʈ�����Ž��ٶ�

    kalman->Angle_err = Accel - kalman->Angle;
    kalman->Angle    += kalman->K_0 * kalman->Angle_err;
    kalman->Q_Bias   += kalman->K_1 * kalman->Angle_err;

    kalman->Gyro_x = Gyro - kalman->Q_Bias;

    // ���¹���ģ�͵ķ���
    kalman->t_0 = kalman->PCt_0;
    kalman->t_1 = kalman->C_0 * kalman->PP[0][1];

    kalman->PP[0][0] -= kalman->K_0 * kalman->t_0;
    kalman->PP[0][1] -= kalman->K_0 * kalman->t_1;
    kalman->PP[1][0] -= kalman->K_1 * kalman->t_0;
    kalman->PP[1][1] -= kalman->K_1 * kalman->t_1;

}

void Moving_Init(moving_status* moving)
{
    uint8 i;

    moving->data_average   = 0;
    moving->data_sum       = 0;
    moving->index          = 0;


    for(i=0;i<10;i++)
    {
        moving->data_buffer[i] = 0;
    }
}

float Moving_Filter(moving_status* moving, float new_data)
{
    moving->data_sum     = moving->data_sum - moving->data_buffer[moving->index]+ new_data ;
    moving->data_average = moving->data_sum / 10;

    moving->data_buffer[moving->index] = new_data;
    moving->index ++;
    if(10 <= moving->index)
    {
        moving->index = 0;
    }
    return moving->data_average;
}

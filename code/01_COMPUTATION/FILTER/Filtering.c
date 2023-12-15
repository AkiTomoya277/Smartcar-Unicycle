/*
 * Filtering.c
 *
 *  Created on: 2023年12月4日
 *      Author: Aki Tomoya
 */

#include <code/01_COMPUTATION/FILTER/Filtering.h>

struct kanman_status;
struct moving_status;

void Kanman_Init(kanman_status * kalman)
{
    int i;

    //输出值
    (*kalman).Angle = 0.0;
    (*kalman).Gyro_x = 0.0;

    //固定参量
    (*kalman).Q_Angle = 0.001;
    (*kalman).Q_Gyro  = 0.003;
    (*kalman).R_Angle = 0.5;

    (*kalman).C_0   = 1;

    //中间量
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
* @ 函数名:    Kanman_Filter(kanman_status *kalman, float Gyro, float Accel, uint32 dt)
* @ 作者:      Aki_Tomoya
* @ 函数功能:  实现卡尔曼滤波
* @ 参数含义： Gyro: 陀螺仪的测量值 Accel: 加速度计的测量值 dt: 时间微元
* @ 使用说明:
*     建系方式: x轴向前，y周向左；
*     输入参数: 以俯仰角为例，y轴角速度和y轴的倾角加速度计的估计值
*     角度估计值:  上一次最优角度 +（角速度测量值-上一次最有零飘），默认零飘恒定
*
***********************************************************************************/

void Kanman_Filter(kanman_status * kalman, float Gyro, float Accel, uint32 dt)
{
    float dt_f;

    // 将dt(ms)转换位dt_f(s)

    dt_f = (float)dt;
    dt_f = dt_f /1000;

    // 估计角度

    kalman->Angle += (Gyro - kalman->Q_Bias) * dt_f;

    // 估计模型的方差

    kalman->Pdot[0] = kalman->Q_Angle - kalman->PP[0][1] - kalman->PP[1][0];
    kalman->Pdot[1] = -kalman->PP[1][1];
    kalman->Pdot[2] = -kalman->PP[1][1];
    kalman->Pdot[3] = kalman->Q_Gyro;

    kalman->PP[0][0] += kalman->Pdot[0] * dt_f;
    kalman->PP[0][1] += kalman->Pdot[1] * dt_f;
    kalman->PP[1][0] += kalman->Pdot[2] * dt_f;
    kalman->PP[1][1] += kalman->Pdot[3] * dt_f;

    // 计算卡尔曼增益

    kalman->PCt_0 = kalman->C_0 * kalman->PP[0][0];
    kalman->PCt_1 = kalman->C_0 * kalman->PP[0][1];
    kalman->E     = kalman->R_Angle + kalman->C_0 * kalman->PCt_0;
    kalman->K_0   = kalman->PCt_0 / kalman->E;
    kalman->K_1   = kalman->PCt_1 / kalman->E;

    // 计算最优角度、最优零飘、最优角速度

    kalman->Angle_err = Accel - kalman->Angle;
    kalman->Angle    += kalman->K_0 * kalman->Angle_err;
    kalman->Q_Bias   += kalman->K_1 * kalman->Angle_err;

    kalman->Gyro_x = Gyro - kalman->Q_Bias;

    // 更新估计模型的方差
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

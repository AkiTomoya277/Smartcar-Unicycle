/*
 * Filtering.h
 *
 *  Created on: 2023年12月4日
 *      Author: Aki Tomoya
 */

#ifndef CODE_FILTER_FILTERING_H_
#define CODE_FILTER_FILTERING_H_

#include "zf_common_typedef.h"


/* @ name: 卡尔曼滤波结构体
 * @
 *
 */
typedef struct{

        //输入量

        float dt; //采样时间

        //输出量

        float Angle;    //最优估计的角度
        float Gyro_x;   //最有估计的角速度

        //固定参量
        float Q_Angle;  //陀螺仪噪声协议方差
        float Q_Gyro;   //陀螺仪飘逸噪声协议方差
        float R_Angle;  //加速度计噪声协议方差

        char C_0;       //H矩阵的一个观测参数

        //中间量
        float Q_Bias;       //陀螺仪漂移预估值
        float Angle_err;    //预期值与观测值的偏差（预期-观测）

        float PCt_0,    //计算中间值
              PCt_1,
              E,
              t_0,      //计算中间变量
              t_1;
        float K_0,      //卡尔曼增益
              K_1;

        float Pdot[4];      //计算P矩阵的中间矩阵
        float PP[2][2];     //P矩阵，X (Angle)的协方差

}kanman_status;

/* @ name: 滑动滤波结构体
 * @
 *
 */
typedef struct{

        int16 index;            //下标
        float data_buffer[10];    //缓冲区
        float data_sum;         //数据和
        float data_average;     //数据平均值
}moving_status;



void Kanman_Init(kanman_status* kalman);
void Kanman_Filter(kanman_status* kalman, float Gyro, float Accel, uint32 dt);

void Moving_Init(moving_status* moving);
float Moving_Filter(moving_status* moving, float new_data);

extern struct moving_status;
extern struct kanman_status;

#endif /* CODE_FILTER_FILTERING_H_ */

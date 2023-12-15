/*
 * Attitude_Computation.c
 *
 *  Created on: 2023��12��3��
 *      Author: Aki_Tomoya
 */

#include <Code/02_SENSOR/IMU/IMU.h>
#include "zf_device_imu660ra.h"

#define PI 3.1415926
float angle0 = -4.5; //��ʼƫ��������


IMU_STRUCT imu;

void IMU_Init(void)
{
    while(imu660ra_init());

    xyz_f_t init = {0,0,0};

    imu.Gyro_o  = init;
    imu.Acc_o   = init;

    Kanman_Init(&(imu.atti_x));
    Kanman_Init(&(imu.atti_y));

    Moving_Init(&(imu.Gyro_m_x));
    Moving_Init(&(imu.Gyro_m_y));
    Moving_Init(&(imu.Gyro_m_z));
}

void IMU_Read(void)
{
    imu660ra_get_acc();
    imu660ra_get_gyro();

    //��ȡ���ٶȼƵ�ԭʼAccֵ
     imu.Acc_o.x  = imu660ra_acc_x;
     imu.Acc_o.y  = imu660ra_acc_y;
     imu.Acc_o.z  = imu660ra_acc_z;

    //��ȡ�����ǵ�ԭʼGyroֵ
     imu.Gyro_o.x = imu660ra_gyro_x;
     imu.Gyro_o.y = imu660ra_gyro_y;
     imu.Gyro_o.z = imu660ra_gyro_z;

    //�Ի�ȡ�����ݽ��л����˲�
     imu.Gyro_t.x = Moving_Filter(&(imu.Gyro_m_x),imu.Gyro_o.x);
     imu.Gyro_t.y = Moving_Filter(&(imu.Gyro_m_y),imu.Gyro_o.y);
     imu.Gyro_t.z = Moving_Filter(&(imu.Gyro_m_z),imu.Gyro_o.z);
     imu.Acc_t.x  = Moving_Filter(&(imu.Acc_m_x),imu.Acc_o.x);
     imu.Acc_t.y  = Moving_Filter(&(imu.Acc_m_y),imu.Acc_o.y);
     imu.Acc_t.z  = Moving_Filter(&(imu.Acc_m_z),imu.Acc_o.z);


}

void IMU_Update(void)
{
    //���˲�������ݽ��н���ת��
     imu.Acc_g.x = imu660ra_acc_transition( imu.Acc_t.x);
     imu.Acc_g.y = imu660ra_acc_transition( imu.Acc_t.y);
     imu.Acc_g.z = imu660ra_acc_transition( imu.Acc_t.z);

     imu.Gyro_g.x = -imu660ra_gyro_transition( imu.Gyro_t.x);
     imu.Gyro_g.y = -imu660ra_gyro_transition( imu.Gyro_t.y);
     imu.Gyro_g.z = -imu660ra_gyro_transition( imu.Gyro_t.z);

    //ͨ�����ٶȼƹ��ƽ��ٶ�
     imu.Angle_stimate.z = atan2((float)imu.Acc_g.y,(float)imu.Acc_g.x)*180/PI;
     imu.Angle_stimate.x = atan2((float)imu.Acc_g.z,(float)imu.Acc_g.y)*180/PI;
     imu.Angle_stimate.y = atan2((float)imu.Acc_g.x,(float)imu.Acc_g.z)*180/PI;

    //�����ݽ��п������˲�
     Kanman_Filter(&(imu.atti_x),imu.Gyro_g.x,imu.Angle_stimate.x,5);
     Kanman_Filter(&(imu.atti_y),imu.Gyro_g.y,imu.Angle_stimate.y,5);

     imu.Gyro.x = imu.atti_x.Gyro_x;
     imu.Gyro.y = imu.atti_y.Gyro_x;

     imu.Angle.x =  imu.atti_x.Angle;
     imu.Angle.y = (imu.atti_y.Angle) + angle0;
}












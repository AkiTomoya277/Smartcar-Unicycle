/*
 * Attitude_Computation.h
 *
 *  Created on: 2023Äê12ÔÂ3ÈÕ
 *      Author: Aki Tomoya
 */

#ifndef _ATTITUDE_COMPUTATION_H_
#define _ATTITUDE_COMPUTATION_H_

#include "../../../User/include.h"
#include "../../01_COMPUTATION/FILTER/Filtering.h"

typedef struct{

    xyz_f_t Gyro_o;
    xyz_f_t Acc_o;

    xyz_f_t Gyro_t;
    xyz_f_t Acc_t;

    xyz_f_t Gyro_g;
    xyz_f_t Acc_g;

    moving_status Gyro_m_x;
    moving_status Gyro_m_y;
    moving_status Gyro_m_z;

    moving_status Acc_m_x;
    moving_status Acc_m_y;
    moving_status Acc_m_z;

    kanman_status atti_x;
    kanman_status atti_y;

    xyz_f_t Angle_stimate;

    xyz_f_t Gyro;
    xyz_f_t Angle;

}IMU_STRUCT;

extern IMU_STRUCT imu;

void IMU_Init(void);
void IMU_Read(void);
void IMU_Update(void);


#endif /* CODE_IMU_MEASURE_ATTITUDE_COMPUTATION_H_ */

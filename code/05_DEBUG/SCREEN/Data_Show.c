/*
 * Data_Show.c
 *
 *  Created on: 2023Äê12ÔÂ4ÈÕ
 *      Author: Aki Tomoya
 */
#include <code/03_DRIVER/FLYWHEEL/Flywheel.h>
#include <code/05_DEBUG/SCREEN/Data_Show.h>
#include <code/05_DEBUG/TOOLS/Tools.h>
#include <Code/02_SENSOR/IMU/IMU.h>
#include "zf_common_typedef.h"
#include "zf_device_imu660ra.h"
#include "zf_device_tft180.h"
#include "zf_driver_gpio.h"

void Screen_Init(void)
{
    tft180_set_dir(TFT180_CROSSWISE);
    tft180_init();

}
void IMU_Get_10x12_Show(void)
{

}

void IMU_Filter_10x12_Show(void)
{

}

void IMU_Debug_10x12_Show(void)
{
    if(SW1==0)
    {
        tft180_show_string(0, 0,"o.x: ");tft180_show_int(60, 0,imu660ra_gyro_x,4);
        tft180_show_string(0,16,"o.y: ");tft180_show_int(60,16,imu660ra_gyro_y,4);
        tft180_show_string(0,32,"o.z: ");tft180_show_int(60,32,imu660ra_gyro_z,4);

        tft180_show_string(0,48,"f.x: ");tft180_show_float(60,48,imu.Gyro_t.x,4,1);
        tft180_show_string(0,64,"f.y: ");tft180_show_float(60,64,imu.Gyro_t.y,4,1);
        tft180_show_string(0,80,"f.z: ");tft180_show_float(60,80,imu.Gyro_t.z,4,1);
    }

    if(SW2==0)
    {
        tft180_show_string(0, 0,"o.x: ");tft180_show_float(60, 0,imu.Acc_t.x,4,1);
        tft180_show_string(0,16,"o.y: ");tft180_show_float(60,16,imu.Acc_t.y,4,1);
        tft180_show_string(0,32,"o.z: ");tft180_show_float(60,32,imu.Acc_t.z,4,1);

        tft180_show_string(0,48,"f.x: ");tft180_show_float(60,48,imu.Acc_g.x,4,1);
        tft180_show_string(0,64,"f.y: ");tft180_show_float(60,64,imu.Acc_g.y,4,1);
        tft180_show_string(0,80,"f.z: ");tft180_show_float(60,80,imu.Acc_g.z,4,1);

    }

    if(SW3==0)
    {
        tft180_show_string(0, 0,"t.x: ");tft180_show_float(60, 0,imu.Angle_stimate.x,4,1);
        tft180_show_string(0,16,"t.y: ");tft180_show_float(60,16,imu.Angle_stimate.y,4,1);


        tft180_show_string(0,40,"G.x: ");tft180_show_float(60,40,imu.Gyro.x, 4,1);
        tft180_show_string(0,56,"G.y: ");tft180_show_float(60,56,imu.Gyro.y, 4,1);

        tft180_show_string(0,80,"A.x: ");tft180_show_float(60,80,imu.Angle.x,4,1);
        tft180_show_string(0,96,"A.y: ");tft180_show_float(60,96,imu.Angle.y,4,1);
    }

    if(SW4==0)
    {
        tft180_show_string(0,80,"A.x: ");tft180_show_float(60,80,imu.Angle.x,4,1);
        tft180_show_string(0,96,"A.y: ");tft180_show_float(60,96,imu.Angle.y,4,1);
        tft180_show_string(0, 0,"S.l: ");tft180_show_int(60, 0,wheel_l.speed,4);
        tft180_show_string(0,16,"S.r: ");tft180_show_int(60,16,wheel_r.speed,4);
    }

}



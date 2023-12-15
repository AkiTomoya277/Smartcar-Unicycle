/*
 * Encoder.c
 *
 *  Created on: 2023Äê12ÔÂ3ÈÕ
 *      Author: Aki Tomoya
 */

#include <Code/02_SENSOR/ENCODER/Encoder.h>
#include "zf_driver_encoder.h"
encoder_status Encoder;

void Encoder_Init(void)
{
    encoder_quad_init(TIM5_ENCODER,TIM5_ENCODER_CH1_P10_3,TIM5_ENCODER_CH2_P10_1);
    encoder_quad_init(TIM2_ENCODER,TIM2_ENCODER_CH1_P33_7,TIM2_ENCODER_CH2_P33_6);
    encoder_quad_init(TIM4_ENCODER,TIM4_ENCODER_CH1_P02_8,TIM4_ENCODER_CH2_P00_9);

    Encoder.data_l = 0.0;
    Encoder.data_r = 0.0;
    Encoder.data   = 0.0;

    Encoder.speed_l = 0.0;
    Encoder.speed_r = 0.0;
}

void Encoder_Read_update(void)
{
    Encoder.data_l = encoder_get_count(ENCODER_1);
    Encoder.data_r = encoder_get_count(ENCODER_2);
    Encoder.data   = encoder_get_count(ENCODER);

    Encoder.speed_l = (float)Encoder.data_l/10.0 ;
    Encoder.speed_r = (float)Encoder.data_r/10.0 ;
    //Encoder.speed   = (float)Encoder.data  /100*(float)dt /(2*PI)*r;

    encoder_clear_count(ENCODER_1);
    encoder_clear_count(ENCODER_2);
    encoder_clear_count(ENCODER);
}



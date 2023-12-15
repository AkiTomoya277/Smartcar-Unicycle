/*
 * Forwardwheel.h
 *
 *  Created on: 2023Äê12ÔÂ7ÈÕ
 *      Author: Aki Tomoya
 */

#ifndef CODE_03_DRIVER_FORWARD_FORWARDWHEEL_H_
#define CODE_03_DRIVER_FORWARD_FORWARDWHEEL_H_

#include "zf_common_typedef.h"


#define FORWARD_FRE         (250)

#define PWM_GO      ATOM1_CH0_P21_2
#define PWM_BACK    ATOM0_CH1_P21_3

typedef struct{

        int16 speed;

}forwardwheel_status;


void Forwardwheel_Init(void);
void Forwardwheel_Output(void);

extern forwardwheel_status wheel;

#endif /* CODE_03_DRIVER_FORWARD_FORWARDWHEEL_H_ */

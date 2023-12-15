/*
 * Tools.h
 *
 *  Created on: 2023Äê12ÔÂ9ÈÕ
 *      Author: Aki Tomoya
 */

#ifndef CODE_05_DEBUG_TOOLS_TOOLS_H_
#define CODE_05_DEBUG_TOOLS_TOOLS_H_

#include "zf_common_typedef.h"

#define Buzzer P13_0

#define BM1    P33_11
#define BM2    P33_12
#define BM3    P33_13
#define BM4    P32_4


#define SW1    gpio_get_level(BM1)
#define SW2    gpio_get_level(BM2)
#define SW3    gpio_get_level(BM3)
#define SW4    gpio_get_level(BM4)

void Buzzer_init(void);
void beep(uint32 ms);
void SW_Init(void);
void Get_SW(void);

#endif /* CODE_05_DEBUG_TOOLS_TOOLS_H_ */

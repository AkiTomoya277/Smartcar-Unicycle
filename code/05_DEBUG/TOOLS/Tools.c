/*
 * Tools.c
 *
 *  Created on: 2023Äê12ÔÂ9ÈÕ
 *      Author: Aki Tomoya
 */
#include <code/05_DEBUG/TOOLS/Tools.h>
#include "zf_common_typedef.h"
#include "zf_driver_delay.h"
#include "zf_driver_gpio.h"

void Buzzer_init(void)
{
    gpio_init(Buzzer,GPO,0,GPO_PUSH_PULL);
}
void beep(uint32 ms)
{
    gpio_set_level(Buzzer,1);
    system_delay_ms(ms);
    gpio_set_level(Buzzer,0);
}

void SW_Init(void)
{
    gpio_init(BM1,GPI,1,GPI_PULL_UP);
    gpio_init(BM2,GPI,1,GPI_PULL_UP);
    gpio_init(BM3,GPI,1,GPI_PULL_UP);
    gpio_init(BM4,GPI,1,GPI_PULL_UP);
}


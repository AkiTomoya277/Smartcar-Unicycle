/*
 * include.h
 *
 *  Created on: 2023Äê12ÔÂ3ÈÕ
 *      Author: Aki Tomoya
 */

#ifndef USER_INCLUDE_H_
#define USER_INCLUDE_H_


#include "zf_common_typedef.h"

#define ABS(x)                      ( (x)>0?        (x)     :(-x))
#define LIMIT(x,min,max)            ( (x)<(min)?    (min)   :((x)>(max)? (max):(x)))
#define _MIN(a,b)                   ( (a)<(b)?      (a)     :(b))
#define _MAX(a,b)                   ( (a)>(b)?      (a)     :(b))


typedef struct{

        char x, y, z;

}xyz_char_t;

typedef struct{

        int16 x, y, z;

}xyz_s16_t;

typedef struct{

        float x, y, z;

}xyz_f_t;

typedef struct{

        int32 x, y, z;

}xyz_s32_t;

typedef struct{

        float Kp;
        float Ki;
        float Kd;

}pid_f_t;

typedef struct{

        int16 l;
        int16 r;
}lr_s16_t;

typedef struct{

        float l;
        float r;
}lr_f_t;

typedef struct{

        float x[4];
        float y[4];
        float z[4];
}xyz_f_4_t;

typedef struct{

        float x[2][2];
        float y[2][2];
        float z[2][2];
}xyz_f_2_2_t;

#endif /* _INCLUDE_H_ */

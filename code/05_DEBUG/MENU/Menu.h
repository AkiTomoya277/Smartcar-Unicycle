/*
 * Menu.h
 *
 *  Created on: 2023Äê12ÔÂ8ÈÕ
 *      Author: Aki Tomoya
 */

#ifndef CODE_05_DEBUG_MENU_MENU_H_
#define CODE_05_DEBUG_MENU_MENU_H_

#include "zf_common_headfile.h"

typedef struct{

        uint8 current;
        uint8 up;
        uint8 down;
        uint8 enter;
        uint8 back;
        void (*current_operation)();

}keytable_status;

// code keytable_status table[30]=
//{
//
//};



#endif /* CODE_05_DEBUG_MENU_MENU_H_ */

#ifndef _DEV_PROCESS_H_
#define _DEV_PROCESS_H_

#include "led.h"
#include "usart.h"

DEV_ERR Sys_Params_Init(void);

DEV_ERR Sys_Devs_Init(void);


DEV_ERR Sys_Process(void);

#endif

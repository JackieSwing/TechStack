#ifndef _LED_H_
#define _LED_H_

#include "stm32f10x.h"
#include "common.h"
#include "error.h"

void Led_Params_Init(void);

void Led_Init(GPIO_Configer configer);
void Led_On(GPIO_Configer configer);
void Led_Off(GPIO_Configer configer);

#endif

#ifndef _USART_H_
#define _USART_H_

#include "stm32f10x.h"
#include "common.h"
#include "error.h"


void Usart_Params_Init(void);

void Usart_Init(USART_Configer configer);
void Usart_Port_Init(USART_Configer configer);
void Usart_Ext_Init(USART_Configer configer);


#endif

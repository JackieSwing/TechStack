#ifndef _USART_H_
#define _USART_H_

#include "stm32f10x.h"
#include "dev_common.h"
#include "stdio.h"

#ifdef __GNUC__
    #define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
    #define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif

void Usart_Init(void);
void Usart_Pin_Init(void);
void Usart_Port_Init(void);

#endif

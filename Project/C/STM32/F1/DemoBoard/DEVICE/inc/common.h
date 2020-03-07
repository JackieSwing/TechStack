#ifndef _DEV_COMMON_H_
#define _DEV_COMMON_H_

#include "def.h"
#include "config.h"

// externs
//   Led2
extern GPIO_Configer Led2;
//   Usart1
extern USART_Configer Usart1;

#ifdef __GNUC__
    #define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
    #define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif

void APB_Clock_Enable(uint32_t clock, Clock_Type clockType);

void Delay_US(void);
void Delay_MS(int ms);

#endif


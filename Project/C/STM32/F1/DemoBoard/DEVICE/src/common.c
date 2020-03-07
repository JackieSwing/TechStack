#include "common.h"

// Globals Devices
//   Led2
GPIO_Configer Led2;
//   Usart1
USART_Configer Usart1;

void Delay_US(void) {
   uint16_t i = 1000;
   while(i--);
}

void Delay_MS(int ms) {
    while(ms--) {
        Delay_US();
    }
}

// Init APB1 or APB2 clock
void APB_Clock_Enable(uint32_t clock, Clock_Type clockType) {
    if (clockType == CLOCK_TYPE_APB1) {
        RCC_APB1PeriphClockCmd(clock, ENABLE);
    } else {
        RCC_APB2PeriphClockCmd(clock, ENABLE);
    }
    return;
}


// Rewrite fputs function to use usart as printer
PUTCHAR_PROTOTYPE {
  USART_SendData(PRINTER, (uint8_t) ch);
  while (USART_GetFlagStatus(PRINTER, USART_FLAG_TC) == RESET);
  return ch;
}

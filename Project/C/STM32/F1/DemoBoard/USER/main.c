/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"
#include <stdio.h>
#include "led.h"
#include "usart.h"

void Delay_US(void) {
    int i = 1000;
    while(i--);
}

void Delay_MS(int ms) {
    while(ms--) {
        Delay_US();
    }
}

/**
  * @brief  Main program.
  * @param  None
  * @retval None
  */
int main(void) {
    Led_Init(); // GPIO Configuration
    Usart_Init();

    while (1) {
        Led_On();
        Delay_MS(1000);
        printf("Hello, I am USART1\r\n");
        Led_Off();
        Delay_MS(1000);
    }
}

/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"
#include <stdio.h>
#include "led.h"

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

    while (1) {
        Led_On();
        Delay_MS(1000);

        Led_Off();
        Delay_MS(1000);
    }
}

/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/

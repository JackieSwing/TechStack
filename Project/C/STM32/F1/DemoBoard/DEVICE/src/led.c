#include "led.h"

void Led_Init(void) {
    RCC_APB2PeriphClockCmd(DEV_LED2_CLOCK, ENABLE);
    GPIO_InitTypeDef GPIO_InitStructure;

    GPIO_InitStructure.GPIO_Pin = DEV_LED2_PIN;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_Init(DEV_LED2_PORT, &GPIO_InitStructure);
    return;
}


void Led_On(void) {
    GPIO_WriteBit(DEV_LED2_PORT, DEV_LED2_PIN, Bit_RESET);
    return;
}


void Led_Off(void) {
    GPIO_WriteBit(DEV_LED2_PORT, DEV_LED2_PIN, Bit_SET);
    return;
}

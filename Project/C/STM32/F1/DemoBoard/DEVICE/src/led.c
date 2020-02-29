#include "led.h"

int Led_Init(void) {
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE, ENABLE);
    GPIO_InitTypeDef GPIO_InitStructure;

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_Init(GPIOE, &GPIO_InitStructure);
    return 0;
}


int Led_On(void) {
    GPIO_WriteBit(GPIOE, GPIO_Pin_5, Bit_RESET);
    return 0;
}


int Led_Off(void) {
    GPIO_WriteBit(GPIOE, GPIO_Pin_5, Bit_SET);
    return 0;
}

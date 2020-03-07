#include "led.h"

void Led_Params_Init() {
    GPIO_Configer *configer = &Led2;

    configer->port = GPIOE;
    configer->clock = RCC_APB2Periph_GPIOE;
    configer->clockType = CLOCK_TYPE_APB2;

    configer->config.GPIO_Pin = GPIO_Pin_5;
    configer->config.GPIO_Mode = GPIO_Mode_Out_PP;
    configer->config.GPIO_Speed = GPIO_Speed_50MHz;
    return;
}


void Led_Init(GPIO_Configer configer) {
    APB_Clock_Enable(configer.clock, configer.clockType);
    GPIO_Init(configer.port, &(configer.config));
    return;
}

void Led_On(GPIO_Configer configer) {
    GPIO_WriteBit(configer.port, configer.config.GPIO_Pin, Bit_RESET);
    return;
}


void Led_Off(GPIO_Configer configer) {
    GPIO_WriteBit(configer.port, configer.config.GPIO_Pin, Bit_SET);
    return;
}


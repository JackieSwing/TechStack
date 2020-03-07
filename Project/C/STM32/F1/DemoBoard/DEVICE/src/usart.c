#include "usart.h"

// serial port init
void Usart_Params_Init(void) {
    // get handles
    USART_Configer *ptConfiger = &Usart1;

    // configer of pin rx
    ptConfiger->configRx.port = GPIOA;
    ptConfiger->configRx.clock = RCC_APB2Periph_GPIOA;
    ptConfiger->configRx.clockType = CLOCK_TYPE_APB2;

    ptConfiger->configRx.config.GPIO_Pin = GPIO_Pin_10;
    ptConfiger->configRx.config.GPIO_Mode = GPIO_Mode_IN_FLOATING;

    // configer of pin tx 
    ptConfiger->configTx.port = GPIOA;
    ptConfiger->configTx.clock = RCC_APB2Periph_GPIOA;
    ptConfiger->configTx.clockType = CLOCK_TYPE_APB2;

    ptConfiger->configTx.config.GPIO_Pin = GPIO_Pin_9;
    ptConfiger->configTx.config.GPIO_Mode = GPIO_Mode_AF_PP;
    ptConfiger->configTx.config.GPIO_Speed = GPIO_Speed_50MHz;

    // configer of ext usart
    ptConfiger->configUsartExt.portExt = USART1;
    ptConfiger->configUsartExt.clockExt = RCC_APB2Periph_USART1;
    ptConfiger->configUsartExt.clockType = CLOCK_TYPE_APB2;

    ptConfiger->configUsartExt.configExt.USART_BaudRate = 9600;
    ptConfiger->configUsartExt.configExt.USART_Parity = USART_Parity_No;
    ptConfiger->configUsartExt.configExt.USART_StopBits = USART_StopBits_1;
    ptConfiger->configUsartExt.configExt.USART_WordLength = USART_WordLength_8b;
    ptConfiger->configUsartExt.configExt.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    ptConfiger->configUsartExt.configExt.USART_Mode = USART_Mode_Tx;

    return;
}

// Init with USART params
void Usart_Init(USART_Configer configer) {
    Usart_Port_Init(configer);
    Usart_Ext_Init(configer);

    USART_ClearFlag(configer.configUsartExt.portExt, USART_FLAG_TC);
}

void Usart_Port_Init(USART_Configer configer) {
    // get handles
    GPIO_Configer *ptConfigerTx = &(configer.configTx);
    GPIO_Configer *ptConfigerRx = &(configer.configRx);

    // process pin tx
    APB_Clock_Enable(ptConfigerTx->clock, ptConfigerTx->clockType);
    GPIO_Init(ptConfigerTx->port, &(ptConfigerTx->config));

    // process pin rx
    APB_Clock_Enable(ptConfigerRx->clock, ptConfigerRx->clockType);
    GPIO_Init(ptConfigerRx->port, &(ptConfigerRx->config));
    return;
}

void Usart_Ext_Init(USART_Configer configer) {
    // get configer handle
    USART_Ext_Configer *ptConfigerUsartExt = &(configer.configUsartExt);

    // call apporate function to enable device clock
    APB_Clock_Enable(ptConfigerUsartExt->clockExt, ptConfigerUsartExt->clockType);
    // init usart
    USART_Init(ptConfigerUsartExt->portExt, &(ptConfigerUsartExt->configExt));
    USART_Cmd(ptConfigerUsartExt->portExt, ENABLE);
    return;
}


#include "usart.h"

// serial port init
void Usart_Init(void) {
    Usart_Pin_Init();
    Usart_Port_Init();
    USART_ClearFlag(USART1, USART_FLAG_TC);

    return;
}


void Usart_Pin_Init(void) {
    GPIO_InitTypeDef GPIO_InitStructure;

    RCC_APB2PeriphClockCmd(DEV_USART1_CLOCK_PORT, ENABLE); // open clock

    // USART1_TX
    GPIO_InitStructure.GPIO_Pin = DEV_USART1_PIN_TX;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_Init(DEV_USART1_PORT, &GPIO_InitStructure);

    // USART1_RX
    GPIO_InitStructure.GPIO_Pin = DEV_USART1_PIN_RX;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Init(DEV_USART1_PORT, &GPIO_InitStructure);
    return;
}

void Usart_Port_Init(void) {
    USART_InitTypeDef USART_InitStructure;
    RCC_APB2PeriphClockCmd(DEV_USART1_CLOCK_COM, ENABLE);

    USART_InitStructure.USART_BaudRate = DEV_UASRT_BAUD_RATE;
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;
    USART_InitStructure.USART_StopBits = USART_StopBits_1;
    USART_InitStructure.USART_Parity = USART_Parity_No;
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    USART_InitStructure.USART_Mode = USART_Mode_Tx;

    USART_Init(DEV_USART1_NO, &USART_InitStructure);
    USART_Cmd(DEV_USART1_NO, ENABLE);
    return;
}

PUTCHAR_PROTOTYPE {
  USART_SendData(USART1, (uint8_t) ch);
  while (USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET) {
  }
  return ch;
}

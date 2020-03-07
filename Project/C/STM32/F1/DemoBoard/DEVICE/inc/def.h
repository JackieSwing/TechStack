#ifndef _DEV_DEF_H_
#define _DEV_DEF_H_

#include "stdio.h"
#include "stm32f10x.h"

// enum of clock type: APB1 or APB2
typedef enum Clock_Type {
    CLOCK_TYPE_APB1,
    CLOCK_TYPE_APB2
}Clock_Type;


// define gpio config of usart
typedef struct GPIO_Configer {
    GPIO_TypeDef* port; // address
    GPIO_InitTypeDef config; // config

    uint32_t clock; // clock
    Clock_Type clockType; // clock Type, APB1 or APB2
}GPIO_Configer;

// define ext config of usart
typedef struct USART_Ext_Configer {
// defination of usart extension
    USART_TypeDef* portExt;
    uint32_t clockExt; // clock
    Clock_Type clockType; // clock Type, APB1 or APB2

    USART_InitTypeDef configExt;
}USART_Ext_Configer;

// define config
typedef struct USART_Configer {
//  defination of physical pins
    GPIO_Configer configTx;
    GPIO_Configer configRx;

    USART_Ext_Configer configUsartExt;
}USART_Configer;
#endif


#ifndef _DEV_COMMON_H_
#define _DEV_COMMON_H_

#include "stm32f10x.h"

// macro definations of devices

// dev1: led
#define DEV_LED2_PORT GPIOE
#define DEV_LED2_PIN GPIO_Pin_5
#define DEV_LED2_CLOCK RCC_APB2Periph_GPIOE

// dev2: usart
#define DEV_USART1_NO USART1
// port
#define DEV_USART1_CLOCK_PORT RCC_APB2Periph_GPIOA
#define DEV_USART1_PORT GPIOA
#define DEV_USART1_PIN_TX GPIO_Pin_9
#define DEV_USART1_PIN_RX GPIO_Pin_10

// controller
#define DEV_USART1_CLOCK_COM RCC_APB2Periph_USART1

// config
#define DEV_UASRT_BAUD_RATE 115200


#endif

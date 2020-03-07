#include "process.h"

DEV_ERR Sys_Params_Init(void) {
    Led_Params_Init();
    Usart_Params_Init();
    return DEV_OK;
}

DEV_ERR Sys_Devs_Init(void) {
    Led_Init(Led2);
    Usart_Init(Usart1);
    return DEV_OK;
}

DEV_ERR Sys_Process(void) {
    uint8_t idx = 0;
    while (1) {
        Led_On(Led2);
        Delay_MS(100);

        printf("[%d]: Hello, I am USART1\r\n", idx);
        idx += 1;
        Led_Off(Led2);
        Delay_MS(100);
    }
}



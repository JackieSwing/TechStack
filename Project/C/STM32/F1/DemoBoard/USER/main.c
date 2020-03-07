/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"
#include "process.h"

/**
  * @brief  Main program.
  * @param  None
  * @retval None
  */
int main(void) {
    // Init configs
    Sys_Params_Init();

    // Init ext devcices
    Sys_Devs_Init();

    // Process
    Sys_Process();
}

/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/

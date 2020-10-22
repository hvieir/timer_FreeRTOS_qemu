/*==================================================================================================

  timer_FreeRTOS_qemu.c

  Used hardware: STM32F4-Discovery evaluation board (QEMU)

  Example of using the FreeRTOS Real-Time Operating System on the STM32F4-Discovery board.

  ==================================================================================================
*/

#include "stm32f4_discovery.h"
#include "FreeRTOS.h"
#include "timers.h"


TimerHandle_t xTimer;


void vTimerCallback(TimerHandle_t xTimer){
	BSP_LED_Toggle(LED3);
} // vTimerCallback



void main(void){
  __HAL_RCC_GPIOD_CLK_ENABLE();
  BSP_LED_Init(LED3);

  xTimer = xTimerCreate("Timer", 500 / portTICK_PERIOD_MS, pdTRUE, NULL, vTimerCallback);
  xTimerStart(xTimer, 0);

  vTaskStartScheduler();
  while(1);
} // main

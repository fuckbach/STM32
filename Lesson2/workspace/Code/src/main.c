#include "stm32f4xx.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

void GPIO_Init(void);
void VTaskLed1(void* argument);
void VTaskLed2(void* argument);
/*******************************************************************/
void vApplicationIdleHook( void )
{
}
 
 
 
/*******************************************************************/
void vApplicationMallocFailedHook( void )
{
    for( ;; );
}
 
 
 
/*******************************************************************/
void vApplicationStackOverflowHook( xTaskHandle pxTask, signed char *pcTaskName )
{
    ( void ) pcTaskName;
    ( void ) pxTask;
 
    for( ;; );
}
 
 
 
/*******************************************************************/
void vApplicationTickHook( void )
{
}
 
 
 
 int main(void)
{
	SystemCoreClockUpdate();
	SysTick_Config(SystemCoreClock/1000);
	GPIO_Init();
	xTaskCreate(VTaskLed1,"LED BLINK1", 32, NULL, 1, NULL);
	xTaskCreate(VTaskLed2,"LED BLINK2", 32, NULL, 1, NULL);
	vTaskStartScheduler();
	
	while(1)
		{
	
	  }
}
/******************************************************************/

void GPIO_Init(void){
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;
	GPIOD->MODER |= GPIO_MODER_MODER15_0 | GPIO_MODER_MODER14_0 | GPIO_MODER_MODER13_0 | GPIO_MODER_MODER12_0;
	GPIOD->OTYPER = 0;
	GPIOD->OSPEEDR = 0;
}

void VTaskLed1(void* argument){

	while(1){
		GPIOD->BSRR |= GPIO_BSRR_BS_15;
		vTaskDelay(1000);	
		GPIOD->BSRR |= GPIO_BSRR_BR_15;
		vTaskDelay(1000);	
			
			
	}
	
}

	void VTaskLed2(void* argument){

	while(1){
		GPIOD->BSRR |= GPIO_BSRR_BR_14;
		vTaskDelay(100);	
		GPIOD->BSRR |= GPIO_BSRR_BS_14;
		vTaskDelay(100);
	}
	
}


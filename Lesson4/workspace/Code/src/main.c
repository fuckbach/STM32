#include "stm32f4xx.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

void GPIO_Init(void);
void VTaskLed1(void* argument);
void VTaskButtonUser(void* argument);
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
	xTaskCreate(VTaskButtonUser,"LED BLINK1", 32, NULL, 1, NULL);

	

	vTaskStartScheduler();
	
	while(1)
		{
	
	  }
}
/******************************************************************/

void GPIO_Init(void){
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;//RCC
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;
	GPIOD->MODER |= GPIO_MODER_MODER15_0 | GPIO_MODER_MODER14_0 | GPIO_MODER_MODER13_0 | GPIO_MODER_MODER12_0;//LED
	GPIOD->OTYPER = 0;
	GPIOD->OSPEEDR = 0;
	GPIOA->MODER &= ~(3>>0);//Button
	
}

void VTaskButtonUser(void* argument){

	while(1){
		if((GPIOA->IDR & GPIO_IDR_IDR_0) != 0){
			vTaskDelay(100);	
			if((GPIOA->IDR & GPIO_IDR_IDR_0) != 0){
		
			
			GPIOD->ODR ^= GPIO_ODR_ODR_15;
			GPIOD->ODR ^= GPIO_ODR_ODR_14;}
		}
		
			
			
	}
	
}

	


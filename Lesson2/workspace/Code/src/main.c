#include "stm32f4xx.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

 
 void delay( uint32_t time){
	 uint32_t i ;
	 for (i = 0;i<time;i++){
		 
	 }
 }
 
int main(void)
{
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;
	GPIOD->MODER |= GPIO_MODER_MODER15_0 | GPIO_MODER_MODER14_0 | GPIO_MODER_MODER13_0 | GPIO_MODER_MODER12_0;
	GPIOD->OTYPER = 0;
	GPIOD->OSPEEDR = 0;


	
	while(1)
		{
				GPIOD->BSRR |= GPIO_BSRR_BS_15;
				delay(2000000);
				GPIOD->BSRR |= GPIO_BSRR_BR_15;
				delay(2000000);
				GPIOD->BSRR |= GPIO_BSRR_BS_14;
				delay(2000000);
				GPIOD->BSRR |= GPIO_BSRR_BR_14;
				delay(2000000);
				GPIOD->BSRR |= GPIO_BSRR_BS_13;
				delay(2000000);
				GPIOD->BSRR |= GPIO_BSRR_BR_13;
				delay(2000000);	
				GPIOD->BSRR |= GPIO_BSRR_BS_12;
				delay(2000000);
				GPIOD->BSRR |= GPIO_BSRR_BR_12;
				delay(2000000);
					
	  }
	
}

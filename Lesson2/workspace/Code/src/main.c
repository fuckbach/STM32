#include "stm32f4xx.h"
 int t = 0;
 
 
int main(void)
{
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;
	GPIOD->MODER |= GPIO_MODER_MODER15_0 | GPIO_MODER_MODER14_0 | GPIO_MODER_MODER13_0 | GPIO_MODER_MODER12_0;
	GPIOD->OTYPER = 0;
	GPIOD->OSPEEDR = 0;


	
	while(1)
		{
				GPIOD->BSRR |= GPIO_BSRR_BS_15;
				for (t = 0;t<500000;t++){}
				GPIOD->BSRR |= GPIO_BSRR_BR_15;
				for (t = 0;t<2000000;t++){}
				
				GPIOD->BSRR |= GPIO_BSRR_BS_14;
				for (t = 0;t<500000;t++){}
				GPIOD->BSRR |= GPIO_BSRR_BR_14;
				for (t = 0;t<500000;t++){}	
					
				GPIOD->BSRR |= GPIO_BSRR_BS_13;
				for (t = 0;t<500000;t++){}
				GPIOD->BSRR |= GPIO_BSRR_BR_13;
				for (t = 0;t<500000;t++){}	
					
				GPIOD->BSRR |= GPIO_BSRR_BS_12;
				for (t = 0;t<500000;t++){}
				GPIOD->BSRR |= GPIO_BSRR_BR_12;
				for (t = 0;t<500000;t++){}
					
	  }
	
}

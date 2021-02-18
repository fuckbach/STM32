
#include "stm32f4xx.h"                  // Device header

uint32_t delay_counter = 0;

void SysTick_Handler()
{
  if(delay_counter)
  {
    delay_counter--;
  }
}


void delay(uint32_t ms)
{
  delay_counter = ms;
  while(delay_counter){}
}

void GPIO_Init(void);

int main()
{
  
  GPIO_Init();
  SystemCoreClockUpdate();
  
  SysTick_Config(SystemCoreClock/1000);
  
  while(1)
  {
    GPIOD->BSRR |= GPIO_BSRR_BS_15;
    delay(500);
    
    GPIOD->BSRR |= GPIO_BSRR_BR_15;
    delay(500);
  
  }
  
}


void GPIO_Init(){
  
  RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;
  GPIOD->MODER |= GPIO_MODER_MODER15_0 | GPIO_MODER_MODER14_0 | GPIO_MODER_MODER13_0 | GPIO_MODER_MODER12_0;
  GPIOD->OTYPER = 0;
  GPIOD->OSPEEDR = 0;
  
}
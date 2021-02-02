
/*Connect the path in project properties  C - compiler - directories
 configure st-link as debugger - run - debug configure- debugger
*/

#include "stm32f4xx.h"

uint32_t delay_counter = 0;


void SysTick_Handler()
{
  if (delay_counter)
  {
    delay_counter--;
  }
}


void delay(uint32_t ms)
{
  delay_counter = ms;
  while (delay_counter)
  {
  }
}



void setup()
{
  RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;
  GPIOD->MODER |= GPIO_MODER_MODER15_0 | GPIO_MODER_MODER14_0 | GPIO_MODER_MODER13_0 | GPIO_MODER_MODER12_0;
  GPIOD->OTYPER = 0;
  GPIOD->OSPEEDR = 0;
  SystemCoreClockUpdate();
  SysTick_Config(SystemCoreClock/1000);
}


void blink()
{
  GPIOD->BSRR |= GPIO_BSRR_BS_13;
  delay(1000);
  GPIOD->BSRR |= GPIO_BSRR_BR_13;
  delay(1000);
}


int main()
{
  setup();
  while (1)
  {
  blink();
  }
}

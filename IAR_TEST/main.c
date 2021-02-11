//USART2 - APB1
//RCC_APB1ENR USART2 17bit 
//USART2 AF7
//USART2_TX PA2
//USART2_RX PA3
//GPIOA AHB1
//MCO2 - PC9
#include "stm32f4xx.h"                  // Device header

volatile uint8_t d = 0x15;//test value, do not use

void USART2_init(void) ;
void MCO2_init(void);

int main()
{
   
  USART2_init();
   MCO2_init();
    while(1)
    {
while ((USART2->SR & USART_SR_RXNE) == 0) {}
    d = USART2->DR;
    while ((USART2->SR & USART_SR_TXE) == 0) {}
    USART2->DR = d;
    //for(int i =0;i<420000;i++){};//delay
   


    }
}

/////////
void USART2_init(void) 
{
    RCC -> AHB1ENR |= (1<<0);
    RCC -> APB1ENR |= (1<<17);
    GPIOA -> AFR[0] |= (1792) | (28672);
    GPIOA -> MODER |= (32) | (128);
    USART2 -> BRR = 0x11170;//168Mhz/7860;(7860 Hz = 9600Baud)
    USART2 -> CR1 |= (1<<3);//transmit enable
    USART2 -> CR1 |= (1<<13);//USART enable
    USART2 -> CR1 |= (1<<2);
}






void MCO2_init(void){
  RCC -> AHB1ENR |= RCC_AHB1ENR_GPIOCEN ;
  GPIOC ->MODER |= GPIO_MODER_MODER9_1;//AF
  GPIOC ->OTYPER |= ~(GPIO_OTYPER_OT_9);//push pull
  GPIOC ->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR9;//very hight speed
  GPIOC ->AFR[1] = 0;
  //RCC ->CFGR |= (RCC_CFGR_MCO2)|RCC_CFGR_MCO2PRE;
}




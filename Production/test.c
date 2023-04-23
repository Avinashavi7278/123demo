#include "stm32f4xx.h"

void delay(uint32_t time) {
  while(time--) {
    __NOP();
  }
}

int main(void) {
  RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN; // enable GPIOD clock
  GPIOD->MODER |= GPIO_MODER_MODE15_0; // set PD15 as output

  while(1) {
    GPIOD->ODR |= GPIO_ODR_OD15; // set PD15 high
    delay(100); // wait for 00.1s
    GPIOD->ODR &= ~GPIO_ODR_OD15; // set PD15 low
    delay(100); // wait for 00.1sec
  }
}

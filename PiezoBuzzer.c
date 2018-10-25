#include "PiezoBuzzer.h"

void initBuzzer()
{
	RCC->AHB2ENR |= RCC_AHB2ENR_GPIOCEN;//turn on port A clock
	//set PIN PC14 to be drain on the buzzer
	GPIOC->MODER &= ~GPIO_MODER_MODE14_0 ;//set to output
	GPIOC->MODER |= GPIO_MODER_MODE14_1 ;//set to output
	GPIOC->PUPDR &= ~GPIO_PUPDR_PUPD14_0;//set to no push pull
	GPIOC->PUPDR &= ~GPIO_PUPDR_PUPD14_1;//set to no push pull
	GPIOC->OTYPER |= GPIO_OTYPER_ODR14;// concerned this is incorrect
	GPIOC->ODR |= GPIO_ODR_OD14; //set buzzer to be off
}

void soundBuzzer(int time)
{
	GPIOC->ODR &= ~GPIO_ODR_OD14;
	for (int delay = 0; delay < time; delay++)
	{
		(void)0;
	}
	GPIOC->ODR |= GPIO_ODR_OD14;
}

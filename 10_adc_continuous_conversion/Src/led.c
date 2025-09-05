/*
 * led.c
 *
 *  Created on: 28-Apr-2025
 *      Author: Spectrum RND
 */
#include "led.h"
//#define USER_LED1			(1U << 0)
//#define USER_LED1			(1U << 7)
//#define USER_LED1			(1U << 14)
void led_init(void)
{

	RCC -> AHB1ENR |= GPIOB_CLK_EN;
	//Set PB0 to output mode
	GPIOB ->MODER |= (1U << 0);
	GPIOB ->MODER &= ~(1U << 1);
	//Set PB7 to output mode
	GPIOB ->MODER |= (1U << 14);
	GPIOB ->MODER &= ~(1U << 15);
	//Set PB14 to output mode
	GPIOB ->MODER |= (1U << 28);
	GPIOB ->MODER &= ~(1U << 29);


}

void all_led_ON(void)
{
	GPIOB ->ODR |= (RED_LED | GREEN_LED | BLUE_LED);
}

void all_led_OFF(void)
{
	GPIOB ->ODR &= ~(RED_LED | GREEN_LED | BLUE_LED);
}

void all_led_toggle(void)
{
	GPIOB ->ODR ^= (RED_LED | GREEN_LED | BLUE_LED);
}

void led_on(ledType led)
{
	GPIOB ->ODR |= led;
}

void led_off(ledType led)
{
	GPIOB ->ODR &= ~led;
}

void led_toggle(ledType led)
{
	GPIOB ->ODR ^= led;
}

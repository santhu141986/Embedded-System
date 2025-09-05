#include "stm32f7xx.h"

#define TIM1_CLK_EN			(1U << 0)
#define TIM1_CNTRL_REG		(1U << 0)


void tim1_1hz_init(void)
{
	/* Enable clock access to APB2*/
	RCC-> APB2ENR |=  TIM1_CLK_EN;
	/* Set the prescaler*/
	TIM1 ->PSC = 1600 - 1; // 16000000/1600 = 10000
	/* Set the auto reload values*/
	TIM1 ->ARR = 10000;
	/* Enable the timer*/
	TIM1 ->CR1 |=  TIM1_CNTRL_REG;
}


void pwm_1khz_init(void)
{
	// using timer 2 chanel 1
	//Timer 2 is connected to apb1 bus, its alternate function is PA0- AF1

	RCC-> AHB1ENR |= (1 << 0); // enabling clock to gpioA module
	RCC ->APB1ENR |= (1 << 0);// enabling clock to timer2 module
	// set gpio mode to alternate function mode 10
	GPIOA ->MODER |= (1 << 1 );
	GPIOA ->MODER &= ~(1 << 0);

	// Set alternate function as AF1
	GPIOA ->AFR[0] &= ~(0xF << (0 *4));
	GPIOA->AFR[0] |= (1U << (0 * 4));



}

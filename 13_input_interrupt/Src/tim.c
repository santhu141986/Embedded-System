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



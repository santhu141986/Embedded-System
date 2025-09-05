#include "stm32f7xx.h"

#define TIM1_CLK_EN			(1U << 0)
#define TIM1_CNTRL_REG		(1U << 0)
#define DIER_UIF			(1 << 0)
#define EGR_UG				(1 << 0)
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

void tim1_1hz_IT_init(void)
{
	/* Enable clock access to APB2*/
	RCC-> APB2ENR |=  TIM1_CLK_EN;
	/* Set the prescaler*/
	TIM1 ->PSC = 1600 - 1; // 16000000/1600 = 10000
	/* Set the auto reload values*/
	TIM1 ->ARR = 10000;

	//Enable TIM1 update interrupt
	TIM1->DIER |= DIER_UIF;

	//Enable TIM1 update interrupt in NVIC
	NVIC_EnableIRQ(TIM1_UP_TIM10_IRQn);

	/* Enable the timer*/
	TIM1 ->CR1 |=  TIM1_CNTRL_REG;

	//Force update generation
	TIM1->EGR |= EGR_UG;
}

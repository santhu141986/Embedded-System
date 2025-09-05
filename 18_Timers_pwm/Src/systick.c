#include "stm32f7xx.h"

#define SYSTICK_LOAD_VAL	16000
#define CTRL_ENABLE			(1U << 0)
#define CTRL_CLOCK_SOURCE	(1U << 2)
#define CTRL_COUNTFLAG		(1U << 16)

void systickDelayMs(int delay)
{
	/* Relaod number of clocks per miliseconds*/
	SysTick -> LOAD = SYSTICK_LOAD_VAL;
	/* Clear the curren value register*/
	SysTick -> VAL	= 0;
	/* Select clock source and enable the register*/
	SysTick ->CTRL	= CTRL_ENABLE | CTRL_CLOCK_SOURCE;

	for(int i=0; i<= delay; i++)
	{
		while((SysTick ->CTRL & CTRL_COUNTFLAG) ==0){}
	}
	SysTick ->CTRL = 0;
}


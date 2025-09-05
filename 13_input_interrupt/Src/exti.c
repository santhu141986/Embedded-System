#include "stm32f7xx.h"

void pc13_exti_init(void)
{
	/* Enable clock access to PORTC*/
	/* Set pin13 to input*/
	/* ENable clock access to SYSCFG module * /
	 * Clear port selection for EXTI13
	 * Select PORTC for EXTI13
	 * UNmask EXTI13
	 * Select Fallig edge triggere
	 * Enable EXTI13 in NVIC
	 */
}

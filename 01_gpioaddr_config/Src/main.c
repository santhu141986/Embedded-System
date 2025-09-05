
#include "main.h"

int main(void)
{
	/*Enable Clock access to Port B*/
	AHB1_ENR    |= GPIOB_CLK_EN;
	/*Configure Port pin as a output pins*/
	GPIOB_MODER |= USER_LED1_MODER | USER_LED2_MODER | USER_LED3_MODER;

	while(1)
	{
		/*Turn ON all LED*/
		//GPIO_ODR |= USER_LED1_ODR | USER_LED2_ODR | USER_LED3_ODR;

		/*toggle*/
		GPIO_ODR ^= USER_LED1_ODR | USER_LED2_ODR | USER_LED3_ODR;
		for(int i=0; i<100000; i++) {}
	}

}













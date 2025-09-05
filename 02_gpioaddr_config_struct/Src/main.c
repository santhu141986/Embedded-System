
#include "main.h"

#define GPIOB_CLK_EN						(1U << 1) // since 1st bit of AHB1_ENR is to enable clock to GPIOB

//Now we have to set mode of the register as input or output, for that got GPIO_MODER and set perticular bits

#define USER_LED1_MODER						(1U << 0) // 0th pin is set as a output mode
#define USER_LED2_MODER						(1U << 14) // 7th pin is set as a output mode
#define USER_LED3_MODER						(1U << 28) // 14th pin is set as a output mode

//now we have set base address for outout data register as we are using gpio as output mode

#define USER_LED1_ODR						(1U << 0) // enabling ODR for pin0
#define USER_LED2_ODR					    (1U << 7) // enabling ODR for pin7
#define USER_LED3_ODR						(1U << 14) // enabling ODR for pin14

int main(void)
{
	/*Enable Clock access to Port B*/
	//AHB1_ENR    |= GPIOB_CLK_EN;

	RCC -> AHB1ENR |= (1U << 1);
	/*Configure Port pin as a output pins*/
	//GPIOB_MODER |= USER_LED1_MODER | USER_LED2_MODER | USER_LED3_MODER;
	GPIOB -> MODER |= USER_LED1_MODER | USER_LED2_MODER | USER_LED3_MODER;
	while(1)
	{
		/*Turn ON all LED*/
		//GPIO_ODR |= USER_LED1_ODR | USER_LED2_ODR | USER_LED3_ODR;

		/*toggle*/
		//GPIO_ODR ^= USER_LED1_ODR | USER_LED2_ODR | USER_LED3_ODR;
		GPIOB ->ODR ^=USER_LED1_ODR | USER_LED2_ODR | USER_LED3_ODR;
		for(int i=0; i<100000; i++) {}
	}

}













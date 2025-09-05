#include "stm32f7xx.h"

#define GPIOB_CLK_EN						(1U << 1) // since 1st bit of AHB1_ENR is to enable clock to GPIOB
#define GPIOC_CLK_EN						(1U << 2) // since 1st bit of AHB1_ENR is to enable clock to GPIOB
//Now we have to set mode of the register as input or output, for that got GPIO_MODER and set perticular bits

#define USER_LED1_MODER						(1U << 0) // 0th pin is set as a output mode
#define USER_LED2_MODER						(1U << 14) // 7th pin is set as a output mode
#define USER_LED3_MODER						(1U << 28) // 14th pin is set as a output mode

//now we have set base address for outout data register as we are using gpio as output mode

#define USER_LED1_ODR						(1U << 0) // enabling ODR for pin0
#define USER_LED2_ODR					    (1U << 7) // enabling ODR for pin7
#define USER_LED3_ODR						(1U << 14) // enabling ODR for pin14

#define USER_BTN							(1U << 13)

int main(void)
{
		RCC -> AHB1ENR |= GPIOB_CLK_EN |GPIOC_CLK_EN; // enabling clock for both PORTB and PORTC

		/*Configure Port pin as a output pins*/
		//GPIOB_MODER |= USER_LED1_MODER | USER_LED2_MODER | USER_LED3_MODER;
		GPIOB -> MODER |= USER_LED1_MODER | USER_LED2_MODER | USER_LED3_MODER;
		GPIOC ->MODER &= ~(1U << 26);
		GPIOC ->MODER &= ~(1U << 27);
		while(1)
		{
			if( GPIOC ->IDR & USER_BTN ) // check wheather data in IDR and USER_BTN are same?
			{
				GPIOB ->BSRR =(1U << 0) | (1U << 7) | (1U << 14);// if same or button pressed then turn on led

			}
			else
			{
				GPIOB ->BSRR = (1U << 16) | (1U << 23) | (1U << 30); // else turn off led

			}

		}
}

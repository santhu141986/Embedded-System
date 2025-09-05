#include "stm32f7xx.h"
#include "uart.h"
#include "rcc.h"
#include "led.h"
#include "adc.h"
#include "systick.h"
#include "tim.h"
int sensor_value;

static void tim1_update_callback();
int main(void)
{
	pa4_adc_init();
	uart3_rxtx_init();
	tim1_1hz_IT_init();
	while(1)
	{


	}
}




static void tim1_update_callback()
{
	printf("Seconds just passed \r\n");
}



void TIM1_UP_TIM10_IRQHandler()
{
	if((TIM1->SR & TIM1_SR_UIF) !=0)
	{
		// Clear the TIM1_SR_UIF bit
		TIM1->SR &=~(TIM1_SR_UIF);
		// do something...
		tim1_update_callback();
	}
}

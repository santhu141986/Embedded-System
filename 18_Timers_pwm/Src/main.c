#include "stm32f7xx.h"
#include "uart.h"
#include "rcc.h"
#include "led.h"
#include "adc.h"
#include "systick.h"
#include "tim.h"
int sensor_value;

int main(void)
{
	pa4_adc_init();
	uart3_rxtx_init();
	tim1_1hz_init();
	while(1)
	{

		while (!(TIM1 ->SR & TIM1_SR_UIF)){}

		TIM1 ->SR &= ~ TIM1_SR_UIF;

		printf("Seconds Just Passed !! \n\r " );


	}
}




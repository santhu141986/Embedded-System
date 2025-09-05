#include "stm32f7xx.h"
#include "uart.h"
#include "rcc.h"
#include "led.h"
#include "adc.h"

static void adc_conv_callback();

int sensor_value;

int main(void)
{
	pa4_adc_init();
	uart3_rxtx_init();
	pa4_adc_IT_init();
	while(1)
	{


	}
}


static void adc_conv_callback()
{
	sensor_value = ADC1 -> DR;
	printf("Sensor valie is : %d \n\r",sensor_value);
}
void ADC_IRQHandler()
{
	if((ADC1->SR & SR_EOC) == SR_EOC)
	{
		// clear a EOC flag
		ADC1 ->SR &= ~SR_EOC;
		// do somethin...
		adc_conv_callback();
	}
}

#include "stm32f7xx.h"
#include "uart.h"
#include "rcc.h"
#include "led.h"
#include "adc.h"

int sensor_value;

int main(void)
{
	pa4_adc_init();
	uart3_rxtx_init();
	while(1)
	{

		sensor_value = adc_get_data();
		printf("Sensor valie is : %d \n\r",sensor_value);

	}
}




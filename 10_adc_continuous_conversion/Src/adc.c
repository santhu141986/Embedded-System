/*
 * adc.c
 *
 *  Created on: 05-May-2025
 *      Author: Spectrum RND
 */
#include "adc.h"

void pa4_adc_init(void)
{
	/**************Enable ADC gpio pin********/
	// Enable clock accest to GPIO pin -
	RCC -> AHB1ENR |= GPIOACLKEN;
	// Enable mode of gpio pin as analog
	GPIOA ->MODER |= (1U << 8);
	GPIOA ->MODER |= (1U << 9);
	/**************Enable ADC module********/
	// Enable Clock access to adc module
	RCC ->APB2ENR |= ADCCLKEN;
	// set conversion mode to continues
	ADC1 -> CR2  |= ADCCONCONV;
	// set sequence length
	ADC1 ->SQR1 = ADC_SEQ_LEN_1;
	// set ADC channel
	ADC1 ->SQR3 |= CH4_RANK1;
	// Enable ADC module
	ADC1 ->CR2 |= ADCON;
	// Start conversion
	ADC1 ->CR2 |= ADCSTART;
}

uint32_t adc_get_data(void)
{
	// wait for end of conversion
	while (!(ADC1 ->SR & SR_EOC)) {}
	// Read  the result
	return (ADC1 -> DR);
}

/*
 * adc.h
 *
 *  Created on: 05-May-2025
 *      Author: Spectrum RND
 */

#ifndef ADC_H_
#define ADC_H_

// ADC is connected to APB2 bus
//GPIOA is connected to the AHB1 bus
// pA4 is ADC1 IN4
#include "stm32f7xx.h"
#include "stdint.h"


#define GPIOACLKEN		(1U << 0)
#define ADCCLKEN		(1U << 8)
#define ADCCONCONV		(1U << 1)
#define ADC_SEQ_LEN_1	0
#define CH4_RANK1		(1U << 2)
#define ADCON			(1U << 0)
#define ADCSTART		(1U << 30)
#define SR_EOC			(1U << 1)


uint32_t adc_get_data(void);
void pa4_adc_init(void);

#endif /* ADC_H_ */

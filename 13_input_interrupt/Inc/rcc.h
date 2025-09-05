/*
 * rcc.h
 *
 *  Created on: 23-Apr-2025
 *      Author: Spectrum RND
 */

#ifndef RCC_H_
#define RCC_H_
#include "uart.h"

void set_apb1_periph_clock(uint32_t periphs);
void set_ahb1_periph_clock(uint32_t periphs);
void set_ahb2_periph_clock(uint32_t periphs);
void set_apb2_periph_clock(uint32_t periphs);

#endif /* RCC_H_ */

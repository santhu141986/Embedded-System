/*
 * main.h
 *
 *  Created on: Apr 16, 2025
 *      Author: Spectrum RND
 */

#ifndef MAIN_H_
#define MAIN_H_

#define PERIPHERAL_BASE_ADDR				0x40000000UL
#define AHB1_OFFSET							0x00020000UL
#define AHB1_PERIPHERAL_BASE_ADDR			(PERIPHERAL_BASE_ADDR + AHB1_OFFSET) // GPIOB is connected to AHB1 bus so AHB1 bus base address is calculated

#define GPIOB_OFFSET						0x400UL
	#define GPIOB_BASE_ADDR						(AHB1_PERIPHERAL_BASE_ADDR + GPIOB_OFFSET)// this is the base address of GPIOB

#define RCC_OFFSET							0x3800UL
	#define RCC_BASE_ADDR						(AHB1_PERIPHERAL_BASE_ADDR + RCC_OFFSET)// this is to enable clock to each peripherals

// Now we have to enable clock access inside RCC, we have to locat AHB1_ENR having offset 0x30 then we have to enable perticular port clock acess
#define AHB1_ENR_OFFSET						0x30UL
#define AHB1_ENR		 					(*(volatile unsigned int *)(RCC_BASE_ADDR + AHB1_ENR_OFFSET))
#define GPIOB_CLK_EN						(1U << 1) // since 1st bit of AHB1_ENR is to enable clock to GPIOB

//Now we have to set mode of the register as input or output, for that got GPIO_MODER and set perticular bits
#define GPIOB_MODER_OFFSET					0x00UL
#define GPIOB_MODER 						(*(volatile unsigned int *)(GPIOB_BASE_ADDR + GPIOB_MODER_OFFSET))
#define USER_LED1_MODER						(1U << 0) // 0th pin is set as a output mode
#define USER_LED2_MODER						(1U << 14) // 7th pin is set as a output mode
#define USER_LED3_MODER						(1U << 28) // 14th pin is set as a output mode

//now we have set base address for outout data register as we are using gpio as output mode
#define GPIO_ODR_OFFSET						0x14UL
#define GPIO_ODR 							(*(volatile unsigned int *)(GPIOB_BASE_ADDR + GPIO_ODR_OFFSET))
#define USER_LED1_ODR						(1U << 0) // enabling ODR for pin0
#define USER_LED2_ODR					    (1U << 7) // enabling ODR for pin7
#define USER_LED3_ODR						(1U << 14) // enabling ODR for pin14



#endif /* MAIN_H_ */

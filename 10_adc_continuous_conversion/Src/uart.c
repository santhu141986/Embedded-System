/*
 * uart.c
 *
 *  Created on: 23-Apr-2025
 *      Author: Spectrum RND
 *      PD8 -> TX pin
 *      PD9 -> RX pin
 */

#include "uart.h"


void uart3_tx_init(void)
{
	/* 1. Enable clock access to GPIOD*/
	set_ahb1_periph_clock(GPIODEN);
	/* 2. Set PD8 as a Alternate function mode*/
	set_pin_mode(GPIOD, UART3_TX, GPIO_ALTERNATE_MODE);
	/* 3. Set alternate function to USART*/
	GPIOD -> AFR[1] |= (1U << 0);
	GPIOD -> AFR[1] |= (1U << 1);
	GPIOD -> AFR[1] |= (1U << 2);
	GPIOD -> AFR[1] &= ~(1U << 3);
	/* 4. Enable Clock Access to USART3 module*/
	set_apb1_periph_clock(UART3_CLK_EN);
	/* 5. Configure USART parameters*/
	config_uart_param(USART3, UART3_DATAWIDTH_8B, UART3_PARITY_NONE, UART3_STOPBITS_1);
	set_uart_transfer_direction(USART3, USART_CR1_TE);

	/* 6. Set baudrate*/
	uart_set_baudrate(USART3 ,16000000, 115200);
	/* 7. Enable USART*/
	uart_enable(USART3);
}

void uart3_rxtx_init(void)
{
	/*************************CONFIGURING TX PIN***********************/
	/* 1. Enable clock access to GPIOD*/
	set_ahb1_periph_clock(GPIODEN);
	/* 2. Set PD8 as a Alternate function mode*/
	set_pin_mode(GPIOD, UART3_TX, GPIO_ALTERNATE_MODE);
	/* 3. Set alternate function to USART*/
	GPIOD -> AFR[1] |= (1U << 0);
	GPIOD -> AFR[1] |= (1U << 1);
	GPIOD -> AFR[1] |= (1U << 2);
	GPIOD -> AFR[1] &= ~(1U << 3);

	/*************************CONFIGURING RX PIN***********************/
	/*  Set PD9 as a Alternate function mode*/
	set_pin_mode(GPIOD, UART3_RX, GPIO_ALTERNATE_MODE);
	/*  Set alternate function to USART*/
	GPIOD -> AFR[1] |= (1U << 4);
	GPIOD -> AFR[1] |= (1U << 5);
	GPIOD -> AFR[1] |= (1U << 6);
	GPIOD -> AFR[1] &= ~(1U << 7);

	/* 4. Enable Clock Access to USART3 module*/
	set_apb1_periph_clock(UART3_CLK_EN);
	/* 5. Configure USART parameters*/
	config_uart_param(USART3, UART3_DATAWIDTH_8B, UART3_PARITY_NONE, UART3_STOPBITS_1);
	set_uart_transfer_direction(USART3, (USART_CR1_TE | USART_CR1_RE));

	/* 6. Set baudrate*/
	uart_set_baudrate(USART3 ,16000000, 115200);
	/* 7. Enable USART*/
	uart_enable(USART3);
}

void uart_write(USART_TypeDef *USARTx, uint8_t data)
{
	/*Make sure transmit data register is empty*/
	while(! ((USARTx -> ISR & USART_ISR_TXE ) )){}
	/*Write values to transmit data register*/
	USARTx -> TDR = data;
}

uint8_t uart_read(USART_TypeDef *USARTx)
{
	while(!(USARTx ->ISR & USART_ISR_RXNE)){}
	return (READ_BIT(USARTx ->RDR, USART_RDR_RDR) & 0xFFU);
}

void set_pin_mode(GPIO_TypeDef *GPIOx, uint32_t Pin, uint32_t Mode)
{

	// MODIFY_REG(REG, CLEARMASK, SETMASK)
	MODIFY_REG(GPIOx ->MODER,(0x3 << (POSITION_VAL(Pin) * 2U)), (Mode << (POSITION_VAL(Pin) * 2U )) );

}

void config_uart_param(USART_TypeDef *USARTx, uint32_t Datawidth, uint32_t Parity, uint32_t StopBits)
{
	MODIFY_REG(USARTx -> CR1, USART_CR1_PS | USART_CR1_PCE | USART_CR1_M, Parity | Datawidth);
	MODIFY_REG(USARTx -> CR2, USART_CR2_STOP, StopBits);
}


void uart_set_baudrate(USART_TypeDef *USARTx, uint32_t PeriphClk, uint32_t BaudRate)
{
	USARTx ->BRR = compute_uart_div( PeriphClk, BaudRate);
}

uint16_t compute_uart_div(uint32_t PeriphClk, uint32_t BaudRate)
{
	return ((PeriphClk + (BaudRate/2))/BaudRate);
}

void uart_enable(USART_TypeDef *USARTx)
{
	USARTx -> CR1 |= (1U << 0);
}

void set_uart_transfer_direction(USART_TypeDef *USARTx, uint32_t TransferDirection)
{
	MODIFY_REG(USARTx -> CR1, USART_CR1_TE | USART_CR1_RE, TransferDirection);
}




int __io_putchar(int ch)
{
	uart_write(USART3,ch);

	return ch;
}

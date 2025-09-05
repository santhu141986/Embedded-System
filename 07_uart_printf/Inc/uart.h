/*
 * uart.h
 *
 *  Created on: 23-Apr-2025
 *      Author: Spectrum RND
 */

#ifndef UART_H_
#define UART_H_
#include "stdio.h"
#include "stm32f7xx.h"

#define GPIODEN					(1U << 3)
#define UART3_TX				(1U << 8)
#define GPIO_ALTERNATE_MODE		0x2  // 0b 10

#define	UART3_CLK_EN				(1U << 18)
#define UART3_DATAWIDTH_8B			0x00000000U
#define UART3_PARITY_NONE			0x00000000U
#define UART3_STOPBITS_1			0x00000000U

void set_apb1_periph_clock(uint32_t periphs);
void set_ahb1_periph_clock(uint32_t periphs);
void set_pin_mode(GPIO_TypeDef *GPIOx, uint32_t Pin, uint32_t Mode);
void config_uart_param(USART_TypeDef *USARTx, uint32_t Datawidth, uint32_t Parity, uint32_t StopBits);
uint16_t compute_uart_div(uint32_t PeriphClk, uint32_t BaudRate);
void uart_set_baudrate(USART_TypeDef *USARTx, uint32_t PeriphClk, uint32_t BaudRate);
void uart_enable(USART_TypeDef *USARTx);
void uart_write(USART_TypeDef *USARTx, uint8_t data);
void set_uart_transfer_direction(USART_TypeDef *USARTx, uint32_t TransferDirection);

int __io_putchar(int ch);
void uart3_tx_init(void);

#endif /* UART_H_ */

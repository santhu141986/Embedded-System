#include "stm32f7xx.h"
#include "uart.h"
static void usart3_callback();
int main(void)
{
	int x;
	uart3_tx_IT_init();

	while(1)
	{
		uart_write(USART3, 'B');
		for(int i=0; i<100000; i++){ x++;}
	}
}


static void usart3_callback()
{
	USART3 -> TDR = 'A';
}

void USART3_IRQHandler()
{
	if((USART3->ISR & ISR_TXE)!=0)
	{
		// clear falg

		// do something...
		usart3_callback();
	}
}

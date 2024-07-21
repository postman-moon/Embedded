#include "stm32f10x.h"
#include "stm32f10x_pal.h"

int main(void)
{
	PAL_Init();
	
	// 1. 开启中断源
	USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);
	
	// 2. 配置NVIC
	NVIC_InitTypeDef NVIC_InitStruct;
	NVIC_InitStruct.NVIC_IRQChannel = USART1_IRQn;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 2;
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
	
	NVIC_Init(&NVIC_InitStruct);
	
	while(1)
	{
	}
}

void USART1_IRQHandler(void) {

	// 处理中断的具体代码，由用户根据需要填写

}
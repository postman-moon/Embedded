#include "stm32f10x.h"
#include "stm32f10x_pal.h"

int main(void)
{
	uint8_t previous = Bit_SET;		// PA0 上次的值
	uint8_t current = Bit_SET;		// PA0 当前的值
	
	PAL_Init();
	
	// PA0 - IPU
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(GPIOA, &GPIO_InitStruct);
	
	// PC13 - Out-OD
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
	
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_OD;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_13;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(GPIOC, &GPIO_InitStruct);
	
	while(1)
	{
		previous = current;
		current = GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0);
		if (current != previous) {
			// 按键消抖
			PAL_Delay(10);
			current = GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0);
			if (current != previous) {
				if (current == Bit_SET) {	// 按钮按下
				
				} else {	// 按钮松开
					if (GPIO_ReadOutputDataBit(GPIOC, GPIO_Pin_13) == Bit_RESET) {
						GPIO_WriteBit(GPIOC, GPIO_Pin_13, Bit_SET);
					} else {
						GPIO_WriteBit(GPIOC, GPIO_Pin_13, Bit_RESET);
					}
 				}
			}
			
		}

	}
}

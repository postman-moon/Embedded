#include "stm32f10x.h"
#include "stm32f10x_pal.h"

int main(void)
{

	PAL_Init();
	
	// 使能时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
	
	// 引脚初始化
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_OD;		// 输出推挽
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_13;					
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;
	
	GPIO_Init(GPIOC, &GPIO_InitStruct);
	
	// 推挽，0 - 点亮，1 - 熄灭
	
	/*
	GPIO_WriteBit(GPIOC, GPIO_Pin_13, Bit_RESET);
	GPIO_WriteBit(GPIOC, GPIO_Pin_13, Bit_SET);
	
	GPIO_Write(GPIOC, 0x0000);
 	GPIO_Write(GPIOC, 0x2000);
	
	GPIO_ResetBits(GPIOC, GPIO_Pin_13);
	GPIO_SetBits(GPIOC, GPIO_Pin_13);
	*/
	
	// 方案一
	/*
	while(1)
	{
		GPIO_WriteBit(GPIOC, GPIO_Pin_13, Bit_RESET);
		PAL_Delay(100);
		GPIO_WriteBit(GPIOC, GPIO_Pin_13, Bit_SET);
		PAL_Delay(100);
	}
	*/
	
	// 方案二
	/*
	GPIO_WriteBit(GPIOC, GPIO_Pin_13, Bit_RESET);
	while (1) {
		PAL_Delay(100);
		
		if (GPIO_ReadOutputDataBit(GPIOC, GPIO_Pin_13) == Bit_RESET) {
			GPIO_WriteBit(GPIOC, GPIO_Pin_13, Bit_SET);
		} else {
			GPIO_WriteBit(GPIOC, GPIO_Pin_13, Bit_RESET);
		}
		
	}
	*/
}

#include "stm32f10x.h"                  // Device header
#include "Delay.h"

int main(void) {
	
	/*
		操作 STM32 的 GPIO 总共需要3个步骤：
		1. 使用RCC开启GPIO的时钟
		2. 使用GPIO_Init函数初始化GPIO
		3. 使用输出或者输入的函数控制GPIO口
	*/
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	// GPIO_ResetBits(GPIOA, GPIO_Pin_0);
	// GPIO_SetBits(GPIOA, GPIO_Pin_0);
	// GPIO_WriteBit(GPIOA, GPIO_Pin_0, Bit_RESET);
	// GPIO_WriteBit(GPIOA, GPIO_Pin_0, Bit_SET);
	
	while (1) {
		
		// GPIO_WriteBit(GPIOA, GPIO_Pin_0, Bit_RESET);
		// Delay_ms(500);
		// GPIO_WriteBit(GPIOA, GPIO_Pin_0, Bit_SET);
		// Delay_ms(500);
		
		// GPIO_ResetBits(GPIOA, GPIO_Pin_0);
		// Delay_ms(100);
		// GPIO_SetBits(GPIOA, GPIO_Pin_0);
		// Delay_ms(100);
		
		GPIO_WriteBit(GPIOA, GPIO_Pin_0, (BitAction)0);
		Delay_ms(500);
		GPIO_WriteBit(GPIOA, GPIO_Pin_0, (BitAction)1);
		Delay_ms(500);
	}
	
}

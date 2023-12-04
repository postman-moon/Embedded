#include "stm32f10x.h"                  // Device header

int main(void) {
	// 方法一：
	// 用RCC寄存器使能GPIOC的时钟，GPIO都是APB2的
	// RCC->APB2ENR = 0x00000010;
	
	// 配置PC13口的模式
	// GPIOC->CRH = 0x00300000;
	
	// 给PC13口输出数据
	// GPIOC->ODR = 0x00002000;
	
	// 方法二：
	// 第一步: 使能时钟 
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
	
	// 第二步: 配置端口模式
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_13;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &GPIO_InitStruct);
	
	// 第三步:
	// GPIO_SetBits(GPIOC, GPIO_Pin_13);
		GPIO_ResetBits(GPIOC, GPIO_Pin_13);
	
	while (1) {
	
	}

}

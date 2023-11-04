#include "stm32f10x.h"                  // Device header

int main(void) {
	
	/*
	RCC->APB2ENR = 0x00000010;
	
	GPIOC->CRH = 0x00300000;
	
	GPIOC->ODR = 0x00002000;
	*/
	
	// 使能时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	// GPIO 模式
	// GPIO_Mode_Out_PP 通用推挽输出
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	// GPIO 端口
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
	// GPIO 速度
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	
	// 配置端口模式
	GPIO_Init(GPIOC, &GPIO_InitStructure);
	
	// 设置端口的高低电平
	// 高电平
	GPIO_SetBits(GPIOC, GPIO_Pin_13);
	// 低电平
	// GPIO_ResetBits(GPIOC, GPIO_Pin_13);
	
	while (1) {
		
	}
	
}

#include "stm32f10x.h"                  // Device header
#include "Delay.h"

int main(void) {
	
	/*
		���� STM32 �� GPIO �ܹ���Ҫ3�����裺
		1. ʹ��RCC����GPIO��ʱ��
		2. ʹ��GPIO_Init������ʼ��GPIO
		3. ʹ�������������ĺ�������GPIO��
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

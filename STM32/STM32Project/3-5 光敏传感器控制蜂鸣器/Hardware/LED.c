#include "stm32f10x.h"                  // Device header

void LED_Init(void) {

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_1 | GPIO_Pin_2;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOA, &GPIO_InitStruct);
	
	GPIO_SetBits(GPIOA, GPIO_Pin_1 | GPIO_Pin_2);

}

void LED_ON(int pin) {

	if (pin == 1) {
		GPIO_ResetBits(GPIOA, GPIO_Pin_1);
	} else if (pin == 2) {
		GPIO_ResetBits(GPIOA, GPIO_Pin_2);
	}
	
}

void LED_OFF(int pin) {
	
	if (pin == 1) {
		GPIO_SetBits(GPIOA, GPIO_Pin_1);
	} else if (pin == 2) {
		GPIO_SetBits(GPIOA, GPIO_Pin_2);
	}
	
}

void LED_Trun(uint8_t pin) {

	if (pin == 1 && GPIO_ReadOutputDataBit(GPIOA, GPIO_Pin_1) == 0) {
		GPIO_SetBits(GPIOA, GPIO_Pin_1);
	} else if (pin == 1 && GPIO_ReadOutputDataBit(GPIOA, GPIO_Pin_1) == 1) {
		GPIO_ResetBits(GPIOA, GPIO_Pin_1);
	}
	
	if (pin == 2 && GPIO_ReadOutputDataBit(GPIOA, GPIO_Pin_2) == 0) {
		GPIO_SetBits(GPIOA, GPIO_Pin_2);
	} else if (pin == 2 && GPIO_ReadOutputDataBit(GPIOA, GPIO_Pin_2) == 1) {
		GPIO_ResetBits(GPIOA, GPIO_Pin_2);
	}

}

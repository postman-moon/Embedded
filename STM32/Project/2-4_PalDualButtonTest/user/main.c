#include "stm32f10x.h"
#include "stm32f10x_pal.h"
#include "stm32f10x_pal_button.h"

// PA0  -> 点亮 PC13 写 0
// PB11 -> 熄灭 PC13 写 1

PalButton_HandleTypeDef hButton1;
PalButton_HandleTypeDef hButton2;

static void onButton1Released() {
	
	GPIO_WriteBit(GPIOC, GPIO_Pin_13, Bit_RESET);
	
}

static void onButton2Released() {

	GPIO_WriteBit(GPIOC, GPIO_Pin_13, Bit_SET);
	
}

int main(void)
{
	PAL_Init();
	
	// PC13
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_OD;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_13;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;
	
	GPIO_Init(GPIOC, &GPIO_InitStruct);
	
	// PA0
	hButton1.Init.GPIOx = GPIOA;
	hButton1.Init.GPIO_Pin = GPIO_Pin_0;
	hButton1.Init.Button_Mode = Button_Mode_IPU;
	hButton1.Init.ButtonReleasedCallback = onButton1Released;
	
	PAL_Button_Init(&hButton1);
	
	// PB11
	hButton2.Init.GPIOx = GPIOB;
	hButton2.Init.GPIO_Pin = GPIO_Pin_11;
	hButton2.Init.Button_Mode = Button_Mode_IPU;
	hButton2.Init.ButtonReleasedCallback = onButton2Released;
	
	PAL_Button_Init(&hButton2);
	
	while(1)
	{
		
		PAL_Button_Proc(&hButton1);
		PAL_Button_Proc(&hButton2);
		
	}
}

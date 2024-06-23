#include "stm32f10x.h"
#include "stm32f10x_pal.h"
#include "stm32f10x_pal_button.h"

PalButton_HandleTypeDef hButton1;

static void onButton1Released() {
	
	// PC13 亮灭状态切换的代码
	if (GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_13) == Bit_SET) {
		GPIO_WriteBit(GPIOC, GPIO_Pin_13, Bit_RESET);
	} else {
		GPIO_WriteBit(GPIOC, GPIO_Pin_13, Bit_SET);
	}
	
}

int main(void)
{
	PAL_Init();
	
	// PC13
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
	
	GPIO_InitTypeDef GPIOInitStruct;
	GPIOInitStruct.GPIO_Mode = GPIO_Mode_Out_OD;
	GPIOInitStruct.GPIO_Pin = GPIO_Pin_13;
	GPIOInitStruct.GPIO_Speed = GPIO_Speed_2MHz;
	
	GPIO_Init(GPIOC, &GPIOInitStruct);
	
	// PA0
	hButton1.Init.GPIOx = GPIOA;																// 按钮的端口号 GPIOA
	hButton1.Init.GPIO_Pin = GPIO_Pin_0;												// 按钮的引脚编号 0
	hButton1.Init.Button_Mode = Button_Mode_IPU;									// 使用内部上拉电阻
	hButton1.Init.ButtonReleasedCallback = onButton1Released;		// 回调函数
	
	PAL_Button_Init(&hButton1);
	
	while(1)
	{
		PAL_Button_Proc(&hButton1);
	}
}

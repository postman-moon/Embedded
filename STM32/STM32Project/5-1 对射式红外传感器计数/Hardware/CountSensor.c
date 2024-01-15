#include "stm32f10x.h"                  // Device header

uint16_t CountSensor_Count;

void CountSensor_Init(void) {

	// 第一步：配置RCC，把这里涉及的外设的时钟都打开
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
	
	// 第二步：配置GPIO，选择我们的端口为输入模式
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	// 第三步：配置AFIO，选择我们用的这一路GPIO，连接到后面的EXTI
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource14);

	// 第四步：配置EXTI，选择边沿触发方式、触发响应方式
	EXTI_InitTypeDef EXTI_InitStructure;
	// 指定要配置的中断线
	EXTI_InitStructure.EXTI_Line = EXTI_Line14;
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	// 下降沿触发
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
	
	EXTI_Init(&EXTI_InitStructure);
	
	// 第五步：配置NVIC，给中断选择一个合适的优先级
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel = EXTI15_10_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
	
	NVIC_Init(&NVIC_InitStructure);
	
}

uint16_t CountSensor_Get(void) {

	return CountSensor_Count;

}

void EXTI15_10_IRQHandler(void) {

	if (EXTI_GetITStatus(EXTI_Line14) == SET) {
		
		// 起到防抖作用
		if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_14) == 1) {
			CountSensor_Count ++;	
		}
		
		EXTI_ClearITPendingBit(EXTI_Line14);
	}

}

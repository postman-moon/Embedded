#include "stm32f10x.h"                  // Device header

void Timer_Init(void) {

	// 1. RCC 开启时钟, 定时器的基准时钟和整个外设的工作时钟就都会同时打开
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	
	// 2. 选择时基单元的时钟源（对于定时中断，选择内部时钟源）
	TIM_InternalClockConfig(TIM2);
	
	// 3. 配置时基单元, 包括预分频器、自动重装器、计数模式等等
	TIM_TimeBaseInitTypeDef TIM_TimBaseInitStructure;
	TIM_TimBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimBaseInitStructure.TIM_Period = 10000 - 1;
	TIM_TimBaseInitStructure.TIM_Prescaler = 7200 - 1;
	TIM_TimBaseInitStructure.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM2, &TIM_TimBaseInitStructure);
	
	TIM_ClearFlag(TIM2, TIM_FLAG_Update);
	TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);
	
	// 4. 配置输出中断控制, 允许更新中断输出到NVIC
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
	// 5. 配置NVIC, 在NVIC中打开定时器中断的通道, 并分配一个优先级
	NVIC_InitTypeDef NVIC_InitStructure;
	// 中断通道
	NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	// 抢占优先级
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;
	// 响应优先级
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
	NVIC_Init(&NVIC_InitStructure);
	
	// 6. 运行控制
	TIM_Cmd(TIM2, ENABLE);
	
}

/*
void TIM2_IRQHandler(void) {

	if (TIM_GetITStatus(TIM2, TIM_IT_Update) == SET) {
	
		TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
	}

}
*/

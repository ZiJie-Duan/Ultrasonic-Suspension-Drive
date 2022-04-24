#include "stm32f10x.h"    // Device header

void PWM_Init(void){
	
	
	//主时钟 高级定时器 使能
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);
	
	//主时钟 高级定时器 配置 
	TIM_TimeBaseInitTypeDef TIM1_TimeBaseStructure;
	TIM_TimeBaseStructInit(&TIM1_TimeBaseStructure);
	TIM1_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM1_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM1_TimeBaseStructure.TIM_Period = 100-1; //计数
	TIM1_TimeBaseStructure.TIM_Prescaler = 9-1;  //分频
	TIM1_TimeBaseStructure.TIM_RepetitionCounter = 0; 
	TIM_TimeBaseInit(TIM1, &TIM1_TimeBaseStructure);
	
	/* 主时钟 高级定时器 输出捕获器
	TIM_OCInitTypeDef TIM1_OCStructure;
	TIM_OCStructInit(&TIM1_OCStructure);
	TIM1_OCStructure.TIM_OCMode = TIM_OCMode_Active;
	TIM1_OCStructure.TIM_OCPolarity =TIM_OCPolarity_High;
	TIM1_OCStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM1_OCStructure.TIM_Pulse = 100; //occ
	TIM_OC2Init(TIM1, &TIM1_OCStructure); //疑惑？这个2 输出到哪里去了？
	*/
	
	// 设置 主计时器为 主控制器
	TIM_SelectMasterSlaveMode(TIM1, TIM_MasterSlaveMode_Enable);
	TIM_SelectOutputTrigger(TIM1, TIM_TRGOSource_Update);
	
	//******************设置随从*******************
	
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);  //复用时钟使能
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);  //复用时钟使能
	
	//随从时钟初始化
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseStructure.TIM_Period = 2-1;
	TIM_TimeBaseStructure.TIM_Prescaler = 1-1;
	TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;
	
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);

	//随从时钟 比较捕获器
	TIM_OCInitTypeDef TIM2_OCStructure;
	TIM_OCStructInit(&TIM2_OCStructure);
	TIM2_OCStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM2_OCStructure.TIM_OCPolarity =TIM_OCPolarity_High;
	TIM2_OCStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM2_OCStructure.TIM_Pulse = 1; //occ
	TIM_OC2Init(TIM2,&TIM2_OCStructure); //映射至 A1 GPIO
	
	TIM_OCInitTypeDef TIM3_OCStructure;
	TIM_OCStructInit(&TIM3_OCStructure);
	TIM3_OCStructure.TIM_OCMode = TIM_OCMode_PWM2;
	TIM3_OCStructure.TIM_OCPolarity =TIM_OCPolarity_High;
	TIM3_OCStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM3_OCStructure.TIM_Pulse = 1; //occ
	TIM_OC1Init(TIM3,&TIM3_OCStructure); //映射至 A6 GPIO
	
	
	
	//设置 随从模式 TIM2
	TIM_SelectInputTrigger(TIM2, TIM_TS_ITR0);//选择 TIMx 输入触发源，TIM 内部触发 0      
	TIM_SelectSlaveMode(TIM2,TIM_SlaveMode_External1);//     
	TIM_ITConfig(TIM2,TIM_IT_Update,DISABLE); 
	
	//设置 随从模式 TIM3
	TIM_SelectInputTrigger(TIM3, TIM_TS_ITR0);//选择 TIMx 输入触发源，TIM 内部触发 0      
	TIM_SelectSlaveMode(TIM3,TIM_SlaveMode_External1);//     
	TIM_ITConfig(TIM3,TIM_IT_Update,DISABLE); 

	// 使能 时钟 GPIO
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);

	// 初始化两路 GPIO
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1 | GPIO_Pin_6;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	
	TIM_Cmd(TIM1,ENABLE);
	TIM_Cmd(TIM2,ENABLE);
	TIM_Cmd(TIM3,ENABLE);
}


void PWM_Easy_Init(void){
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);  //复用时钟使能
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);  //复用时钟使能
	
	//随从时钟初始化
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseStructure.TIM_Period = 100-1;
	TIM_TimeBaseStructure.TIM_Prescaler = 72-1;
	TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;
	
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);

	//随从时钟 比较捕获器
	TIM_OCInitTypeDef TIM2_OCStructure;
	TIM_OCStructInit(&TIM2_OCStructure);
	TIM2_OCStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM2_OCStructure.TIM_OCPolarity =TIM_OCPolarity_High;
	TIM2_OCStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM2_OCStructure.TIM_Pulse = 50; //occ
	TIM_OC2Init(TIM2,&TIM2_OCStructure); //映射至 A1 GPIO
	
	TIM_OCInitTypeDef TIM3_OCStructure;
	TIM_OCStructInit(&TIM3_OCStructure);
	TIM3_OCStructure.TIM_OCMode = TIM_OCMode_PWM2;
	TIM3_OCStructure.TIM_OCPolarity =TIM_OCPolarity_High;
	TIM3_OCStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM3_OCStructure.TIM_Pulse = 5; //occ
	TIM_OC1Init(TIM3,&TIM3_OCStructure); //映射至 A6 GPIO

	// 使能 时钟 GPIO
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);

	// 初始化两路 GPIO
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1 | GPIO_Pin_6;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);

	TIM_Cmd(TIM2,ENABLE);
	TIM_Cmd(TIM3,ENABLE);
}

void PWM_Set_Frequency(uint16_t TIM_Period,uint16_t TIM_Prescaler){
	TIM_PrescalerConfig(TIM2,TIM_Prescaler-1,TIM_PSCReloadMode_Update);
	TIM_SetAutoreload(TIM2,TIM_Period-1);
	TIM_ARRPreloadConfig(TIM2,ENABLE);
	TIM_SetCompare2(TIM2,TIM_Period/2);

	TIM_PrescalerConfig(TIM3,TIM_Prescaler-1,TIM_PSCReloadMode_Update);
	TIM_SetAutoreload(TIM3,TIM_Period-1);
	TIM_ARRPreloadConfig(TIM3,ENABLE);
	TIM_SetCompare1(TIM3,TIM_Period/2);

}



/*
void PWM_Init(void){
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);  //复用时钟使能
	
	//主时钟初始化
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseStructure.TIM_Period = 1000-1;
	TIM_TimeBaseStructure.TIM_Prescaler = 12-1;
	TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);

	//主时钟 比较捕获器
	TIM_OCInitTypeDef TIM_OCStructure;
	TIM_OCStructInit(&TIM_OCStructure);
	TIM_OCStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCStructure.TIM_OCPolarity =TIM_OCPolarity_High;
	TIM_OCStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCStructure.TIM_Pulse = 500; //occ
	TIM_OC2Init(TIM2,&TIM_OCStructure);
	
	//设置 主从模式
	TIM_SelectMasterSlaveMode(TIM2, TIM_MasterSlaveMode_Enable);
	TIM_SelectOutputTrigger(TIM2, TIM_TRGOSource_Update);

	// 使能 时钟 GPIO
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);

	// 初始化两路 GPIO
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1 | GPIO_Pin_6;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	
	
	//TIM_Cmd(TIM2,ENABLE);
	// 使能 计时器3 时钟
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);  //复用时钟使能
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure2;
	TIM_TimeBaseStructure2.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseStructure2.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseStructure2.TIM_Period = 2-1;
	TIM_TimeBaseStructure2.TIM_Prescaler = 1-1;
	TIM_TimeBaseStructure2.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure2);
	
	// 设置 计时器3的激活端口
	TIM_SelectInputTrigger(TIM3, TIM_TS_ITR1);//选择 TIMx 输入触发源，TIM 内部触发 0      
	TIM_SelectSlaveMode(TIM3,TIM_SlaveMode_External1 );//     
	TIM_ITConfig(TIM3,TIM_IT_Update,DISABLE); //
	
	//计时器3 比较捕获器
	TIM_OCInitTypeDef TIM_OCStructure2;
	TIM_OCStructInit(&TIM_OCStructure2);
	TIM_OCStructure2.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCStructure2.TIM_OCPolarity =TIM_OCPolarity_High;
	TIM_OCStructure2.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCStructure2.TIM_Pulse = 1; //occ
	TIM_OC1Init(TIM3,&TIM_OCStructure2);
	
	TIM_Cmd(TIM2,ENABLE);
	TIM_Cmd(TIM3,ENABLE);
}

*/

/*
void PWM_Init(void){

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);  //复用时钟使能
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

	GPIO_Init(GPIOE, &GPIO_InitStructure); 

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);
	 

	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	
	TIM_TimeBaseStructure.TIM_ClockDivision = 0;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseStructure.TIM_Period = 1000-1;
	TIM_TimeBaseStructure.TIM_Prescaler = 72-1;
	TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;
	
	TIM_TimeBaseInit(TIM1, &TIM_TimeBaseStructure);
	
	
	TIM_OCInitTypeDef  TIM_OCInitStructure;
 

	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse = 100-1; // 比较值
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	 
	TIM_OC1Init(TIM1, &TIM_OCInitStructure);
	TIM_OC1PreloadConfig(TIM1, TIM_OCPreload_Enable);
	
	
	TIM_ARRPreloadConfig(TIM1, ENABLE); //预加载，影子寄存器

	TIM_Cmd(TIM1, ENABLE);

}
*/


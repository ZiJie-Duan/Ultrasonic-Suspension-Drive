#include "stm32f10x.h"                  // Device header
//#include "Timer.h" 
#include "pwm.h"
//#nclude "Voice.h"
#include "Delay.h"


int main(void){
	
	PWM_Easy_Init();
	PWM_Set_Frequency(10,178); //
	// 第一个参数 为 重装计数器的
	
	
	while(1){

	}

}


/*
	//开启GPIO端口时钟 RRC端口3 IOPB
  //RCC_APB2ENR |= ((1)<<3);
	RCC->APB2ENR |= (1<<3);
	//清空控制PB0的端口
	GPIOB->CRL &= ~(0x0F<<(4*0));
	
	//配置PBO为通用推免输出，速度为10M 
	//想要把修改为PB1 则(1<<5) PB5 (1<<20)
	
	GPIOB->CRL |= ((1)<<0);--_-
	
	//PB0输出低电平（开启LED） <0, 1, 5> 
	GPIOB->ODR |= (0<<0);
	//ODR输出高电平（关闭LED) 
	//GPIOB->ODR |=  (1<<0);
	//BSSR设置 / BRR清除
	//GPIOB->BSRR = (1<<0);
	//GPIOB->BRR  = (1<<0);

int LedState = 0;

void TIM2_IRQHandler(void){
	
	if(TIM_GetITStatus(TIM2,TIM_IT_Update) == SET){
		
		if(LedState == 0){
			GPIO_SetBits(GPIOA,GPIO_Pin_6);
			LedState = 1;
		}else{
			GPIO_ResetBits(GPIOA,GPIO_Pin_6);
			LedState = 0;
		}
		
		TIM_ClearITPendingBit(TIM2,TIM_IT_Update);
	}
	
}

int main(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	
	Timer_Init();
		
	while (1){
		TIM2_IRQHandler();
	}
}


*/
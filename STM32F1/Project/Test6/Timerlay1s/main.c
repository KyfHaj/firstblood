#include "stm32f10x.h"

GPIO_InitTypeDef  GPIO_InitStructure;
TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
NVIC_InitTypeDef NVIC_InitStructure;

__IO uint32_t timedelay;
__IO uint32_t a1,a2,b,c,d,e,f1,f2,g,h,i,j,k1,k2,k3,k4,l,m;
void GPIO_Configuration(void);
void Tim2Base(void);
void delay(__IO uint32_t gan);


int main()
{
	GPIO_Configuration();
	SysTick_Config	(SystemCoreClock / 1000);					// 1000 lan /1s   f=1000hz
																										// Tuc 1ms nhay vao 1 lan se tu dong ngat, nhay vao SysTick_Handler
	Tim2Base();
	GPIO_ResetBits(GPIOB, GPIO_Pin_12);
	
		while(1)
		{
			a1=TIM2->CR1;						//TIMx control register 1
			a2=TIM2->CR2;						//TIMx control register 2
			b=TIM2->SMCR;						//TIMx slave mode control register
			c=TIM2->DIER;						//TIMx DMA/Interrupt enable register
			d=TIM2->SR;							//TIMx status register
			e=TIM2->EGR;						//TIMx event generation register
			f1=TIM2->CCMR1;					//TIMx capture/compare mode register 1
			f2=TIM2->CCMR2;					//TIMx capture/compare mode register 2 
			g=TIM2->CCER;						//TIMx capture/compare enable register
			h=TIM2->CNT;						//TIMx counter
			i=TIM2->PSC;						//TIMx prescaler
			j=TIM2->ARR;						//TIMx auto-reload register
			k1=TIM2->CCR1;					//TIMx capture/compare register 1
			k2=TIM2->CCR2;					//TIMx capture/compare register 2
			k3=TIM2->CCR3;					//TIMx capture/compare register 3
			k4=TIM2->CCR4;					//TIMx capture/compare register 4
			l=TIM2->DCR;						//TIMx DMA control register
			m=TIM2->DMAR;						//TIMx DMA address for full transfer
//			GPIOC ->ODR ^= GPIO_Pin_13;
//			
//			delay(1000);
		}
}
void GPIO_Configuration(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC | RCC_APB2Periph_GPIOB, ENABLE);
			
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13 ;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(GPIOC, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12 ;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
}
void Tim2Base(void)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	
//	TIM_TimeBaseStructure.TIM_Prescaler = ((SystemCoreClock)/1000)-1;   //???     
	TIM_TimeBaseStructure.TIM_Prescaler = 71;
	TIM_TimeBaseStructure.TIM_Period = 1000 - 1;
	TIM_TimeBaseStructure.TIM_ClockDivision = 0;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);
	
	TIM_ITConfig(TIM2,TIM_IT_Update,ENABLE);
	TIM_Cmd(TIM2, ENABLE);
	
	NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority= 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority= 1;
	NVIC_InitStructure.NVIC_IRQChannelCmd= ENABLE;
	NVIC_Init(&NVIC_InitStructure);
}
void delay(__IO uint32_t gan)
{
	timedelay = gan;
	while(timedelay!=0);
}


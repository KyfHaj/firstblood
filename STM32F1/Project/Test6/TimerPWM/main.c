#include "stm32f10x.h"
 
 
 __IO uint32_t a1,a2,b,c,d,e,f1,f2,g,h,i,j,k1,k2,k3,k4,l,m;
 
 
GPIO_InitTypeDef           GPIO_InitStructure;
TIM_TimeBaseInitTypeDef    TIM_TimeBaseStructure;
TIM_OCInitTypeDef          TIM_OCInitStructure;
 
 
void TIM_PWM_Configuration(void);
void Delay(__IO uint32_t nCount);
 
int main()
{
 TIM_PWM_Configuration();
 TIM1->CCR1 = 5 * 65535 / 100;  //10% Duty cycle
 TIM1->CCR2 = 30 * 65535 / 100;  //30% Duty cycle
 TIM1->CCR3 = 60 * 65535 / 100;  //60% Duty cycle
 TIM1->CCR4 = 90 * 65535 / 100;  //90% Duty cycle
 while(1)        
 {
		a1=TIM1->CR1;						//TIMx control register 1
		a2=TIM1->CR2;						//TIMx control register 2
		b=TIM1->SMCR;						//TIMx slave mode control register
		c=TIM1->DIER;						//TIMx DMA/Interrupt enable register
		d=TIM1->SR;							//TIMx status register
		e=TIM1->EGR;						//TIMx event generation register
		f1=TIM1->CCMR1;					//TIMx capture/compare mode register 1
		f2=TIM1->CCMR2;					//TIMx capture/compare mode register 2 
		g=TIM1->CCER;						//TIMx capture/compare enable register
		h=TIM1->CNT;						//TIMx counter
		i=TIM1->PSC;						//TIMx prescaler
		j=TIM1->ARR;						//TIMx auto-reload register
		k1=TIM1->CCR1;					//TIMx capture/compare register 1
		k2=TIM1->CCR2;					//TIMx capture/compare register 2
		k3=TIM1->CCR3;					//TIMx capture/compare register 3
		k4=TIM1->CCR4;					//TIMx capture/compare register 4
		l=TIM1->DCR;						//TIMx DMA control register
		m=TIM1->DMAR;						//TIMx DMA address for full transfer
 }
}
void TIM_PWM_Configuration(void)
{
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
 
 /* Configure PB0 PB1 in output pushpull mode */
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_11;
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
 GPIO_Init(GPIOA, &GPIO_InitStructure);         
 
 TIM_TimeBaseStructure.TIM_Prescaler = 0;  
 TIM_TimeBaseStructure.TIM_Period = 0xFFFF;   // 65535
 TIM_TimeBaseStructure.TIM_ClockDivision = 0;
 TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
 
 TIM_TimeBaseInit(TIM1, &TIM_TimeBaseStructure);
  
 TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
 TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; 
 TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
 TIM_OCInitStructure.TIM_OutputNState = TIM_OutputNState_Enable; 
 TIM_OCInitStructure.TIM_OCNPolarity = TIM_OCNPolarity_High;
 TIM_OCInitStructure.TIM_Pulse = 0;
 //TIM_OCStructInit(&TIM_OCInitStructure);
    
 TIM_OC1Init(TIM1, &TIM_OCInitStructure);  							//Initializes the TIMx Channel1 according to the specified parameters in the TIM_OCInitStruct.
 TIM_OC1PreloadConfig(TIM1, TIM_OCPreload_Enable);			//Enables the TIMx peripheral Preload register on CCR1.
 
 TIM_OC2Init(TIM1, &TIM_OCInitStructure);
 TIM_OC2PreloadConfig(TIM1, TIM_OCPreload_Enable);
  
 TIM_OC3Init(TIM1, &TIM_OCInitStructure);
 TIM_OC3PreloadConfig(TIM1, TIM_OCPreload_Enable);
 
 TIM_OC4Init(TIM1, &TIM_OCInitStructure);
 TIM_OC3PreloadConfig(TIM1, TIM_OCPreload_Enable);
 
 TIM_ARRPreloadConfig(TIM1, ENABLE);										// Enables TIMx peripheral Preload register on ARR.
 
 /* TIM1 enable counter */
 TIM_Cmd(TIM1, ENABLE);
 TIM_CtrlPWMOutputs(TIM1, ENABLE);
}
 
void Delay(__IO uint32_t nCount)
{
 while(nCount--)
 {
 }
}
  

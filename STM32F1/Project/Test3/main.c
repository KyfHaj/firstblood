#include "stm32f10x.h"
//A9|A0->B14
//A11|A4->B12
//A0|A9   <  A11|A4
GPIO_InitTypeDef  GPIO_InitStructure;
EXTI_InitTypeDef   EXTI_InitStructure;           //   Interupt EXTI
NVIC_InitTypeDef   NVIC_InitStructure;           //   NVIC structure
 
void GPIO_Configuration(void);
void EXTILine9_Config(void);
void EXTILine11_Config(void);
void Delay(__IO uint32_t nCount);

 __IO uint32_t  m;
 __IO uint32_t  n;
 __IO uint32_t  p;
int main()
{
	GPIO_Configuration();
	
	NVIC_PriorityGroupConfig (NVIC_PriorityGroup_4);					 //4 bit cho preemp uu tiên 0-bit cho uu tiên ph?
	
	EXTILine9_Config();
	EXTILine11_Config();
	
	 while(1)        
	 {
		 GPIOC->ODR ^= GPIO_Pin_13;						 // Dao trang thai
		 Delay(5000000);
		 p+=1;
	 }
}

void GPIO_Configuration(void)
{
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC | RCC_APB2Periph_GPIOB, ENABLE);
 
 /* Configure PC13 in output pushpull mode */
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13 ;
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
 GPIO_Init(GPIOC, &GPIO_InitStructure);
 /* Configure PB14 in output pushpull mode */                   
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14 | GPIO_Pin_12;
  GPIO_Init(GPIOB, &GPIO_InitStructure);	
}

void EXTILine9_Config(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA , ENABLE);
	/* Configure PA10 in output input floating mode */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9 ;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING ;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	/* Enable AFIO */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
		/* Connect EXTI10 Line to PA.0 pin */
  GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource9);
	
/* Configure EXTI0 line */
  EXTI_InitStructure.EXTI_Line = EXTI_Line9;
  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;  
  EXTI_InitStructure.EXTI_LineCmd = ENABLE;
  EXTI_Init(&EXTI_InitStructure);

  		
	/* Enable and set EXTI0 Interrupt to the lowest priority */
  NVIC_InitStructure.NVIC_IRQChannel = EXTI9_5_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x02;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x00;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
  
}
void EXTILine11_Config(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA , ENABLE);
	/* Configure PA10 in output input floating mode */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11 ;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING ;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	/* Enable AFIO */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
		/* Connect EXTI10 Line to PA.4 pin */
  GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource11);
	
/* Configure EXTI4 line */
  EXTI_InitStructure.EXTI_Line = EXTI_Line11;
  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;  
  EXTI_InitStructure.EXTI_LineCmd = ENABLE;
  EXTI_Init(&EXTI_InitStructure);

			
  /* Enable and set EXTI4 Interrupt to the lowest priority */
  NVIC_InitStructure.NVIC_IRQChannel = EXTI15_10_IRQn;							 
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x01;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x00;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
  
}
void Delay(__IO uint32_t nCount)
{
 while(nCount--)
 {
 }
}
  
#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}

#endif

/**
  * @}
  */

/**
  * @}
  */

/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/








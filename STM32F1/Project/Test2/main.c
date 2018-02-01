/**
  ******************************************************************************
  * @file    GPIO/IOToggle/main.c 
  * @author  MCD Application Team
  * @version V3.5.0
  * @date    08-April-2011
  * @brief   Main program body.
  ******************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2011 STMicroelectronics</center></h2>
  ******************************************************************************
  */ 

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"


GPIO_InitTypeDef  GPIO_InitStructure;
 
void GPIO_Configuration(void);
void Delay(__IO uint32_t nCount);
 // volatile int m;
uint32_t n;

int main()
{
	
 GPIO_Configuration();
	GPIO_ResetBits(GPIOB, GPIO_Pin_14);
	 
	n= SystemCoreClock ;

	 while(1)        
	 {
//		 if(m>=35){GPIO_SetBits(GPIOB ,GPIO_Pin_14);}
//		 GPIO_SetBits(GPIOC ,GPIO_Pin_13);
//			Delay(5000000);
//		 GPIO_ResetBits(GPIOC, GPIO_Pin_13);
//			Delay(5000000);
//		 m++;
		 
		
		 GPIOC->ODR ^= GPIO_Pin_13;
		
		 GPIOB->ODR ^= GPIO_Pin_14;
		 Delay(5000000);
		 
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
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14;
  GPIO_Init(GPIOB, &GPIO_InitStructure);	
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

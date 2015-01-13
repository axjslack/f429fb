/**
  ******************************************************************************
  * @file    Template/main.c
  * @author  MCD Application Team
  * @version V1.0.0
  * @date    20-September-2013
  * @brief   Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2013 STMicroelectronics</center></h2>
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/software_license_agreement_liberty_v2
  *
  * Unless required by applicable law or agreed to in writing, software
  * distributed under the License is distributed on an "AS IS" BASIS,
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f4xx_hal_ltdc.h"
#include "stm32f429i_discovery_lcd.h"
/** @addtogroup Template
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/

/* Private functions ---------------------------------------------------------*/

/**
  * @brief   Main program
  * @param  None
  * @retval None
  */
   
    #define MESSAGE1   "HELLO WORLD"
    #define MESSAGE2   "GIBBA"
int main(void)
{
  /*!< At this stage the microcontroller clock setting is already configured,
       this is done through SystemInit() function which is called from startup
       files (startup_stm32f429_439xx.s) before to branch to application main.
       To reconfigure the default setting of SystemInit() function, refer to
       system_stm32f4xx.c file
     */ 
 
  /* Add your application code here */
   
   
    STM_EVAL_LEDInit(LED3);
    STM_EVAL_LEDInit(LED4);
   
    STM_EVAL_LEDOn(LED3);
    STM_EVAL_LEDOff(LED4);
   
    STM_EVAL_PBInit(BUTTON_USER, BUTTON_MODE_GPIO);
   
   
    LCD_Init();
  LCD_LayerInit();
 
  /* LTDC reload configuration */ 

	__HAL_LTDC_RELOAD_CONFIG(__HANDLE__);
		

//  LTDC_ReloadConfig(LTDC_IMReload);
 
  /* Enable the LTDC */
  LTDC_Cmd(ENABLE);
 
  /* Set LCD foreground layer */
  LCD_SetLayer(LCD_FOREGROUND_LAYER);
 
  /* Clear the Foreground Layer */
  LCD_Clear(LCD_COLOR_BLACK);
   
   
    LCD_SetBackColor(LCD_COLOR_BLACK);
    LCD_SetTextColor(LCD_COLOR_WHITE);
   
    LCD_DisplayStringLine(LCD_LINE_1, (uint8_t *)MESSAGE1);
   
   
   
   
   
  /* Infinite loop */
  while (1)
  {
            /* Wait for User push-button is pressed */
        if (STM_EVAL_PBGetState(BUTTON_USER) != Bit_RESET)
    {    
      /* Wait for User push-button is released */
      while (STM_EVAL_PBGetState(BUTTON_USER) != Bit_SET)
      {

               
      }
           
                LCD_DisplayStringLine(LCD_LINE_1, (uint8_t *)MESSAGE2);
           
                STM_EVAL_LEDToggle(LED3);
                STM_EVAL_LEDToggle(LED4);
        }else{

        }
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

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

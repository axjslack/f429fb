#include "ili9341.h"
#include "myfb.h"

static frameB *myfb;

static void Error_Handler(void)
{
  /* Turn LED4 (RED) on */
  //BSP_LED_On(LED4);
  while(1)
  {
  }
}



void init_myfb()
{
        int i,j;
		
		myfb=(frameB*)0xD0000000;

        for(i=0;i<240;i++)
        {
                for(j=0;j<320;j++)
                {
				myfb->tablePix.PixelTable[i][j].red=0xFF;
                myfb->tablePix.PixelTable[i][j].green=0x0;
                myfb->tablePix.PixelTable[i][j].blue=0X0;
				myfb->tablePix.PixelTable[i][j].alpha=0xFF;
                }
        }
	
	//LCD_Config();
	BSP_LCD_Init();
	BSP_LCD_LayerDefaultInit(0, (uint32_t)&myfb->tableInt);
	BSP_LCD_SetLayerVisible(0, ENABLE);

}


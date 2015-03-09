#ifndef _myfb_h
#define _myfb_h

#include <stdint.h>
#include "stm32f4xx_hal_ltdc.h"

typedef struct strPixel
{
        uint8_t red: 5;
        uint8_t green: 6;
        uint8_t blue: 5;
} t565Pixel;

union Pixel
{
        t565Pixel  destructured[2];
        uint32_t structured;

};

typedef struct strTablePix {
	t565Pixel PixelTable[240][320];
} tTablePix;



union frameB
{
	tTablePix tablePix;
	uint32_t tableInt[38400];
	
};

LTDC_HandleTypeDef LtdcHandle;

void init_myfb(tTablePix tablePix);
static void LCD_Config(uint32_t *myfb);
static void Error_Handler(void);

#endif 
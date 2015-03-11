#ifndef _myfb_h
#define _myfb_h

#include <stdint.h>
#include "stm32f4xx.h"
#include "stm32f4xx_hal_conf.h"
#include "stm32f4xx_hal_ltdc.h"

typedef struct strPixel
{
        unsigned char red: 5;
        unsigned char green: 6;
		unsigned char blue: 5;
} t565Pixel;

union Pixel
{
        t565Pixel  destructured[2];
        uint32_t structured;

};

typedef struct strTablePix {
	volatile t565Pixel PixelTable[240][160];
} tTablePix;



typedef union frameBuf
{
	tTablePix tablePix;
	volatile uint32_t *tableInt;
	
} frameB;

LTDC_HandleTypeDef LtdcHandle;

void init_myfb();

#endif 
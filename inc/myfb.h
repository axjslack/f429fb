#ifndef _myfb_h
#define _myfb_h

#include <stdint.h>
#include "stm32f4xx.h"
#include "stm32f4xx_hal_conf.h"
#include "stm32f4xx_hal_ltdc.h"

/* RGB 565 test 
typedef struct strPixel
{
		unsigned char red: 5;
        unsigned char green: 6;
		unsigned char blue: 5;
} t565Pixel;
*/

/* LTDC_PIXEL_FORMAT_ARGB8888 */
typedef struct strPixel
{
	volatile uint8_t blue;
	volatile uint8_t green;
	volatile uint8_t red;
	volatile uint8_t alpha;
} t565Pixel;

union Pixel
{
        t565Pixel  destructured;
        uint32_t structured;

};

typedef struct strTablePix {
	volatile t565Pixel PixelTable[240][320];
} tTablePix;



typedef union frameBuf
{
	tTablePix tablePix;
	volatile uint32_t *tableInt;
	
} frameB;

LTDC_HandleTypeDef LtdcHandle;

void init_myfb();

#endif 
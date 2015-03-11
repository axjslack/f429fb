#Basic Makefile for STM32F429

PRJ_NME=mytest3

SRC_DIR	=	./src
INC_DIR	=	./inc
ASM_DIR	=	./asm
OBJ_DIR	=	./obj

#SOURCES	= 	$(wildcard $(SRC_DIR)/*.c)


# Source List
SOURCES	=	\
$(SRC_DIR)/stm32f429i_discovery.c \
$(SRC_DIR)/system_stm32f4xx.c \
$(SRC_DIR)/stm32f4xx_it.c \
$(SRC_DIR)/HAL/stm32f4xx_hal.c \
$(SRC_DIR)/HAL/stm32f4xx_hal_cortex.c \
$(SRC_DIR)/HAL/stm32f4xx_hal_rcc.c \
$(SRC_DIR)/HAL/stm32f4xx_hal_gpio.c \
$(SRC_DIR)/HAL/stm32f4xx_hal_spi.c \
$(SRC_DIR)/HAL/stm32f4xx_hal_ltdc.c \
$(SRC_DIR)/HAL/stm32f4xx_hal_pwr_ex.c \
$(SRC_DIR)/HAL/stm32f4xx_hal_rcc_ex.c \
$(SRC_DIR)/HAL/stm32f4xx_hal_sdram.c \
$(SRC_DIR)/HAL/stm32f4xx_hal_dma.c \
$(SRC_DIR)/HAL/stm32f4xx_ll_fmc.c \
$(SRC_DIR)/BSP/driver/ili9341.c \
$(SRC_DIR)/BSP/stm32f429i_discovery_lcd.c \
$(SRC_DIR)/BSP/stm32f429i_discovery_sdram.c \
$(SRC_DIR)/systemclock_config.c \
$(SRC_DIR)/myfb.c \
$(SRC_DIR)/main.c 



#$(SRC_DIR)/HAL/stm32f4xx_hal_dma.c \
#$(SRC_DIR)/BSP/stm32f429i_discovery_sdram.c \
#$(SRC_DIR)/HAL/stm32f4xx_hal_rcc_ex.c \
#$(SRC_DIR)/HAL/stm32f4xx_hal_flash.c \
#$(SRC_DIR)/HAL/stm32f4xx_hal_flash_ex.c \
#$(SRC_DIR)/HAL/stm32f4xx_hal_i2c.c \
#$(SRC_DIR)/HAL/stm32f4xx_hal_i2c_ex.c \
#$(SRC_DIR)/HAL/stm32f4xx_hal_pwr.c \
#$(SRC_DIR)/HAL/stm32f4xx_hal_pwr_ex.c \
# \
#$(SRC_DIR)/HAL/stm32f4xx_hal_sdram.c \
#$(SRC_DIR)/HAL/stm32f4xx_ll_fmc.c \
# \
#$(SRC_DIR)/HAL/stm32f4xx_hal_msp.c \
#  \

HEADERS	= 	$(wildcard $(INC_DIR)/*.h)
ASM	=	$(ASM_DIR)/startup_stm32f429xx.s
STARTUP	=	$(ASM_DIR)/startup_stm32f429xx.o
LDSCRIPT=STM32F429ZI_FLASH.ld

CROSS_COMPILE 	?= 	arm-none-eabi-
CC	=	$(CROSS_COMPILE)gcc
LD	=	$(CROSS_COMPILE)ld
AS	=	$(CROSS_COMPILE)as
OBJDUMP = 	$(CROSS_COMPILE)objdump
OBJCOPY = 	$(CROSS_COMPILE)objcopy
SIZE 	= 	$(CROSS_COMPILE)size

CFLAGS	=	-O0 -g3 -mcpu=cortex-m4 -mthumb -mlittle-endian -mfloat-abi=softfp -march=armv7e-m -mthumb-interwork -mfpu=fpv4-sp-d16
CFLAGS	+=	-D STM32F429xx -D USE_STM32F429I_DISCO  -D HAL_LTDC_MODULE_ENABLED -D USE_HAL_DRIVER -D HAL_SDRAM_MODULE_ENABLED
CFLAGS 	+= 	-ffunction-sections -fdata-sections -Wall -fmessage-length=0 -fsigned-char -std=c99 -Wl,-Map=$(BUILDPROJ).map -Wl,--gc-sections 

#-D USE_STDPERIPH_DRIVER

CFLAGS	+= 	-I$(INC_DIR) 
CFLAGS	+=	-I$(INC_DIR)/BSP
CFLAGS	+=	-I$(INC_DIR)/BSP/driver
CFLAGS	+=	-I$(INC_DIR)/CMSIS
CFLAGS	+=	-I$(INC_DIR)/HAL



all : build size

build : $(PRJ_NME).elf $(PRJ_NME).bin 

$(STARTUP) : $(ASM)
	$(AS) $(ASM) -o $@

$(PRJ_NME).elf : $(STARTUP) $(SOURCES) $(HEADERS) $(LDSCRIPT)
	$(CC) -Wl,-M=$(PRJ_NME).map -Wl,-T$(LDSCRIPT) $(CFLAGS) $(STARTUP) $(SOURCES) -o $@


%.bin: %.elf
	$(OBJCOPY) -O binary $< $@
size: $(PRJ_NME).elf
	$(SIZE) $(PRJ_NME).elf

install: build
	st-flash write $(PRJ_NME).bin 0x08000000

clean:
	rm -f $(PRJ_NME).elf
	rm -f $(PRJ_NME).bin


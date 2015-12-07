CC=arm-none-eabi-gcc
AS=arm-none-eabi-as
LD=arm-none-eabi-ld
DB=arm-none-eabi-gdb

CFLAGS=-O0 -g3 -Wall -mcpu=cortex-m7 -mfloat-abi=hard -mfpu=fpv5-sp-d16 -mthumb \
		-Iinc/ \
		-Ilib/CMSIS/Device/ST/STM32F7xx/Include/ \
		-Ilib/CMSIS/Include/ \
		-Ilib/STM32F7xx_HAL_Driver/Inc \
		-DSTM32F746xx \
		-DUSE_HAL_DRIVER
AFLAGS=

ELF=blink-stm32f7.elf
LINKER=stm32.ld

CSOURCES=	src/main.c \
		lib/CMSIS/Device/ST/STM32F7xx/Source/Templates/system_stm32f7xx.c \
		#lib/STM32F7xx_HAL_Driver/Src/*.c

ASOURCES=	lib/CMSIS/Device/ST/STM32F7xx/Source/Templates/gcc/startup_stm32f746xx.s

COBJECTS=$(notdir $(CSOURCES:.c=.o))
AOBJECTS= asm.o

all: $(ELF)

$(ELF): $(COBJECTS) $(AOBJECTS)
	$(CC) $(CFLAGS) $(AFLAGS) -T$(LINKER) -o $(ELF) $(COBJECTS) $(AOBJECTS)

$(COBJECTS): $(CSOURCES)
	$(CC) $(CFLAGS) -c $(CSOURCES)

$(AOBJECTS): $(ASOURCES)
	$(AS) $(AFLAGS) -o $(AOBJECTS) $(ASOURCES)

clean:
	rm -f *.o $(ELF)

debug:
	$(DB) -tui -x gdb.cfg $(ELF)

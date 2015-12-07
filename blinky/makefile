CC=arm-none-eabi-gcc
AS=arm-none-eabi-as
LD=arm-none-eabi-ld
DB=arm-none-eabi-gdb

CFLAGS=-O0 -g3 -Wall -mcpu=cortex-m7 -mfloat-abi=hard -mfpu=fpv5-sp-d16 -mthumb
AFLAGS=

ELF=blink-stm32f7.elf
LINKER=stm32.ld

CSOURCES=src/main.c src/toggle.c
ASOURCES=src/startup_stm32f746xx.S

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

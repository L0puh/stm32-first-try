# Simple working Makefile for STM32F1

PROJECT = blinker

# Paths
LIBOPENCM3 = ../libs/libopencm3
INCLUDE = -I$(LIBOPENCM3)/include

# Device
DEVICE = stm32f103c8

# Toolchain
PREFIX = arm-none-eabi-
CC = $(PREFIX)gcc
OBJCOPY = $(PREFIX)objcopy
SIZE = $(PREFIX)size

# Use the generic linker script
LINKER_SCRIPT = $(LIBOPENCM3)/lib/cortex-m-generic.ld

# Compiler flags
CFLAGS = -Os -g -Wall -Wextra
CFLAGS += $(INCLUDE)
CFLAGS += -mcpu=cortex-m3 -mthumb
CFLAGS += -DSTM32F1
CFLAGS += -fno-common -ffunction-sections -fdata-sections

# Linker flags
LDFLAGS = --static -nostartfiles
LDFLAGS += -T$(LINKER_SCRIPT)
LDFLAGS += -L$(LIBOPENCM3)/lib -lopencm3_stm32f1
LDFLAGS += -mcpu=cortex-m3 -mthumb -Wl,--gc-sections
LDFLAGS += -Wl,-Map=$(PROJECT).map

# Source files
SRCS = main.c
OBJS = $(SRCS:.c=.o)

# Default target
all: $(PROJECT).elf $(PROJECT).bin

# Link
$(PROJECT).elf: $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) -o $@
	$(SIZE) $@

# Compile
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Create binary
$(PROJECT).bin: $(PROJECT).elf
	$(OBJCOPY) -O binary $< $@

# Flash
flash: $(PROJECT).bin
	st-flash --reset write $(PROJECT).bin 0x08000000

# Clean
clean:
	rm -f *.o *.elf *.bin *.map

.PHONY: all clean flash

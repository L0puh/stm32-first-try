PROJECT = blinker
BUILD_DIR = build

LIBOPENCM3 = ../libs/libopencm3
LINKER_SCRIPT = ../libs/stm32f103c8t6.ld

PREFIX = arm-none-eabi-
CC = $(PREFIX)gcc
OBJCOPY = $(PREFIX)objcopy
SIZE = $(PREFIX)size

CFLAGS = -Os -g -Wall -Wextra
CFLAGS += -I$(LIBOPENCM3)/include
CFLAGS += -mcpu=cortex-m3 -mthumb
CFLAGS += -DSTM32F1 -DSTM32F103xB
CFLAGS += -ffunction-sections -fdata-sections

LDFLAGS = -T$(LINKER_SCRIPT)
LDFLAGS += -L$(LIBOPENCM3)/lib -lopencm3_stm32f1
LDFLAGS += -nostartfiles -Wl,--gc-sections
LDFLAGS += -mcpu=cortex-m3 -mthumb

SRCS = main.c
OBJS = $(SRCS:%.c=$(BUILD_DIR)/%.o)

all: $(BUILD_DIR) $(BUILD_DIR)/$(PROJECT).elf $(BUILD_DIR)/$(PROJECT).bin

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/%.o: %.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/$(PROJECT).elf: $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) -o $@
	$(SIZE) $@

$(BUILD_DIR)/$(PROJECT).bin: $(BUILD_DIR)/$(PROJECT).elf
	$(OBJCOPY) -O binary $< $@

flash: $(BUILD_DIR)/$(PROJECT).bin
	st-flash --reset write $(BUILD_DIR)/$(PROJECT).bin 0x08000000

clean:
	rm -rf $(BUILD_DIR)

.PHONY: all clean flash

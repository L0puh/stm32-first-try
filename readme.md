# STM32 first-try projects
chip: `stm32f103c8t6`


the repository contains
1. simple mini blink 
2. mini blink usuing FreeRTOS 

# setup
> connect STM32 to PC with programmer (st-link v2)
```bash
cd libs && make # build libraries 

# build some project
cd status_blink_RTOS  
make
make flash
```
# libraries used 
- [libopencm3](https://github.com/libopencm3/libopencm3)
- [FreeRTOS-Kernel](https://github.com/FreeRTOS/FreeRTOS-Kernel/tree/0030d609a4b99118d9a400340d88c3c3c4816f2b)

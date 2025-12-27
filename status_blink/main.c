#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>

static void delay(volatile uint32_t count)
{
    while (count--) {
        __asm__ volatile ("nop");
    }
}

static void setup_gpio(void){
    rcc_periph_clock_enable(RCC_GPIOC);
    gpio_set_mode(GPIOC,
                  GPIO_MODE_OUTPUT_2_MHZ,
                  GPIO_CNF_OUTPUT_PUSHPULL,
                  GPIO13);

    gpio_set(GPIOC, GPIO13);

}

int main(void)
{
   setup_gpio();

    while (1) {
        gpio_clear(GPIOC, GPIO13);  
        delay(1000000);


        gpio_set(GPIOC, GPIO13);    
        delay(1000000);
    }
}


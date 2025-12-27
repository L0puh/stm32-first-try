#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>

static void delay(volatile uint32_t count)
{
    while (count--) {
        __asm__ volatile ("nop");
    }
}

int main(void)
{
    /* Enable GPIOC clock */
    rcc_periph_clock_enable(RCC_GPIOC);

    /* PC13: LED (active LOW on Blue Pill) */
    gpio_set_mode(GPIOC,
                  GPIO_MODE_OUTPUT_2_MHZ,
                  GPIO_CNF_OUTPUT_PUSHPULL,
                  GPIO13);

    /* LED OFF initially */
    gpio_set(GPIOC, GPIO13);

    while (1) {
        gpio_clear(GPIOC, GPIO13);  /* LED ON */
        delay(1000000);

        gpio_set(GPIOC, GPIO13);    /* LED OFF */
        delay(1000000);
    }
}


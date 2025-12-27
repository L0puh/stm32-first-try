#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>

#define LED_PIN GPIO13

static void gpio_setup(void){
   rcc_periph_clock_enable(RCC_GPIOC);
   gpio_set_mode(GPIOC, GPIO_MODE_OUTPUT_2_MHZ, 
                  GPIO_CNF_OUTPUT_PUSHPULL, LED_PIN);
            
}

void delay(int ms) {
   for (int i = 0; i < ms; i++){
      __asm__("nop");
   }
}

int main(void) {
   gpio_setup();
   while(1){
      gpio_clear(GPIOC, LED_PIN);
   }
}

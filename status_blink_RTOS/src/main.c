#include "FreeRTOS.h"
#include "task.h"

#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>

#define LED_PORT GPIOC
#define LED_PIN GPIO13

static void blink_task(void *arg) {
   (void)arg;
   for (;;) {
      gpio_clear(LED_PORT, LED_PIN);
      vTaskDelay(pdMS_TO_TICKS(1400));
      gpio_set(LED_PORT, LED_PIN);
      vTaskDelay(pdMS_TO_TICKS(1000));

   }
}

void setup_gpio(void){
   rcc_clock_setup_pll(&rcc_hse_configs[RCC_CLOCK_HSE8_72MHZ]);
   rcc_periph_clock_enable(RCC_GPIOC);
   gpio_set_mode(LED_PORT, GPIO_MODE_OUTPUT_2_MHZ, 
         GPIO_CNF_OUTPUT_PUSHPULL, LED_PIN);
}


int main(void) {
   setup_gpio();

   xTaskCreate(blink_task, "Blink", 128, NULL, 1, NULL);
   vTaskStartScheduler();

   for (;;);
   return 0;
}

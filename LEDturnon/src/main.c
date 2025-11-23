#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

void app_main() {
    int LEDpin = 2;
    gpio_set_direction(LEDpin, GPIO_MODE_OUTPUT);

    while (1) {
        gpio_set_level(LEDpin, 1);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
        gpio_set_level(LEDpin, 0);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }

    
}
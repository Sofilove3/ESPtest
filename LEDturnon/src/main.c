#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

void app_main() {
    // set pu LED
    int LEDpin = GPIO_NUM_2;
    gpio_set_direction(LEDpin, GPIO_MODE_OUTPUT);

    while (1) {
        // turn on LED and wait 1 sec
        gpio_set_level(LEDpin, 1);
        vTaskDelay(1000 / portTICK_PERIOD_MS);

        // turn LED off and wait 1 sec
        gpio_set_level(LEDpin, 0);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }

    
}
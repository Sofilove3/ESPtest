#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

void app_main() {
    int redLED1 = 18;
    int redLED2 = 19;
    int greenLED = 17;
    int button = 16;

    gpio_set_direction(redLED1, GPIO_MODE_OUTPUT);
    gpio_set_direction(redLED2, GPIO_MODE_OUTPUT);
    gpio_set_direction(greenLED, GPIO_MODE_OUTPUT);
    gpio_set_direction(button, GPIO_MODE_INPUT);
    while(1) {
        if (gpio_get_level(button) == 0){
            gpio_set_level(redLED1, 0);
            gpio_set_level(redLED2, 0);
            gpio_set_level(greenLED, 1);
        } else {
            gpio_set_level(redLED1, 1);
            gpio_set_level(redLED2, 1);
            gpio_set_level(greenLED, 0);
            vTaskDelay(250 / portTICK_PERIOD_MS);
            gpio_set_level(redLED1, 0);
            gpio_set_level(redLED2, 0);
            gpio_set_level(greenLED, 0);
            vTaskDelay(250 / portTICK_PERIOD_MS);
        }
    }
}
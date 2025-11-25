#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

void app_main() {
    // make varibles for LED and button
    int redLED1 = GPIO_NUM_18;
    int redLED2 = GPIO_NUM_19;
    int greenLED = GPIO_NUM_17;
    int button = GPIO_NUM_16;

    // set up LEDs as output and bUtton as input
    gpio_set_direction(redLED1, GPIO_MODE_OUTPUT);
    gpio_set_direction(redLED2, GPIO_MODE_OUTPUT);
    gpio_set_direction(greenLED, GPIO_MODE_OUTPUT);
    gpio_set_direction(button, GPIO_MODE_INPUT);
    gpio_pullup_en(button);
    while(1) {
        if (gpio_get_level(button) == 0){
            // if button is not pressed turn on the green LED
            gpio_set_level(redLED1, 0);
            gpio_set_level(redLED2, 0);
            gpio_set_level(greenLED, 1);
        } else {
            // if the button is pressed make the red leds blink
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
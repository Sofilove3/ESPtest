#include "driver/adc.h"
#include "esp_adc_cal.h"
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

void app_main() {
    // set up adc channel
    adc1_config_channel_atten(ADC1_CHANNEL_0, ADC_ATTEN_DB_12);
    adc1_config_width(ADC_WIDTH_BIT_12);

    // make varible for adc information
    esp_adc_cal_characteristics_t adc_chars;
    esp_adc_cal_characterize(ADC_UNIT_1, ADC_ATTEN_DB_12, ADC_WIDTH_BIT_12, 1100, &adc_chars);

    // get values from sensor and calculate
    int sensor_val = adc1_get_raw(ADC1_CHANNEL_0);
    int voltage = esp_adc_cal_raw_to_voltage(sensor_val, &adc_chars);
    float temperatur = (voltage / 1000.0 - 0.5) * 100.00;

    // print values
    printf("Sensor val: %d, voltage(mV): %d, temperatur in C: %.2f\n", sensor_val, voltage, temperatur);
    while(1) {
        // get values from sensor at calculate
        sensor_val = adc1_get_raw(ADC1_CHANNEL_0);
        voltage = esp_adc_cal_raw_to_voltage(sensor_val, &adc_chars);
        temperatur = (voltage / 1000.0 - 0.5) * 100.00;

        // print values and wait 1 sec
        printf("Sensor val: %d, voltage(mV): %d, temperatur in C: %.2f\n", sensor_val, voltage, temperatur);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}
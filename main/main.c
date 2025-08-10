// Program: Application code for Dual Motor Control PWM 
// Author: Fayyaz Shaikh
// Email: fayyaz.shaikh7862005@gmail.com
// Phone: +91 8591686239

#include <stdio.h>

#include "esp_system.h"
#include "esp_log.h"
#include "esp_err.h"

#include "driver/mcpwm_prelude.h"  // new driver

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"


#include "soc/mcpwm_periph.h"
#include "driver/gpio.h"

#include "mcpwm_driver.h"
#include "mcpwm_driver_2.h"

#define MCPWM_TIMER_RESOLUTION_HZ 1000000



void app_main(void){

    uint8_t gpio_num_fwd = 4;
    uint8_t gpio_num_rev = 5;
    uint8_t gpio_num_fwd_2 = 13;
    uint8_t gpio_num_rev_2 = 15;

    uint32_t freq_hz = 50;

    gpio_set_direction(2, GPIO_MODE_OUTPUT);

    mcpwm_driver_init(gpio_num_fwd, gpio_num_rev, freq_hz, 0.0f);
    mcpwm_motor2_init(gpio_num_fwd_2, gpio_num_rev_2, freq_hz, 0.0f);

    while(1){

        float duty_cycle = 100.0f;

        ESP_LOGI("MCPWM", "FORWARD");
        mcpwm_set_motor_direction(true, duty_cycle);
        mcpwm_motor2_set_direction(true, duty_cycle);
        gpio_set_level(2, 1);

        vTaskDelay(pdMS_TO_TICKS(2000));

        gpio_set_level(2, 0);
        ESP_LOGI("MCPWM", "STOP");
        mcpwm_set_motor_direction(true, 0.0f);
        mcpwm_motor2_set_direction(true, 0.0f);
        mcpwm_set_motor_direction(false, 0.0f);
        mcpwm_motor2_set_direction(false, 0.0f);
        vTaskDelay(pdMS_TO_TICKS(1000));

        ESP_LOGI("MCPWM", "REVERSE");
        mcpwm_set_motor_direction(false, duty_cycle);
        mcpwm_motor2_set_direction(false, duty_cycle);

        vTaskDelay(pdMS_TO_TICKS(2000));

        ESP_LOGI("MCPWM", "Right");
        mcpwm_set_motor_direction(true, duty_cycle);
        mcpwm_motor2_set_direction(false, duty_cycle);
        gpio_set_level(2, 1);


        vTaskDelay(pdMS_TO_TICKS(1000));

        gpio_set_level(2, 0);

        ESP_LOGI("MCPWM", "Left");
        mcpwm_set_motor_direction(false, duty_cycle);
        mcpwm_motor2_set_direction(true, duty_cycle);

        vTaskDelay(pdMS_TO_TICKS(1000));

        // mcpwm_set_duty_cycle(duty_cycle);
        // vTaskDelay(pdMS_TO_TICKS(100));

    }
    
}
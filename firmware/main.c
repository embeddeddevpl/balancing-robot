/**
 * @file    main.c
 * @author  Łukasz Łaguna
 * @brief   Main file
 */

#include "stm32f10x.h"

#include "FreeRTOS.h"
#include "task.h"

#include "gpio/gpio.h"

void vLEDTask( void *pvParameters );

int main(void)
{
    /* Hardware configuration */
    gpio_init();

    /* Creating tasks */
    xTaskCreate( vLEDTask, "LEDTask", 100, NULL, 1, NULL );

    /* Start the scheduler */
    vTaskStartScheduler();

    /* Will only get here if there was not enough heap space */
    while(1);

    return 0;
}

void vLEDTask(void *pvParameters) {

    for (;;) {

        GPIOA->ODR ^= 1<<5;
        vTaskDelay( 1000 / portTICK_RATE_MS );
    }

    vTaskDelete(NULL);
}
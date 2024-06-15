// ========================================================
// File    : led.c
// Role    : LED
// Date    : 2024.04.11
// Author  : Osaka Sangyo University
// ========================================================
// --- Header files (system)
#include "sdkconfig.h"
#include "hal/gpio_types.h"
#include "driver/gpio.h"
// --- Header of own file
#include "led.h"

// --- macros
#define LED1	GPIO_NUM_16
#define LED2	GPIO_NUM_17
#define LED3	GPIO_NUM_18
#define LED4	GPIO_NUM_19

// --- functions (extern)
// ========================================================
// Name       : led_init
// Function   : initialize LED
// Parameters : none
// Return     : none
// notes      : call before closed loop
// ========================================================
void led_init(void)
{
	esp_rom_gpio_pad_select_gpio(LED1);
	ESP_ERROR_CHECK(gpio_set_level(LED1, 1U));
	ESP_ERROR_CHECK(gpio_set_direction(LED1, GPIO_MODE_OUTPUT));
	esp_rom_gpio_pad_select_gpio(LED2);
	ESP_ERROR_CHECK(gpio_set_level(LED2, 1U));
	ESP_ERROR_CHECK(gpio_set_direction(LED2, GPIO_MODE_OUTPUT));
	esp_rom_gpio_pad_select_gpio(LED3);
	ESP_ERROR_CHECK(gpio_set_level(LED3, 1U));
	ESP_ERROR_CHECK(gpio_set_direction(LED3, GPIO_MODE_OUTPUT));
	esp_rom_gpio_pad_select_gpio(LED4);
	ESP_ERROR_CHECK(gpio_set_level(LED4, 1U));
	ESP_ERROR_CHECK(gpio_set_direction(LED4, GPIO_MODE_OUTPUT));
	return;
}

// ========================================================
// Name       : led_set
// Function   : set LED
// Parameters : led
//              OFF 0, ON 1
//              set bit0 of led to LED1
//              set bit1 of led to LED2
//              set bit2 of led to LED3
//              set bit3 of led to LED4
// Return     : none
// notes      : none
// ========================================================
void led_set(unsigned char led)
{
	unsigned char	led1;
	unsigned char	led2;
	unsigned char	led3;
	unsigned char	led4;

	led1 = (led & BIT0) ^ BIT0;			// LED1 bit0 of led
	led2 = ((led >> 1U) & BIT0) ^ BIT0;	// LED2 bit1 of led
	led3 = ((led >> 2U) & BIT0) ^ BIT0;	// LED3 bit2 of led
	led4 = ((led >> 3U) & BIT0) ^ BIT0;	// LED4 bit3 of led
	// set each LED
	ESP_ERROR_CHECK(gpio_set_level(LED1, led1));
	ESP_ERROR_CHECK(gpio_set_level(LED2, led2));
	ESP_ERROR_CHECK(gpio_set_level(LED3, led3));
	ESP_ERROR_CHECK(gpio_set_level(LED4, led4));

	return;
}

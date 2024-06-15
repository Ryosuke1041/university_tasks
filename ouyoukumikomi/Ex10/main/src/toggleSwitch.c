// ========================================================
// File    : toggleSwitch.c
// Role    : toggle switch
// Date    : 2024.06.06
// Author  : Osaka Sangyo University
// ========================================================
// --- Header files (system)
#include "sdkconfig.h"
#include "hal/gpio_types.h"
#include "driver/gpio.h"
// --- Header of own file
#include "toggleSwitch.h"

// --- macros
#define TSW1	GPIO_NUM_32
#define TSW2	GPIO_NUM_33
#define TSW3	GPIO_NUM_34
#define TSW4	GPIO_NUM_35

// --- functions (extern)
// ========================================================
// Name       : tsw_init
// Function   : initialize toggle switch
// Parameters : none
// Return     : none
// notes      : call before closed loop
// ========================================================
void tsw_init(void)
{
	esp_rom_gpio_pad_select_gpio(TSW1); 
	ESP_ERROR_CHECK(gpio_set_direction(TSW1, GPIO_MODE_INPUT));
	ESP_ERROR_CHECK(gpio_pullup_en(TSW1));
	esp_rom_gpio_pad_select_gpio(TSW2); 
	ESP_ERROR_CHECK(gpio_set_direction(TSW2, GPIO_MODE_INPUT));
	ESP_ERROR_CHECK(gpio_pullup_en(TSW2));
	esp_rom_gpio_pad_select_gpio(TSW3); 
	ESP_ERROR_CHECK(gpio_set_direction(TSW3, GPIO_MODE_INPUT));
	ESP_ERROR_CHECK(gpio_pullup_en(TSW3));
	esp_rom_gpio_pad_select_gpio(TSW4); 
	ESP_ERROR_CHECK(gpio_set_direction(TSW4, GPIO_MODE_INPUT));
	ESP_ERROR_CHECK(gpio_pullup_en(TSW4));
	return;
}

// ========================================================
// Name       : tsw_get
// Function   : read toggle switch
// Parameters : none
// Return     : tsw (data of toggle switch)
//              OFF 0, ON 1
//              bit0 of tsw is TSW1
//              bit1 of tsw is TSW2
//              bit2 of tsw is TSW3
//              bit3 of tsw is TSW4
// notes      : none
// ========================================================
unsigned char tsw_get(void)
{
	unsigned char	tsw;
	unsigned char	tsw1;
	unsigned char	tsw2;
	unsigned char	tsw3;
	unsigned char	tsw4;

	// read each toggle switch 
	tsw1 = (unsigned char)gpio_get_level(TSW1);
	tsw2 = (unsigned char)gpio_get_level(TSW2);
	tsw3 = (unsigned char)gpio_get_level(TSW3);
	tsw4 = (unsigned char)gpio_get_level(TSW4);
	// set each bit of tsw
	tsw = tsw1;					// bit0
	tsw = tsw | (tsw2 << 1U);	// bit1
	tsw = tsw | (tsw3 << 2U);	// bit2
	tsw = tsw | (tsw4 << 3U);	// bit3

	return tsw;
}

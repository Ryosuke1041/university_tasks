// ========================================================
// File    : pushButton.c
// Role    : Push Buttons (RTOS)
// Date    : 2024.05.16
// Author  : Osaka Sangyo University
// ========================================================
// --- Header files (system)
#include "driver/gpio.h"
#include "hal/gpio_types.h"
// --- Header of own file
#include "pushButton.h"

// --- macros
#define PB1	GPIO_NUM_36
#define PB2	GPIO_NUM_39

// --- functions (extern)
// ========================================================
// Name       : pb_init
// Function   : initialize push buttons
// Parameters : none
// Return     : none
// notes      : call before closed loop and using push buttons
// ========================================================
void pb_init(void)
{
	esp_rom_gpio_pad_select_gpio(PB1); 
	ESP_ERROR_CHECK(gpio_set_direction(PB1, GPIO_MODE_INPUT));
	ESP_ERROR_CHECK(gpio_pullup_dis(PB1));
	ESP_ERROR_CHECK(gpio_pulldown_en(PB1));
	esp_rom_gpio_pad_select_gpio(PB2); 
	ESP_ERROR_CHECK(gpio_set_direction(PB2, GPIO_MODE_INPUT));
	ESP_ERROR_CHECK(gpio_pullup_dis(PB2));
	ESP_ERROR_CHECK(gpio_pulldown_en(PB2));
	// initialize interrupt
	ESP_ERROR_CHECK(gpio_set_intr_type(PB1, GPIO_INTR_POSEDGE));
	ESP_ERROR_CHECK(gpio_set_intr_type(PB2, GPIO_INTR_POSEDGE));
	ESP_ERROR_CHECK(gpio_install_isr_service(0));
	ESP_ERROR_CHECK(gpio_isr_handler_add(PB1, &pb1_isr_handler, NULL));
	ESP_ERROR_CHECK(gpio_isr_handler_add(PB2, &pb2_isr_handler, NULL));
	return;
}

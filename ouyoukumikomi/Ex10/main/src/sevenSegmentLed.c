// ========================================================
// File    : sevenSegmentLed.c
// Role    : seven segment LED
// Date    : 2024.04.11
// Author  : Osaka Sangyo University
// ========================================================
// --- Header files (system)
#include "sdkconfig.h"
#include "hal/gpio_types.h"
#include "driver/gpio.h"
// --- Header of own file
#include "sevenSegmentLed.h"

// --- macros
#define SV_HEXADECIMAL	16
#define SV_DS			GPIO_NUM_0
#define SV_SHCP			GPIO_NUM_2
#define SV_STCP			GPIO_NUM_4
#define SV_PATTERN_MAX	20
#define SV_SEGMENTS		8
#define SV_NUMBER		2

// --- data (static)
static const unsigned char sv_number_to_pattern[SV_PATTERN_MAX]
= {
	0xC0U,	// 0	abcdef
	0xF9U,	// 1	 bc
	0xA4U,	// 2	ab def
	0xB0U,	// 3	abcd  g
	0x99U,	// 4	 bc  fg
	0x92U,	// 5	a cd fg
	0x82U,	// 6	a cdefg
	0xF8U,	// 7	abc
	0x80U,	// 8	abcdefg
	0x90U,	// 9	abcd fg
	0x88U,	// A	abc efg
	0x83U,	// b	  cdefg
	0xC6U,	// C	a  de g
	0xA1U,	// d	 bcde g
	0x86U,	// E	a  defg
	0x8EU,	// F	a   efg
	0x00U	// not digit
};

// --- prototypes (static)
static void	sv_set(unsigned char pattern);
static void sv_fix(void);

// --- functions (extern)
// ========================================================
// Name       : sv_init
// Function   : initialize seven segment LED
// Parameters : none
// Return     : none
// notes      : call before closed loop
// ========================================================
void sv_init(void)
{
	unsigned char	i;
	unsigned char	j;

	esp_rom_gpio_pad_select_gpio(SV_DS);
	ESP_ERROR_CHECK(gpio_set_level(SV_DS, 1U));
	ESP_ERROR_CHECK(gpio_set_direction(SV_DS, GPIO_MODE_OUTPUT));
	esp_rom_gpio_pad_select_gpio(SV_SHCP);
	ESP_ERROR_CHECK(gpio_set_level(SV_SHCP, 0U));
	ESP_ERROR_CHECK(gpio_set_direction(SV_SHCP, GPIO_MODE_OUTPUT));
	esp_rom_gpio_pad_select_gpio(SV_STCP);
	ESP_ERROR_CHECK(gpio_set_level(SV_STCP, 0U));
	ESP_ERROR_CHECK(gpio_set_direction(SV_STCP, GPIO_MODE_OUTPUT));
	// seven segments all off
	for (i = 0; i < SV_NUMBER; ++i) {
		for (j = 0; j < SV_SEGMENTS; ++j) {
			ESP_ERROR_CHECK(gpio_set_level(SV_DS, 1U));
			ESP_ERROR_CHECK(gpio_set_level(SV_SHCP, 0U));
			ESP_ERROR_CHECK(gpio_set_level(SV_SHCP, 1U));
		}
		ESP_ERROR_CHECK(gpio_set_level(SV_STCP, 0U));
		ESP_ERROR_CHECK(gpio_set_level(SV_STCP, 1U));
	}

	return;
}

// ========================================================
// Name       : sv_hexadecimal
// Function   : display hexadecimal number on 7-segment LED
// Parameters : number
// Return     : none
// notes      : none
// ========================================================
void sv_hexadecimal(unsigned char number)
{
	unsigned char	num_1;
	unsigned char	num_x10;
	unsigned char	lower;
	unsigned char	upper;

	num_1 = number % SV_HEXADECIMAL;
	lower = sv_number_to_pattern[num_1];
	num_x10 = (number / SV_HEXADECIMAL) % SV_HEXADECIMAL;
	upper = sv_number_to_pattern[num_x10];
	sv_set(upper);
	sv_set(lower);
	sv_fix();

	return;
}

// --- functions (static)
// ========================================================
// Name       : sv_set
// Function   : output pattern on seven segment LED
// Parameters : pat
// Return     : none
// notes      : none
// ========================================================
static void sv_set(unsigned char pattern)
{
	unsigned char	i;

	for (i = 0; i < SV_SEGMENTS; ++i) {
		uint32_t	level;

		level = (pattern & (0x01U << (7 - i))) >> (7 - i);
		ESP_ERROR_CHECK(gpio_set_level(SV_DS, level));
		ESP_ERROR_CHECK(gpio_set_level(SV_SHCP, 0U));
		ESP_ERROR_CHECK(gpio_set_level(SV_SHCP, 1U));
	}

	return;
}

// ========================================================
// Name       : sv_fix
// Function   : output from shift register to seven segment LED
// Parameters : none
// Return     : none
// notes      : none
// ========================================================
static void sv_fix(void)
{
	ESP_ERROR_CHECK(gpio_set_level(SV_STCP, 0U));
	ESP_ERROR_CHECK(gpio_set_level(SV_STCP, 1U));
	return;
}

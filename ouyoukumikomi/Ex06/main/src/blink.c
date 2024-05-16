// ========================================================
// File    : blink.c
// Role    : LED blinking
// Date    : 2024.04.18
// Author  : Osaka Sangyo University
// ========================================================
// --- Header files (project)
#include "led.h"
// --- Header of own file
#include "blink.h"

// --- macros
#define BL_INIT		0x05U
#define LOWER_4BIT	0x0FU

// --- data (static)
static unsigned char	bl_pattern;

// --- functions (extern)
// ========================================================
// Name       : bl_init
// Function   : initialize LED blinking
// Parameters : none
// Return     : none
// notes      : none
// ========================================================
void bl_init(void)
{
	bl_pattern = BL_INIT;
	led_set(bl_pattern);
	return;
}

// ========================================================
// Name       : bl_blink
// Function   : LED blinking
// Parameters : none
// Return     : none
// notes      : none
// ========================================================
void bl_blink(void)
{
	bl_pattern = bl_pattern ^ LOWER_4BIT;
	led_set(bl_pattern);
	return;
}

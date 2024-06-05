// ========================================================
// File    : countLed.c
// Role    : count and display on LED
// Update  : 2024.05.30
// Date    : 2024.05.16
// Author  : Osaka Sangyo University
// ========================================================
// --- Header files (project)
#include "led.h"
// --- Header of own file
#include "countLed.h"

// --- macros
#define CT_OVER	0x10U

// --- data (static)
static unsigned char	ct_counter;	// 0 - 15 (0x0F)

// --- functions (extern)
// ========================================================
// Name       : ct_init
// Function   : initialize counting
// Parameters : none
// Return     : none
// notes      : none
// ========================================================
void ct_init(void)
{
	ct_counter = 0U;
	led_set(ct_counter);
	return;
}

// ========================================================
// Name       : ct_increment
// Function   : increment ct_counter
// Parameters : none
// Return     : none
// notes      : none
// ========================================================
void ct_increment(void)
{
	ct_counter = (ct_counter + 1) % CT_OVER;
	led_set(ct_counter);
	return;
}

// ========================================================
// Name       : ct_decrement
// Function   : increment ct_counter
// Parameters : none
// Return     : none
// notes      : none
// ========================================================
void ct_decrement(void)
{
	ct_counter = (ct_counter - 1) % CT_OVER;
	led_set(ct_counter);
	return;
}

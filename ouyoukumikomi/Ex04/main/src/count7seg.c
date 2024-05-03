// ========================================================
// File    : count7seg.c
// Role    : counting and display on 7segment LED
// Update  : 2024.05.02 for Ex03
// Date    : 2024.05.02
// Author  : Osaka Sangyo University
// ========================================================
// --- Header files (system)
#include <stdio.h>
// --- Header files (project)
#include "sevenSegmentLed.h"
#include "led.h"
// --- Header of own file
#include "count7seg.h"

// --- macros
#define CT_OVER	0x10U

// --- data (static)
static unsigned char	ct_upper;
static unsigned char	ct_lower;

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
	unsigned char	counter;

	ct_lower = 0U;
	ct_upper = 0U;
	counter = ct_lower | (ct_upper << 4U);
	sv_hexadecimal(counter);

	return;
}

// ========================================================
// Name       : ct_increment
// Function   : counting
// Parameters : none
// Return     : none
// notes      : none
// ========================================================
void ct_increment(void)
{
	unsigned char	counter;

	ct_lower = (ct_lower + 1U) % CT_OVER;
	counter = ct_lower | (ct_upper << 4U);
	sv_hexadecimal(counter);

	return;
}

// ========================================================
// Name       : ct_decrement
// Function   : decrement
// Parameters : none
// Return     : none
// notes      : none
// ========================================================
void ct_decrement(void)
{
	unsigned char	counter;

	ct_upper = (ct_upper - 1U) % CT_OVER;
	counter = ct_lower | (ct_upper << 4U);
	sv_hexadecimal(counter);

	return;
}

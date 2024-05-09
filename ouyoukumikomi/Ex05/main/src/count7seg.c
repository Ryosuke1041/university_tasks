// ========================================================
// File    : count7seg.c
// Role    : counting and display on 7segment LED
// Update  : 2024.05.09 for Ex05
// Update  : 2024.05.02 for Ex04
// Date    : 2024.05.02
// Author  : Osaka Sangyo University
// ========================================================
// --- Header files (system)
#include <stdio.h>
// --- Header files (project)
#include "sevenSegmentLed.h"
// --- Header of own file
#include "count7seg.h"

// --- macros
#define CT_OVER	0x100U

// --- data (static)
static unsigned char	ct_counter;

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
	sv_hexadecimal(ct_counter);
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
	ct_counter = (ct_counter + 1U) % CT_OVER;
	sv_hexadecimal(ct_counter);
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
	ct_counter = (ct_counter - 1U) % CT_OVER;
	sv_hexadecimal(ct_counter);
	return;
}

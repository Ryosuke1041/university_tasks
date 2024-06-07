// ========================================================
// File    : countLed.c
// Role    : count and display on LED
// Update  : 2024.06.06 state transition
// Date    : 2024.05.16
// Author  : your ID number and name
// ========================================================
// --- Header files (project)
#include "led.h"
// --- Header of own file
#include "countLed.h"

// --- macros
#define CT_OVER	0x10U

// --- types
typedef enum {
	eCT_STOP,
	eCT_RUN
} ct_state_t;

// --- data (static)
static unsigned char	ct_counter;	// 0 - 15 (0x0F)
static ct_state_t		ct_state;

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
	ct_state = eCT_RUN;
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
	// *** challenge
	ct_counter = (ct_counter + 1) % CT_OVER;
	led_set(ct_counter);
	return;
}

// ========================================================
// Name       : ct_startstop
// Function   : start counting / stop counting
// Parameters : none
// Return     : none
// notes      : none
// ========================================================
void ct_startstop(void)
{
	// *** challenge
	return;
}

// ========================================================
// File    : character.c
// Role    : print a character on LCD
// Date    : 2024.06.13
// Author  : Osaka Sangyo University
// ========================================================
// --- Header files (system)
#include <stdbool.h>
// --- Header files (project)
#include "./lcd/printLcd.h"
// --- Header of own file
#include "character.h"

// --- macros
#define CR_SIZE		2
#define CR_START	' '
#define CR_LAST		'~'	// try 0xFF

// --- functions (extern)
// ========================================================
// Name       : cr_init
// Function   : clear LCD
// Parameters : none
// Return     : none
// notes      : none
// ========================================================
void cr_init(void)
{
	pr_lcd_clear();
	return;
}

// ========================================================
// Name       : cr_character
// Function   : print a character
// Parameters : character code
// Return     : none
// notes      : none
// ========================================================
void cr_character(unsigned char c)
{
	pr_lcd_clear();
	if ((c >= CR_START) && (c <= CR_LAST)) {
		pr_lcd_putchar(c);
	} else {
		pr_lcd_puts("not ascii char");
	}
	return;
}

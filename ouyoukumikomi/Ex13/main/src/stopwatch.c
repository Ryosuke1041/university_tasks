// ========================================================
// File    : stopwatch.c
// Role    : stopwatch
// Date    : 2024.07.04
// Author  : your ID number and name
// ========================================================
// --- Header files (project)
#include "./lcd/printLcd.h"
// --- Header of own file
#include "stopwatch.h"

// --- macros
#define SW_OVER		10U	// *** challenge
#define SW_LENGTH	16U
#define SW_SIZE		(SW_LENGTH + 1)
#define SW_INDEX_1	1U
#define SW_INDEX_10	0U

// --- data (static)
static unsigned char	sw_counter;		// 0 - (SW_OVER - 1)
static const char		sw_author[SW_SIZE] = "";	// *** Step1:your id number
static char				sw_string[SW_SIZE] = "                ";

// --- prototypes (static)
static void sw_print(void);

// --- functions (extern)
// ========================================================
// Name       : sw_init
// Function   : initialize stopwatch
// Parameters : none
// Return     : none
// notes      : none
// ========================================================
void sw_init(void)
{
	pr_lcd_init();
	pr_lcd_setcursor(PR_LCD_LEFT, PR_LCD_LOWER);
	pr_lcd_puts(sw_author);
	sw_counter = 0U;
	sw_print();
	return;
}

// ========================================================
// Name       : sw_count
// Function   : increment sw_counter
// Parameters : none
// Return     : none
// notes      : none
// ========================================================
void sw_count(void)
{
	sw_counter = (sw_counter + 1) % SW_OVER;
	sw_print();
	return;
}

// --- functions (static)
// ========================================================
// Name       : sw_print
// Function   : print counter on LCD
// Parameters : none
// Return     : none
// notes      : none
// ========================================================
static void sw_print(void)
{
	sw_string[SW_INDEX_10] = '0';	// *** challenge
	sw_string[SW_INDEX_1] = '0' + (sw_counter % 10U);
	pr_lcd_setcursor(PR_LCD_LEFT, PR_LCD_UPPER);
	pr_lcd_puts(sw_string);
	return;
}

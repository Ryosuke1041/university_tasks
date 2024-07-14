// ========================================================
// File    : printLcd.c
// Role    : print on LCD
// Update  : 2024.06.20
// Date    : 2024.06.13
// Author  : Osaka Sangyo University
// ========================================================
// --- Header files (system)
#include <stdio.h>
#include <stdbool.h>
#include "driver/gptimer.h"
// --- Header files (project)
#include "timerPrint.h"
#include "lcd.h"
// --- Header of own file
#include "printLcd.h"
#include "printLcdImpr.h"

// --- macros
#define PR_LCD_COLUMNS		16U
#define PR_LCD_LINES		2U
#define PR_LCD_BUFFER_SIZE	160U
#define PR_LCD_COMMAND		'\x1b'
#define PR_LCD_WAIT_LONG	(1600U + 100U)	// over 1530 microsecond
#define PR_LCD_WAIT_SHORT	(100U + 100U)	// over 39 microsecond
#define PR_LCD_LOCALBUFFER	3U

// --- data (static)
static unsigned char	pr_lcd_buffer[PR_LCD_BUFFER_SIZE];
static unsigned int		pr_lcd_write;
static unsigned int		pr_lcd_read;

// --- prototypes (static)
static int	pr_lcd_getchar(void);
static bool	pr_lcd_empty(void);
static void	pr_lcd_outdata(void);

// --- functions (extern)
// ========================================================
// Name       : pr_lcd_init
// Function   : initialize printLcd
// Parameters : none
// Return     : none
// notes      : none
// ========================================================
void pr_lcd_init(void)
{
	pr_lcd_write = 0U;
	pr_lcd_read = 0U;
	return;
}

// ========================================================
// Name       : pr_lcd_putchar
// Function   : print character on LCD (interface)
// Parameters : character
// Return     : none
// notes      : none
// ========================================================
void pr_lcd_putchar(int c)
{
	char	buf[PR_LCD_LOCALBUFFER];

	buf[0] = (char)c;
	buf[1] = '\0';
	pr_lcd_puts(buf);

	return;
}

// ========================================================
// Name       : pr_lcd_puts
// Function   : print string on LCD
// Parameters : string (terminated by null character)
// Return     : none
// notes      : none
// ========================================================
void pr_lcd_puts(const char s[])
{
	pr_lcd_puts_send(s);
	return;
}

// ========================================================
// Name       : pr_lcd_clear
// Function   : clear LCD
// Parameters : none
// Return     : none
// notes      : none
// ========================================================
void pr_lcd_clear(void)
{
	char	buf[PR_LCD_LOCALBUFFER];

	buf[0] = PR_LCD_COMMAND;
	buf[1] = LCD_CLEAR_DISPLAY;
	buf[2] = '\0';
	pr_lcd_puts_send(buf);

	return;
}

// ========================================================
// Name       : pr_lcd_setcursor
// Function   : set cursor on LCD
// Parameters : column and line
// Return     : none
// notes      : none
// ========================================================
void pr_lcd_setcursor(unsigned int column, unsigned int line)
{
	char	buf[PR_LCD_LOCALBUFFER];

	column %= PR_LCD_COLUMNS;
	line %= PR_LCD_LINES;
	if (line != 0U) {
		line = LCD_SET_DDRAM_LINE2;
	}
	buf[0] = PR_LCD_COMMAND;
	buf[1] = LCD_SET_DDRAM_ADDR | line | column;
	buf[2] = '\0';
	pr_lcd_puts_send(buf);

	return;
}

// ========================================================
// Name       : pr_lcd_output
// Function   : output from buffer to LCD
// Parameters : none
// Return     : none
// notes      : none
// ========================================================
void pr_lcd_output(void)
{
	tm_check();
	if (tm_ready() == true) {
		if (pr_lcd_empty() != true) {	// buffer is not empty
			pr_lcd_outdata();
		}
	}
	return;
}

// ========================================================
// Name       : pr_lcd_puts_impr
// Function   : print character on LCD (imprement)
// Parameters : character
// Return     : none
// notes      : none
// ========================================================
void pr_lcd_puts_impr(const char s[])
{
	unsigned int	i;
	unsigned int	next;

	for (i = 0U; i < PR_LCD_COLUMNS; ++i) {
		if (s[i] == '\0') {
			break;
		}
		next = (pr_lcd_write + 1) % PR_LCD_BUFFER_SIZE;
		if (next != pr_lcd_read) {
			pr_lcd_buffer[pr_lcd_write] = s[i];
			pr_lcd_write = next;
		} else {	// buffer full
			puts("pr_lcd_puts_impr: buffer full");
		}
	}

	return;
}

// --- functions (static)
// ========================================================
// Name       : pr_lcd_getchar
// Function   : read buffer
// Parameters : none
// Return     : data / '\0' empty
// notes      : none
// ========================================================
static int pr_lcd_getchar(void)
{
	int	data = '\0';

	if (pr_lcd_read != pr_lcd_write) {	// not empty
		data = (int) pr_lcd_buffer[pr_lcd_read];
		pr_lcd_read = (pr_lcd_read + 1) % PR_LCD_BUFFER_SIZE;
	}

	return data;
}

// ========================================================
// Name       : pr_lcd_empty
// Function   : buffer is empty or not
// Parameters : none
// Return     : true empty / false data exist
// notes      : none
// ========================================================
static bool pr_lcd_empty(void)
{
	bool	empty = false;

	if (pr_lcd_read == pr_lcd_write) {
		empty = true;
	}

	return empty;
}

// ========================================================
// Name       : pr_lcd_outdata
// Function   : output data or commands to LCD
// Parameters : none
// Return     : none
// notes      : call when LCD is not busy
// ========================================================
static void pr_lcd_outdata(void)
{
	int			data;
	uint32_t	wait = 0U;

	data = pr_lcd_getchar();
	if (data == '\0') {
		printf("pr_lcd_outdata: data not exist\n");
	} else if (data == PR_LCD_COMMAND) {
		data = pr_lcd_getchar();
		lcd_command(data);
		if ((data == LCD_CLEAR_DISPLAY) || (data == LCD_RETURN_HOME)) {
			wait = PR_LCD_WAIT_LONG;
		} else {
			wait = PR_LCD_WAIT_SHORT;
		}
	} else {
		lcd_data(data);
		wait = PR_LCD_WAIT_SHORT;
	}
	tm_busy(wait);

	return;
}

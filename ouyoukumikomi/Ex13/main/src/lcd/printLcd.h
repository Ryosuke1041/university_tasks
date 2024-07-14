// ========================================================
// File    : printLcd.h
// Role    : print on LCD
// Update  : 2024.06.20
// Date    : 2024.06.13
// Author  : Osaka Sangyo University
// ========================================================
#ifndef PRINT_LCD_H
#define PRINT_LCD_H

// --- macros
#define PR_LCD_LEFT		0U
#define PR_LCD_UPPER	0U
#define PR_LCD_LOWER	1U

// --- prototypes (extern)
extern void	pr_lcd_init(void);
extern void	pr_lcd_putchar(int c);
extern void	pr_lcd_puts(const char s[]);
extern void	pr_lcd_clear(void);
extern void	pr_lcd_setcursor(unsigned int column, unsigned int line);
extern void	pr_lcd_output(void);

#endif	// PRINT_LCD_H

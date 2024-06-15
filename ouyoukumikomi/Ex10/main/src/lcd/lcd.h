// ========================================================
// File    : lcd.h
// Role    : LCD
// Date    : 2023.12.13
// Author  : Osaka Sangyo University
// ========================================================
#ifndef LCD_H
#define LCD_H

// --- macros
#define LCD_SET_DDRAM_ADDR	0x80U	// Set DDRAM address
#define LCD_SET_DDRAM_LINE2	0x40U	// 2nd line 40H - 67H (1st line 00H - 27H)
#define LCD_CLEAR_DISPLAY	0x01U	// Clear entire display and sets DDRAM address 0
#define LCD_RETURN_HOME		0x02U	// Set DDRAM address 0

// --- prototypes (extern)
extern void lcd_init(void);
extern void lcd_command(unsigned char cmd);
extern void lcd_data(unsigned char data);

#endif	// LCD_H

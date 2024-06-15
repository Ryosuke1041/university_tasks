// ========================================================
// File    : lcdHard.h
// Role    : LCD (LCD1602)
// Date    : 2024.06.27
// Author  : Osaka Sangyo University
// ========================================================
#ifndef LCD_HARD_H
#define LCD_HARD_H

// --- macros
#define LCD_X_SIZE		(16U)	// LCD1602
#define LCD_Y_SIZE		(2U)

#define LCD_ENTRY_MODE_SET	(1U<<2U)		// Set cursor move direction and specifies display shift
#define LCD_EMODE_INC		(1U<<1U)
#define LCD_EMODE_DEC		(0U<<1U)
#define LCD_EMODE_SHIFT		(1U<<0U)
#define LCD_EMODE_NOSFT		(0U<<0U)

#define LCD_DISP_ONOFF_CTRL	(1U<<3U)		// Set entire display on/off, cursor on/off
											// and blinking of cursor position character
#define LCD_DISP_ON			(1U<<2U)
#define LCD_DISP_OFF		(0U<<2U)
#define LCD_DISP_CUR_ON		(1U<<1U)
#define LCD_DISP_CUR_OFF	(0U<<1U)
#define LCD_DISP_BLINK		(1U<<0U)
#define LCD_DISP_NOBLINK	(0U<<0U)

#define LCD_CUR_DISP_SHIFT	(1U<<4U)		// Move cursor and shifts display
#define LCD_SHIFT_L_CUR		(0U<<2U)
#define LCD_SHIFT_R_CUR		(1U<<2U)
#define LCD_SHIFT_L_DSP		(2U<<2U)
#define LCD_SHIFT_R_DSP		(3U<<2U)

#define LCD_FUNCSION_SET	(1U<<5U)	// Set interface data length, number of display lines
										// and character font
#define LCD_SET_IF_8		(1U<<4U)	
#define LCD_SET_IF_4		(0U<<4U)
#define LCD_SET_2LINES		(1U<<3U)
#define LCD_SET_1LINE		(0U<<3U)
#define LCD_SET_BIG			(1U<<2U)
#define LCD_SET_SMALL		(0U<<2U)

#define LCD_SET_CGADDR		(1U<<6U)	// Set CGRAM address

#endif	// LCD_HARD_H

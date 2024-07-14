// ========================================================
// File    : lcd.c
// Role    : LCD
// Date    : 2024.06.13
// Author  : Osaka Sangyo University
// ========================================================
// --- Header files (system)
#include <stdbool.h>
#include "driver/gpio.h"
#include "hal/gpio_types.h"
#include "driver/i2c.h"
// --- Header of own file
#include "lcdHard.h"
#include "lcd.h"

// --- macros
// I2C
#define I2C_MASTER_SCL_IO			GPIO_NUM_23	// GPIO number used for I2C master clock
#define I2C_MASTER_SDA_IO			GPIO_NUM_22	// GPIO number used for I2C master data
#define I2C_MASTER_NUM				I2C_NUM_0	// I2C master i2c port number, the number of i2c peripheral interfaces available will depend on the chip */
#define I2C_MASTER_FREQ_HZ			100000U		// I2C master clock frequency
#define I2C_MASTER_TX_BUF_DISABLE	0U			// I2C master doesn't need buffer
#define I2C_MASTER_RX_BUF_DISABLE	0U			// I2C master doesn't need buffer
#define I2C_MASTER_TIMEOUT_MS		100U		// I2C master timeout
#define LCD_DATA_LENGTH_W			2U			// I2C master size of the write buffer
#define LCD_DATA_LENGTH_R           1U			// I2C master size of the read buffer
//LCD
#define LCD_I2C_ADDRESS	0x3EU
#define LCD_CTL_WINST	0x00U	// write instruction (off bit6)
#define LCD_CTL_WDATA	0x40U	// write data (set bit6)
#define LCD_CTL_RBUSY	0x00U	// read busy flag (off bit6)
#define LCD_CTL_RDATA	0x40U	// read data (set bit6)

// --- prototypes (static)
static void lcd_init_i2c(void);
static void lcd_init_display(void);
static void lcd_delay_microseconds(unsigned long tim);
static void lcd_delay_milliseconds(unsigned long tim);

// --- functions (extern)
// ========================================================
// Name       : lcd_init
// Function   : initialize LCD
// Parameters : none
// Return     : none
// notes      : call before closed loop
// ========================================================
void lcd_init(void)
{
	lcd_init_i2c();
	lcd_init_display();
	return;
}

// ========================================================
// Name       : lcd_data
// Function   : sending data
// Parameters : data
// Return     : none
// notes      : none
// ========================================================
void lcd_data(unsigned char data)
{
	uint8_t data_wr[LCD_DATA_LENGTH_W];

	data_wr[0] = LCD_CTL_WDATA;
	data_wr[1] = data;
	ESP_ERROR_CHECK(i2c_master_write_to_device(
		I2C_MASTER_NUM,
		LCD_I2C_ADDRESS,
		data_wr,
		sizeof(data_wr),
		I2C_MASTER_TIMEOUT_MS / portTICK_PERIOD_MS
	));
	return;
}

// ========================================================
// Name       : lcd_command
// Function   : sending command
// Parameters : command
// Return     : none
// notes      : none
// ========================================================
void lcd_command(unsigned char cmd)
{
	uint8_t data_wr[LCD_DATA_LENGTH_W];

	data_wr[0] = LCD_CTL_WINST;
	data_wr[1] = cmd;
	ESP_ERROR_CHECK(i2c_master_write_to_device(
		I2C_MASTER_NUM,
		LCD_I2C_ADDRESS,
		data_wr,
		sizeof(data_wr),
		I2C_MASTER_TIMEOUT_MS / portTICK_PERIOD_MS
	));
	return;
}

// --- functions (static)
// ========================================================
// Name       : lcd_init_i2c
// Function   : initialize i2c for LCD
// Parameters : none
// Return     : none
// notes      : call before closed loop
// ========================================================
static void lcd_init_i2c(void)
{
	// Allocate an I2C master bus.
	i2c_config_t conf;

	conf.mode = I2C_MODE_MASTER;
	conf.sda_io_num = I2C_MASTER_SDA_IO;
	conf.sda_pullup_en = GPIO_PULLUP_DISABLE;
	conf.scl_io_num = I2C_MASTER_SCL_IO;
	conf.scl_pullup_en = GPIO_PULLUP_DISABLE;
	conf.master.clk_speed = I2C_MASTER_FREQ_HZ;
	conf.clk_flags = 0;
	// Configure an I2C bus with the given configuration.
	ESP_ERROR_CHECK(i2c_param_config(I2C_MASTER_NUM, &conf));
	// Install an I2C driver.
	ESP_ERROR_CHECK(i2c_driver_install(
		I2C_MASTER_NUM,
		conf.mode,
		I2C_MASTER_RX_BUF_DISABLE,
		I2C_MASTER_TX_BUF_DISABLE,
		0
	));
	return;
}

// ========================================================
// Name       : lcd_init_display
// Function   : initialize LCD Display
// Parameters : none
// Return     : none
// notes      : call before closed loop
// ========================================================
static void lcd_init_display(void)
{
	lcd_delay_milliseconds(15U);

	// Function Set
	lcd_command(LCD_FUNCSION_SET | LCD_SET_IF_8 | LCD_SET_2LINES | LCD_SET_SMALL);
	lcd_delay_microseconds(40U);

	// Dispay ON/OFF Control
	lcd_command(LCD_DISP_ONOFF_CTRL | LCD_DISP_OFF | LCD_DISP_CUR_OFF | LCD_DISP_NOBLINK);
	lcd_delay_microseconds(40U);

	// Display Clear
	lcd_command(LCD_CLEAR_DISPLAY);
	lcd_delay_milliseconds(2U);
	
	// Entry Mode Set
	lcd_command(LCD_ENTRY_MODE_SET | LCD_EMODE_INC | LCD_EMODE_NOSFT);
	lcd_delay_microseconds(40U);

	// Dispay ON/OFF Control
	lcd_command(LCD_DISP_ONOFF_CTRL | LCD_DISP_ON | LCD_DISP_CUR_OFF | LCD_DISP_NOBLINK);
	lcd_delay_microseconds(40U);
	return;
}

// ========================================================
// Name       : lcd_delay_milliseconds
// Function   : delay
// Parameters : tim (milliseconds)
// Return     : none
// notes      : about
// ========================================================
static void lcd_delay_milliseconds(unsigned long tim)
{
	volatile unsigned long	i;

	for (i = 0U; i < tim; ++i) {
		lcd_delay_microseconds(1000U);
	}

	return;
}

// ========================================================
// Name       : lcd_delay_microseconds
// Function   : delay
// Parameters : tim (microseconds)
// Return     : none
// notes      : abuot
// ========================================================
inline void lcd_delay_microseconds(unsigned long tim)
{
	unsigned long	i;

	for (i = 0U; i < tim; ++i) {
		volatile unsigned char	cnt;

		for (cnt = 0; cnt < 7U; ++cnt) {
		}
	}

	return;
}

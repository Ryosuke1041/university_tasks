// ========================================================
// File    : task.c
// Role    : Ex03 create task
// Date    : 2024.04.25
// Author  : your ID number and name
// Notes   : none
// ========================================================
// --- Header files (system)
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
// --- Header files (project)
#include "led.h"
#include "sevenSegmentLed.h"
#include "blink.h"

// --- macros
#define STACK_DEPTH		((uint32_t) 4096)
#define PRIORITY_BLINK	(tskIDLE_PRIORITY + 1)
#define DELAY_BLINK		pdMS_TO_TICKS(1000)

// --- data (static)
static TaskHandle_t		taskHandleBlink = NULL;

// --- prototypes (static)
static void	taskBlink(void *arg);
static void	initialize(void);

// --- app_main function
// ========================================================
// Name       : app_main
// Function   : create tasks
// Parameters : none
// Return     : none
// notes      : called from Main Task
// ========================================================
void app_main(void)
{
	BaseType_t	pass;

	// initialize devices
	initialize();
	// create task
	pass = xTaskCreate(
				&taskBlink,
				"taskBlink",
				STACK_DEPTH,
				NULL,
				PRIORITY_BLINK,
				&taskHandleBlink
			);
	if (pass != pdPASS) {
		puts("cannot create taskBlink\n");
	}
	return;
}

// --- task functions
// ========================================================
// Name       : taskBlink
// Function   : blinking LED
// Parameters : informations
// Return     : none
// notes      : none
// ========================================================
static void taskBlink(void *arg)
{
	bl_init();
	for (;;) {	// closed loop
		// *** Hint:1 second (or 500 millisecond) delay
		// *** Hint:call function 'bl_blink'
	}
}

// --- functions (static)
// ========================================================
// Name       : initialize
// Function   : initialize devices
// Parameters : none
// Return     : none
// notes      : call before creating tasks
// ========================================================
static void initialize(void)
{
	led_init();
	sv_init();
	return;
}
// ========================================================
// File    : task.c
// Role    : Ex04 tasks
// Date    : 2024.05.02
// Author  : 22H062 中江亮介
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
#include "count7seg.h"

// --- macros
#define STACK_DEPTH			((uint32_t) 4096)
#define PRIORITY_BLINK		(tskIDLE_PRIORITY + 1)	// lower
#define PRIORITY_INCREMENT	(tskIDLE_PRIORITY + 2)	// higher
#define PRIORITY_DECREMENT	(tskIDLE_PRIORITY + 1)	// lower
#define DELAY_BLINK			pdMS_TO_TICKS(1000)
#define DELAY_INCREMENT		pdMS_TO_TICKS(250)
#define DELAY_DECREMENT		pdMS_TO_TICKS(2000)

// --- data (static)
static TaskHandle_t			taskHandleBlink = NULL;
static TaskHandle_t			taskHandleIncrement = NULL;
static TaskHandle_t			taskHandleDecrement = NULL;

// --- prototypes (static)
static void	taskBlink(void *arg);
static void	taskIncrement(void *arg);
static void	taskDecrement(void *arg);
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
	// create tasks
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
	} else {
		pass = xTaskCreate(
					/*** Hint:task function */&taskBlink,
					"taskIncrement",
					STACK_DEPTH,
					NULL,
					PRIORITY_INCREMENT,
					&taskHandleIncrement
				);
		if (pass != pdPASS) {
			puts("cannot create taskIncrement\n");
		} else {
			// *** Hint:challenge
		}
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
	// monitor
	TaskHandle_t handle = xTaskGetCurrentTaskHandle();
	char* taskname = pcTaskGetName(handle);
	puts(taskname);

	bl_init();
	for (;;) {	// closed loop
		// *** Hint:delay
		// *** Hint:blink
	}
}

// ========================================================
// Name       : taskIncrement
// Function   : increment (7 segment LED)
// Parameters : informations
// Return     : none
// notes      : none
// ========================================================
static void taskIncrement(void *arg)
{
	// monitor
	TaskHandle_t handle = xTaskGetCurrentTaskHandle();
	char* taskname = pcTaskGetName(handle);
	puts(taskname);

	ct_init();
	for (;;) {	// closed loop
		// *** Hint:delay
		// *** Hint:increment
	}
}

// ========================================================
// Name       : taskDecrement
// Function   : decrement (7 segment LED)
// Parameters : informations
// Return     : none
// notes      : none
// ========================================================
static void taskDecrement(void *arg)
{
	// monitor
	TaskHandle_t handle = xTaskGetCurrentTaskHandle();
	char* taskname = pcTaskGetName(handle);
	puts(taskname);

	// *** Hint:challenge
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

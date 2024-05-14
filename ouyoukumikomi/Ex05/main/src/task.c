// ========================================================
// File    : task.c
// Role    : Ex05 software timer
// Date    : 2024.05.09
// Author  : your ID number and name
// Notes   : none
// ========================================================
// --- Header files (system)
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/timers.h"
// --- Header files (project)
#include "sevenSegmentLed.h"
#include "count7seg.h"

// --- macros
// task
#define STACK_DEPTH			((uint32_t) 4096)
#define PRIORITY_INCREMENT	(tskIDLE_PRIORITY + 1)
// timer
#define PERIOD_INCREMENT	pdMS_TO_TICKS(1000)
// notify
#define CLEAR_NONE			((uint32_t) 0)
#define TICKS_TO_WAIT		pdMS_TO_TICKS(1000 * 10)
#define VALUE_NONE			((uint32_t) 0)

// --- data (static)
static TaskHandle_t		taskHandleIncrement = NULL;
static TimerHandle_t	timerHandleIncrement = NULL;
static uint8_t counter = 0;

// --- prototypes (static)
static void	taskIncrement(void *arg);
static void	callbackIncrement(TimerHandle_t timer);
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
		&taskIncrement,
		"taskIncrement",
		STACK_DEPTH,
		NULL,
		PRIORITY_INCREMENT,
		&taskHandleIncrement
	);
	if (pass != pdPASS) {
		puts("cannot create taskIncrement\n");
	} else {
		// create timer
		timerHandleIncrement = xTimerCreate(
			"timerIncrement",
			PERIOD_INCREMENT,
			pdTRUE,
			NULL,
			&callbackIncrement
		);
		if (timerHandleIncrement == NULL) {
			puts("cannot create timerIncrement");
		} else {
			pass = xTimerStart(timerHandleIncrement, 0);
			if (pass != pdPASS) {
				puts("cannot start timerIncrement");
			}
		}
	}
	return;
}

// --- task functions
// ========================================================
// Name       : taskIncrement
// Function   : increment counter
// Parameters : informations
// Return     : none
// notes      : none
// ========================================================
static void taskIncrement(void *arg)
{
	// monitor
	TaskHandle_t	handle = xTaskGetCurrentTaskHandle();
	char*			taskname = pcTaskGetName(handle);
	puts(taskname);

	ct_init();
	for (;;) {	// closed loop
		BaseType_t	pd;

		pd = xTaskNotifyWait(
			CLEAR_NONE,
			CLEAR_NONE,
			NULL,
			TICKS_TO_WAIT
		);
		if (pd != pdPASS) {
			puts("not notified");
		} else {
			counter++;
            ct_display(counter);
		}
	}
}

// --- callbacks from timer
// ========================================================
// Name       : callbackIncrement
// Function   : notify to taskIncrement
// Parameters : timer
// Return     : none
// notes      : none
// ========================================================
static void callbackIncrement(TimerHandle_t timer)
{
	// *** Hint:notify to taskIncrement
	xTaskNotifyGive(taskHandleIncrement);
	return;
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
	sv_init();
	return;
}

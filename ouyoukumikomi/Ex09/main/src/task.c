// ========================================================
// File    : task.c
// Role    : Ex09 state transition
// Date    : 2024.06.06
// Author  : your ID number and name
// Notes   : none
// ========================================================
// --- Header files (system)
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/timers.h"
// --- Header files (project)
#include "led.h"
#include "sevenSegmentLed.h"
#include "pushButton.h"
#include "countLed.h"

// --- macros
// task
#define STACK_DEPTH		((uint32_t) 4096)
#define PRIORITY_COUNT	(tskIDLE_PRIORITY + 1)
// notify
#define CLEAR_NONE		((uint32_t) 0)
#define CLEAR_ALL		ULONG_MAX
#define PERIOD_COUNT	pdMS_TO_TICKS(1000)
#define TICKS_TO_WAIT	pdMS_TO_TICKS(1000 * 60 * 60)	// 1 hour
#define VALUE_NONE		((uint32_t) 0)
#define VALUE_INCREMENT	((uint32_t) 0x01)
#define VALUE_STARTSTOP	((uint32_t) 0x02)

// --- data (static)
static TaskHandle_t		taskHandleCount = NULL;
static TimerHandle_t	timerHandleCount = NULL;

// --- prototypes (static)
static void	taskCount(void *arg);
static void	callbackCount(TimerHandle_t timer);
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
		&taskCount,
		"taskCount",
		STACK_DEPTH,
		NULL,
		PRIORITY_COUNT,
		&taskHandleCount
	);
	if (pass != pdPASS) {
		puts("cannot create taskCount");
	} else {
		// create timer
		timerHandleCount = xTimerCreate(
			"timerCount",
			PERIOD_COUNT,
			pdTRUE,
			NULL,
			&callbackCount
		);
		if (timerHandleCount == NULL) {
			puts("cannot create timerCount");
		} else {
			pass = xTimerStart(timerHandleCount, 0);
			if (pass != pdPASS) {
				puts("cannot start timerCount");
			}
		}
	}

	return;
}

// --- task functions
// ========================================================
// Name       : taskCount
// Function   : counting LED
// Parameters : informations
// Return     : none
// notes      : none
// ========================================================
static void taskCount(void *arg)
{
	// monitor
	TaskHandle_t	handle = xTaskGetCurrentTaskHandle();
	char*			taskname = pcTaskGetName(handle);
	puts(taskname);

	ct_init();
	for (;;) {	// closed loop
		BaseType_t	pd;
		// *** challenge

		pd = xTaskNotifyWait(
			CLEAR_NONE,
			CLEAR_NONE,		// *** challenge
			NULL,			// *** challenge
			TICKS_TO_WAIT
		);
		if (/*** Hint:check notified */pdPASS) {
			puts("not notified");
		} else {
			// *** Hint:increment
		}
	}
}

// --- callback from timer
// ========================================================
// Name       : callbackCount
// Function   : notify to taskCount
// Parameters : timer
// Return     : none
// notes      : none
// ========================================================
static void callbackCount(TimerHandle_t timer)
{
	// *** Hint:notify to taskCount
	return;
}

// --- interrupt service routines
// ========================================================
// Name       : pb1_isr_handler
// Function   : notify to taskCount
// Parameters : informations
// Return     : none
// notes      : none
// ========================================================
void pb1_isr_handler(void *arg)
{
	BaseType_t	higherPriorityTaskWoken = pdFALSE;

	// *** challenge
	portYIELD_FROM_ISR(higherPriorityTaskWoken);

	return;
}

// ========================================================
// Name       : pb2_isr_handler
// Function   : do nothing
// Parameters : informations
// Return     : none
// notes      : none
// ========================================================
void pb2_isr_handler(void *arg)
{
	// do nothing
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
	led_init();
	sv_init();
	pb_init();
	return;
}

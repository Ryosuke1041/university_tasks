// ========================================================
// File    : task.c
// Role    : Ex08 notification value
// Date    : 2024.05.30
// Author  : 22H062 中江亮介
// Notes   : 起動できていません
// ========================================================
// --- Header files (system)
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
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
#define TICKS_TO_WAIT	pdMS_TO_TICKS(1000 * 60 * 60)	// 1 hour
#define VALUE_NONE		((uint32_t) 0)
#define VALUE_INCREMENT	((uint32_t) 0x01)
#define VALUE_DECREMENT	((uint32_t) 0x02)

// --- data (static)
static TaskHandle_t	taskHandleCount = NULL;

// --- prototypes (static)
static void	taskCount(void *arg);
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
	}

	return;
}

// --- task functions
// ========================================================
// Name       : taskCount
// Function   : count and display on LED
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
	uint32_t count = 0;
    uint32_t notifyValue;
	for (;;) {	// closed loop
		BaseType_t	pd;
		// *** challenge

		pd = xTaskNotifyWait(	// *** challenge
			CLEAR_NONE,
			CLEAR_NONE,
			NULL,
			TICKS_TO_WAIT
		);
		if (pd != pdPASS) {
			puts("not notified");
		} else {
			if (notifyValue == VALUE_INCREMENT) {
                count++;
            } else if (notifyValue == VALUE_DECREMENT) {
                count--;
            }
            ct_display(count);// *** Hint:increment
		}
	}
}

// --- interrupt service routines
// ========================================================
// Name       : pb1_isr_handler
// Function   : notify to taskCount VALUE_INCREMENT
// Parameters : informations
// Return     : none
// notes      : none
// ========================================================
void pb1_isr_handler(void *arg)
{
	BaseType_t	higherPriorityTaskWoken = pdFALSE;

	// *** Hint:notify to taskCount
	xTaskNotifyFromISR(
        taskHandleCount,
        VALUE_INCREMENT,
        eSetValueWithOverwrite,
        &higherPriorityTaskWoken
    );
	portYIELD_FROM_ISR(higherPriorityTaskWoken);

	return;
}

// ========================================================
// Name       : pb2_isr_handler
// Function   : notify to taskCount VALUE_DECREMENT
// Parameters : informations
// Return     : none
// notes      : none
// ========================================================
void pb2_isr_handler(void *arg)
{
	BaseType_t	higherPriorityTaskWoken = pdFALSE;

	// *** challenge
	portYIELD_FROM_ISR(higherPriorityTaskWoken);

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

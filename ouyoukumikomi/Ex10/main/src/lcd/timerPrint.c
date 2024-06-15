// ========================================================
// File    : timerPrint.h
// Role    : timer for print
// Date    : 2024.06.06
// Author  : Osaka Sangyo University
// ========================================================
// --- Header files (system)
#include <stdbool.h>
#include "driver/gptimer.h"
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
// --- Header of own file
#include "timerPrint.h"

// --- macros
#define TM_100US_PERIOD	((uint64_t) 10 * 1000)

// --- data (static)
static gptimer_handle_t		gptimer = NULL;
static uint32_t				tm_busycounter;

// --- functions (extern)
// ========================================================
// Name       : tm_init
// Function   : initialize project timer
// Parameters : none
// Return     : none
// notes      : call before closed loop
// ========================================================
void tm_init(void)
{
	gptimer_config_t			timer_config;
	gptimer_alarm_config_t		alarm_config;
	gptimer_event_callbacks_t	cbs;

	timer_config.clk_src = GPTIMER_CLK_SRC_DEFAULT;
	timer_config.direction = GPTIMER_COUNT_UP;
	timer_config.resolution_hz = TM_100US_PERIOD;	// 10KHz, 1 tick == 100us
	ESP_ERROR_CHECK(gptimer_new_timer(&timer_config, &gptimer));

	alarm_config.reload_count = 0;
	alarm_config.alarm_count = 1;
	alarm_config.flags.auto_reload_on_alarm = true;
	ESP_ERROR_CHECK(gptimer_set_alarm_action(gptimer, &alarm_config));

	cbs.on_alarm = &tm_100us_interrupt;
	ESP_ERROR_CHECK(gptimer_register_event_callbacks(gptimer, &cbs, ""));

	// data clear
	tm_busycounter = 0U;

	// timer start
	ESP_ERROR_CHECK(gptimer_enable(gptimer));

	return;
}

void tm_start(void)
{
	ESP_ERROR_CHECK(gptimer_start(gptimer));
	return;
}

// ========================================================
// Name       : tm_busy
// Function   : start counting
// Parameters : micro second (0 - 25500)
// Return     : none
// notes      : none
// ========================================================
void tm_busy(uint64_t usec)
{
	if (usec > 0U) {
		if (tm_busycounter > 0U) {
			printf("tm_busy: counter = %lx\n", tm_busycounter);
		} else {
			tm_busycounter = usec / 100U;
		}
	}
	return;
}

// ========================================================
// Name       : tm_check
// Function   : check counting
// Parameters : none
// Return     : none
// notes      : call from high priority task
// ========================================================
void tm_check(void)
{
	if (tm_busycounter > 0U) {
		--tm_busycounter;
	}
	return;
}

// ========================================================
// Name       : tm_ready
// Function   : tm_busycounter == 0U or not
// Parameters : none
// Return     : true: tm_busycounter == 0U / false: tm_busycounter > 0
// notes      : none
// ========================================================
bool tm_ready(void)
{
	bool	ready;

	ready = tm_busycounter == 0U;

	return ready;
}

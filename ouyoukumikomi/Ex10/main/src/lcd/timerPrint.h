// ========================================================
// File    : timerPrint.h
// Role    : timer for print
// Date    : 2024.06.06
// Author  : Osaka Sangyo University
// ========================================================
#ifndef TIMER_PRINT_H
#define TIMER_PRINT_H

// --- prototypes (extern)
extern void	tm_init(void);
extern void	tm_busy(uint64_t usec);
extern bool	tm_ready(void);
extern void	tm_check(void);
extern void	tm_start(void);

// --- interrupt service routine
extern bool	tm_100us_interrupt(
	gptimer_handle_t timer,
	const gptimer_alarm_event_data_t *edata,
	void *user_ctx
);

#endif	// TIMER_PRINT_H

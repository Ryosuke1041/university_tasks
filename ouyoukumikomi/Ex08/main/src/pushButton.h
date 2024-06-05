// ========================================================
// File    : pushButton.h
// Role    : Push Buttons (RTOS)
// Date    : 2024.05.16
// Author  : Osaka Sangyo University
// ========================================================
#ifndef PUSH_BUTTON_H
#define PUSH_BUTTON_H

// --- prototypes (extern)
extern void	pb_init(void);

// --- interrupt service routine defined task.c
extern void pb1_isr_handler(void *arg);
extern void pb2_isr_handler(void *arg);

#endif	// PUSH_BUTTON_H

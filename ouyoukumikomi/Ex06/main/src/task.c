// File    : task.c
// Role    : Ex06 interrupt service routine
// Date    : 2024.05.16
// Author  : your 22H062 中江亮介
// Notes   : none　延期希望
// ========================================================
// --- Header files (system)
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
// --- Header files (project)
#include "led.h"
#include "sevenSegmentLed.h"
#include "pushButton.h"
#include "blink.h"

// --- macros
// task
#define STACK_DEPTH     ((uint32_t) 4096)
#define PRIORITY_BLINK  (tskIDLE_PRIORITY + 1)
// notify
#define CLEAR_NONE      ((uint32_t) 0)
#define TICKS_TO_WAIT   pdMS_TO_TICKS(1000 * 60 * 60) 
#define VALUE_NONE      ((uint32_t) 0)

// --- data (static)
static TaskHandle_t taskHandleBlink = NULL;

// --- prototypes (static)
static void taskBlink(void *arg);
static void initialize(void);

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
    BaseType_t pass;

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
    // monitor
    TaskHandle_t handle = xTaskGetCurrentTaskHandle();
    char* taskname = pcTaskGetName(handle);
    puts(taskname);

    bl_init();
    int ledState = 0; // 0: off, 1: on
    for (;;) {   // closed loop
        BaseType_t pd;

        pd = xTaskNotifyWait(
            CLEAR_NONE,
            CLEAR_NONE,
            NULL,
            TICKS_TO_WAIT
        );
        if (pd == pdPASS) {
            ledState = !ledState;
            bl_setState(ledState);
        } else {
            puts("not notified");
        }
    }
}

// --- interrupt service routines
// ========================================================
// Name       : pb1_isr_handler
// Function   : notify to taskBlink
// Parameters : informations
// Return     : none
// notes      : none
// ========================================================
void pb1_isr_handler(void *arg)
{
    BaseType_t higherPriorityTaskWoken = pdFALSE;

    vTaskNotifyGiveFromISR(taskHandleBlink, &higherPriorityTaskWoken);
    portYIELD_FROM_ISR(higherPriorityTaskWoken);

    return;
}

// ========================================================
// Name       : pb2_isr_handler
// Function   : notify to taskBlink
// Parameters : informations
// Return     : none
// notes      : none
// ========================================================
void pb2_isr_handler(void *arg)
{
    BaseType_t higherPriorityTaskWoken = pdFALSE;

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
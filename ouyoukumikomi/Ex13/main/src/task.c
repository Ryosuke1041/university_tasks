// ========================================================
// File    : task.c
// Role    : Ex13 stopwatch
// Date    : 2024.07.04
// Author  : 22H062 中江亮介
// Notes   : 完成
// ========================================================
// --- Header files (system)
#include <stdbool.h>
#include <stdio.h>
#include <assert.h>
#include "driver/gptimer.h"        // LCD
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/timers.h"
#include "freertos/queue.h"        // LCD
// --- Header files (project)
#include "sevenSegmentLed.h"
#include "pushButton.h"            // final exam
#include "lcd/lcd.h"
#include "lcd/printLcd.h"
#include "lcd/printLcdImpr.h"
#include "lcd/timerPrint.h"
#include "stopwatch.h"

// --- macros
// tasks
#define STACK_DEPTH                ((uint32_t) 4096)
#define PRIORITY_STOPWATCH        (tskIDLE_PRIORITY + 2)
// tasks (LCD)
#define PRIORITY_LCDOUTPUT        (tskIDLE_PRIORITY + 1)    // lowest
#define PRIORITY_LCDPRINT        (tskIDLE_PRIORITY + 3)
#define PRIORITY_LCDCHECKBUSY    (tskIDLE_PRIORITY + 4)
// notify
#define CLEAR_NONE    ((uint32_t) 0)
#define CLEAR_ALL    ULONG_MAX
#define VALUE_NONE    ((uint32_t) 0)
// timer
#define PERIOD_STOPWATCH    pdMS_TO_TICKS(1000)
// queue (LCD)
#define QUEUE_LENGTH    ((UBaseType_t) 4)
// etc
#define TICKS_TO_WAIT    pdMS_TO_TICKS(1000 * 60 * 60)    // 1 hour

// --- data (static)
static TaskHandle_t        taskHandleStopwatch = NULL;
static TimerHandle_t    timerHandleStopwatch = NULL;
// LCD
static TaskHandle_t        taskHandleLcdOutput = NULL;
static TaskHandle_t        taskHandleLcdPrint = NULL;
static TaskHandle_t        taskHandleLcdCheckbusy = NULL;
static QueueHandle_t    queueHandleLcdPrint = NULL;

// --- prototypes (static)
static void taskStopwatch(void *arg);
static void callbackStopwatch(TimerHandle_t timer);
static void    initialize(void);
// LCD
static void    taskLcdOutput(void *arg);
static void    taskLcdPrint(void *arg);
static void    taskLcdCheckbusy(void *arg);

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
    BaseType_t    pass;

    // initialize devices
    initialize();
    // create queue
    queueHandleLcdPrint = xQueueCreate(        // LCD
        QUEUE_LENGTH,
        sizeof(char *)
    );
    if (queueHandleLcdPrint == NULL) {
        puts("cannot create queueLcdPrint");
        assert(false);
    }
    // create tasks
    pass = xTaskCreate(        // LCD
        &taskLcdCheckbusy,
        "taskLcdCheckbusy",
        STACK_DEPTH,
        NULL,
        PRIORITY_LCDCHECKBUSY,
        &taskHandleLcdCheckbusy
    );
    if (pass != pdPASS) {
        puts("cannot create taskLcdCheckbusy");
        assert(false);
    }
    pass = xTaskCreate(        // LCD
        &taskLcdPrint,
        "taskLcdPrint",
        STACK_DEPTH,
        NULL,
        PRIORITY_LCDPRINT,
        &taskHandleLcdPrint
    );
    if (pass != pdPASS) {
        puts("cannot create taskLcdPrint");
        assert(false);
    }
    pass = xTaskCreate(
        &taskStopwatch,
        "taskStopwatch",
        STACK_DEPTH,
        NULL,
        PRIORITY_STOPWATCH,
        &taskHandleStopwatch
    );
    if (pass != pdPASS) {
        puts("cannot create taskStopwatch");
        assert(false);
    }
    pass = xTaskCreate(        // LCD
        &taskLcdOutput,
        "taskLcdOutput",
        STACK_DEPTH,
        NULL,
        PRIORITY_LCDOUTPUT,
        &taskHandleLcdOutput
    );
    if (pass != pdPASS) {
        puts("cannot create taskLcdOutput");
        assert(false);
    }
    timerHandleStopwatch = xTimerCreate(
        "timerStopwatch",
        PERIOD_STOPWATCH,
        pdTRUE,
        NULL,
        &callbackStopwatch
    );
    if (timerHandleStopwatch == NULL) {
        puts("cannot create timerStopwatch");
        assert(false);
    }
    pass = xTimerStart(timerHandleStopwatch, 0);
    if (pass != pdPASS) {
        puts("cannot start timerStopwatch");
        assert(false);
    }
    // LCD (start busy check)
    tm_start();

    return;
}

// --- task functions
// ========================================================
// Name       : taskStopwatch
// Function   : run stopwatch
// Parameters : informations
// Return     : none
// notes      : none
// ========================================================
static void taskStopwatch(void *arg)
{
    // monitor
    TaskHandle_t    handle = xTaskGetCurrentTaskHandle();
    char*            taskname = pcTaskGetName(handle);
    puts(taskname);

    sw_init();
    int seconds = 0;
    for (;;) {    // closed loop
        BaseType_t    pd;

        pd = xTaskNotifyWait(
            CLEAR_NONE,
            CLEAR_NONE,
            NULL,
            TICKS_TO_WAIT
        );
        if (pd != pdPASS) {
            puts(taskname);
            puts("not notified");
        } else {
            // カウントと表示のロジック
            seconds = (seconds + 1) % 100; // 00〜99をカウント
            char buffer[3];
            snprintf(buffer, sizeof(buffer), "%02d", seconds);
            pr_lcd_puts_send(buffer);
        }
    }
}

// --- callback from timer
// ========================================================
// Name       : callbackStopwatch
// Function   : notify to taskStopwatch
// Parameters : timer
// Return     : none
// notes      : none
// ========================================================
static void callbackStopwatch(TimerHandle_t timer)
{
    // タスクに通知を送る
    xTaskNotify(
        taskHandleStopwatch,
        VALUE_NONE,
        eNoAction
    );
    return;
}

// --- interrupt service routines
// ========================================================
// Name       : pb1_isr_handler
// Function   : notify to taskChange
// Parameters : informations
// Return     : none
// notes      : none
// ========================================================
void pb1_isr_handler(void *arg)    // final exam
{
    // do nothing
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
    sv_init();
    pb_init();    // final exam
    lcd_init();
    tm_init();
    return;
}

// *** LCD ***
// --- tasks
// ========================================================
// Name       : taskLcdOutput
// Function   : output data on LCD
// Parameters : information
// Return     : none
// notes      : none
// ========================================================
static void taskLcdOutput(void *arg)
{
    // monitor
    TaskHandle_t    handle = xTaskGetCurrentTaskHandle();
    char*            taskname = pcTaskGetName(handle);
    puts(taskname);

    for (;;) {    // closed loop
        BaseType_t    pd;

        pd = xTaskNotifyWait(
            CLEAR_NONE,
            CLEAR_NONE,
            VALUE_NONE,
            TICKS_TO_WAIT
        );
        if (pd != pdPASS) {
            puts(taskname);
            puts("not notified");
        } else {
            pr_lcd_output();
        }
    }
}

// ========================================================
// Name       : taskLcdPrint
// Function   : receive printing data
// Parameters : information
// Return     : none
// notes      : none
// ========================================================
static void taskLcdPrint(void *arg)
{
    // monitor
    TaskHandle_t    handle = xTaskGetCurrentTaskHandle();
    char*            taskname = pcTaskGetName(handle);
    puts(taskname);

    for (;;) {    // closed loop
        BaseType_t    pd;
        char        *string;

        pd = xQueueReceive(
            queueHandleLcdPrint,
            (void *) &string,
            TICKS_TO_WAIT
        );
        if (pd != pdPASS) {
            puts(taskname);
            puts("not receive");
        } else {
            pr_lcd_puts_impr(string);
        }
    }
}

// ========================================================
// Name       : taskLcdCheckbusy
// Function   : check LCD is busy or not
// Parameters : information
// Return     : none
// notes      : none
// ========================================================
static void taskLcdCheckbusy(void *arg)
{
    // monitor
    TaskHandle_t    handle = xTaskGetCurrentTaskHandle();
    char*            taskname = pcTaskGetName(handle);
    puts(taskname);

    for (;;) {    // closed loop
        BaseType_t    pd;

        pd = xTaskNotifyWait(
            CLEAR_NONE,
            CLEAR_NONE,
            VALUE_NONE,
            TICKS_TO_WAIT
        );
        if (pd != pdPASS) {
            puts(taskname);
            puts("not notified");
        } else {
            eTaskState    state;

            tm_check();
            state = eTaskGetState(taskHandleLcdOutput);
            if (state == eBlocked) {
                if (tm_ready() == true) {
                    (void)xTaskNotify(
                        taskHandleLcdOutput,
                        VALUE_NONE,
                        eNoAction
                    );
                }
            }
        }
    }
}

// --- interrupt service routines
// ========================================================
// Name       : tm_100us_interrupt
// Function   : increment counter
// Parameters : not use
// Return     : false
// notes      : interrupt service routine
// ========================================================
bool tm_100us_interrupt(
    gptimer_handle_t timer,
    const gptimer_alarm_event_data_t *edata,
    void *user_ctx)
{
    BaseType_t    higherPriorityTaskWoken = pdFALSE;

    (void)xTaskNotifyFromISR(
        taskHandleLcdCheckbusy,
        VALUE_NONE,
        eNoAction,
        &higherPriorityTaskWoken
    );
    portYIELD_FROM_ISR(higherPriorityTaskWoken);

    return false;
}

// --- functions (called from some tasks)
// ========================================================
// Name       : pr_lcd_puts_send
// Function   : send string to queue
// Parameters : string (terminated by null character)
// Return     : none
// notes      : none
// ========================================================
void pr_lcd_puts_send(const char s[])
{
    BaseType_t        pd;

    TaskHandle_t    handle = xTaskGetCurrentTaskHandle();
    char*            taskname = pcTaskGetName(handle);

    pd = xQueueSend(
        queueHandleLcdPrint,
        (void *)&s,
        (TickType_t) 0        // not wait
    );
    if (pd != pdTRUE) {
        puts(taskname);
        puts("cannot send string (pr_lcd_puts)");
    }

    return;
}
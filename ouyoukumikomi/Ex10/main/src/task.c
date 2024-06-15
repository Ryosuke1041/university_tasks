// ========================================================
// File    : task.c
// Role    : Ex10 queue
// Date    : 2024.06.13
// Author  : 22H062 中江亮介
// Notes   : 実行はできていません
// ========================================================
// --- Header files (system)
#include <stdbool.h>
#include <stdio.h>
#include <assert.h>
#include "driver/gptimer.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
// --- Header files (project)
#include "led.h"
#include "toggleSwitch.h"
#include "sevenSegmentLed.h"
#include "pushButton.h"
#include "lcd/lcd.h"
#include "lcd/printLcd.h"
#include "lcd/timerPrint.h"
#include "character.h"

// --- macros
// tasks
#define STACK_DEPTH             ((uint32_t) 4096)
#define PRIORITY_TOGGLE_SWITCH  (tskIDLE_PRIORITY + 3)
#define PRIORITY_CHARACTER      (tskIDLE_PRIORITY + 2)
// tasks (LCD)
#define PRIORITY_LCDOUTPUT      (tskIDLE_PRIORITY + 1)  // lowest
#define PRIORITY_LCDCHECKBUSY   (tskIDLE_PRIORITY + 4)
// notify
#define CLEAR_NONE      ((uint32_t) 0)
#define CLEAR_ALL       ULONG_MAX
#define VALUE_NONE      ((uint32_t) 0)
#define VALUE_UPPER     ((uint32_t) 0x01)
#define VALUE_LOWER     ((uint32_t) 0x02)
// queue
#define QUEUE_LENGTH    ((UBaseType_t) 4)
// etc
#define TICKS_TO_WAIT   pdMS_TO_TICKS(1000 * 60 * 60)   // 1 hour
#define LOWER_4BITS     ((uint8_t) 0x0F)

// --- data (static)
static TaskHandle_t     taskHandleToggleSwitch = NULL;
static TaskHandle_t     taskHandleCharacter = NULL;
static QueueHandle_t    queueHandleCharacter = NULL;
// LCD
static TaskHandle_t     taskHandleLcdOutput = NULL;
static TaskHandle_t     taskHandleLcdCheckbusy = NULL;

// --- prototypes (static)
static void taskToggleSwitch(void *arg);
static void taskCharacter(void *arg);
static void initialize(void);
// LCD
static void taskLcdOutput(void *arg);
static void taskLcdCheckbusy(void *arg);

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
    // create queue
    queueHandleCharacter = xQueueCreate(
        QUEUE_LENGTH,
        sizeof(uint8_t)
    );
    if (queueHandleCharacter == NULL) {
        puts("cannot create queueCharacter");
        assert(false);
    }
    // create tasks
    pass = xTaskCreate(
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
    pass = xTaskCreate(
        &taskToggleSwitch,
        "taskToggleSwitch",
        STACK_DEPTH,
        NULL,
        PRIORITY_TOGGLE_SWITCH,
        &taskHandleToggleSwitch
    );
    if (pass != pdPASS) {
        puts("cannot create taskToggleSwitch");
        assert(false);
    }
    pass = xTaskCreate(
        &taskCharacter,
        "taskCharacter",
        STACK_DEPTH,
        NULL,
        PRIORITY_CHARACTER,
        &taskHandleCharacter
    );
    if (pass != pdPASS) {
        puts("cannot create taskCharacter");
        assert(false);
    }
    pass = xTaskCreate(
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
    // LCD (start busy check)
    tm_start();

    return;
}

// --- task functions
// ========================================================
// Name       : taskToggleSwitch
// Function   : read toggle switch and send
// Parameters : informations
// Return     : none
// notes      : none
// ========================================================
static void taskToggleSwitch(void *arg)
{
    uint8_t lower;
    uint8_t upper;

    // monitor
    TaskHandle_t handle = xTaskGetCurrentTaskHandle();
    char* taskname = pcTaskGetName(handle);
    puts(taskname);

    lower = 0U;
    upper = 0U;
    for (;;) {  // closed loop
        BaseType_t pd;
        uint32_t notifiedValue;

        pd = xTaskNotifyWait(
            CLEAR_NONE,
            CLEAR_ALL,
            &notifiedValue,
            TICKS_TO_WAIT
        );
        if (pd != pdPASS) {
            puts(taskname);
            puts("not notified");
        } else {
            uint8_t tsw;
            uint8_t pattern = 0U;

            tsw = tsw_get();
            led_set(tsw);
            if ((notifiedValue & VALUE_UPPER) != VALUE_NONE) {
                upper = (tsw & LOWER_4BITS) << 4U;
            }
            if ((notifiedValue & VALUE_LOWER) != VALUE_NONE) {
                lower = (tsw & LOWER_4BITS);
                pattern = upper | lower;
                // send to queue
                pd = xQueueSend(
                    queueHandleCharacter,
                    &pattern,
                    portMAX_DELAY
                );
                if (pd != pdPASS) {
                    puts(taskname);
                    puts("cannot send");
                }
            }
        }
    }
}

// ========================================================
// Name       : taskCharacter
// Function   : display character on monitor
// Parameters : informations
// Return     : none
// notes      : none
// ========================================================
static void taskCharacter(void *arg)
{
    // monitor
    TaskHandle_t handle = xTaskGetCurrentTaskHandle();
    char* taskname = pcTaskGetName(handle);
    puts(taskname);

    cr_init();
    for (;;) {  // closed loop
        BaseType_t pd = pdFAIL;
        uint8_t data;

        // receive from queue
        pd = xQueueReceive(
            queueHandleCharacter,
            &data,
            portMAX_DELAY
        );
        if (pd != pdPASS) {
            puts(taskname);
            puts("cannot receive");
            vTaskDelay((TickType_t) 1); // for WDT
        } else {
            sv_hexadecimal(data);
            // display data on LCD
            if (data >= 0x20 && data <= 0x7E) {
                pr_lcd_character(data);
            } else {
                pr_lcd_string("Invalid Char");
            }
        }
    }
}

// --- interrupt service routines
// ========================================================
// Name       : pb1_isr_handler
// Function   : notify to taskToggleSwitch
// Parameters : informations
// Return     : none
// notes      : none
// ========================================================
void pb1_isr_handler(void *arg)
{
    BaseType_t higherPriorityTaskWoken = pdFALSE;

    (void)xTaskNotifyFromISR(
        taskHandleToggleSwitch,
        VALUE_LOWER,
        eSetBits,
        &higherPriorityTaskWoken
    );
    portYIELD_FROM_ISR(higherPriorityTaskWoken);

    return;
}

// ========================================================
// Name       : pb2_isr_handler
// Function   : notify to taskToggleSwitch
// Parameters : informations
// Return     : none
// notes      : none
// ========================================================
void pb2_isr_handler(void *arg)
{
    BaseType_t higherPriorityTaskWoken = pdFALSE;

    (void)xTaskNotifyFromISR(
        taskHandleToggleSwitch,
        VALUE_UPPER,
        eSetBits,
        &higherPriorityTaskWoken
    );
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
    tsw_init();
    sv_init();
    pb_init();
    lcd_init();
    tm_init();
    return;
}
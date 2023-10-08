#include "system.h"
#include "button.h"
#include "pacer.h"
#include "tinygl.h"
#include "task.h"
#include "../fonts/font3x5_1.h"

/* Define polling rates in Hz.  */
#define BUTTON_TASK_RATE 100
#define DISPLAY_TASK_RATE 250  /* Display rate */
#define TIMER_TASK_RATE 100 /* from Stopwatch code */
#define PACER_RATE 500 /* Pacer loop - controls main loop */

static bool run;

static void button_task_init (void)
{
    button_init ();
}

static void button_poll_task (void)
{
    button_update ();

    if (button_push_event_p (BUTTON1))
    {
        run = !run;
    }
}

static void display_task_init (void)
{
    tinygl_init (DISPLAY_TASK_RATE);
    tinygl_font_set (&font3x5_1);
    tinygl_text_mode_set (TINYGL_TEXT_MODE_STEP);
    tinygl_text_dir_set (TINYGL_TEXT_DIR_ROTATE);
}


static void display_task (void)
{
    tinygl_update ();
}


static void timer_task_init (void)
{
    tinygl_text ("00");
}


static void timer_task (void)
{
    static uint16_t time;
    char str[3];

    if (!run)
    {
        time = 0;
        return;
    }

    str[0] = ((time / 10) % 10) + '0';
    str[1] = (time % 10) + '0';
    str[2] = 0;

    tinygl_text (str);

    time++;
}

int main (void)
{
    system_init();
    task_t tasks[] =
    {
        {.func = display_task, .period = TASK_RATE / DISPLAY_TASK_RATE}, 
        {.func = button_task, .period = TASK_RATE / BUTTON_TASK_RATE},
        {.func = timer_task, .period = TASK_RATE / TIMER_TASK_RATE},
    };
    
    /* TODO: Initialise the button driver, tinygl, and the pacer.  */
    pacer_init (PACER_RATE);
    tinygl_init (PACER_RATE);
    tinygl_font_set (&font5x7_1);
    tinygl_text_speed_set (MESSAGE_RATE);
    navswitch_init ();

    //Initialise timer/
    display_task_init ();
    button_task_init ();
    timer_task_init ();



    while(1)
    {
        pacer_wait();

	/* TODO: call the tasks at the appropriate frequencies  */
        task_schedule (tasks, ARRAY_SIZE (tasks));

    }
    return 0;
}

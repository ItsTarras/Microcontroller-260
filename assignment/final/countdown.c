#include <avr/io.h>
#include "system.h"
#include "pio.h"
#include "pacer.h"
#include "led.h"
#include "button.h"
#include "ledmat.h"
#include "navswitch.h"
#include "ir_uart.h"
#include "tinygl.h"
#include "../fonts/font5x7_1.h"
#include "direction.h"

void startCountdown(void) {
    resetPins();
    tinygl_text_mode_set(TINYGL_TEXT_MODE_STEP);
    tinygl_text_speed_set (10);
    tinygl_text("321 ");
    
    
    for (int i = 0; i < 2000; i++) {
        pacer_wait();
        tinygl_update();
    }
}

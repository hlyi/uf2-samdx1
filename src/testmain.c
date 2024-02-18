#include "uf2.h"

#include "sam.h"

int main(void) {
    led_init();

    //logmsg("Start");

    /* We have determined we should stay in the monitor. */
    /* System initialization */
    system_init();
    __DMB();
    __enable_irq();


    // We should not reach here normally.
    while (1) {
        PINOP(LED_PIN, OUTSET);
        delay(100);
        PINOP(LED_PIN, OUTCLR);
        delay(100);
    }
}

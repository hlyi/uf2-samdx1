#include "uf2.h"

#include "sam.h"

int main(void) {
    led_init();

    //logmsg("Start");

    /* We have determined we should stay in the monitor. */
    /* System initialization */
    system_init();
    __disable_irq();
    __DMB();


    *DBL_TAP_PTR = 0;

    // re-base int vector back to bootloader, so that the flash erase
    // below doesn't write over the vectors.
    SCB->VTOR = 0;


    LED_MSC_OFF();
    NVIC_SystemReset();

    // We should not reach here normally.
    while (1) {
    }
}

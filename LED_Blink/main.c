#include <AT89X52.H>       // Include header for AT89X52 microcontroller

#define LED P2_0           // Define LED as bit 0 of Port 2 (P2.0)

/**
 * Function: delay
 * ----------------
 * Generates a blocking delay of approximately 'milliseconds' ms
 * using nested software loops.
 *
 * Assumes system clock = 11.0592 MHz.
 * Each iteration of the inner loop takes a few microseconds.
 * The total delay per millisecond is calibrated by adjusting
 * the loop bounds (i and j).
 *
 * Note:
 * - This method is CPU-blocking and not precise.
 * - Best used for simple tasks like LED blinking.
 */
void delay(unsigned int milliseconds) {
    unsigned int ms;
    unsigned int i, j;

    for (ms = 0; ms < milliseconds; ms++) {
        // Outer loop for coarse granularity
        for (i = 0; i < 11; i++) {
            // Inner loop for fine control
            for (j = 0; j < 11; j++) {
                // Empty loop body — just wasting CPU cycles
                // Each iteration takes ~8–9 instruction cycles
                // Total delay per ms ˜ 11 × 11 × ~8.5 cycles ˜ 1000 µs
            }
        }
    }
}

/**
 * Function: main
 * --------------
 * Main program loop that toggles an LED every 1000 ms (1 second).
 * Uses calibrated software delay to create a visible blinking effect.
 */
void main() {
    LED = 0;               // Initialize LED to OFF (logic low)

    while (1) {
        LED = ~LED;        // Toggle LED state (ON ? OFF)
        delay(1000);       // Wait for 1000 ms (1 second)
    }
}

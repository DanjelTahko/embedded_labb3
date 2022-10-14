#include <avr/io.h>
#include "led.h"

void LED_init() {
	DDRD &= ~(1 << PD2); // Sets PD2 as input
}




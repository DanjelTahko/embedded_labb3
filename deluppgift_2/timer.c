#include <avr/io.h>

#include "timer.h"

void timer_init() {
	
	TCCR0A |= (1 << WGM01); // CTC Mode

	TCCR0B |= (1 << CS02) | (1 << CS00); // prescaler 1024

	OCR0A = 156; // set top
}


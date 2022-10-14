#include <avr/io.h>

#include "timer.h"

void timer_init() {
	
	// Timer/Compare0 Register A 
	TCCR0A |= (1 << COM0A1) | (1 << WGM01) | (1 << WGM00); // Timer0 fast PWM-mode, 255-TOP
	// Timer/Compare0 Register B 
	TCCR0B |= (1 << CS01) | (1 << CS00); // Prescaler 64


	TCCR2A |= (1 << COM2A1) | (1 << WGM21); // CTC-mode, compare on match

	TCCR2B |= (1 << CS22) | (1 << CS21) | (1 << CS20); // Prescaler 1024

	TIMSK2 |= (1 << OCIE0A); // Compare match A interrupt enable

	OCR2A = 156;

}






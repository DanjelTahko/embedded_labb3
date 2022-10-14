#include <avr/interrupt.h>
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <stdio.h>

#include "led.h"
#include "serial.h"
#include "timer.h"
#include "adc.h"

void main (void) {

	LED_init();
	uart_init();
	timer_init();
	ADC_init();

	volatile int ADC_value;

	while (1) {

		if (ADCSRA != (ADCSRA |= (1 << ADSC))) { // if conversion is complete
			ADC_value = ADCH; // Save value to global 
		}

		if (TIFR2 == (TIFR2 |= (1 << OCF2A))) { 
			TIFR2 &= (1 << OCF2A); // Reset flag
			ADC_start(); // Start conversion
			OCR0A = ADC_value; // Write ADC-value to OCR0A
		}
	}
}



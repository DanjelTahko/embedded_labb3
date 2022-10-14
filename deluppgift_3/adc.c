#include <avr/io.h>
#include "adc.h"

void ADC_init() {

	// ADC Multiplexer Selection Register 
	ADMUX |= (1 << ADLAR) | // ADC Left Adjust Result 
			 (1 << REFS0);  // AVcc with external capacitor at AREF pin

	ADMUX &= ~(1 << MUX3) |
			  (1 << MUX2) |
			  (1 << MUX1) |
			  (1 << MUX0); // Set Input ADC0
	
	// ADC Control and Status Register A 
	ADCSRA |= (1 << ADEN) | // Enable ADC 
			  (1 << ADPS1)| (1 << ADPS0); // Prescaler 8 
}

void ADC_start() {
    ADCSRA |= (1 << ADSC); // Start conversion
}

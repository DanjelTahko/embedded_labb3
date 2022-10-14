#include <avr/interrupt.h>
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <stdio.h>

#include "led.h"
#include "serial.h"
#include "timer.h"

const char pushed[] = "pushed\r\n";
const char released[] = "released\r\n";

const char *push_ptr = &pushed[0];
const char *releas_ptr = &released[0];

int prev_button = 0;
int active_button = 0;
int debounce = 0;
int reading_button = 0;

int currentTime = 0;
int lastDebounce = 0;
int delay = 1;

void debounceButton(){

    if (debounce) {
		if ((currentTime - lastDebounce) > delay) {
			if (PIND & (1 << PD2)) {
				uart_putstr(push_ptr);
			}else {
				uart_putstr(releas_ptr);
			}
			debounce = 0;
		}
	} else {
		active_button = PIND & (1 << PD2); 
		if (active_button != prev_button) {
			debounce = 1;
			lastDebounce = currentTime;
		}
		prev_button = active_button;
	}
}


void main() {

	LED_init();
	uart_init();
	timer_init();

	while (1) {

		if (TIFR0 == (TIFR0 |= (1 << OCF0A))) { //count every 10 millisec
			currentTime += 1;
		}

		debounceButton();
	}
}








        



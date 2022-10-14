#include <avr/io.h>

#include <stdio.h>

#include "serial.h"

//static FILE uart_stdout = FDEV_SETUP_STREAM(uart_putchar, NULL, _FDEV_SETUP_WRITE);
// doesn't understand how it works??

void uart_init(void) {
	UBRR0H = (unsigned char)(UBRR >> 8);
	UBRR0L = (unsigned char)(UBRR);
	UCSR0A = 0;
	UCSR0B = (1 << TXEN0 | 1 << RXEN0);
	UCSR0C = (1 << UCSZ01 | 1 << UCSZ00);

}

void uart_putstr(const char *str) {
	while(*str != '\0') {
		uart_putchar(*str++);
	}
}

int uart_putchar(char chr) {
	if (chr == '\n') {
		uart_putchar('\r');
	}
	while (!(UCSR0A & (1 << UDRE0)))
		;
	UDR0 = chr;
	return 0;
}

char uart_getchar(void) {
	while (!(UCSR0A & (1 << RXC0)))
		;
	return UDR0;
}


#include "rc522.h"
#include "spi.h"

#include <avr/io.h>
#include <util/delay.h>

#define F_CPU 1000000
#define BAUD 4800
#define BAUD_PRESCALE ((((F_CPU/16) + (BAUD/2)) / (BAUD)) - 1)

char getchar(void);
void putchar(char c);
void puts(const char *s);

void init_uart(void)
{
    UBRRH = (BAUD_PRESCALE >> 8);
    UBRRL = BAUD_PRESCALE;
    UCSRB = (1 << RXEN) | (1 << TXEN);
    UCSRC = (1 << URSEL) | (1 << UCSZ0) | (1 << UCSZ1) | (0 << UCSZ2)
            | (0 << UMSEL) | (0 << UPM0) | (0 << UPM1);
}


int main(void)
{
    char result;

    init_uart();
    spi_master_init();

    putchar('?');
    getchar();
    putchar('-');
    putchar('\n');
    putchar('\n');

    while (1)
    {
        result = spi_master_tranceiver(getchar());
        putchar(result);
        putchar('\n');
        _delay_ms(1000);
    }

    return 0;
}

void putchar(char c)
{
    while ((UCSRA & (1 << UDRE)) == 0) {}
    UDR = c;
}

char getchar(void)
{
    while ((UCSRA & (1 << RXC)) == 0) {}
    return UDR;
}

void puts(const char *s)
{
    while (*s != '\0')
    {
        putchar(*s);
        s++;
    }
}

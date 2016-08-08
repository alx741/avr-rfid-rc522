#include <avr/io.h>

void spi_master_init(void)
{
    DDRB = (1 << DDRB4) | (1 << DDRB5) | (1 << DDRB7);
    SPCR = (1 << SPE) | (1 << MSTR) | (1 << SPR0);
    PORTB = (0 << PORTB4);
}

char spi_master_tranceiver(char data)
{
    SPDR = data;

    while ( !(SPSR & (1 << SPIF)) );

    return SPDR;
}

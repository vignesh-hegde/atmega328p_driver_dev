#include "atmega328p_io.h"


volatile uint8_t *port_ddr_map[3][3] = 
{
    { &REG_PORTB, &REG_DDRB, &REG_PINB},
    { &REG_PORTC, &REG_DDRC, &REG_PINC},
    { &REG_PORTD, &REG_DDRD, &REG_PIND}
};

extern void init_pin_as
(
    port_t              port,
    bit_location_t      pin_location,
    signal_mode_t       signal_mode,
    signal_direction_t  signal_direction
)
{
    *port_ddr_map[port][DDR_LOOKUP] |= (1 << pin_location);
}

extern digital_logic_t toggle_digital_signal
(    
    port_t              port,
    bit_location_t      pin_location
)
{
    *port_ddr_map[port][PORT_LOOKUP] ^= (1 << pin_location); 
}
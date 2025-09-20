#ifndef ATMEGA328P_IO_H
#define ATMEGA328P_IO_H


#include "atmega328p_memory_map.h"

#define PORT_LOOKUP 0x00
#define DDR_LOOKUP  0x01    
#define PIN_LOOKUP  0x02

typedef enum
{
    logic_0_e = 0x00u,
    logic_1_e = 0x01u
} digital_logic_t;

typedef enum
{
    analog_e  = 0x00u,
    digital_e = 0x01u  
} signal_mode_t; 

typedef enum
{
    input_e   = 0x00u,
    output_e  = 0x01
} signal_direction_t;

extern volatile uint8_t *port_ddr_map[3][3];




typedef enum
{
    port_b_e = 0,
    port_c_e = 1,
    port_d_e = 2
} port_t;


extern void init_pin_as
(
    port_t              port,
    bit_location_t      pin_location,
    signal_mode_t       signal_mode,
    signal_direction_t  signal_direction
);

extern digital_logic_t toggle_digital_signal
(    
    port_t              port,
    bit_location_t      pin_location
);

#endif
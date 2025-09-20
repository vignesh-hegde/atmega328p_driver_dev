#ifndef ATMEGA328P_MEMORY_MAP_H
#define ATMEGA328P_MEMORY_MAP_H

#include <stdint.h>


#define MEMORY_MAPPED_OFFSET 0x0020

#define PTR_ADDRESS( address ) (*(volatile uint8_t *)(address + MEMORY_MAPPED_OFFSET))


#define ADDR_START              0x0000
#define ADDR_END                0x3FFF

/* 32 Registers */
#define ADDR_START_INT_REG          0x0000
#define ADDR_END_INT_REG            0x001F

/* 64 I/O Registers */
#define ADDR_START_IO_REG           0x0020
#define ADDR_END_IO_REG             0x005F


#define ADDR_REG_EEARH              0x0022
#define ADDR_REG_EEARL              0x0021
#define ADDR_REG_EEDR               0x0020
#define ADDR_REG_EECR               0x001F
#define ADDR_REG_GPIOR0             0x001E
#define ADDR_REG_EIMSK              0x001D
#define ADDR_REG_EIFR               0x001C
#define ADDR_REG_PCIFR              0x001B
#define ADDR_REG_Reserved_01        0x001A
#define ADDR_REG_Reserved_02        0x0019
#define ADDR_REG_Reserved_03        0x0018
#define ADDR_REG_TIFR2              0x0017
#define ADDR_REG_TIFR1              0x0016
#define ADDR_REG_TIFR0              0x0015
#define ADDR_REG_Reserved_04        0x0014
#define ADDR_REG_Reserved_05        0x0013
#define ADDR_REG_Reserved_06        0x0012
#define ADDR_REG_Reserved_07        0x0011
#define ADDR_REG_Reserved_08        0x0010
#define ADDR_REG_Reserved_09        0x000F
#define ADDR_REG_Reserved_10        0x000E
#define ADDR_REG_Reserved_11        0x000D
#define ADDR_REG_Reserved_12        0x000C
#define ADDR_REG_PORTD              0x000B
#define ADDR_REG_DDRD               0x000A
#define ADDR_REG_PIND               0x0009
#define ADDR_REG_PORTC              0x0008
#define ADDR_REG_DDRC               0x0007
#define ADDR_REG_PINC               0x0006
#define ADDR_REG_PORTB              0x0005
#define ADDR_REG_DDRB               0x0004
#define ADDR_REG_PINB               0x0003
#define ADDR_REG_Reserved_13        0x0002
#define ADDR_REG_Reserved_14        0x0001
#define ADDR_REG_Reserved_15        0x0000 


#define REG_EEARH              PTR_ADDRESS( ADDR_REG_EEARH       )
#define REG_EEARL              PTR_ADDRESS( ADDR_REG_EEARL       )
#define REG_EEDR               PTR_ADDRESS( ADDR_REG_EEDR        )
#define REG_EECR               PTR_ADDRESS( ADDR_REG_EECR        )
#define REG_GPIOR0             PTR_ADDRESS( ADDR_REG_GPIOR0      )
#define REG_EIMSK              PTR_ADDRESS( ADDR_REG_EIMSK       )
#define REG_EIFR               PTR_ADDRESS( ADDR_REG_EIFR        )
#define REG_PCIFR              PTR_ADDRESS( ADDR_REG_PCIFR       )
#define REG_Reserved_01        PTR_ADDRESS( ADDR_REG_Reserved_01 )
#define REG_Reserved_02        PTR_ADDRESS( ADDR_REG_Reserved_02 )
#define REG_Reserved_03        PTR_ADDRESS( ADDR_REG_Reserved_03 )
#define REG_TIFR2              PTR_ADDRESS( ADDR_REG_TIFR2       )
#define REG_TIFR1              PTR_ADDRESS( ADDR_REG_TIFR1       )
#define REG_TIFR0              PTR_ADDRESS( ADDR_REG_TIFR0       )
#define REG_Reserved_04        PTR_ADDRESS( ADDR_REG_Reserved_04 )
#define REG_Reserved_05        PTR_ADDRESS( ADDR_REG_Reserved_05 )
#define REG_Reserved_06        PTR_ADDRESS( ADDR_REG_Reserved_06 )
#define REG_Reserved_07        PTR_ADDRESS( ADDR_REG_Reserved_07 )
#define REG_Reserved_08        PTR_ADDRESS( ADDR_REG_Reserved_08 )
#define REG_Reserved_09        PTR_ADDRESS( ADDR_REG_Reserved_09 )
#define REG_Reserved_10        PTR_ADDRESS( ADDR_REG_Reserved_10 )
#define REG_Reserved_11        PTR_ADDRESS( ADDR_REG_Reserved_11 )
#define REG_Reserved_12        PTR_ADDRESS( ADDR_REG_Reserved_12 )
#define REG_PORTD              PTR_ADDRESS( ADDR_REG_PORTD       )
#define REG_DDRD               PTR_ADDRESS( ADDR_REG_DDRD        )
#define REG_PIND               PTR_ADDRESS( ADDR_REG_PIND        )
#define REG_PORTC              PTR_ADDRESS( ADDR_REG_PORTC       )
#define REG_DDRC               PTR_ADDRESS( ADDR_REG_DDRC        )
#define REG_PINC               PTR_ADDRESS( ADDR_REG_PINC        )
#define REG_PORTB              PTR_ADDRESS( ADDR_REG_PORTB       )
#define REG_DDRB               PTR_ADDRESS( ADDR_REG_DDRB        )
#define REG_PINB               PTR_ADDRESS( ADDR_REG_PINB        )
#define REG_Reserved_13        PTR_ADDRESS( ADDR_REG_Reserved_13 )
#define REG_Reserved_14        PTR_ADDRESS( ADDR_REG_Reserved_14 )
#define REG_Reserved_15        PTR_ADDRESS( ADDR_REG_Reserved_15 )



/* 
    160 Ext I/O Registers 
*/
#define ADDR_START_EXT_IO_REG       0x0060
#define ADDR_END_EXT_IO_REG         0x00FF

typedef enum
{
    bit_0_e = 0x00,  
    bit_1_e = 0x01,  
    bit_2_e = 0x02,  
    bit_3_e = 0x03,  
    bit_4_e = 0x04,  
    bit_5_e = 0x05,  
    bit_6_e = 0x06,  
    bit_7_e = 0x07,   
} bit_location_t;

/*
    Internal SRAM
    (1048 x 8)
*/
#define ADDR_START_INT_SRAM_REG      0x0100
#define ADDR_END_INT_SRAM_REG        0x08FF
#endif
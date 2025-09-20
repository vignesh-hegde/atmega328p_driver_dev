#include "main.h"

int main(void)
{
    init_pin_as(port_b_e, bit_5_e, digital_e, output_e);

    while (1)
    {
        toggle_digital_signal(port_b_e, bit_5_e);
        for (volatile long i = 0; i < 100000; i++); // crude delay
    }
}

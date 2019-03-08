#include "Click_Hall_Current_types.h"


const uint32_t _HALLCURRENT_SPI_CFG[ 3 ] = 
{ 
        1000000, 
        _SPI_MASTER, 
        _SPI_8_BIT | 
        _SPI_CLK_IDLE_LOW |
        _SPI_SECOND_CLK_EDGE_TRANSITION
};

#include "Click_Hall_Current_types.h"


const uint32_t _HALLCURRENT_SPI_CFG[ 3 ] = 
{ 
        _SPI_MASTER_CLK_RATIO_256,
        _SPI_CFG_POLARITY_IDLE_HIGH |
        _SPI_CFG_PHASE_CAPTURE_FALLING |
        _SPI_CFG_SS_AUTO_DISABLE | 
        _SPI_CFG_FIFO_DISABLE, 
        _SPI_SS_LINE_NONE 
};

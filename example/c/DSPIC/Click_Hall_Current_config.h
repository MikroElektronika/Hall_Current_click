#include "Click_Hall_Current_types.h"


const uint32_t _HALLCURRENT_SPI_CFG[ 8 ] = 
{ 
        _SPI_MASTER,
        _SPI_8_BIT, 
        _SPI_PRESCALE_SEC_4,
        _SPI_PRESCALE_PRI_4,
        _SPI_SS_DISABLE, 
        _SPI_DATA_SAMPLE_END,
        _SPI_CLK_IDLE_LOW, 
        _SPI_IDLE_2_ACTIVE 
};

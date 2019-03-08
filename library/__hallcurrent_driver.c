/*
    __hallcurrent_driver.c

-----------------------------------------------------------------------------

  This file is part of mikroSDK.

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

#include "__hallcurrent_driver.h"
#include "__hallcurrent_hal.c"

/* ------------------------------------------------------------------- MACROS */



/* ---------------------------------------------------------------- VARIABLES */

#ifdef   __HALLCURRENT_DRV_I2C__
static uint8_t _slaveAddress;
#endif

/* -------------------------------------------- PRIVATE FUNCTION DECLARATIONS */



/* --------------------------------------------- PRIVATE FUNCTION DEFINITIONS */



/* --------------------------------------------------------- PUBLIC FUNCTIONS */

#ifdef   __HALLCURRENT_DRV_SPI__

void hallcurrent_spiDriverInit(T_HALLCURRENT_P gpioObj, T_HALLCURRENT_P spiObj)
{
    hal_spiMap( (T_HAL_P)spiObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    hal_gpio_csSet( 1 );
}

#endif
#ifdef   __HALLCURRENT_DRV_I2C__

void hallcurrent_i2cDriverInit(T_HALLCURRENT_P gpioObj, T_HALLCURRENT_P i2cObj, uint8_t slave)
{
    _slaveAddress = slave;
    hal_i2cMap( (T_HAL_P)i2cObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif
#ifdef   __HALLCURRENT_DRV_UART__

void hallcurrent_uartDriverInit(T_HALLCURRENT_P gpioObj, T_HALLCURRENT_P uartObj)
{
    hal_uartMap( (T_HAL_P)uartObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif



/* ----------------------------------------------------------- IMPLEMENTATION */



/* Generic read 16-bit data function */
uint16_t hallcurrent_readData()
{
    uint8_t buffer[ 2 ];
    uint16_t result;

    hal_gpio_csSet( 0 );
    hal_spiRead( buffer, 2 );
    hal_gpio_csSet( 1 );
    
    result = buffer[ 0 ];
    result <<= 8;
    result |= buffer[ 1 ];
    
    return result;
}

/* Check status of read data function */
uint8_t hallcurrent_chackStatus()
{
    uint16_t readValue;

    readValue = hallcurrent_readData();

    if ( ( readValue >> 15 ) == 0 )
    {
        return 0;
    }
    else
    {
        return 1;
    }

}

/* Read electric current function */
float hallcurrent_readCurrent()
{
    float result;
    uint16_t currentValue;
    
    result = 0.0;
    
    currentValue = hallcurrent_readData();

    if ( !hallcurrent_chackStatus() )
    {
        currentValue &= 0x1FFF;
        
        currentValue -= 4096;
        
        result = ( float ) currentValue;
        result *= 0.0125;
    }
    
    if ( result > 50 )
        result = 0.0;

    return result;
}



/* -------------------------------------------------------------------------- */
/*
  __hallcurrent_driver.c

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

3. All advertising materials mentioning features or use of this software
   must display the following acknowledgement:
   This product includes software developed by the MikroElektonika.

4. Neither the name of the MikroElektonika nor the
   names of its contributors may be used to endorse or promote products
   derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY MIKROELEKTRONIKA ''AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL MIKROELEKTRONIKA BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

----------------------------------------------------------------------------- */
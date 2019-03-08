/*
    __hallcurrent_driver.h

-----------------------------------------------------------------------------

  This file is part of mikroSDK.
  
  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

/**
@file   __hallcurrent_driver.h
@brief    Hall_Current Driver
@mainpage Hall_Current Click
@{

@image html libstock_fb_view.jpg

@}

@defgroup   HALLCURRENT
@brief      Hall_Current Click Driver
@{

| Global Library Prefix | **HALLCURRENT** |
|:---------------------:|:-----------------:|
| Version               | **1.0.0**    |
| Date                  | **Oct 2018.**      |
| Developer             | **Nenad Filipovic**     |

*/
/* -------------------------------------------------------------------------- */

#include "stdint.h"

#ifndef _HALLCURRENT_H_
#define _HALLCURRENT_H_

/** 
 * @macro T_HALLCURRENT_P
 * @brief Driver Abstract type 
 */
#define T_HALLCURRENT_P    const uint8_t*

/** @defgroup HALLCURRENT_COMPILE Compilation Config */              /** @{ */

   #define   __HALLCURRENT_DRV_SPI__                            /**<     @macro __HALLCURRENT_DRV_SPI__  @brief SPI driver selector */
//  #define   __HALLCURRENT_DRV_I2C__                            /**<     @macro __HALLCURRENT_DRV_I2C__  @brief I2C driver selector */                                          
// #define   __HALLCURRENT_DRV_UART__                           /**<     @macro __HALLCURRENT_DRV_UART__ @brief UART driver selector */ 

                                                                       /** @} */
/** @defgroup HALLCURRENT_VAR Variables */                           /** @{ */



                                                                       /** @} */
/** @defgroup HALLCURRENT_TYPES Types */                             /** @{ */



                                                                       /** @} */
#ifdef __cplusplus
extern "C"{
#endif

/** @defgroup HALLCURRENT_INIT Driver Initialization */              /** @{ */

#ifdef   __HALLCURRENT_DRV_SPI__
void hallcurrent_spiDriverInit(T_HALLCURRENT_P gpioObj, T_HALLCURRENT_P spiObj);
#endif
#ifdef   __HALLCURRENT_DRV_I2C__
void hallcurrent_i2cDriverInit(T_HALLCURRENT_P gpioObj, T_HALLCURRENT_P i2cObj, uint8_t slave);
#endif
#ifdef   __HALLCURRENT_DRV_UART__
void hallcurrent_uartDriverInit(T_HALLCURRENT_P gpioObj, T_HALLCURRENT_P uartObj);
#endif


/** @defgroup HALLCURRENT_FUNC Driver Functions */                   /** @{ */


/**
 * @brief Generic read 16-bit data function
 *
 * @return result                       16-bit read data
 *
 * Function read the 16-bit data from the target register address
 * of TLI4970-D050T4 miniature magnetic digital current sensor
 */
uint16_t hallcurrent_readData();

/**
 * @brief Check status of read data function
 *
 * @return status
 * - 0 : OK, Sensor Value Message.
 * - 1 : ERROR, Sensor Status Message.
 *
 * Function read the 16-bit data from the target register address
 * and return 0 if data is valid or 1 of data not valid.
 */
uint8_t hallcurrent_chackStatus();

/**
 * @brief Read electric current function
 *
 * @return result                       float electric current data
 *
 * Function read the 16-bit data from the target register address
 * and calculate electric current value in [ A ].
 */
float hallcurrent_readCurrent();




                                                                       /** @} */
#ifdef __cplusplus
} // extern "C"
#endif
#endif

/**
    @example Click_Hall_Current_STM.c
    @example Click_Hall_Current_TIVA.c
    @example Click_Hall_Current_CEC.c
    @example Click_Hall_Current_KINETIS.c
    @example Click_Hall_Current_MSP.c
    @example Click_Hall_Current_PIC.c
    @example Click_Hall_Current_PIC32.c
    @example Click_Hall_Current_DSPIC.c
    @example Click_Hall_Current_AVR.c
    @example Click_Hall_Current_FT90x.c
    @example Click_Hall_Current_STM.mbas
    @example Click_Hall_Current_TIVA.mbas
    @example Click_Hall_Current_CEC.mbas
    @example Click_Hall_Current_KINETIS.mbas
    @example Click_Hall_Current_MSP.mbas
    @example Click_Hall_Current_PIC.mbas
    @example Click_Hall_Current_PIC32.mbas
    @example Click_Hall_Current_DSPIC.mbas
    @example Click_Hall_Current_AVR.mbas
    @example Click_Hall_Current_FT90x.mbas
    @example Click_Hall_Current_STM.mpas
    @example Click_Hall_Current_TIVA.mpas
    @example Click_Hall_Current_CEC.mpas
    @example Click_Hall_Current_KINETIS.mpas
    @example Click_Hall_Current_MSP.mpas
    @example Click_Hall_Current_PIC.mpas
    @example Click_Hall_Current_PIC32.mpas
    @example Click_Hall_Current_DSPIC.mpas
    @example Click_Hall_Current_AVR.mpas
    @example Click_Hall_Current_FT90x.mpas
*/                                                                     /** @} */
/* -------------------------------------------------------------------------- */
/*
  __hallcurrent_driver.h

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
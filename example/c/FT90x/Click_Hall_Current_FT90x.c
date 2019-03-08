/*
Example for Hall_Current Click

    Date          : Oct 2018.
    Author        : Nenad Filipovic

Test configuration FT90x :
    
    MCU                : FT900
    Dev. Board         : EasyFT90x v7 
    FT90x Compiler ver : v2.3.0.0

---

Description :

The application is composed of three sections :

- System Initialization - Initializes SPI, GPIO and LOG structures, set INT pin as input,
     CS pins as output.
- Application Initialization - Initialization driver enable's - SPI and start write log.
- Application Task - (code snippet) This is a example which demonstrates the use of Hall Current Click board.
     Hall Current Click communicates with register via SPI by read from register,
     read data and calculate electric current value in [ A ].
     Results are being sent to the Usart Terminal where you can track their changes.
     All data logs on usb uart for aproximetly every 5 sec.

Additional Functions :

- UART
- Conversions

*/

#include "Click_Hall_Current_types.h"
#include "Click_Hall_Current_config.h"


float currentReadFloat;
char logText[50];

void systemInit()
{
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_INT_PIN, _GPIO_INPUT );
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_CS_PIN, _GPIO_OUTPUT );

    mikrobus_spiInit( _MIKROBUS1, &_HALLCURRENT_SPI_CFG[0] );

    mikrobus_logInit( _MIKROBUS2, 9600 );

    Delay_ms( 100 );
}

void applicationInit()
{
    hallcurrent_spiDriverInit( (T_HALLCURRENT_P)&_MIKROBUS1_GPIO, (T_HALLCURRENT_P)&_MIKROBUS1_SPI );

    mikrobus_logWrite( "------------------------", _LOG_LINE );
    mikrobus_logWrite( "       Hall Current     ", _LOG_LINE );
    mikrobus_logWrite( "------------------------", _LOG_LINE );

    Delay_ms( 100 );
}

void applicationTask()
{
    currentReadFloat = hallcurrent_readCurrent();

    Delay_ms( 100 );

    FloatToStr( currentReadFloat, logText );

    mikrobus_logWrite( " Current : ", _LOG_TEXT );
    mikrobus_logWrite( logText, _LOG_TEXT );
    mikrobus_logWrite( " [ A ]", _LOG_LINE );
    mikrobus_logWrite( "------------------------", _LOG_LINE );

    Delay_ms( 5000 );
}

void main()
{
    systemInit();
    applicationInit();

    while (1)
    {
            applicationTask();
    }
}
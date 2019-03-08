![MikroE](http://www.mikroe.com/img/designs/beta/logo_small.png)

---

# Hall_Current Click

---

- **CIC Prefix**  : HALLCURRENT
- **Author**      : Nenad Filipovic
- **Verison**     : 1.0.0
- **Date**        : Oct 2018.

---

### Software Support

We provide a library for the Hall_Current Click on our [LibStock](https://libstock.mikroe.com/projects/view/1039/hall-current-click-board-example) 
page, as well as a demo application (example), developed using MikroElektronika 
[compilers](http://shop.mikroe.com/compilers). The demo can run on all the main 
MikroElektronika [development boards](http://shop.mikroe.com/development-boards).

**Library Description**

The library covers all the necessary functions to control Hall Current Click board.
Hall Current click communicates with the target board via SPI. 
This library contains drivers for read data, check status of read data 
and get electric current  from TLI4970-D050T4 miniature magnetic digital current sensor.


Key functions :

- ``` uint16_t hallcurrent_readData() ``` - Generic read 16-bit data function
- ``` uint8_t hallcurrent_chackStatus() ``` - Check status of read data function
- ``` float hallcurrent_readCurrent() ``` - Read electric current function

**Examples Description**

The application is composed of three sections :

- System Initialization - Initializes SPI, GPIO and LOG structures, set INT pin as input,
     CS pins as output.
- Application Initialization - Initialization driver enable's - SPI and start write log.
- Application Task - (code snippet) This is a example which demonstrates the use of Hall Current Click board.
     Hall Current Click communicates with register via SPI by read from register,
     read data and calculate electric current value in [ A ].
     Results are being sent to the Usart Terminal where you can track their changes.
     All data logs on usb uart for aproximetly every 5 sec.


```.c

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

```



The full application code, and ready to use projects can be found on our 
[LibStock](https://libstock.mikroe.com/projects/view/1039/hall-current-click-board-example) page.

Other mikroE Libraries used in the example:

- SPI
- UART
- Conversions

**Additional notes and informations**

Depending on the development board you are using, you may need 
[USB UART click](http://shop.mikroe.com/usb-uart-click), 
[USB UART 2 Click](http://shop.mikroe.com/usb-uart-2-click) or 
[RS232 Click](http://shop.mikroe.com/rs232-click) to connect to your PC, for 
development systems with no UART to USB interface available on the board. The 
terminal available in all Mikroelektronika 
[compilers](http://shop.mikroe.com/compilers), or any other terminal application 
of your choice, can be used to read the message.

---
---

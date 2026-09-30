/*
 Name       : Radhika Galagi

Date        : 11-09-2026

Project     : CAN BASED AUTOMOTIVE DASHBOARD (ECU1).

Description :  This project implements ECU1 sensor data transmission using the CAN protocol
               in an automotive embedded system. The system reads vehicle speed
               using the ADC module and detects gear position using the digital
               keypad interface. The processed data is periodically transmitted
               over the CAN bus to other ECUs.
 */
#include <xc.h>
#define _XTAL_FREQ 20000000
#pragma config OSC = HS, WDT = OFF, LVP = OFF, PBADEN = OFF
#include "can.h"
#include "clcd.h"
#include "message_handler.h"
static void init_config(void)
{
    TRISB = 0x08;
    LATB = 0;
    init_clcd();
    init_can();
}
void main(void)
{
    init_config();
    while (1)
    {
        process_canbus_data();
        __delay_ms(20);
    }
}

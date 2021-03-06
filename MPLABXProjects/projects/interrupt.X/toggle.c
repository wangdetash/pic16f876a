/*program to toggle using INTE external interrupt
 * File:   toggle.c
 * Author: tashi
 *
 * Created on 26 July, 2017, 10:44 AM
 */


// PIC16F876A Configuration Bit Settings

// 'C' source line config statements

// CONFIG
#pragma config FOSC = XT        // Oscillator Selection bits (XT oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#define _XTAL_FREQ 4000000

#include <xc.h>

int f=0;
void main()
{
    TRISC=0X00;
    PORTB=0XFF;
    INTE=1;
    INTF=0;
    INTEDG=1;
    while(1)
    {
        if(f==1)
        {
            PORTC=~PORTC;
        }
    }
}

static void interrupt isr()
{
    GIE=0;
    if(INTF==1)
    {
        INTF=0;
        f=1;
    }
    GIE=1;
}

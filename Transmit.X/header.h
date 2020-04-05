/* 
 * File:   header.h
 * Author: MohmedAly7
 *
 * Created on February 6, 2017, 10:34 PM
 */

#ifndef HEADER_H
#define	HEADER_H



#endif	/* HEADER_H */

// CONFIG
#pragma config FOSC = XT        // Oscillator Selection bits (XT oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = ON       // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)
#define _XTAL_FREQ 4000000 
// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>

void inilizeCounter ()
{
    TMR1ON =1 ;                 // enable Timer1 
    T1OSCEN = 0;                // disable  Oscillator
    TMR1CS =1 ;                 // enable external clock from bin   
    TMR1 =0;                    // inilize timer1 to zero
    
}
void inilizeTransmit()
{
    TRISC6=0;
    SPEN = 1;
    TXEN =1;
    SYNC =0;
    TX9 = 0;
    BRGH =1;
    SPBRG = 207;
            
}
void inilizeReciver()
{
    TRISC7=1;
    SPEN = 1;
    RX9 =0;
    BRGH =1;
    SPBRG = 207;
    CREN =1;
}
void transmit (char value)
{
    while (TXIF==0);
    TXIF=0;
    TXREG = value ;
}
char recive ()
{
 while (RCIF==0);
 RCIF=0;
 return (RCREG);
}


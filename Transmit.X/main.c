/*
 * File:   main.c
 * Author: MohmedAly7
 *
 * Created on February 12, 2017, 9:30 AM
 */


#include <xc.h>
#include "header.h"
char count =0 ;

void main(void) {
    TRISC0=1;
    TRISC1=1;
    inilizeCounter ();
    inilizeTransmit();
    
    while (1)
    {
        count = TMR1L ;
        transmit(count);
        
        
    }
    
    
    
    return;
}

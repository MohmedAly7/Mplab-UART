/*
 * File:   main.c
 * Author: MohmedAly7
 *
 * Created on February 13, 2017, 7:35 AM
 */


#include <xc.h>
#include "header.h"

char  count =0 ;
void main(void) {
 inilizeReciver();
    inilizeTransmit();
    TRISD=0;
  
    while (1)
    {
        transmit(count);
        if (count ==0)
        {RD0=1;
        }
        else if (count==2)
         RD0=0;
        else if (count ==49)
            RD1=1;
        else if (count == 50)
            RD1=0;
    }
    
    return;
}
void interrupt Recive( )
{ 
    if (RCIF)
    {
        count = RCREG ;
        __delay_ms(1000);
        transmit(count);
        RCIF=0;
    }
}


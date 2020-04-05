/*
 * File:   pic1main.c
 * Author: Lenovo
 *
 * Created on February 13, 2017, 7:21 AM
 */


#include <xc.h>
#include "header.h"
char  count = 0;
void main(void) {
    inilizeReciver() ;
    TRISB=0;
    
    while (1)
    {
        count =recive ();
        PORTB=count;
    }
    
    return;
}

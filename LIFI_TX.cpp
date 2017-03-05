/*!
** Written by Ivan Chan (mlc1g14@soton.ac.uk) & Dev Dixit (dd9g13@soton.ac.uk)
**
** @file main.c
** @version 0.1
** @brief 
        Lifi Transmitter
        Given a set of binary value, attempt to transmit using On-Off keying.
**/


#include "mbed.h"

//DigitalOut gpo(D0);
DigitalOut led(D1);

int strIn[16] = {1,0,1,0,1,1,1,0,0,1,0,1,0,0,1,0};

int main()
{
    while (true) {
        //gpo = !gpo; // toggle pin
        /*
        led = !led; // toggle led
        wait(0.05f);
        */
        for(int x = 0; x < 16; x++){
            if(strIn[x] == 0){
                led = 0;
            }else{
                led = 1;
            } 
            wait(0.02f);
        }
    }
    
    
}

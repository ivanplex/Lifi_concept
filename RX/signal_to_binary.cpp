/**
** Lifi-concept using embedded FRDM-K64F
**
** Written by Ivan Chan (mlc1g14@soton.ac.uk) & Dev Dixit (dd9g13@soton.ac.uk)
** 
** Project for Advance Computer Networks under the supervision of 
** Kirk Martinez (https://github.com/kmartinez) & Olli Bills (ob@ecs.soton.ac.uk)
**
**
** Signal Receiver
** The following implementation process binary signals according to the LDR reading.
**
**/
 
#include "mbed.h"

Serial pc(USBTX, USBRX);
AnalogIn sensor(A0);

/*
Threshold is the minimum reading for the signal to be 
determined as ON, any reading less than the threshold
would be considered as a zero.

Threshold must be redetermined if the surounding environment
have changed.
*/
int threshold = 100;

int main()
{
    pc.baud(9600);
    
    while (true) {
        if(sensor.read_u16() > threshold){
            pc.printf("ON");
            pc.printf("%u\n\r", sensor.read_u16());
        }else if(sensor.read_u16() <= threshold){
            pc.printf("OFF");
            pc.printf("%u\n\r", sensor.read_u16());
        }else{
            pc.printf("%s\n\r", "ERROR");
        }
        wait(0.2f);
    }
}

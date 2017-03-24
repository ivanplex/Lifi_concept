#include "mbed.h"

Serial pc(USBTX, USBRX);
DigitalOut gpo(D0);
DigitalOut led(LED_RED);
DigitalOut power(D2);
AnalogIn sensor(A0);

int main()
{
    power = 1;
    pc.baud(9600);
    while (true) {
        if(sensor.read() > 0){
            led = 1;
        }else{
            led = 0;
        }
        wait(0.2f);
        pc.printf("%u\n\r", sensor.read());
        
        /*
        pc.printf("%u\n", sensor.read());
        wait(0.2f);
        */
    }
}

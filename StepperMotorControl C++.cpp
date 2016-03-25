#include<iostream>
#include<stdio.h>
#include<wiringPi.h>

int main(void)
{
    if(wiringPiSetup() == -1)
    {       printf("quitting");
            return 1;
    }
    int i,halfstep,pin;
    int controlPin[4] = {22,23,24,25}; // GPIOs for wiringPi
    
    
    pinMode (22, OUTPUT); // bcm(GPIO on Rpi2) 31. Set as output
    pinMode (23, OUTPUT); // bcm(GPIO on Rpi2) 33
    pinMode (24, OUTPUT); // bcm(GPIO on Rpi2) 35
    pinMode (25, OUTPUT); // bcm(GPIO on Rpi2) 37
    
    digitalWrite(22, 0); // bring GPIOs to LOW
    digitalWrite(23, 0);
    digitalWrite(24, 0);
    digitalWrite(25, 0);
    
    // 1 = HIGH, 0 = LOW
    //control the speed/torque of stepper motor
    int seq[8][4] = { {1,0,0,0},
            {1,1,0,0},
            {0,1,0,0},
            {0,1,1,0},
            {0,0,1,0},
            {0,0,1,1},
            {0,0,0,1},
            {1,0,0,1}} ;
    
    // 1 revolution = 8 cycles
    // gear reduction = 1/64
    // 8x64 = 512 cycles
    for(i = 0;i<512;i = i + 1)
    {
            for(halfstep = 0;halfstep<8; halfstep = halfstep + 1)
            {
                    for(pin = 0;pin<4; pin = pin + 1)
                    {
                            digitalWrite(controlPin[pin], seq[halfstep][pin]);
                    }
    
            delay(100); // = 0.001ms
            }
    }
    // once the program ends
    digitalWrite(22, 0); // bring all GPIOs to LOW
    digitalWrite(23, 0);
    digitalWrite(24, 0);
    digitalWrite(25, 0);
    
    return 0;
}

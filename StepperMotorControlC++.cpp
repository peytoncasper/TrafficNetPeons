#include<iostream>
#include<stdio.h>
#include<wiringPi.h>
#include<stdlib.h>
#include<termios.h>
#include<unistd.h>
#include<sys/select.h>
#include<sys/ioctl.h>
#include<stropts.h>

int _kbhit(){
	static const int STDIN = 0;
	static bool initialized = false;
		
	if(!initialized){
		termios term;
		tcgetattr(STDIN, &term);
		term.c_lflag &= ~ICANON;
		tcsetattr(STDIN, TCSANOW, &term);
		setbuf(stdin, NULL);
		initialized = true;
	}

	int bytesWaiting;
	ioctl(STDIN, FIONREAD, &bytesWaiting);
	return bytesWaiting;
}

int main(void)
{
    
    if(wiringPiSetup() == -1)
    {       printf("quitting");
            return 1;
    }
    int i,halfstep,pin;
    int controlPin[4] = {26,27,28,29}; // GPIOs for wiringPi
    char key = 127; 
   pinMode (controlPin[0], OUTPUT); 
   pinMode (controlPin[1], OUTPUT);
   pinMode (controlPin[2], OUTPUT);
   pinMode (controlPin[3], OUTPUT);
   // pinMode (22, OUTPUT); // bcm(GPIO on Rpi2) 31. Set as output
   // pinMode (23, OUTPUT); // bcm(GPIO on Rpi2) 33
   // pinMode (24, OUTPUT); // bcm(GPIO on Rpi2) 35
   // pinMode (25, OUTPUT); // bcm(GPIO on Rpi2) 37
    
    digitalWrite(controlPin[0], 0); // bring GPIOs to LOW
    digitalWrite(controlPin[1], 0);
    digitalWrite(controlPin[2], 0);
    digitalWrite(controlPin[3], 0);
    
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
    do 
{
while(! _kbhit())
{
   	 key = getchar();
    	if(key == 27)
    	{
		key = getchar();
		if(key == 91)
		{
			key = getchar();
			if(key == 65)
			{
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
    
            					delay(1); // = 0.001ms
            				}
    				}
			}
         	}
	}
}

} while(key != '.');   
    
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
    
            delay(1); // = 0.001ms
            }
    }
    // once the program ends
    digitalWrite(controlPin[0], 0); // bring all GPIOs to LOW
    digitalWrite(controlPin[1], 0);
    digitalWrite(controlPin[2], 0);
    digitalWrite(controlPin[3], 0);
    
    return 0;
}

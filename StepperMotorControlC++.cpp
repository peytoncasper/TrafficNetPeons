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
    int controlPin[8] = {22,23,24,25,26,27,28,29}; // GPIOs for wiringPi
    char key = 127; 
    for(int i = 0; i < 8; i++)
    {
        pinMode(controlPin[i], OUTPUT);  
        digitalWrite(controlPin[i], 0); // bring GPIOs to LOW
                                      
    }
    // 1 = HIGH, 0 = LOW
    //control the speed/torque of stepper motor
    int sequence[8][4] = { {1,0,0,0},
            {1,1,0,0},
            {0,1,0,0},
            {0,1,1,0},
            {0,0,1,0},
            {0,0,1,1},
            {0,0,0,1},
            {1,0,0,1}} ;

     while(true)
     {
        if(_kbhit())
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
                        for(i = 0;i<50;i = i + 1)
                        {
                                for(halfstep = 0;halfstep<8; halfstep = halfstep + 1)
                                {
                                        for(pin = 0;pin<4; pin = pin + 1)
                                        { 
                                                digitalWrite(controlPin[pin], sequence[halfstep][pin]);
                                        }

                                        delay(1); // = 0.001ms
                                }
                        }
                    }
                    else if(key == 66)
                    {
                        for(i = 0;i<50;i = i + 1)
                        {
                                for(halfstep =7;halfstep >= 0; halfstep = halfstep - 1)
                                {
                                        for(pin = 3;pin >= 0; pin = pin - 1)
                                        { 
                                                digitalWrite(controlPin[pin], sequence[halfstep][pin]);
                                        }

                                        delay(1); // = 0.001ms
                                }
                        }
                    }
                    else if(key == 67)
                    {
                        for(i = 0;i<50;i = i + 1)
                        {
                                for(halfstep = 0;halfstep<8; halfstep = halfstep + 1)
                                {
                                        for(pin = 4;pin<8; pin = pin + 1)
                                        { 
                                                digitalWrite(controlPin[pin], sequence[halfstep][pin]);
                                        }

                                        delay(1); // = 0.001ms
                                }
                        }
                    }
                    else if(key == 68)
                    {
                        for(i = 0;i<50;i = i + 1)
                        {
                                for(halfstep =7;halfstep >= 0; halfstep = halfstep - 1)
                                {
                                        for(pin = 7;pin >= 4; pin = pin - 1)
                                        { 
                                                digitalWrite(controlPin[pin], sequence[halfstep][pin]);
                                        }

                                        delay(1); // = 0.001ms
                                }
                        }
                    }
                }
            }
        }
     }
//         while(true)
// {
//         if (_kbhit())
//         {
//                 key = getchar();
//                 if(key == 27)
//                 {
//                         key = getchar();
//                         if(key == 91)
//                         {
//                                 key = getchar();
//                                 if(key == 65)
//                                 {

//                                 }
//                                 else if(key == 66)
//                                 {

//                                 }
//                         }
//                 }
//         }
// }
// } while(key != '.');   
    
//     // 1 revolution = 8 cycles
//     // gear reduction = 1/64
//     // 8x64 = 512 cycles
//     for(i = 0;i<512;i = i + 1)
//     {
//             for(halfstep = 0;halfstep<8; halfstep = halfstep + 1)
//             {
//                     for(pin = 0;pin<4; pin = pin + 1)
//                     {
//                             digitalWrite(controlPin[pin], seq[halfstep][pin]);
//                     }
    
//             delay(1); // = 0.001ms
//             }
//     }
//     // once the program ends
    digitalWrite(controlPin[0], 0); // bring all GPIOs to LOW
    digitalWrite(controlPin[1], 0);
    digitalWrite(controlPin[2], 0);
    digitalWrite(controlPin[3], 0);
    
    return 0;
}

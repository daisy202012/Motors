/****************************************************************************************************************************************
* 
* Class: CSC-615-01 Spring 2020
*
* Name: Daisy Sanchez
* 
* Project: Motors & Motor Shield
*
* File: motor.c
*
* Description: For this program we will control two motors. We will use motor 1 and motor 2. 
* Motor 1 has pin 0 to enable and pins 2 and 3 to control. Motor 2 has pin 6 to enable and pins 4 and 5 to control.
* For this program both motors should move forward, backward, and stop. The motors should also have speed control (Pulse Width Modulation).
*
*****************************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <softPwm.h>
 


int main (void){

wiringPiSetup();

//Motor 1
// 0 is to enable
//2 and 3 to control
pinMode(0, OUTPUT);
pinMode(2, OUTPUT);
pinMode(3, OUTPUT);

//Motor 2
//6 is to enable
//4 and 5 to control
pinMode(6, OUTPUT);
pinMode(4, OUTPUT);
pinMode(5, OUTPUT);

int speed = 10;

softPwmCreate (0, speed, 100);
softPwmCreate (6, speed, 100);
  
int var = 0;
  
  while(var < 2) {
  
printf("Motor moving forward\n");

//Motor 1 moves forward
digitalWrite(0, HIGH);
digitalWrite(2, HIGH);
digitalWrite(3, LOW);

//Motor 2 moves forward
digitalWrite(6, HIGH);
digitalWrite(4, HIGH);
digitalWrite(5, LOW);

delay(5000);

printf("Motor moving backward\n");



//Motor 1 moves Backward 
digitalWrite(0, HIGH);
digitalWrite(2, LOW);
digitalWrite(3, HIGH);

//Motor 2 moves Backward
digitalWrite(6, HIGH); 
digitalWrite(4, LOW);
digitalWrite(5, HIGH);


delay(5000);

printf("Motors stop\n");

//Stop the Motors
digitalWrite(0, LOW);
digitalWrite(2, LOW);
digitalWrite(3, LOW);
digitalWrite(6, LOW);
digitalWrite(4, LOW);
digitalWrite(5, LOW);

var++;
speed += 30;

//Change speed
softPwmWrite(0, speed);
softPwmWrite(6, speed);

    }
  return  0;
} 

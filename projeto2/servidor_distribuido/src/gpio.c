#include <wiringPi.h> 
#include <softPwm.h>
#include <stdlib.h>
#include <stdio.h>
#include "../inc/gpio.h"
#include "../inc/push_notification.h"



int leGpio(int ref){

    pinMode(ref,INPUT);
    int result = digitalRead(ref);
    return result;
}

void configuragpio(){
    if (wiringPiSetup() < 0){
        printf("erro");
        exit(2);
    }
    pinMode(SA1, OUTPUT);
    pinMode(SA2, OUTPUT);
    pinMode(SA3, OUTPUT);
    pinMode(SA4, OUTPUT);
    pinMode(SA5, OUTPUT);
    pinMode(SA6, OUTPUT);
    pinMode(SP1, OUTPUT);
    pinMode(SP2, OUTPUT);

}

void LigaGpio(int ref){

    pinMode(ref, OUTPUT);
    digitalWrite(ref, HIGH);
}

void DesligaGpio(int ref){

    pinMode(ref, OUTPUT);
    digitalWrite(ref, LOW);
}



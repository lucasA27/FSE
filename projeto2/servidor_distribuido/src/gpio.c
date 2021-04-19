#include <wiringPi.h> 
#include <softPwm.h>
#include <stdlib.h>
#include <stdio.h>
#include "../inc/gpio.h"
#include "../inc/push_notification.h"

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

int leGpio(int ref){

    pinMode(ref,INPUT);
    int result = digitalRead(ref);
    return result;
}


void LigaGpio(int ref){

    pinMode(ref, OUTPUT);
    digitalWrite(ref, HIGH);
}

void DesligaGpio(int ref){

    pinMode(ref, OUTPUT);
    digitalWrite(ref, LOW);
}

void desligarDispositivos() {
  
    
  pinMode(AC1, OUTPUT);
  digitalWrite(AC1, LOW);


  pinMode(AC2, OUTPUT);
  digitalWrite(AC2, LOW);

  pinMode(LAMP1, OUTPUT);
  digitalWrite(LAMP1, LOW);

 
  pinMode(LAMP2, OUTPUT);
  digitalWrite(LAMP2, LOW);


  pinMode(LAMP3, OUTPUT);
  digitalWrite(LAMP3, LOW);

  
  pinMode(LAMP4, OUTPUT);
  digitalWrite(LAMP4, LOW);

  
}

#include <wiringPi.h> 
#include <softPwm.h>
#include <stdlib.h>
#include <stdio.h>

int wiringPiSetup();

int PWM_pin_vent = 5;

void LigaVentoinha(double ref ){

    if (wiringPiSetup() < 0){
        printf("erro");
        exit(2);
    }
    pinMode(PWM_pin_vent, OUTPUT);
    softPwmCreate(PWM_pin_vent, 0, 100);
    softPwmWrite(PWM_pin_vent, ref);
}

void DesligaVentoinha(){

    pinMode(PWM_pin_vent, OUTPUT);
    softPwmCreate(PWM_pin_vent, 0, 100);
    softPwmWrite(PWM_pin_vent, 0);
}

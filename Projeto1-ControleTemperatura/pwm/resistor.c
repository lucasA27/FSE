#include <wiringPi.h> 
#include <softPwm.h>
#include <stdlib.h>
#include <stdio.h>

int wiringPiSetup();

int PWM_pin_res = 4;

void LigaResistor(double ref){

    if (wiringPiSetup() < 0){
        printf("erro");
        exit(2);
    }
    pinMode(PWM_pin_res, OUTPUT);
    softPwmCreate(PWM_pin_res, 0, 100);
    softPwmWrite(PWM_pin_res, ref);
}

void DesligaResistor(){

    pinMode(PWM_pin_res, OUTPUT);
    softPwmCreate(PWM_pin_res, 0, 100);
    softPwmWrite(PWM_pin_res, 0);
}

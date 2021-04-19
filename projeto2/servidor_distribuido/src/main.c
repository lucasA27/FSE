#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include "../inc/bme280.h"
#include "../inc/gpio.h"
#include "../inc/servidor.h"
#include "../inc/bme280_control.h"
#include "../inc/push_notification.h"
#include <wiringPi.h>




int main(){

    configuragpio();

    setupsensor();
    
    distribuido();
    

return 0;
}

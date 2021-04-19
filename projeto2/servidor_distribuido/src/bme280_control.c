#include <stdio.h>
#include <stdlib.h>
#include "../inc/bme280.h"
#include "../inc/bme280_control.h"

void iniciaBme()
{
  int x = bme280Init(0x01, 0x76);
  if (x != 0)
    exit(1);
}

void lerBme()
{
    bme280ReadValues(&t, &p, &h);
}

float gTemperatura(){
    return (float) t/100.0;
}
float gPressao(){
    return (float) p/256.0;
}

float gUmidade(){
    return (float) h/1024.0;
}
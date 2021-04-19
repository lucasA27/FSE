#ifndef __BME280_control__
#define __BME280_control__

int t, p, h;

void iniciaBme();

void lerBme();

float gTemperatura();

float gUmidade();

#endif // __BME280_control__
#ifndef __UART__
#define __UART__

float TemperaturaInterna();
float TemperaturaPotenciometro();
short CRC16(short crc, char data);
short calcula_CRC(unsigned char *commands, int size);

#endif // __UART__
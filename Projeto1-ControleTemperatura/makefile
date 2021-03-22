make: uart bme280 lcd resistor ventoinha arquivo
	gcc ./main/index.c ./objects/*.o -o main.o -lwiringPi -lpthread

uart: ./gpio/uart.c pid
	gcc -c ./gpio/uart.c -o ./objects/uart.o

bme280: ./bme280/bme280.c
	gcc -c ./bme280/bme280.c -o ./objects/bme280.o 

pid: ./pid/pid.c
	gcc -c ./pid/pid.c -o ./objects/pid.o
	
lcd: ./lcd/lcd.c
	gcc -c ./lcd/lcd.c -o ./objects/lcd.o -lwiringPi

resistor: ./pwm/resistor.c
	gcc -c ./pwm/resistor.c -o ./objects/resistor.o -lpthread

ventoinha: ./pwm/ventoinha.c
	gcc -c ./pwm/ventoinha.c -o ./objects/ventoinha.o -lpthread

arquivo: ./arquivo/escreverArq.c
	gcc -c ./arquivo/escreverArq.c -o ./objects/escreverArq.o


make: bme280 bme gpio servidor client
	gcc ./src/main.c ./obj/*.o -o ./bin/bin -lwiringPi -lpthread

bme280: ./src/bme280.c
	gcc -c ./src/bme280.c -o ./obj/bme280.o

bme: ./src/bme280_control.c 
	gcc -c ./src/bme280_control.c -o ./obj/bme280_control.o
 
gpio: ./src/gpio.c
	gcc -c ./src/gpio.c -o ./obj/gpio.o

servidor: ./src/servidor.c
	gcc -c ./src/servidor.c -o ./obj/servidor.o


client: ./src/push_notification.c 
	gcc -c ./src/push_notification.c -o ./obj/push_notification.o

clean: 
	rm -r obj/*
	rm main.o
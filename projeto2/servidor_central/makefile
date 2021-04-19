make: client menu servidor
	gcc ./src/main.c ./obj/*.o -o ./bin/bin -lwiringPi -lpthread

client: ./src/client.c
	gcc -c ./src/client.c -o ./obj/client.o 

menu: ./src/menu.c
	gcc -c ./src/menu.c -o ./obj/menu.o

servidor: ./src/servidor.c
	gcc -c ./src/servidor.c -o ./obj/servidor.o

clean: 
	rm -r objects/*
	rm main.o
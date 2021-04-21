make: client menu servidor arquivo
	gcc ./src/main.c ./obj/*.o -o ./bin/bin -lwiringPi -lpthread

client: ./src/client.c
	gcc -c ./src/client.c -o ./obj/client.o 

menu: ./src/menu.c
	gcc -c ./src/menu.c -o ./obj/menu.o

servidor: ./src/servidor.c
	gcc -c ./src/servidor.c -o ./obj/servidor.o

arquivo: ./src/csv.c
	gcc -c ./src/csv.c -o ./obj/csv.o

clean: 
	rm -r objects/*
	rm main.o
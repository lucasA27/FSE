#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "../inc/gpio.h"
#include "../inc/bme280_control.h"
#include "../inc/bme280.h"

int socketCliente;
char mensagemCliente[50];

void temperaturaUmidade(){
	iniciaBme();
	float temperatura, umidade;
        lerBme();
        temperatura = gTemperatura();
        umidade = gUmidade();
        memset(&mensagemCliente, 0, sizeof(mensagemCliente));
        char t_string[10];
        char u_string[10];
    	memset(&t_string, 0, sizeof(t_string));
      	memset(&u_string, 0, sizeof(u_string));
        gcvt(temperatura, 4, t_string);
        gcvt(umidade, 4, u_string);

        strcat(mensagemCliente, "Temperatura = ");
        strcat(mensagemCliente, t_string);
        strcat(mensagemCliente, ", Umidade = ");
        strcat(mensagemCliente, u_string);
        strcat(mensagemCliente, "\0");
		
}

void TrataClienteTCP(int socketCliente) {
	char buffer[50];
	int tamanhoRecebido;

	if((tamanhoRecebido = recv(socketCliente, buffer, 50, 0)) < 0)
		printf("Erro no recv()\n");

	if(strncmp(buffer, "1", 1) == 0){
		LigaGpio(AC1);
	}else if(strncmp(buffer, "2", 1) == 0){
		LigaGpio(AC2);
	}else if(strncmp(buffer, "3", 1) == 0){
		DesligaGpio(AC1);
	}else if(strncmp(buffer, "4", 1) == 0){
		DesligaGpio(AC2);
	}else if(strncmp(buffer, "5", 1) == 0){
		LigaGpio(LAMP1);
	}else if(strncmp(buffer, "6", 1) == 0){
		LigaGpio(LAMP2);
	}else if(strncmp(buffer, "7", 1) == 0){
		LigaGpio(LAMP3);
	}else if(strncmp(buffer, "8", 1) == 0){
		LigaGpio(LAMP4);
	}else if(strncmp(buffer, "9", 1) == 0){
		DesligaGpio(LAMP1);
	}else if(strncmp(buffer, "a", 1) == 0){
		DesligaGpio(LAMP2);
	}else if(strncmp(buffer, "b", 1) == 0){
		DesligaGpio(LAMP3);
	}else if(strncmp(buffer, "c", 1) == 0){
		DesligaGpio(LAMP4);
	}
	else if(strncmp(buffer, "t", 1) == 0){
		temperaturaUmidade();
	}else{
		printf("comando invÃ¡lido");
	}

	while (tamanhoRecebido > 0) {
		if(strncmp(buffer, "t", 1) == 0){
			if(send(socketCliente, mensagemCliente, strlen(mensagemCliente), 0) < 0)
			printf("Erro no envio - send()\n");

		}
		if(send(socketCliente, buffer, tamanhoRecebido, 0) != tamanhoRecebido)
			printf("Erro no envio - send()\n");
		
		if((tamanhoRecebido = recv(socketCliente, buffer, 50, 0)) < 0)
			printf("Erro no recv()\n");
	}
	
}

void distribuido() {
	int servidorSocket;
	int socketCliente;
	struct sockaddr_in servidorAddr;
	struct sockaddr_in clienteAddr;
	unsigned short servidorPorta = 10107;
	unsigned int clienteLength;

	// Abrir Socket
	if((servidorSocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
		printf("falha no socker do Servidor\n");

	// Montar a estrutura sockaddr_in
	memset(&servidorAddr, 0, sizeof(servidorAddr)); // Zerando a estrutura de dados
	servidorAddr.sin_family = AF_INET;
	servidorAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servidorAddr.sin_port = htons(servidorPorta);

	// Bind
	if(bind(servidorSocket, (struct sockaddr *) &servidorAddr, sizeof(servidorAddr)) < 0)
		printf("Falha no Bind\n");

	// Listen
	if(listen(servidorSocket, 10) < 0)
		printf("Falha no Listen\n");		

	while(1) {
		clienteLength = sizeof(clienteAddr);
		if((socketCliente = accept(servidorSocket, 
			                      (struct sockaddr *) &clienteAddr, 
			                      &clienteLength)) < 0)
			printf("Falha no Accept\n");
		
		printf("ConexÃ£o do Cliente %s\n", inet_ntoa(clienteAddr.sin_addr));
		
		TrataClienteTCP(socketCliente);
		close(socketCliente);

	}
	close(servidorSocket);

}
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "../inc/gpio.h"
#include <wiringPi.h> 



void client() {
	int clienteSocket;
	char *mensagem;	
	unsigned int tamanhoMensagem;	
	struct sockaddr_in servidorAddr;
	unsigned short servidorPorta;
	char *IP_Servidor;
	char buffer[16];

	int bytesRecebidos;
	int totalBytesRecebidos;

	IP_Servidor = "192.168.0.53";
	servidorPorta = 10007;
	mensagem = "sensor detectado\n";

	// Criar Socket
	if((clienteSocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
		printf("Erro no socket()\n");

	// Construir struct sockaddr_in
	memset(&servidorAddr, 0, sizeof(servidorAddr)); // Zerando a estrutura de dados
	servidorAddr.sin_family = AF_INET;
	servidorAddr.sin_addr.s_addr = inet_addr(IP_Servidor);
	servidorAddr.sin_port = htons(servidorPorta);

	// Connect
	if(connect(clienteSocket, (struct sockaddr *) &servidorAddr, 
							sizeof(servidorAddr)) < 0)
		printf("Erro no connect()\n");

	tamanhoMensagem = strlen(mensagem);

	if(send(clienteSocket, mensagem, tamanhoMensagem, 0) != tamanhoMensagem)
		printf("Erro no envio: numero de bytes enviados diferente do esperado\n");


	totalBytesRecebidos = 0;
	while(totalBytesRecebidos < tamanhoMensagem) {
		if((bytesRecebidos = recv(clienteSocket, buffer, 16-1, 0)) <= 0)
			printf("Não recebeu o total de bytes enviados\n");
		totalBytesRecebidos += bytesRecebidos;
		buffer[bytesRecebidos] = '\0';
		printf("%s\n", buffer);
	}
	close(clienteSocket);
}


void enviaSensor(){
	client();	
}


void setupsensor(){
    wiringPiISR(SA1, INT_EDGE_RISING, &enviaSensor);
    wiringPiISR(SA2, INT_EDGE_RISING, &enviaSensor);
    wiringPiISR(SA3, INT_EDGE_RISING, &enviaSensor);
    wiringPiISR(SA4, INT_EDGE_RISING, &enviaSensor);
    wiringPiISR(SA5, INT_EDGE_RISING, &enviaSensor);
    wiringPiISR(SA6, INT_EDGE_RISING, &enviaSensor);
    wiringPiISR(SP1, INT_EDGE_RISING, &enviaSensor);
    wiringPiISR(SP2, INT_EDGE_RISING, &enviaSensor);
}

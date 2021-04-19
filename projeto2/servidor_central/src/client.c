#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int deveprintar = 1;

void set_deveprintar(int valor){
	deveprintar = valor;
}

int client(char *x) {
	int clienteSocket;
	struct sockaddr_in servidorAddr;
	unsigned short servidorPorta;
	char *IP_Servidor;
	char *mensagem;
	char buffer[50];
	unsigned int tamanhoMensagem;

	int bytesRecebidos;
	int totalBytesRecebidos;

	IP_Servidor = "192.168.0.4";
	servidorPorta = 10107;
	mensagem = x;

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
		if((bytesRecebidos = recv(clienteSocket, buffer, 50-1, 0)) <= 0)
			printf("Não recebeu o total de bytes enviados\n");
		totalBytesRecebidos += bytesRecebidos;
		buffer[bytesRecebidos] = '\0';
		if(deveprintar == 1)
			printf("%s\n", buffer);

	}
	close(clienteSocket);
}

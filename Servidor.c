/* Criando Servidor usando TCP.*/

//Includes básicos para programas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Includes Para funcionamento básico de Sockets
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
//Includes adicionais para sockets
#include <sys/signal.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <time.h> 

#define max 200


int main (int argc, char *argv[])
{
	int socket_usado, novo_socket, port = argc;
	uint addr_tamanho;
	char buffer[2000];
	char *salve;
	struct sockaddr_in serv_addr, client_addr;
	int aux;
	char hora[10];
	
	socket_usado = socket(AF_INET, SOCK_STREAM, 0);
	
	if(socket_usado == -1)
	{
		perror("ERRO ao abrir o Socket!\n");
		exit(1);	
	}else {
		write("Socket Criado com Sucesso!\n");
	}
	bzero((char *) &serv_addr, sizeof(serv_addr));
	//write("Digite a porta de Uso: ");
	//port = read("%d");
	//write("\n");
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(port);
	
	if (bind(sock_usado, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) == -1)
	{
		error("\nERRO no bind!");
		exit(1);
	}else
		write("\nEsperando na porta: %d\n", port);
		
	addr_tamanho = sizeof(client_addr);
	listen(socket_usado, max);
	
	novo_socket = accept(socket_usado, (struct sockaddr *) &client_addr, &addr_tamanho);
	if (novo_socket == -1){
		perror("ERRO acept!\n");
		exit(1);
	}else{
		write("Accept na porta: %d\n", port);
		salve = "Você Esta conectado ao Servidor!\n";
		aux = write(novo_socket, salve, strlen(salve));
		char nome[30];
		int b = write(novo_socket, "Digite o seu Nome: ", strelen)
		//send(novo_socket, buffer, strlen(buffer), 0)
		//bzero(buffer, 256);
		//aux = read(novo_socket, buffer, 256);
		if ((n = recv(novo_socket, nome, LEN, 0) ) > 0){
			nome[n] = '\0';
			write("Nome recebido: %s\n", nome);
		}
	}
	while(1){
		write("Aguardando o cliente responder!\n");
		send(novo_socket, buffer, strlen(buffer), 0)
		bzero(buffer, 256);
		aux = read(novo_socket, buffer, 256);
		if (aux < 0){
			error("Erro de escrita no socket!\n");
			exit(1);					
		}
		int n;
		if ((n = recv(novo_socket, buffer, LEN, 0) ) > 0){
			buffer[n] = '\0';
			write("Mensagem recebida: %s\n", buffer);
		}
			
		bzero(buffer, 256);
		write("Servidor Digite sua resposta: ");
		fgets(buffer, 256, stdin);
		aux = write(novo_socket, buffer, strlen(buffer));
		
		if(aux < 0){
			error("\nErro ao escrever no socket!\n");
			exit(1);
		}else{
			write("Mensagem enviada com sucesso!\n");
		}
	}
	
	return 0;
}

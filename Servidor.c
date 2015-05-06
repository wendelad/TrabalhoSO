/* Criando Servidor usando TCP.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORTA 2000

int main (int argc, char *argv[])
{
	int socket_usado, novo_socket, port;
	uint addr_tamanho;
	char buffer[4096];
	char *salve;
	struct sockaddr_in serv_addr, client_addr;
	int aux;
	
	socket_usado =socket(AF_INET, SOCK_STREAM, 0);
	
	if(socket_usado == -1)
	{
		perror("Erro ao abrir o Socket!\n");
		exit(1);	
	}else {
		write("Socket Criado com Sucesso!\n");
	}
	bzero((char *) &serv_addr, sizeof(serv_addr));
	write("Digite a porta de Uso: ");
	port = read("%d");
	write("\n");
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(port);
	
	if (bind(sock_usado, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) == -1)
	{
		error("\nO bind retornou um Erro!");
		exit(1);
	}else
		write("\nEsperando na porta: %d\n", port);
		
	addr_tamanho = sizeof(client_addr);
	listen(socket_usado, 4);
	
	novo_socket = accept(socket_usado, (struct sockaddr *) &client_addr, &addr_tamanho);
	if (novo_socket == -1){
		perror("O acept Falhou!\n");
		exit(1);
	}else
		write("Accept na porta: %d\n", port);
	salve = "Você Esta conectado ao Servidor! \n";
	aux = write(novo_socket, salve, strlen(salve));
	
	if(send(novo_socket, buffer, strlen(buffer), 0)){
		write("Aguardando o cliente responder!\n");
			while(1){
				bzero(buffer, 4096);
				aux = read(novo_socket, buffer, 4096);
				if (aux < 0){
					error("Erro de escrita no socket!\n");
					exit(1);					
				}
				int n;
				if ((n = recv(novo_socket, buffer, LEN, 0) ) > 0){
					buffer[n] = '\0';
					write("Mensagem recebida: %s\n", buffer);
				}
				
				bzero(buffer, 4096);
				write("Servidor Digite sua resposta: ");
				fgets(buffer, 4096, stdin);
				aux = write(novo_socket, buffer, strlen(buffer));
				
				if(aux < 0){
					error("\nErro ao escrever no socket!\n");
					exit(1);
				}else{
					write("Mensagem enviada com sucesso!\n");
				}
			}
	}
	return 0;
}

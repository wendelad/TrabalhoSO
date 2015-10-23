/*Cliente para o sistema de chat do trabalho de SO, aqui usaremos TCP*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*heaers para sockets*/
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>

struct sockaddr_in server;
struct sockaddr_in cliente;

int main (int argc, char **argv)
{
	int socket, porta, p;
	char buffer[2048];
	
	if (argc < 3)
	{
		fprintf(stderr, "usando a porta: %s do Hostname", argv[0]);
	}
	
	port = atoi(argv[2]);
}

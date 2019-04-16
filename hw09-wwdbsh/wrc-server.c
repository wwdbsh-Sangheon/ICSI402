#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>

#define PORT "3838"
#define BACKLOG 10
#define BUFLEN 65536
#define LOCALHOST "127.0.0.1"
#define HOST "localhost:3838/ls"
#define DATA "Hello Server!"

int main(int argc, char* argv[])
{
	int server_sock, client_sock, new_sock, rv, yes = 1;
	struct addrinfo hints, *servinfo, *p;
	struct sockaddr_storage their_addr;
	struct sockaddr_in server;
	char server_buffer[BUFLEN], client_buffer[BUFLEN];
	socklen_t addr_size;

/* Server */

	memset(&hints, 0X00, sizeof(hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;

	if((rv = getaddrinfo("127.0.0.1", PORT, &hints, &servinfo)) == -1)
	{
		fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(rv)); fflush(stdout);
		exit(1);
	}

	for(p = servinfo; p != NULL; p = p->ai_next)
	{
		if((server_sock = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1)
		{
			perror("Server:");
			continue;
		}

		if(setsockopt(server_sock, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) == -1)
		{
			close(server_sock);
			perror("setsockopt");
			exit(1);
		}

		if(bind(server_sock, p->ai_addr, p->ai_addrlen) == -1)
		{
			close(server_sock);
			perror("Server: bind");
			continue;
		}
	}

	freeaddrinfo(servinfo);

	if(listen(server_sock, BACKLOG) == -1)
	{
		perror("Server: listen");
		exit(1);
	}

	printf("waiting for connecting...\n"); fflush(stdout);

/* Client */

	memset(&hints, 0X00, sizeof(hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;

	if((rv = getaddrinfo("127.0.0.1", PORT, &hints, &servinfo)) == -1)
	{
		fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(rv)); fflush(stdout);
		exit(1);
	}

	for(p = servinfo; p != NULL; p = p->ai_next)
	{
		if((client_sock = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1)
		{
			perror("Client:");
			continue;
		}

		if(setsockopt(client_sock, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) == -1)
		{
			close(client_sock);
			perror("setsockopt");
			exit(1);
		}

		if(connect(client_sock, p->ai_addr, p->ai_addrlen) == -1)
		{
			close(client_sock);
			perror("Client: connect");
			continue;
		}
	}

	freeaddrinfo(servinfo);

/* Accept */

	addr_size = sizeof(their_addr);

	while(1)
	{
		if((new_sock = socket(server_sock, (struct sockaddr*)&their_addr, &addr_size)) == -1)
			perror("Server: accept");
		else
		{
			if(send(client_sock, DATA, sizeof(DATA), 0) == -1)
			{
				perror("Send:");
				exit(1);
			}

			memset(&server_buffer, 0X00, sizeof(server_buffer));

			if((rv = recv(new_sock, server_buffer, sizeof(server_buffer), 0)) == -1)
				perror("Read:");
			else
			{
				printf("MSG: %s\n", server_buffer); fflush(stdout);
			}

		}
	}

	close(new_sock);
	close(server_sock);
	close(client_sock);

	return 0;
}
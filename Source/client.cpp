#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
// #include <sys/types.h>
// #include <sys/socket.h>
#include "../include/client.h"
#define DEBUG

#define n_client 4
#define serv_port 19999

#ifdef DEBUG
#define TRACE_PRINTF(x) printf x
#endif


client::client()
{
	printf("created client\n");
}
int client::create_socket()
{
	// int socketid;
	// struct sockaddr_in serv_addr; // address of socket of the server
	if ( (socketid = socket(AF_INET, SOCK_STREAM, 0)) < 0 )
	{
		printf("Cannot create client socket\n");
		return -1;
	}
	printf("Socket created...\n");
	// memset(&serv_addr, 0, sizeof(serv_addr));
	// serv_addr.sin_family = AF_INET;
	// serv_addr.sin_port = 19999;
	// // printf("port: %d, family: %d\n", serv_addr.sin_port, serv_addr.sin_family);
	// int retaton = inet_aton("192.6.7.9", &serv_addr.sin_addr);
	// if (!retaton)
	// {
	// 	printf("IP address invalid\n");
	// 	return -1;
	// }
	// printf("ip of server is: %s\n", inet_ntoa(serv_addr.sin_addr));
	printf("ip of this client is: %s\n", this->getip());
	return socketid;
}

const char * client::getip()
{
	return this->client_ip;
}

int client::connect_to_server(int sock_id)
{
	struct sockaddr_in serv_addr;
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(atoi("16001"));
	serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	int c = connect(sock_id, (struct sockaddr *) & serv_addr, sizeof(serv_addr));
	if (c == -1)
		{
			printf("Can't connect to server\n");
			return -1;
		}
	// printf("c: %d\n", c);
	char recv_buffer[256];
	int count  = recv(this->socketid, &recv_buffer, sizeof(recv_buffer), 0);
	printf("%s\n", recv_buffer);
	return c;
}

int client::client_run(int sock_id)
{
	this->connect_to_server(sock_id);
	return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "../include/client.h"
#include "../include/server.h"

#define DEBUG
#ifdef DEBUG
#define TRACE_PRINTF(x) printf x
#endif


int main()
{
	// pthread_t server_thread, client_thread;

	// create server socket
	server s1;
	int server_socket = s1.create_socket();
	// pthread_create(&server_thread, NULL, s1.run, NULL);
	s1.run();
	// struct sockaddr_in serv_addr; // address of socket of the server
	// memset(&serv_addr, 0, sizeof(serv_addr));
	// serv_addr.sin_family = AF_INET;
	// serv_addr.sin_port = 19999;
	// int retaton = inet_aton("192.6.7.9", &serv_addr.sin_addr);
	// if (!retaton)
	// {
	// 	printf("IP address invalid\n");
	// 	return -1;
	// }
	// printf("ip of server is: %s\n", inet_ntoa(serv_addr.sin_addr));

	// handle client
	// client c1;
	// int client_socket = c1.create_socket();
	// TRACE_PRINTF(("Starting client application...\n"));
	// c1.client_run(client_socket);	
	return 0;
}

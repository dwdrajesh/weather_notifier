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
    time_t t1;
    int res = 0;
    srand((unsigned) time(&t1));
    
    // char ip[64] = {0};
    for (int i = 0; i < 4; i++)
    {
        char temp[3];
        res = rand();
        sprintf(temp, "%d", res%255);
        strncat(this->client_ip, temp, 3);
        if (i < 3) strncat(this->client_ip, ".", 1);
    }
	printf("created client\n");
}
int client::create_socket()
{
	if ( (socketid = socket(AF_INET, SOCK_STREAM, 0)) < 0 )
	{
		printf("Cannot create client socket\n");
		return -1;
	}
	printf("Socket created...\n");
	printf("ip of this client is: %s\n", this->getip());
	return socketid;
}

char * client::getip()
{
    printf("ip: %s\n", this->client_ip);
	return this->client_ip;
}

int client::connect_to_server(int sock_id, char * ip)
{
	struct sockaddr_in serv_addr;
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(atoi("19001"));
	serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	int c = connect(sock_id, (struct sockaddr *) & serv_addr, sizeof(serv_addr));
	if (c == -1)
		{
			printf("Can't connect to server\n");
			return -1;
		}
	// printf("c: %d\n", c);
	char recv_buffer[256];
	while (1)
	{

		send(sock_id, ip, 64, 0);
		int count  = recv(this->socketid, &recv_buffer, sizeof(recv_buffer), 0);
		printf("%s\n", recv_buffer);	
		send(sock_id, ip, 64, 0);	
	}

	return c;
}

int client::client_run(int sock_id, char * ip)
{
	this->connect_to_server(sock_id, ip);
	return 0;
}
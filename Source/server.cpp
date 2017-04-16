#include <stdio.h>
#include <pthread.h>
#include "../include/server.h"
#define DEBUG

#define n_client 4
#define serv_port 19999

#ifdef DEBUG
#define TRACE_PRINTF(x) printf x
#endif

server::server()
{
	printf("server created\n");
}
int server::create_socket()
{
	// int socketid;
	// struct sockaddr_in serv_addr; // address of socket of the server
	if ( (this->socketid = socket(AF_INET, SOCK_STREAM, 0)) < 0 )
	{
		printf("Cannot create server socket\n");
		return -1;
	}
	printf("Server socket created...\n");
	printf("ip of the server is: %s\n", this->getip());
	return socketid;
}

int get_data(char * str)
{
	char location[64] = " ottawa canada";
	// char command[] = "./wunderground_wrapper/weather ottawa canada";
	char command[256] = "./wunderground_wrapper/weather ";
	strcat(command, location);
	printf("command: %s\n", command);
	FILE * fp = popen(command, "r");
	if 	(!fp)
	{
		printf("Can't open the weather program\n");
		return -1;
	}
	// char str[] = {0};
	// fread(str, 10, 1, fp);
	fgets(str, 256, fp);

	return 0;
}

int server::run()
{
	struct sockaddr_in serv_addr;
	memset(&serv_addr, 0, sizeof(&serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(atoi("19001"));
	serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	int bind_ret;
	if ( (bind_ret = bind(this->socketid, (struct sockaddr *)&serv_addr, sizeof(serv_addr))) < 0 )
		{
			printf("bind_ret: %d, can't bind server socket to serv_addr\n", bind_ret);
			return -1;
		}
	else
		{
			printf("Server socket bind\n");
		}

	int lis_ret = listen(this->socketid, 1);

	while(1)
	{
		struct sockaddr_in client_addr;
		socklen_t client_addr_len = sizeof(client_addr);
		int conn_sockid = accept(this->socketid, (struct sockaddr *) & client_addr, &client_addr_len);

		pthread_t threadid;
		if (pthread_create(&threadid, NULL,  this->connection_handler, (void *)&conn_sockid) )
		{
			printf("Cannot create thread for this client\n");
			return -1;
		}
		// pthread_join(threadid, NULL);
		// connection_handler(&conn_sockid);
	
	}

	// while(1);
	return 0;
}

void * server::connection_handler(void * conn_sockid)
{
	int sockid = *(int *)conn_sockid;
	char output_string[256] = {0};
	char input_string[256] = {0};
	while(1)
	{
		char client_ip[64] = {0};
		int count  = recv(sockid, &client_ip, sizeof(client_ip), 0);
		printf("This client ip: %s\n", client_ip);
		// printf("%s\n", client_ip);
		// strncpy(client_ips[0], client_ip, 64);
		get_data(output_string);
		send(sockid, &output_string, sizeof(output_string), 0);
		// memcpy(output_string, "hello\n", 256);
		// output_string = "hello\n";
		sleep(5);
		// send(sockid, &output_string, sizeof(output_string), 0);		
	}

	// for(int j = 0; j <= client_count; j++)
		// printf("Client ip %d: %s\n", j, client_ips[j]);	
}

const char * server::getip()
{
	return this->server_ip;
}




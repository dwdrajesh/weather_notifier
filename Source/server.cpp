#include <stdio.h>
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
	char command[] = "./wunderground_wrapper/weather ottawa canada";
	FILE * fp = popen(command, "r");
	if 	(!fp)
	{
		printf("Can't open the weather program\n");
		return -1;
	}
	// char str[] = {0};
	// fread(str, 10, 1, fp);
	fgets(str, 256, fp);
	// puts(str);
	// while( fgets(str, 256, fp) != NULL)
	// 	{
	// 		puts(str);
	// 	}
	
	// pclose(fp);
	return 0;
}

int server::run()
{
	struct sockaddr_in serv_addr;
	memset(&serv_addr, 0, sizeof(&serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(atoi("16001"));
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
	struct sockaddr_in client_addr;
	socklen_t client_addr_len = sizeof(client_addr);
	int conn_sockid = accept(this->socketid, (struct sockaddr *) & client_addr, &client_addr_len);
	char send_buffer[] = "Rajesh Dawadi\n";
	// send(conn_sockid, &send_buffer, sizeof(send_buffer), 0);

	char output_string[256] = {0};
	get_data(output_string);
	send(conn_sockid, &output_string, sizeof(output_string), 0);
	// system("./wunderground/weather ottawa canada");
	return 0;
}



const char * server::getip()
{
	return this->server_ip;
}
// int main()
// {
// 	TRACE_PRINTF(("Starting server application...\n"));
	
// 	return 0;
// }




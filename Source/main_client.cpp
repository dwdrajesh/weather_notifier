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


int main(int argc, char * argv[])
{
	char * ip = argv[1];


	// handle client
	client c1;
	int client_socket = c1.create_socket();
	TRACE_PRINTF(("Starting client application...\n"));
	printf("This client ip: %s\n", c1.getip());
	c1.client_run(client_socket, c1.getip());	
	return 0;
}

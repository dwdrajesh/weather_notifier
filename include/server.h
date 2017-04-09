#ifndef SERVER_H
#define SERVER_H
#include <arpa/inet.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
class server
{
public:
	server();
	int create_socket();
	int bind_socket();
	int run_server();
	const char * getip();
	int run();
	// ~server();
private:
	int socketid;
	const char * server_ip = "172.16.116.197";
	struct sockaddr_in serv_addr;
};

#endif
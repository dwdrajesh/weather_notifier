#ifndef CLIENT_H
#define CLIENT_H

#include <time.h>



class client
{
public:
	client();
	int create_socket();
	int connect_to_server(int sock_id, char * ip);
	int client_run(int sock_id, char * ip);
	char * getip();
	// ~client();
private:
	char rxstring[64];
	int socketid;
	int client_port;
	char client_ip[16] = {0};
};

#endif
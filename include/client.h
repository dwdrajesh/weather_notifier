#ifndef CLIENT_H
#define CLIENT_H




class client
{
public:
	client();
	int create_socket();
	int connect_to_server(int sock_id);
	int client_run(int sock_id);
	const char * getip();
	// ~client();
private:
	char rxstring[64];
	int socketid;
	int client_port;
	const char * client_ip = "172.16.116.110";
};

#endif
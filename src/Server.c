// the core of our HTTP server is here 

#include "stdio.h" 
#include "stdlib.h"
#include "netinet/in.h"
#include "sys/socket.h"

// define HTTP_server struct 

typedef struct HTTP_server {
    int port;
    int socket;
    struct sockaddr_in address;
} HTTP_server;

void init_http(HTTP_server *server, int port) {
    server->port = port;

    server->socket = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in address; // create a socket address 

    address.sin_family = AF_INET; 
    address.sin_addr.s_addr = INADDR_ANY; 
    address.sin_port = htons(port); 

    bind(server->socket, (struct sockaddr *) &address, sizeof(address));

    listen(server->socket, 5); 

    server->address = address; 

    printf("Server started on port %d" , port); 
}

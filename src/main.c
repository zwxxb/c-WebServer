#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h> 
#include <netinet/in.h>
#include <fcntl.h>
#include <errno.h>

#include "Server.c" 
#include "Routing.c"
#include "Reponse.c"

int main() {
    // initialize the server

    int port = 8080;
    HTTP_server *server = malloc(sizeof(HTTP_server)); 
    init_http(server, port); 

    int client_socket; 

    // add routes 
    init_routes();

    while (1) {
        client_socket = accept(server->socket, NULL, NULL); 
        char request[1024] = {0} ; 
        read(client_socket, request, 2000); // :D
        printf("Request: %s", request); 

        // parse the request 
        char *method = strtok(request, " "); 
        char *path = strtok(NULL, " "); 
        char *protocol = strtok(NULL, " "); 

        // get the route 
        struct Route *route = get_route(path, method); 
        if (route == NULL) {
            char *response = render_static_file("/static/404.html"); 
            send(client_socket, response, strlen(response), 0); 
        }
        else {
            char *response = render_static_file(route->response); 
            send(client_socket, response, strlen(response), 0); 
        }

        close(client_socket);
    }
    

}
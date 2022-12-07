#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

// return route struct 
struct Route {
    char *path;
    char *method;
    char *response;
};

struct Route *routes[100]; 

struct Route *initRoute(char *path, char *method, char *response) {
    struct Route *route = malloc(sizeof(struct Route)); 
    route->path = path; 
    route->method = method; 
    route->response = response; 
    return route; 
}

struct Route *get_route(char *path, char *method) {
    for (int i = 0; i < 100; i++) {
        struct Route *route = routes[i];
        if (route == NULL) {
            return NULL; 
        }
        if (strcmp(route->path, path) == 0 && strcmp(route->method, method) == 0) {
            return route; 
        }
    }
    return NULL; 
}

struct Route add_route(char *path, char *method, char *response) {
    for (int i = 0; i < 100; i++) {
        if (routes[i] == NULL) {
            routes[i] = initRoute(path, method, response); 
            return *routes[i]; 
        }
    }
}


void init_routes() {
    add_route("/", "GET", "Hello World"); 
    add_route("/about", "GET", "Pwnin' the world one byte at a time"); 
    add_route("/login", "POST", "Login Page"); 
}
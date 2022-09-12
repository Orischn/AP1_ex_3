#include <iostream>
#include "server.hpp"
#include "cli.hpp"
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

typedef void* (*THREADFUNCPTR)(void*);
void* runServer(Server* server);

int main() {
    Server server(42069);
    runServer(&server);
    return 0;
}

void* runServer(Server* server) {
    int sock = server->acceptClient();
    pthread_t thread;
    pthread_create(&thread, NULL, (THREADFUNCPTR)runServer, server);
    if (sock < 0) {
        std::cout<<"error connecting to client\n";
        return NULL;
    }
    CLI* cli = new CLI(sock);
    cli->start();
    close(sock);
    delete cli;
    return NULL;
}
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include "sock.hpp"

#define SERVER_PORT 1234

void sock::bindSocket(int sock) {
    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(SERVER_PORT);
    if (bind(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        perror("error binding socket");
    }
    if (listen(sock, 5) < 0) {
        perror("error listening to a socket");
    }
}

int sock::acceptClient(int sock) {
    struct sockaddr_in client_sin;
    unsigned int addr_len = sizeof(client_sin);
    int client_socket = accept(sock,  (struct sockaddr *) &client_sin,  &addr_len);
    if (client_socket < 0) {
        perror("error accepting client");
    }
    return client_socket;
}
#include <iostream>
#include <fstream>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include "client.hpp"
#include "standardIO.hpp"
#include "socketIO.hpp"

#define BUFFER_SIZE 512

Client::Client() {
    this->sock = socket(AF_INET, SOCK_STREAM, 0);
    if (this->sock < 0) {
        perror("error creating socket");
        exit(1);
    }
}

Client::~Client() {
    close(this->sock);
}

void Client::connectToServer(const char* ip, int port) {
    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = inet_addr(ip);
    sin.sin_port = htons(port);
    if (connect(this->sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        close(this->sock);
        perror("error connecting to server");
        exit(1);
    }
}

void Client::read() {
    SocketIO sockio(this->sock);
    StandardIO stdio;
    stdio.write(sockio.read());
}

void Client::write() {
    SocketIO sockio(this->sock);
    StandardIO stdio;
    sockio.write(stdio.read());
}


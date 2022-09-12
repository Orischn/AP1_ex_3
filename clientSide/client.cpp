#include <iostream>
#include <fstream>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string>
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

std::string Client::read() {
    SocketIO sockio(this->sock);
    StandardIO stdio;
    std::string readString = sockio.read();
    stdio.write(readString);
    return readString;
}

std::string Client::write() {
    SocketIO sockio(this->sock);
    StandardIO stdio;
    std::string readString(stdio.read());
    sockio.write(readString);
    return readString;
}


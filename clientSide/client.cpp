#include <iostream>
#include <fstream>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include "client.hpp"

#define BUFFER_SIZE 512

Client::Client() {
    this->sock = socket(AF_INET, SOCK_STREAM, 0);
    if (this->sock < 0) {
        perror("error creating socket");
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
    }
}

void Client::sendData(char* inputPath) {
    std::ifstream input;
    input.open(inputPath);
    char unclassifiedData[BUFFER_SIZE];
    int i = 0;
    while(!input.eof()) {
        input.get(unclassifiedData[i++]);
    }
    input.close();
    int sent = send(this->sock, unclassifiedData, BUFFER_SIZE, 0);
    if (sent < 0) {
        close(this->sock);
        perror("error sending data");
    }
}

void Client::handleResponse(char* outputPath) {
    char classifiedData[BUFFER_SIZE];
    int read_bytes = recv(this->sock, classifiedData, BUFFER_SIZE, 0);
    else if (read_bytes < 0) {
        close(this->sock);
        perror("error recieving data");
    }
    else {
        std::ofstream output;
        output.open(outputPath);
        output<<classifiedData;
        output.close();
    }
}

#include <iostream>
#include <sys/socket.h>
#include <fstream>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "sock.hpp"
#define BUFFER_SIZE 512

int main(int argc, char* argv[]) {
    const char* ip_address = "127.0.0.1";
    const int port = 42069; //hehe

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("error creating socket");
    }
    sock::connectToServer(sock, ip_address, port);
    std::ifstream input;
    input.open(argv[1]);
    char unclassifiedData[BUFFER_SIZE];
    int i = 0;
    while(!input.eof()) {
        input.get(unclassifiedData[i++]);
    }
    input.close();
    int sent_bytes = send(sock, unclassifiedData, BUFFER_SIZE, 0);

    if (sent_bytes < 0) {
        perror("error sending data");
    }

    char classifiedData[BUFFER_SIZE];
    int read_bytes = recv(sock, classifiedData, BUFFER_SIZE, 0);
    if (read_bytes == 0) {
        perror("connection was closed");
    }
    else if (read_bytes < 0) {
        perror("error recieving data");
    }
    else {
        std::ofstream output;
        output.open(argv[2]);
        output<<classifiedData;
        output.close();
    }
    close(sock);
    return 0;
}
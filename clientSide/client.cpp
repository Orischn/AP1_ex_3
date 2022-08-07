#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "sock.hpp"

int main() {
    const char* ip_address = "127.0.0.1";
    const int port = 1234;

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("error creating socket");
    }

    sock::connectToServer(sock, ip_address, port);
    char data_addr[] = "flower stuff";
    int sent_bytes = send(sock, data_addr, strlen(data_addr), 0);

    if (sent_bytes < 0) {
    // error
    }

    char buffer[4096];
    int read_bytes = recv(sock, buffer, sizeof(buffer), 0);
    if (read_bytes == 0) {
    // connection is closed
    }
    else if (read_bytes < 0) {
    // error
    }
    else {
        std::cout<<buffer<<std::endl;
    }

    close(sock);


    return 0;
}
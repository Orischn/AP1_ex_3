#include <iostream>
#include "server.hpp"
#include "cli.hpp"
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() {
    Server server(42069);
    while(1) {
        int sock = server.acceptClient();
        if (sock < 0) {
            std::cout<<"error connecting to client\n";
            continue;
        }
        CLI* cli = new CLI(sock);
        cli->start();
        close(sock);
        delete cli;
    }
    return 0;
}
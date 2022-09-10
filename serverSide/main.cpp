#include <iostream>
#include "server.hpp"
#include "cli.hpp"

int main() {
    Server server(42069);
    while(1) {
        int sock = server.acceptClient();
        if (sock < 0) {
            std::cout<<"error connecting to client\n";
            continue;
        }
        CLI cli(sock);
        cli.start();
    }
    return 0;
}
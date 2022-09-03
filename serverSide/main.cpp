#include "server.hpp"
#include "cli.hpp"

int main() {
    /*Server server(42069);
    while(1) {
        server.acceptClient();
    }*/
    CLI cli;
    cli.start();
    return 0;
}
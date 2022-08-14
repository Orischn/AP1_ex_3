#include "server.hpp"

int main() {
    Server server(42069);
    while(1) {
        server.acceptClient();
    }
    return 0;
}
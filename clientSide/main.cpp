#include "client.hpp"

int main(int argc, char* argv[]) {
    const char* ip = "127.0.0.1";
    const int port = 42069;
    Client client;
    client.connectToServer(ip, port);
    client.sendData(argv[1]);
    client.handleResponse(argv[2]);
}
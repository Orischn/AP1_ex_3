#include "client.hpp"
#include "socketIO.hpp"
#include "standardIO.hpp"
#include <pthread.h>

typedef void* (THREADFUNCPTR)(void);
void read(Client client);

int main(int argc, char* argv[]) {
    const char* ip = "127.0.0.1";
    const int port = 42069;
    Client* client = new Client();
    client->connectToServer(ip, port);
    pthread_t thread;
    pthread_create(&thread, NULL, (THREADFUNCPTR)read, client);
    while (true) {
        client.write();
    }
}

void read(Client client) {
    while (true) {
        client->read();
    }
}
#include <pthread.h>
#include <string>
#include <iostream>
#include "client.hpp"
#include "socketIO.hpp"
#include "standardIO.hpp"


typedef void* (*THREADFUNCPTR)(void*);
void* read(Client* client);

int main(int argc, char* argv[]) {
    const char* ip = "127.0.0.1";
    const int port = 42069;
    Client* client = new Client();
    client->connectToServer(ip, port);
    pthread_t thread;
    pthread_create(&thread, NULL, (THREADFUNCPTR)read, client);
    std::string writtenString = "default";
    while (writtenString.compare("7")) {
        writtenString = client->write();
    }
    pthread_join(thread, NULL);
    delete client;
}

void* read(Client* client) {
    std::string readString = "default";
    while (readString.compare("")) {
        readString = client->read();
    }
    return NULL;
}
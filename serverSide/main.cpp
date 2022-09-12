#include <iostream>
#include "server.hpp"
#include "cli.hpp"
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define TIMEOUT 10E6 // 10 seconds
typedef void* (*THREADFUNCPTR)(void*);
void* runServer(int*);
void* timeout(pthread_t*);

int main() {
    Server server(42069);
    std::vector<pthread_t> threads;
    pthread_t acceptingThread = pthread_self();
    pthread_t timeoutThread;
    while(true) {
        pthread_create(&timeoutThread, NULL, (THREADFUNCPTR)timeout, &acceptingThread);
        int sock = server.acceptClient();
         if (sock < 0) {
            std::cout<<"error connecting to client\n";
            pthread_cancel(timeoutThread);
            continue;
        }
        pthread_cancel(timeoutThread);
        pthread_t thread;
        threads.push_back(thread);
        pthread_create(&threads.back(), NULL, (THREADFUNCPTR)runServer, &sock);
    }
    return 0;
}

void* runServer(int* sock) {
    CLI* cli = new CLI(*sock);
    cli->start();
    close(*sock);
    delete cli;
    pthread_exit(NULL);
}

void* timeout(pthread_t* runningThread) {
    const clock_t startingTime = clock();
    while(clock() - startingTime < TIMEOUT);
    pthread_cancel(*runningThread);
    pthread_exit(NULL);
}

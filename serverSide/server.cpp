#include <vector>
#include <string.h>
#include <fstream>
#include <iostream>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "flower.hpp"
#include "server.hpp"

#define BUFFER_SIZE 512
#define TEMP_FILE_PATH "serverSide/tempDataFile.csv"
#define CLASSIFIED_FILE_PATH "serverSide/classified.csv"

Server::Server(int port) {
    this->server = socket(AF_INET, SOCK_STREAM, 0);
    if (this->server < 0) {
        perror("error creating socket");
        exit(1);
    }
    this->bindToPort(port);
}

Server::~Server() {
    close(this->server);
}

void Server::bindToPort(int port) {
    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(port);
    if (bind(this->server, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        close(this->server);
        perror("error binding socket");
        exit(1);
    }
    if (listen(this->server, 10) < 0) {
        close(this->server);
        perror("error listening to a socket");
        exit(1);
    }
}

void Server::acceptClient() {
    struct sockaddr_in client_sin;
    unsigned int addr_len = sizeof(client_sin);
    int subServer = accept(this->server,  (struct sockaddr *) &client_sin,  &addr_len);
    if (subServer < 0) {
        close(this->server);
        perror("error accepting client");
        return;
    }
    handleDataFromClient(subServer);
}

void Server::handleDataFromClient(int sock) {
    while(true) {
        char unclassifiedData[BUFFER_SIZE];
        int read_bytes = recv(sock, unclassifiedData, sizeof(unclassifiedData), 0);
        if (read_bytes == 0) {
            close(sock);
            return;
        }
        else if (read_bytes < 0) {
            close(sock);
            std::cout<<"error receiving from client";
            return;
        }
        // else {
        //     std::vector<Flower> classifiedFlowers = file::getDataFromFile(CLASSIFIED_FILE_PATH);
        //     std::ofstream output;
        //     output.open(TEMP_FILE_PATH);
        //     output<<unclassifiedData;
        //     output.close();
        //     std::vector<Flower> unclassifiedFlowers = file::getDataFromFile(TEMP_FILE_PATH);
        //     remove(TEMP_FILE_PATH);
        //     for (Flower& flower : unclassifiedFlowers) {
        //         flower.classifyFlower(classifiedFlowers, 3, &Flower::euclidianDisTo);
        //     }
        //     file::writeDataToFile(unclassifiedFlowers, TEMP_FILE_PATH);
        //     std::ifstream input;
        //     input.open(TEMP_FILE_PATH);
        //     char classifiedData[BUFFER_SIZE];
        //     int i = 0;
        //     while (!input.eof()) {
        //         input.get(classifiedData[i++]);
        //     }
        //     input.close();
        //     remove(TEMP_FILE_PATH);
        //     int sent_bytes = send(sock, classifiedData, BUFFER_SIZE, 0);
        //     if (sent_bytes < 0) {
        //         close(sock);
        //         std::cout<<"error sending to client";
        //         return;
        //     }
        // }
    }
}
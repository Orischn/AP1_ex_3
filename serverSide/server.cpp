#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sys/socket.h>
#include <unistd.h>
#include "file.hpp"
#include "flower.hpp"
#include "sock.hpp"

#define SERVER_PORT 1234
#define BUFFER_SIZE 4096

int main(int argc, char** argv) {
    const int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("error creating socket");
    }
    sock::bindSocketToPort(sock, SERVER_PORT);
    while (true) {
        int client_sock = sock::acceptClient(sock);

        char unclassifiedData[BUFFER_SIZE];
        int read_bytes = recv(client_sock, unclassifiedData, sizeof(unclassifiedData), 0);
        if (read_bytes == 0) {
            perror("connection was closed");
        }
        else if (read_bytes < 0) {
            perror("error");
        }
        else {
            std::ofstream output;
            output.open("serverSide/tempDataFile.csv");
            output<<unclassifiedData;
            output.close();
            std::vector<Flower> unclassifiedFlowers = file::getDataFromFile("serverSide/tempDataFile.csv");
            std::vector<Flower> classifiedFlowers = file::getDataFromFile("serverSide/classified.csv");
            for (Flower& flower : unclassifiedFlowers) {
                flower.classifyFlower(classifiedFlowers, 3, &Flower::euclidianDisTo);
            }
            file::writeDataToFile(unclassifiedFlowers, "serverSide/tempDataFile.csv");
        }
        std::ifstream input;
        input.open("serverSide/tempDataFile.csv");
        char classifiedData[BUFFER_SIZE];
        int i = 0;
        while (!input.eof()) {
            input.get(classifiedData[i++]);
        }
        int sent_bytes = send(client_sock, classifiedData, read_bytes, 0);
        if (sent_bytes < 0) {
            perror("error sending to client");
        }
        input.close();
        remove("serverSide/tempDataFile.csv");
    }
    close(sock);
    return 0;
}
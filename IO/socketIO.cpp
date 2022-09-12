#include "socketIO.hpp"
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <iostream>

#define BUFFER_SIZE 512

SocketIO::SocketIO(int sock) {
	this->sock = sock;
}

std::string SocketIO::read() {
	char buffer[BUFFER_SIZE];
	int recvBytes = recv(this->sock, buffer, BUFFER_SIZE, 0);
	if (recvBytes == 0) {
		return "";
	}
	std::string input(buffer);
	return input;
}

void SocketIO::write(std::string output) {
	send(this->sock, output.c_str(), BUFFER_SIZE, 0);
}
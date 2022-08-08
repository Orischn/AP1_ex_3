#ifndef ADVNACEDPROGRAMMING_EX_2_SERVERSIDE_SOCK_H_
#define ADVNACEDPROGRAMMING_EX_2_SERVERSIDE_SOCK_H_

namespace sock {
    void bindSocketToPort(const int sock, const int port);
    int acceptClient(const int sock);
    void connectToServer(const int sock, const char* ip, const int port);
};

#endif
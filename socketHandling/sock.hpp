#ifndef ADVNACEDPROGRAMMING_EX_2_SERVERSIDE_SOCK_H_
#define ADVNACEDPROGRAMMING_EX_2_SERVERSIDE_SOCK_H_

namespace sock {
    void bindSocketToPort(int sock, int port);
    int acceptClient(int sock);
    void connectToServer(int sock, const char* ip, int port);
};

#endif
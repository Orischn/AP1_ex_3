#ifndef ADVNACEDPROGRAMMING_EX_2_SERVERSIDE_SOCK_H_
#define ADVNACEDPROGRAMMING_EX_2_SERVERSIDE_SOCK_H_

namespace sock {
    void bindSocket(int sock);
    int acceptClient(int sock);
};

#endif1
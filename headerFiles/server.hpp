#ifndef EX_3_HEADERFILES_SERVER_H
#define EX_3_HEADERFILES_SERVER_H

class Server {
private:
    int server;
    void bindToPort(int port);
public:
    Server(int port);
    ~Server();
    int acceptClient();
};

#endif
#ifndef EX_3_HEADERFILES_SERVER_H
#define EX_3_HEADERFILES_SERVER_H

class Server {
    private:
        int server;
        void bindToPort(int port);
        void handleDataFromClient(int client);
    public:
        Server(int port);
        ~Server();
        void acceptClient();
};

#endif
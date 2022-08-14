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
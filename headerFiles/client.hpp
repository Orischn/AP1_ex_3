class Client {
    private:
        int sock;
    public:
        Client();
        ~Client();
        void connectToServer(const char* ip, const int port);
        void sendData(char* inputPath);
        void handleResponse(char* outputPath);
};
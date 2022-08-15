class Client {
    private:
        int sock;
    public:
        Client();
        ~Client();
        void connectToServer(const char* ip, const int port);
        void sendData(const char* data);
        void handleResponse(char* outputPath);
        void handleData(char* inputPath, char* outputPath);
};
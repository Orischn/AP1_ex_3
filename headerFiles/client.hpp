#ifndef EX_3_HEADERFILES_CLIENT_H
#define EX_3_HEADERFILES_CLIENT_H

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

#endif
#ifndef EX_3_HEADERFILES_CLI_H
#define EX_3_HEADERFILES_CLI_H

#include "command.hpp"
#include "settings.hpp"
#include "testAndTrainData.hpp"
#include "socketIO.hpp"
#include <string>
#include <vector>

class CLI{
private:
    std::vector<Command*> commands;
    int sock;
    Settings* settings;
    TestAndTrainData* TATData;
public:
    CLI(int);
    ~CLI();
    void start();
};

#endif
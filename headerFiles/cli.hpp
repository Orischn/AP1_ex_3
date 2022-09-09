#ifndef EX_3_HEADERFILES_CLI_H
#define EX_3_HEADERFILES_CLI_H

#include "command.hpp"
#include <string>
#include <vector>

class CLI{
private:
    std::vector<Command*> commands;
public:
    CLI();
    void start();
 
};

#endif
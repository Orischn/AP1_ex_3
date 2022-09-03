#ifndef EX_3_HEADERFILES_CLI_H
#define EX_3_HEADERFILES_CLI_H


#include <string>
#include "command.hpp"
#include <vector>

class CLI{
private:
    std::vector<Command*> commands;
public:
    void start();
 
};

#endif
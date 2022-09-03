#ifndef EX_3_HEADERFILES_CLI_H
#define EX_3_HEADERFILES_CLI_H


#include <string>
#include "command.hpp"

class CLI : public Command{
public:
    void start();
};

#endif
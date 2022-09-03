#ifndef EX_3_HEADERFILES_COMMAND_H
#define EX_3_HEADERFILES_COMMAND_H

#include <string>
#include "defaultIO.hpp"

class Command {
    public:
        std::string description;
        DefaultIO dio;
        virtual void execute() = 0;
};

#endif
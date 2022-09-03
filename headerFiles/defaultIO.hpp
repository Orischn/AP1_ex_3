#ifndef EX_3_HEADERFILES_DEFAULTIO_H_
#define EX_3_HEADERFILES_DEFAULTIO_H_

#include <string>
#include "command.hpp"

class DefaultIO :: public Command{
    public:
        virtual std::string read();
        virtual void write(std::string);
};

#endif
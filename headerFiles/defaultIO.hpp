#ifndef EX_3_HEADERFILES_DEFAULTIO_H_
#define EX_3_HEADERFILES_DEFAULTIO_H_

#include <string>

class DefaultIO {
public:
    virtual std::string read() = 0;
    virtual void write(std::string) = 0;
};

#endif
#ifndef EX_3_HEADERFILES_STANDARDIO_H_
#define EX_3_HEADERFILES_STANDARDTIO_H_

#include "defaultIO.hpp"

class StandardIO : public DefaultIO {
public:
    std::string read() override;
    void write(std::string) override;
};

#endif
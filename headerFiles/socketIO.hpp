#ifndef EX_3_HEADERFILES_SOCKETIO_H_
#define EX_3_HEADERFILES_SOCKETIO_H_

#include "defaultIO.hpp"

class SocketIO : public DefaultIO {
public:
    std::string read() override;
    void write(std::string) override;
};

#endif
#include "command.hpp"


class DisplayResultsCMD : public Command {
public:
    DisplayResultsCMD();
    void execute() override;
};
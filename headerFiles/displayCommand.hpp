#include "command.hpp"


class DisplayResultsCMD : public Command {
public:
    DisplayResultsCMD(DefaultIO*);
    void execute() override;
};
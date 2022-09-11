#include "command.hpp"


class DownloadResultsCMD : public Command {
public:
    DownloadResultsCMD(DefaultIO*);
    void execute() override;
};
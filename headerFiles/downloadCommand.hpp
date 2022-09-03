#include "command.hpp"


class DownloadResultsCMD : public Command {
public:
    DownloadResultsCMD();
    void execute() override;
};
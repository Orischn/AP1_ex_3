#include "command.hpp"
#include "testAndTrainData.hpp"
#include "defaultIO.hpp"

class DownloadResultsCMD : public Command {
private:
    TestAndTrainData* TATData;
public:
    DownloadResultsCMD(DefaultIO*, TestAndTrainData*);
    ~DownloadResultsCMD();
    void execute() override;
};
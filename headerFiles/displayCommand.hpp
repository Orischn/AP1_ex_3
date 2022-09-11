#include "command.hpp"
#include "testAndTrainData.hpp"
#include "defaultIO.hpp"

class DisplayResultsCMD : public Command {
private:
    TestAndTrainData* TATData;
public:
    DisplayResultsCMD(DefaultIO*, TestAndTrainData*);
    void execute() override;
};
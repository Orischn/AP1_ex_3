#include "command.hpp"
#include "defaultIO.hpp"
#include "testAndTrainData.hpp"

class UploadFileCMD : public Command {
private:
    TestAndTrainData* TATData;
public:
    UploadFileCMD(DefaultIO*, TestAndTrainData*);
    ~UploadFileCMD();
    void execute() override;
};
#include "command.hpp"
#include "settings.hpp"
#include "testAndTrainData.hpp"
#include "defaultIO.hpp"

class AlgorithmConfusionMatrixCMD : public Command {
private:
    Settings* settings;
    TestAndTrainData* TATData;
public:
    AlgorithmConfusionMatrixCMD(DefaultIO*, Settings*, TestAndTrainData*);
    ~AlgorithmConfusionMatrixCMD();
    void execute() override;
};
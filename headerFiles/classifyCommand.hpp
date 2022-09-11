#include "command.hpp"
#include "flower.hpp"
#include "defaultIO.hpp"
#include "settings.hpp"
#include "testAndTrainData.hpp"
#include <vector>
#include <string>

class ClassifyDataCMD : public Command {
private:
    Settings* settings;
    TestAndTrainData* TATData;
public:
    ClassifyDataCMD(DefaultIO*, Settings*, TestAndTrainData*);
    void execute() override;
};
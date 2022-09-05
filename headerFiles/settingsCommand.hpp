#include "command.hpp"
#include "flower.hpp"
#include <string>

class AlgoSettingsCMD : public Command {
private:
    static AlgoSettingsCMD* instance;
    int k;
    std::string distanceFunc;
    AlgoSettingsCMD(DefaultIO*);
public:
    static AlgoSettingsCMD* getInstance(DefaultIO*);
    void execute() override;
    int getK();
    std::string getDistanceFunc();
};
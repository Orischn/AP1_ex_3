#include "command.hpp"
#include "flower.hpp"
#include <string>

class AlgoSettingsCMD : public Command {
private:
    static int k;
    static std::string distanceFunc;
public:
    AlgoSettingsCMD();
    void execute() override;
    static int getK();
    static std::string getDistanceFunc();
};
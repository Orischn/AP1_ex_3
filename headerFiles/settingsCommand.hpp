#include "command.hpp"
#include "flower.hpp"
#include <string>

class AlgoSettingsCMD : public Command {
private:
    Settings* settings;
public:
    AlgoSettingsCMD(DefaultIO*, Settings*);
    void execute() override;
};
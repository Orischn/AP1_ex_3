#include "command.hpp"
#include "flower.hpp"
#include "settings.hpp"
#include <string>

class AlgoSettingsCMD : public Command {
private:
    Settings* settings;
public:
    AlgoSettingsCMD(DefaultIO*, Settings*);
    ~AlgoSettingsCMD();
    void execute() override;
};
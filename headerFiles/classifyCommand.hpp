#include "command.hpp"
#include "flower.hpp"
#include "defaultIO.hpp"
#include "settings.hpp"
#include <vector>
#include <string>

class ClassifyDataCMD : public Command {
private:
    std::vector<Flower> getFlowersFromFile(std::string path);
    Settings* settings;
public:
    ClassifyDataCMD(DefaultIO*, Settings*);
    void execute() override;
};
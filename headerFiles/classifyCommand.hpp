#include "command.hpp"
#include "flower.hpp"
#include "defaultIO.hpp"
#include <vector>
#include <string>

class ClassifyDataCMD : public Command {
public:
    ClassifyDataCMD(DefaultIO*);
    void execute() override;
private:
    std::vector<Flower> getFlowersFromFile(std::string path);
};
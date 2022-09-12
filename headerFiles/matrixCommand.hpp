#include "command.hpp"


class AlgorithmConfusionMatrixCMD : public Command {
public:
    AlgorithmConfusionMatrixCMD();
    ~AlgorithmConfusionMatrixCMD();
    void execute() override;
};
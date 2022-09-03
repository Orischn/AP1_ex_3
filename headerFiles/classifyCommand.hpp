#include "command.hpp"

class ClassifyDataCMD : public Command {
    public:
        ClassifyDataCMD();
        void execute() override;
}
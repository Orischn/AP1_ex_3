#include "command.hpp"

class UploadFileCMD : public Command {
    public:
        UploadFileCMD(DefaultIO*);
        void execute() override;
};
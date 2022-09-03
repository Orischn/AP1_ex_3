#include "command.hpp"

class UploadFileCMD : public Command {
    public:
        UploadFileCMD();
        void execute() override;
}
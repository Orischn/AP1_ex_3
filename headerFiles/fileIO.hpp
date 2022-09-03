#include "defaultIO.hpp"

class FileIO : public DefaultIO {
    private:
        std::string path;
    public:
        FileIO(std::string);
        std::string read() override;
        void write(std::string) override;
};
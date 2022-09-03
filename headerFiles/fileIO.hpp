#include "defaultIO.hpp"

class FileIO : public DefaultIO {
    private:
        std::string path;
    public:
        FileIO();
        FileIO(std::string);
        std::string read() override;
        void write(std::string) override;
        void setPath(std::string);

};
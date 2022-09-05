#include "uploadCommand.hpp"
#include "fileIO.hpp"
#include "standardIO.hpp"

UploadFileCMD::UploadFileCMD(DefaultIO* dio) {
    this->description = "upload an unclassifed csv data file";
    this->dio = dio;
}

void UploadFileCMD::execute() {
    dio->write("Please upload your local train csv file.\n");
    FileIO fio(dio->read());
    std::string data = fio.read();
    fio.setPath("Commands/train.csv");
    fio.write(data);

    dio->write("Please upload your local test csv file.\n");
    fio.setPath(dio->read());
    data = fio.read();
    fio.setPath("Commands/test.csv");
    fio.write(data);
}
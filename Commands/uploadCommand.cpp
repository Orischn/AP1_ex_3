#include "uploadCommand.hpp"
#include "fileIO.hpp"
#include "standardIO.hpp"

UploadFileCMD::UploadFileCMD() {
    this->description = "upload an unclassifed csv data file";
}

void UploadFileCMD::execute() {
    dio->write("Please upload your local train csv file.");
    FileIO fio(dio->read());
    std::string data = fio.read();
    fio.setPath("train.csv");
    fio.write(data);

    dio->write("Please upload your local test csv file.");
    fio.setPath(dio->read());
    data = fio.read();
    fio.setPath("test.csv");
    fio.write(data);
}
#include "uploadCommand.hpp"
#include "fileIO.hpp"
#include "standardIO.hpp"

UploadFileCMD::UploadFileCMD(DefaultIO* dio, TestAndTrainData* TATData) {
    this->description = "upload an unclassifed csv data file";
    this->dio = dio;
    this->TATData = TATData;
}

void UploadFileCMD::execute() {
    FileIO fio;
    dio->write("Please upload your local train csv file.\n");
    fio.setPath(dio->read());
    std::string data = fio.read();
    TATData->setTrainData(data);

    dio->write("Please upload your local test csv file.\n");
    fio.setPath(dio->read());
    data = fio.read();
    TATData->setTestData(data);
}
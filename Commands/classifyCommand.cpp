#include "classifyCommand.hpp"
#include "settingsCommand.hpp"
#include "testAndTrainData.hpp"
#include "fileIO.hpp"

ClassifyDataCMD::ClassifyDataCMD(DefaultIO* dio, Settings* settings, TestAndTrainData* TATData) {
    this->description = "classify data";
    this->dio = dio;
    this->settings = settings;
    this->TATData = TATData;
}

ClassifyDataCMD::~ClassifyDataCMD() {
    delete dio;
}

void ClassifyDataCMD::execute() {
    std::vector<Flower> cFlowers = TATData->getTrainDataVector();
    std::vector<Flower> ucFlowers = TATData->getTestDataVector();
    for (int i = 1; i <= ucFlowers.size(); i++) {
        if (settings->getDistanceFunc().compare("EUC") == 0) {
            ucFlowers[i - 1].classifyFlower(cFlowers, settings->getK(), &Flower::euclidianDisTo);
        }
        if (settings->getDistanceFunc().compare("MAN") == 0) {
            ucFlowers[i - 1].classifyFlower(cFlowers, settings->getK(), &Flower::manhattanDisTo);
        }
        if (settings->getDistanceFunc().compare("CHE") == 0) {
            ucFlowers[i - 1].classifyFlower(cFlowers, settings->getK(), &Flower::chebyshevDisTo);
        }
    }
    std::string data;
    for (int i = 0; i < ucFlowers.size(); i++) {
        data += ucFlowers[i].getFlowerType() + "\n";
    }
    TATData->setResults(data);
}


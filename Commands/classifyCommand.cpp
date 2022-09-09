#include "classifyCommand.hpp"
#include "settingsCommand.hpp"
#include "fileIO.hpp"
#include <sstream>

ClassifyDataCMD::ClassifyDataCMD(DefaultIO* dio, Settings* settings) {
    this->description = "classify data";
    this->dio = dio;
    this->settings = settings;
}

void ClassifyDataCMD::execute() {
    std::vector<Flower> cFlowers = getFlowersFromFile("Commands/train.csv");
    std::vector<Flower> ucFlowers = getFlowersFromFile("Commands/test.csv");
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
    dio->write(data);
}

std::vector<Flower> ClassifyDataCMD::getFlowersFromFile(std::string path) {
    std::vector<Flower> cFlowers;
    FileIO reader(path);
    std::string sFlowers = reader.read();
    std::stringstream ssFlowers(sFlowers);
    std::string sFlower;
    while(getline(ssFlowers, sFlower)) {
        cFlowers.push_back(Flower::stof(sFlower));
    }
    return cFlowers;
}
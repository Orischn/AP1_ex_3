#include "settingsCommand.hpp"

AlgoSettingsCMD::AlgoSettingsCMD(DefaultIO* dio, Settings* settings) {
    this->description = "algorithm settings";
    this->dio = dio;
    this->settings = settings;
}

void AlgoSettingsCMD::execute() {
    dio->write("The current KNN parameters are: K = " + std::to_string(settings->getK()) + ", distance metric = " + settings->getDistanceFunc() + "\n");
    while (true) {
        std::string input = dio->read();
        if (input.compare("") == 0) {
            break;
        }
        try {
            std::string kValueString = input.substr(0, input.find(' '));
            std::string distFuncString = input.substr(input.find(' ') + 1, input.length());
            int kValue = std::stoi(kValueString);
            if (kValue < 1 || kValue > 10) {
                dio->write("Invalid value for K\n");
                continue;
            }
            if (distFuncString.compare("CHE") != 0 && distFuncString.compare("MAN") != 0 && distFuncString.compare("EUC") != 0) {
                dio->write("Invalid value for distance function\n");
                continue;
            }
            settings->setK(kValue);
            settings->setDistanceFunc(distFuncString);
        }
        catch (const std::exception&) {
            dio->write("Invalid input syntax\n");
            continue;
        }
        break;
    }
}

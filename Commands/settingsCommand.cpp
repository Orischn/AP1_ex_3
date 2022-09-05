#include "settingsCommand.hpp"

int AlgoSettingsCMD::k = 3;
std::string AlgoSettingsCMD::distanceFunc = "EUC";

AlgoSettingsCMD::AlgoSettingsCMD() {
    this->description = "algorithm settings";
}

void AlgoSettingsCMD::execute() {}

int AlgoSettingsCMD::getK() {
    return k;
}

std::string AlgoSettingsCMD::getDistanceFunc() {
    return distanceFunc;
}
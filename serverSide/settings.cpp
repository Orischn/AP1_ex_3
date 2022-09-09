#include "settings.hpp"

Settings::Settings() {
	this->k = 3;
	this->distanceFunc = "EUC";
}

int Settings::getK() {
	return this->k;
}

std::string Settings::getDistanceFunc() {
	return this->distanceFunc;
}

void Settings::setK(int k) {
	this->k = k;
}

void Settings::setDistanceFunc(std::string distanceFunc) {
	this->distanceFunc = distanceFunc;
}
#include "testAndTrainData.hpp"
#include "flower.hpp"
#include <vector>
#include <sstream>
#include <string>

void TestAndTrainData::setTestData(std::string testData) {
    this->testData = testData;
}

void TestAndTrainData::setTrainData(std::string trainData) {
    this->trainData = trainData;
}

void TestAndTrainData::setResults(std::string results) {
    this->results = results;
}

std::vector<Flower> TestAndTrainData::getTestDataVector() {
    std::vector<Flower> cFlowers;
    std::stringstream ssFlowers(this->testData);
    std::string sFlower;
    while(getline(ssFlowers, sFlower)) {
        cFlowers.push_back(Flower::stof(sFlower));
    }
    return cFlowers;
}

std::vector<Flower> TestAndTrainData::getTrainDataVector() {
    std::vector<Flower> cFlowers;
    std::stringstream ssFlowers(this->trainData);
    std::string sFlower;
    while(getline(ssFlowers, sFlower)) {
        cFlowers.push_back(Flower::stof(sFlower));
    }
    return cFlowers;
}

std::string TestAndTrainData::getTestDataStr() {
    return this->testData;
}

std::string TestAndTrainData::getTrainDataStr() {
    return this->trainData;
}

std::string TestAndTrainData::getResults() {
    return results;
}

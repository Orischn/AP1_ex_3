#include "flower.hpp"
#include <cmath>
#include <string>
#include <sstream>
#include <vector>
#include <iostream>

Flower::Flower() {
    this->sepalWidth = 0;
    this->sepalLength = 0;
    this->petalWidth = 0;
    this->petalLength = 0;
}

Flower::Flower(const Flower& flower) {
    this->sepalWidth = flower.sepalWidth;
    this->sepalLength = flower.sepalLength;
    this->petalWidth = flower.petalWidth;
    this->petalLength = flower.petalLength;
    this->flowerType = flower.flowerType;
}

void Flower::setSepalWidth(double sepalWidth) {
    this->sepalWidth = sepalWidth;
}

void Flower::setSepalLength(double sepalLength) {
    this->sepalLength = sepalLength;
}

void Flower::setPetalWidth(double petalWidth) {
    this->petalWidth = petalWidth;
}

void Flower::setPetalLength(double petalLength) {
    this->petalLength = petalLength;
}

void Flower::setFlowerType(std::string flowerType) {
    this->flowerType = flowerType;
}

double Flower::getSepalWidth() const {
    return this->sepalWidth;
}

double Flower::getSepalLength() const {
    return this->sepalLength;
}

double Flower::getPetalWidth() const {
    return this->petalWidth;
}

double Flower::getPetalLength() const {
    return this->petalLength;
}

std::string Flower::getFlowerType() const {
    return this->flowerType;
}

double Flower::euclidianDisTo(const Flower& flower) const {
    return pow(pow(std::abs(this->sepalLength - flower.sepalLength), 2) +
            pow(std::abs(this->sepalWidth - flower.sepalWidth), 2) +
            pow(std::abs(this->petalLength - flower.petalLength), 2) +
            pow(std::abs(this->petalWidth - flower.petalWidth), 2), 0.5);
}

double Flower::manhattanDisTo(const Flower& flower) const {
    return std::abs(this->sepalLength - flower.sepalLength) +
            std::abs(this->sepalWidth - flower.sepalWidth) +
            std::abs(this->petalLength - flower.petalLength) +
            std::abs(this->petalWidth - flower.petalWidth);
}

double Flower::chebyshevDisTo(const Flower& flower) const {
    double max1 = std::max(std::abs(this->sepalLength - flower.sepalLength),
                        std::abs(this->sepalWidth - flower.sepalWidth));
    double max2 = std::max(std::abs(this->petalLength - flower.petalLength),
                        std::abs(this->petalWidth - flower.petalWidth));
    return std::max(max1, max2);
}

void Flower::classifyFlower(std::vector<Flower> cFlowers, const int k, double (Flower::*distance)(const Flower&) const) {
    for (int i = 0; i < cFlowers.size(); i++) {
        for (int j = i + 1; j < cFlowers.size(); j++) {
            if ((this->*distance)(cFlowers[i]) > (this->*distance)(cFlowers[j])) {
                Flower temp = cFlowers[i];
                cFlowers[i] = cFlowers[j];
                cFlowers[j] = temp;
            }
        }
    }
    std::vector<int> flowerTypes;
    for (int i = 0; i < 3; i++) {
        flowerTypes.push_back(0);
    }
    for (int i = 0; i < k; i++) {
        if(cFlowers[i].flowerType.compare("Iris-setosa") == 0) {
            flowerTypes[0]++;
        } else if (cFlowers[i].flowerType.compare("Iris-versicolor") == 0) {
            flowerTypes[1]++;
        } else {
            flowerTypes[2]++;
        }
    }
    int maxIndex = 0, maxNum = 0;
    for (int i = 0; i < 3; i++) {
        if (flowerTypes[i] > maxNum) {
            maxNum = flowerTypes[i];
            maxIndex = i;
        }
    }
    if (maxIndex == 0) {
        this->flowerType = "Iris-setosa";
    } else if (maxIndex == 1) {
        this->flowerType = "Iris-versicolor";
    } else {
        this->flowerType = "Iris-virginica";
    }
}

Flower Flower::stof(std::string sFlower) {
    Flower flower;
    std::stringstream ssFlower(sFlower);
    std::vector<std::string> data;
    std::string parsed;
    while(getline(ssFlower, parsed, ',')) {
        data.push_back(parsed);
    }
    flower.setSepalWidth(std::stod(data[0]));
    flower.setSepalLength(std::stod(data[1]));
    flower.setPetalWidth(std::stod(data[2]));
    flower.setPetalLength(std::stod(data[3]));
    flower.setFlowerType(data[data.size() - 1]);
    return flower;
}
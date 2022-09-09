#include "flower.hpp"
#include <cmath>
#include <string>
#include <sstream>
#include <vector>
#include <iostream>

void Flower::setFlowerType(std::string flowerType) {
    this->flowerType = flowerType;
}

std::string Flower::getFlowerType() const {
    return this->flowerType;
}

double Flower::euclidianDisTo(const Flower& flower) const {
    int sum = 0;
    for (int i = 0; i < this->data.size(); i++) {
        sum += pow(std::abs(this->data[i] - flower.data[i]), 2);
    }
    return pow(sum, 0.5);
}

double Flower::manhattanDisTo(const Flower& flower) const {
    int sum = 0;
    for (int i = 0; i < this->data.size(); i++) {
        sum += std::abs(this->data[i] - flower.data[i]);
    }
    return sum;
}

double Flower::chebyshevDisTo(const Flower& flower) const {
    int max = 0;
    for (int i = 0; i < this->data.size(); i++) {
        int val = std::abs(this->data[i] - flower.data[i]);
        if (val > max) {
            max = val;
        }
    }
    return max;
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
    std::string parsed;
    while(getline(ssFlower, parsed, ',')) {
        try {
            flower.data.push_back(std::stod(parsed));
        } catch (const std::exception&) {
            flower.flowerType = parsed;
        }
    }
    return flower;
}
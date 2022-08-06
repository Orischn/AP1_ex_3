#include <iostream>
#include "file.hpp"
#include "flower.hpp"
#include <vector>

using namespace std;

int main(int argc, char** argv) {
    const string cFilePath = "data/classified.csv";
    const string ucFilePath = "data/Unclassified.csv";
    vector<Flower> cFlowers = getDataFromFile(cFilePath);
    vector<Flower> ucFlowers = getDataFromFile(ucFilePath);
    for (int i = 0; i < ucFlowers.size(); i++) {
        ucFlowers[i].classifyFlower(cFlowers, stoi(argv[1]), &Flower::euclidianDisTo);
    }
    writeDataToFile(ucFlowers, "out/euclidean_output.csv");
    for (int i = 0; i < ucFlowers.size(); i++) {
        ucFlowers[i].classifyFlower(cFlowers, stoi(argv[1]), &Flower::manhattanDisTo);
    }
    writeDataToFile(ucFlowers, "out/manhattan_output.csv");
    for (int i = 0; i < ucFlowers.size(); i++) {
        ucFlowers[i].classifyFlower(cFlowers, stoi(argv[1]), &Flower::chebyshevDisTo);
    }
    writeDataToFile(ucFlowers, "out/chebyshev_output.csv");
}
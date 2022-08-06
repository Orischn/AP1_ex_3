#include <vector>
#include <string>
#include "file.hpp"
#include "flower.hpp"

int main(int argc, char** argv) {
    const std::string cFilePath = "data/classified.csv";
    const std::string ucFilePath = "data/Unclassified.csv";
    std::vector<Flower> cFlowers = file::getDataFromFile(cFilePath);
    std::vector<Flower> ucFlowers = file::getDataFromFile(ucFilePath);
    for (int i = 0; i < ucFlowers.size(); i++) {
        ucFlowers[i].classifyFlower(cFlowers, std::stoi(argv[1]), &Flower::euclidianDisTo);
    }
    file::writeDataToFile(ucFlowers, "out/euclidean_output.csv");
    for (int i = 0; i < ucFlowers.size(); i++) {
        ucFlowers[i].classifyFlower(cFlowers, std::stoi(argv[1]), &Flower::manhattanDisTo);
    }
    file::writeDataToFile(ucFlowers, "out/manhattan_output.csv");
    for (int i = 0; i < ucFlowers.size(); i++) {
        ucFlowers[i].classifyFlower(cFlowers, std::stoi(argv[1]), &Flower::chebyshevDisTo);
    }
    file::writeDataToFile(ucFlowers, "out/chebyshev_output.csv");
}
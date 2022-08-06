#include <fstream>
#include <string>
#include <vector>
#include "file.hpp"
#include "flower.hpp"

/*
 * The function takes all the data from the files with information about flowers,
 * and returns a pointer to an array that contains all that data in the format of a Flower.
 * Input: a path to a file.
 * Output: a pointer to an array with the data in the file in the format of a Flower.
 */
std::vector<Flower> file::getDataFromFile(std::string path) {
    std::ifstream input;
    std::string line;
    std::vector<Flower> flowers;
    input.open(path);
    while(getline(input, line)) {
        Flower flower;
        flower.setSepalWidth(stod(line.substr(0, line.find(','))));
        line = line.substr(line.find(',') + 1, line.length());
        flower.setSepalLength(stod(line.substr(0, line.find(','))));
        line = line.substr(line.find(',') + 1, line.length());
        flower.setPetalWidth(stod(line.substr(0, line.find(','))));
        line = line.substr(line.find(',') + 1, line.length());
        flower.setPetalLength(stod(line.substr(0, line.find(','))));
        line = line.substr(line.find(',') + 1, line.length());
        flower.setFlowerType(line);
        flowers.push_back(flower);
    }
    return flowers;
}

void file::writeDataToFile(std::vector<Flower> flowers, std::string path) {
    std::ofstream output;
    output.open(path);
    for (Flower flower : flowers) {
        output<<flower.getFlowerType()<<std::endl;
    }
}

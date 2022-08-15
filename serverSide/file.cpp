#include <fstream>
#include <string>
#include <string.h>
#include <vector>
#include "file.hpp"
#include "flower.hpp"

/*
 * The function takes all the data from the files with information about flowers,
 * and returns a pointer to an array that contains all that data in the format of a Flower.
 * Input: a path to a file.
 * Output: a pointer to an array with the data in the file in the format of a Flower.
 */
std::vector<Flower> file::getDataFromFile(const std::string& path) {
    std::ifstream input;
    std::string line;
    std::vector<Flower> flowers;
    input.open(path);
    while(getline(input, line)) {
        Flower flower;
        char* flowerData = strdup(line.c_str());
        flower.setSepalWidth(std::stod(strtok(flowerData, ",")));
        flower.setSepalLength(std::stod(strtok(NULL, ",")));
        flower.setPetalWidth(std::stod(strtok(NULL, ",")));
        flower.setPetalLength(std::stod(strtok(NULL, ",")));
        flower.setFlowerType(strtok(NULL, ","));
        flowers.push_back(flower);
    }
    input.close();
    return flowers;
}

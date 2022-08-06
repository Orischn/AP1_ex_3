#ifndef ADVNACEDPROGRAMMING_EX_2_SERVERSIDE_FILE_H_
#define ADVNACEDPROGRAMMING_EX_2_SERVERSIDE_FILE_H_

#include <string>
#include <vector>
#include "flower.hpp"

namespace file {
    /*
    * The function goes through the data in the file and creates flower objects from it.
    * Input: A path to a file.
    * Output: An array of flowers representing the data in the file.
    */
    std::vector<Flower> getDataFromFile(std::string path);
    /*
    * The function writes to the file with the given path the type of each flower in
    * the given array.
    * Input: An array of flowers, the length of the array, a path to a file.
    */
    void writeDataToFile(std::vector<Flower> flowers, std::string path);
};

#endif
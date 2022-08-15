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
    std::vector<Flower> getDataFromFile(const std::string& path);
};

#endif
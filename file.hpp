#ifndef ADVNACEDPROGRAMMING_FILE_H_
#define ADVNACEDPROGRAMMING_FILE_H_

#include <string>
#include <vector>
#include "flower.hpp"

/*
* The function goes through the data in the file and creates flower objects from it.
* Input: A path to a file.
* Output: An array of flowers representing the data in the file.
*/
vector<Flower> getDataFromFile(string path);
/*
* The function writes to the file with the given path the type of each flower in
* the given array.
* Input: An array of flowers, the length of the array, a path to a file.
*/
void writeDataToFile(vector<Flower> flowers, string path);

#endif
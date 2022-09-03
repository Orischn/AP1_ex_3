#include <fstream>
#include <sstream>
#include "fileIO.hpp"

FileIO::FileIO(std::string path) {
    this->path = path;
}

std::string FileIO::read() {
    std::ifstream input(this->path);
    std::stringstream buffer;
    buffer << input.rdbuf();
    return buffer.str();
}

void FileIO::write(std::string text) {
    std::ofstream output(this->path);
    output<<text;
}
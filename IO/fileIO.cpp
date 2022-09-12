#include <fstream>
#include <sstream>
#include "fileIO.hpp"

FileIO::FileIO() {}

FileIO::FileIO(std::string path) {
    this->path = path;
}

std::string FileIO::read() {
    std::ifstream input(this->path);
    std::stringstream buffer;
    buffer << input.rdbuf();
    input.close();
    return buffer.str();
}

void FileIO::write(std::string text) {
    std::ofstream output(this->path);
    output << text;
    output.close();
}

void FileIO::setPath(std::string path) {
    this->path = path;
}
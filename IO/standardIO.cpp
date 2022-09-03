#include <iostream>
#include "standardIO.hpp"

std::string StandardIO::read() {
    std::string input;
    std::cin >> input;
    return input;
}

void StandardIO::write(std::string output) {
    std::cout<<output<<std::endl;
}
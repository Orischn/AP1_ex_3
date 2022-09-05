#include "command.hpp"
#include "displayCommand.hpp"
#include "fileIO.hpp"
#include <sstream>

DisplayResultsCMD::DisplayResultsCMD(DefaultIO* dio) {
	description = "display results";
	this->dio = dio;
}

void DisplayResultsCMD::execute() {
	FileIO fio("Commands/output.csv");
	std::string data = fio.read();
	std::stringstream sdata(data);
	std::string type;
	int i = 1;
	while(getline(sdata, type)) {
		dio->write(std::to_string(i++) + "	" + type + "\n");
	}
	dio->write("Done.\n");
}
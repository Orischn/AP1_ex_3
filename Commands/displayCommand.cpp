#include "command.hpp"
#include "displayCommand.hpp"
#include "fileIO.hpp"
#include <sstream>

DisplayResultsCMD::DisplayResultsCMD(DefaultIO* dio, TestAndTrainData* TATData) {
	description = "display results";
	this->dio = dio;
	this->TATData = TATData;
}

void DisplayResultsCMD::execute() {
	std::stringstream sdata(TATData->getResults());
	std::string type;
	int i = 1;
	while(getline(sdata, type)) {
		dio->write(std::to_string(i++) + "	" + type + "\n");
	}
	dio->write("Done.\n");
	dio->read();
}
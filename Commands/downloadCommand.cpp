#include "command.hpp"
#include "fileIO.hpp"
#include "downloadCommand.hpp"
#include <sstream>

DownloadResultsCMD::DownloadResultsCMD(DefaultIO* dio, TestAndTrainData* TATData) {
	description = "download results";
	this->dio = dio;
	this->TATData = TATData;
}

void DownloadResultsCMD::execute() {
	FileIO fioC(dio->read() + "/results.txt");
	std::string results = TATData->getResults();
	std::stringstream sResults(results);
	std::string type;
	int i = 1;
	while (getline(sResults, type)) {
		fioC.write(std::to_string(i++) + "	" + type + "\n");
	}
	dio->write("Done.\n");
	dio->read();
}
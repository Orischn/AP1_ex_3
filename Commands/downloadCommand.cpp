#include "command.hpp"
#include "fileIO.hpp"
#include "downloadCommand.hpp"
#include <sstream>

DownloadResultsCMD::DownloadResultsCMD(DefaultIO* dio, TestAndTrainData* TATData) {
	description = "download results";
	this->dio = dio;
	this->TATData = TATData;
}

DownloadResultsCMD::~DownloadResultsCMD() {
	delete dio;
}

void DownloadResultsCMD::execute() {
	FileIO fioC(dio->read() + "/results.txt");
	std::string results = TATData->getResults();
	std::stringstream sResults(results);
	std::string type;
	std::string temp = "";
	int i = 1;
	while (getline(sResults, type)) {
		temp += std::to_string(i++) + "	" + type + "\n";
	}
	fioC.write(temp);
	dio->write("Done.");
	dio->read();
}
#include "command.hpp"
#include "fileIO.hpp"
#include "downloadCommand.hpp"
#include <sstream>

DownloadResultsCMD::DownloadResultsCMD(DefaultIO* dio) {
	description = "download results";
	this->dio = dio;
}

void DownloadResultsCMD::execute() {
	FileIO fioC(dio->read() + "/results.txt");
	FileIO fioS("Commands/output.csv");
	std::string data = fioS.read();
	std::stringstream sdata(data);
	std::string type;
	int i = 1;
	while (getline(sdata, type)) {
		fioC.write(std::to_string(i++) + "	" + type + "\n");
	}
	dio->write("Done.\n");
	dio->read();
}
#include "cli.hpp"
#include "defaultIO.hpp"
#include "standardIO.hpp"
#include "uploadCommand.hpp"
#include "settingsCommand.hpp"
#include "classifyCommand.hpp"
#include "displayCommand.hpp"
#include "downloadCommand.hpp"
#include "matrixCommand.hpp"

CLI::CLI() {
	commands.push_back(new UploadFileCMD());
	commands.push_back(new AlgoSettingsCMD());
	commands.push_back(new ClassifyDataCMD());
	commands.push_back(new DisplayResultsCMD());
	commands.push_back(new DownloadResultsCMD());
	commands.push_back(new AlgorithmConfusionMatrixCMD());
}
void CLI::start() {
	DefaultIO* dio = new StandardIO();
	dio->write("Welcome to the KNN Classifier Server. Please choose an option");
	for (int i = 0; i < commands.size(); i++) {
		dio->write(std::to_string(i + 1) +". " + (commands[i]->description));
	}
	int input = std::stoi(dio->read());
	while (input < 1 || input > 7) {
		dio->write("Option unavailable! Please try again");
		input = std::stoi(dio->read());
	}
	commands[input]->execute();
	

	

}
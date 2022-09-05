#include "cli.hpp"
#include "defaultIO.hpp"
#include "standardIO.hpp"
#include "fileIO.hpp"
#include "uploadCommand.hpp"
#include "settingsCommand.hpp"
#include "classifyCommand.hpp"
#include "displayCommand.hpp"
#include "downloadCommand.hpp"
#include "matrixCommand.hpp"

CLI::CLI() {
	commands.push_back(new UploadFileCMD(new StandardIO()));
	commands.push_back(AlgoSettingsCMD::getInstance(new StandardIO()));
	commands.push_back(new ClassifyDataCMD(new FileIO("Commands/output.csv")));
	commands.push_back(new DisplayResultsCMD(new StandardIO()));
	commands.push_back(new DownloadResultsCMD());
	commands.push_back(new AlgorithmConfusionMatrixCMD());
}

void CLI::start() {
	StandardIO sio;
	while (true) {
		sio.write("Welcome to the KNN Classifier Server. Please choose an option\n");
		for (int i = 0; i < commands.size(); i++) {
			sio.write(std::to_string(i + 1) +". " + (commands[i]->description) + "\n");
		}
		int input = std::stoi(sio.read());
		while (input < 1 || input > 7) {
			sio.write("Option unavailable! Please try again\n");
			input = std::stoi(sio.read());
		}
		commands[input - 1]->execute();
	}
}
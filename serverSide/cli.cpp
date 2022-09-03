#include "cli.hpp"
#include <cmath>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include "defaultIO.hpp"
#include "standardIO.hpp"

void CLI::start() {
	DefaultIO* dio = new StandardIO();
	dio->write("Welcome to the KNN Classifier Server. Please choose an option\n");
	for (int i = 0; i < commands.size(); i++) {
		dio->write((i + 1) + ". " + (commands[i]->description));
	}
	dio->read();
	/*dio.write("Welcome to the KNN Classifier Server. Please choose an option:\n
					1. upload an unclassified csv data file\n
					2. algorithm settings\n
					3. classify data\n
					4. display results\n 
					5. download results\n
					6. display algorithm confusion matrix\n
					7.exit\n");*/

}
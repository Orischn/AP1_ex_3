#include <vector>
#include <string>
#include <sstream>
#include "command.hpp"
#include "flower.hpp"
#include "matrixCommand.hpp"
#include "settings.hpp"
#include "testAndTrainData.hpp"
#include "defaultIO.hpp"

AlgorithmConfusionMatrixCMD::AlgorithmConfusionMatrixCMD(DefaultIO* dio, Settings* settings, TestAndTrainData* TATData) {
	description = "display algorithm confusion matrix";
	this->settings = settings;
	this->TATData = TATData;
	this->dio = dio;
}

AlgorithmConfusionMatrixCMD::~AlgorithmConfusionMatrixCMD() {
	delete this->dio;
}

void AlgorithmConfusionMatrixCMD::execute() {
	std::vector<Flower> cFlowers = TATData->getTrainDataVector();
	std::vector<Flower> ucFlowers = TATData->getTestDataVector();
	int confusionMatrix[3][3] = {0};
	std::stringstream results(TATData->getResults());
	std::string parsed;
	std::vector<std::string> temp;
	for(int i = 0; getline(results, parsed); i++) {
		temp.push_back(parsed);
	}
	for (int i = 0; i < ucFlowers.size(); i++) {
		if (settings->getDistanceFunc().compare("EUC") == 0) {
			ucFlowers[i].classifyFlower(cFlowers, settings->getK(), &Flower::euclidianDisTo);
		}
		if (settings->getDistanceFunc().compare("MAN") == 0) {
			ucFlowers[i].classifyFlower(cFlowers, settings->getK(), &Flower::manhattanDisTo);
		}
		if (settings->getDistanceFunc().compare("CHE") == 0) {
			ucFlowers[i].classifyFlower(cFlowers, settings->getK(), &Flower::chebyshevDisTo);
		}
	}
	for (int i = 0; i < ucFlowers.size(); i++) {
		if (temp[i].compare("Iris-setosa") == 0) {
			if (ucFlowers[i].getFlowerType().compare("Iris-setosa") == 0) {
				confusionMatrix[0][0]++;
			}
			if (ucFlowers[i].getFlowerType().compare("Iris-versicolor") == 0) {
				confusionMatrix[0][1]++;
			}
			if (ucFlowers[i].getFlowerType().compare("Iris-virginica") == 0) {
				confusionMatrix[0][2]++;
			}
		}

		if (temp[i].compare("Iris-versicolor") == 0) {
			if (ucFlowers[i].getFlowerType().compare("Iris-setosa") == 0) {
				confusionMatrix[1][0]++;
			}
			if (ucFlowers[i].getFlowerType().compare("Iris-versicolor") == 0) {
				confusionMatrix[1][1]++;
			}
			if (ucFlowers[i].getFlowerType().compare("Iris-virginica") == 0) {
				confusionMatrix[1][2]++;
			}
		}

		if (temp[i].compare("Iris-virginica") == 0) {
			if (ucFlowers[i].getFlowerType().compare("Iris-setosa") == 0) {
				confusionMatrix[2][0]++;
			}
			if (ucFlowers[i].getFlowerType().compare("Iris-versicolor") == 0) {
				confusionMatrix[2][1]++;
			}
			if (ucFlowers[i].getFlowerType().compare("Iris-virginica") == 0) {
				confusionMatrix[2][2]++;
			}
		}
	}
	int firstRowSum = confusionMatrix[0][0] + confusionMatrix[0][1] + confusionMatrix[0][2];
	int secondRowSum = confusionMatrix[1][0] + confusionMatrix[1][1] + confusionMatrix[1][2];
	int thirdRowSum = confusionMatrix[2][0] + confusionMatrix[2][1] + confusionMatrix[2][2];

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == 0) {
				confusionMatrix[i][j] = (int)(confusionMatrix[i][j] * 100 / firstRowSum);
			}
			if (i == 1) {
				confusionMatrix[i][j] = (int)(confusionMatrix[i][j] * 100 / secondRowSum);
			}
			if (i == 2) {
				confusionMatrix[i][j] = (int)(confusionMatrix[i][j] * 100 / thirdRowSum);
			}
		}
	}
	dio->write("	Iris-setosa		Iris-versicolor		Iris-virginica\n");
	std::string flowerTypes[3] = { "Iris-setosa", "Iris-versicolor", "Iris-virginica" };
	for (int i = 0; i < 3; i++) {
		dio->write(flowerTypes[i] + "	");
		for (int j = 0; j < 3; j++) {
			dio->write(std::to_string(confusionMatrix[i][j]) + "%	");
		}
		dio->write("\n");
	}
}


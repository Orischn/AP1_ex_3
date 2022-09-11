#ifndef EX_3_HEADERFILES_TESTANDTRAINDATA_H_
#define EX_3_HEADERFILES_TESTANDTRAINDATA_H_

#include "flower.hpp"
#include <vector>

class TestAndTrainData {
private:
	std::string testData;
	std::string trainData;
	std::string results;
public:
	void setTestData(std::string);
	void setTrainData(std::string);
	void setResults(std::string);
	std::vector<Flower> getTestDataVector();
	std::vector<Flower> getTrainDataVector();
	std::string getTestDataStr();
	std::string getTrainDataStr();
	std::string getResults();
};

#endif
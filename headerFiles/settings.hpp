#ifndef EX_3_HEADERFILES_SETTINGS_H
#define EX_3_HEADERFILES_SETTINGS_H

#include "command.hpp"
#include <string>

class Settings {
private:
	int k;
	std::string distanceFunc;
public:
	Settings();
	int getK();
	std::string getDistanceFunc();
	void setK(int);
	void setDistanceFunc(std::string);
};

#endif
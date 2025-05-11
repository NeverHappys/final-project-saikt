#pragma once
#include <string>
#include <fstream>
#include "file_worker.h"
class ReadMap
{
	int sizemap = 200;
	std::ifstream ifs;
public:
	
	void readFile(char **arr, std::string fileName);
};


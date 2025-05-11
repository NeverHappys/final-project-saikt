#include "file_worker.h"

std::string FileWorker::findTheString(std::string fileName, int numOfString) {
	std::ifstream ifs;
	std::string servStr;
	int i = 0;
	ifs.open(fileName + ".txt");
	if (!ifs.is_open()) {
		std::cout << "Access denied!/n";
		ifs.close();
		return "NONE";
	}
	while (i != numOfString) {
		getline(ifs, servStr);
		i++;
	}
	ifs.close();
	return servStr;
}

bool FileWorker::findTheFile(std::string fileName) {
	std::ifstream ifs;
	ifs.open(fileName + ".txt");
	if (ifs.is_open()) {
		ifs.close();
		return true;
	}
	ifs.close();
	return false;
}

void FileWorker::writeToFile(std::string fileName, std::string str, bool flag = false) {
	std::ofstream outFile;
	if (!flag) {
		outFile.open(fileName + ".txt", std::ios::app);
	}
	else {
		outFile.open(fileName + ".txt");
	}
	outFile << str;
	outFile.close();
}

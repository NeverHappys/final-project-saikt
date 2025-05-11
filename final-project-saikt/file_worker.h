#pragma once
#include <iostream>
#include <fstream>
#include <string>

class FileWorker {
public:
	std::string findTheString(std::string, int); // 1 - название файла без расширения, 2 - номер строки
	bool findTheFile(std::string); // Ищет файл, если файл не существует - false
	void writeToFile(std::string, std::string, bool); // 1 - название файла без расширения, 2 - строка для записи, 3 - флаг, true - перезаписать файл, false - добавить строку в конец
};
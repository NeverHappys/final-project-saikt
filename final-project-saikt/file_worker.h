#pragma once
#include <iostream>
#include <fstream>
#include <string>

class FileWorker {
public:
	std::string findTheString(std::string, int); // 1 - �������� ����� ��� ����������, 2 - ����� ������
	bool findTheFile(std::string); // ���� ����, ���� ���� �� ���������� - false
	void writeToFile(std::string, std::string, bool); // 1 - �������� ����� ��� ����������, 2 - ������ ��� ������, 3 - ����, true - ������������ ����, false - �������� ������ � �����
};
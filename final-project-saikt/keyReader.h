#pragma once
#include <conio.h>

class KeyReader {
private:
	int inputKey = 0;
public:
	bool getKeyStatus(); //����������, ������ �� ������; true - ������, flase - �� ������
	int getKeyNumber(); //���������� ������� ������
};
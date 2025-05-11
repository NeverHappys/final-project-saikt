#pragma once
#include <conio.h>

class KeyReader {
private:
	int inputKey = 0;
public:
	bool getKeyStatus(); //Показывает, нажата ли кнопка; true - нажата, flase - не нажата
	int getKeyNumber(); //Возвращает нажатую кнопку
};
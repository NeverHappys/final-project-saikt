#include "keyReader.h"

bool KeyReader::getKeyStatus(){
	if (_kbhit()) {
		this->inputKey = _getch();
		return true;
	}
	else {
		this->inputKey = 0;
		return false;
	}
}

int KeyReader::getKeyNumber(){
	return this->inputKey;
}

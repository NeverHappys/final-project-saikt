#pragma once
#include "Player.h"
#include "keyReader.h"
#include <ctime>

class Controller {
private:
	Player *player;
	KeyReader kr;
public:
	Controller(Player*, KeyReader);
	void moveToFreePos(char**, int, int);
	void playerMove(char**, int& sizes, bool& start);
	bool checkCollision(char**, int, int);
	void checkActivityCollision(char**, int, int, int& sizes);
};
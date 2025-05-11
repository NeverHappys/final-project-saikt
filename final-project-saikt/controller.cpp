#define _CRT_SECURE_NO_WARNINGS
#include "controller.h"
#include <BearLibTerminal.h>
#include "Chest.h"
#include "Enemy.h"
#include "Menu.h"

Controller::Controller(Player *player, KeyReader kr) {
	this->player = player;
	this->kr = kr;
}

void Controller::moveToFreePos(char** map, int WIDTH, int HEIGHT){
	srand(time(NULL));
	while (map[player->getx()][player->gety()] == '2') {
		player->setx(rand() % WIDTH);
		player->sety(rand() % HEIGHT);
	}
}

void Controller::playerMove(char **map, int& sizes, bool &start){
		Menu mn;
		switch (terminal_read()) {
		case 26:
			if (!this->checkCollision(map, player->getx(), player->gety()-1)) {
				player->sety(player->gety() - 1);
				checkActivityCollision(map, player->getx(), player->gety(),sizes);
			}
			break;
		case 22:
			if (!this->checkCollision(map, player->getx(), player->gety()+1)) {
				player->sety(player->gety() + 1);
				checkActivityCollision(map, player->getx(), player->gety(), sizes);
			}
			break;
		case 4:
			if (!this->checkCollision(map, player->getx()-1, player->gety())) {
				player->setx(player->getx() - 1);
				checkActivityCollision(map, player->getx(), player->gety(), sizes);
			}
			break;
		case 7:
			if (!this->checkCollision(map, player->getx()+1, player->gety())) {
				player->setx(player->getx() + 1);
				checkActivityCollision(map, player->getx(), player->gety(), sizes);
			}
			break;
		case 41:
			mn.menu(*player,start);
			break;
		}
}

bool Controller::checkCollision(char** map, int x, int y){
	if (map[x][y] == '2') {
		return true;
	}
	else if(map[x][y] == ' '){
		return false;
	}
	return false;
}

void Controller::checkActivityCollision(char** map, int x, int y, int& sizes)
{
	Chest chest;
	Enemy en;
	if (map[x][y] == '3') {
		terminal_clear();
		chest.chestmenu(*player);
		map[x][y] = ' ';
		terminal_clear();
	}else if (map[x][y] == '4') {
		terminal_clear();
		en.menu(*player);
		map[x][y] = ' ';
		terminal_clear();
		sizes -= 1;
	}
}


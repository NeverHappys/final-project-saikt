#pragma once
#include "Live.h"
#include "Point.h"
#include "PLayer.h"
#include <string>
class Enemy : public Live
{
protected:
	std::string nameEnemy;
public:
	Enemy(){}
	Enemy(int x, int y, int hp, int damage, int armor) : Live(x, y, hp, damage, armor)
	{
		setx(x);
		sety(y);
		sethp(hp);
		setdamage(damage);
		setarmor(armor);
	}
	std::string getName();
	void setName(std::string nameEnemy);
	
	void generator();

	void menu(Player& pl);

	void attack(Player &pl);
	void def(Player &pl);
	void run(Player &pl);
};


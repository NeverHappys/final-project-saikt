#pragma once
#include "Point.h"
class Live : public Point
{
private:
	int hp;
	int damage;
	int armor;
public:
	Live() {};
	Live(int x, int y, int hp, int damage, int armor) : Point(x, y) {
		this->hp = hp;
		this->damage = damage;
		this->armor = armor;
	}
	int gethp();
	int getdamage();
	int getarmor();
	void sethp(int hp);
	void setdamage(int damage);
	void setarmor(int armor);
};


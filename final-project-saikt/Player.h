#pragma once
#include <vector>
#include "Live.h"
#include "Item.h"
class Player :public Live
{
private:
	int capacity = 5;
	std::vector<Item> inventory;
	int mana;
	int coins;
	void update(int id, int value);
public:
	Player() {};
	Player(int mana, int coins, int x, int y, int damage,int hp, int armor) : Live(x,y,hp,damage,armor) {
		this->mana = mana;
		this->coins = coins;
	}
	int getcapacity();
	int getcoins();
	int getmana();
	void setcoins(int coins);
	void setmana(int mana);
	void setcapacity(int capacity);
	bool putToInventory(Item item);
	std::vector<std::string> getAllFromInventory();
	std::string getFromInventory(int index);
	std::string drop(int index);
	bool allUseItem(std::string name);
	bool useItem(int index);
};


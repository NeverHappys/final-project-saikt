#pragma once
#include <vector>
#include "Item.h"
#include "Player.h"
class Chest
{
private:
	Item item;
	std::vector <Item> items;
	std::vector <std::string> nameitems = {"beet","Mysterious fruit","Shield","Sword","Coin"};
public:
	Chest() {};
	std::vector<Item> generatechest();
	void chestmenu(Player& pl);
	void controler(Player& pl, bool& start);
	void chestPostMenu(Player& pl,int itemnumber);
	void postcontroler(Player& pl,int itemnumber);
};


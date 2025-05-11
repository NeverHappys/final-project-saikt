#pragma once
#include "Player.h"
class Menu
{
public:
	void menu(Player& pl, bool& stop);
	void inventories(Player& pl);
	void postmenu(Player& pl, int index);
};


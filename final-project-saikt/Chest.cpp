#define _CRT_SECURE_NO_WARNINGS

#include "Chest.h"
#include <BearLibTerminal.h>
#include <string>
#include <cstring>
#include "Player.h"

std::vector<Item> Chest::generatechest()
{
	int rnd;
	int endsize = 1 + rand() % 2;
	std::string name;
	rnd = 1 + rand() % 3;
	for (int i = 0; i < rnd;i++) {
		std::vector<int> sizeid(endsize);
		for (int j = 0; j < endsize; j++) {
			sizeid[j] = 1 + rand() % 5;
		}
		std::vector<int> sizevalue(endsize);
		for (int j = 0; j < endsize; j++) {
			if (sizeid[j] == 1) { sizevalue[j] = 20 + rand() % 50; name = nameitems[0]; }
			else if (sizeid[j] == 2) { sizevalue[j] = 20; name = nameitems[1]; }
			else if (sizeid[j] == 3) { sizevalue[j] = 1 + rand() % 5; name = nameitems[2]; }
			else if (sizeid[j] == 4) { sizevalue[j] = 10 + rand() % 15; name = nameitems[3]; }
			else if (sizeid[j] == 5) { sizevalue[j] = 20 + rand() % 50; name = nameitems[4]; }
		}
		item.setname(name);
		item.setid(sizeid);
		item.setvalue(sizevalue);
		items.push_back(item);
	}
	return items;
}

void Chest::chestmenu(Player &pl)
{
	items = generatechest();
	std::string str;
	terminal_open();
	bool start = true;
	while (start) {
		terminal_clear();
		terminal_print(1, 1, "chest inventory:");
		for (int i = 0; i < items.size(); i++)
		{
			str = std::to_string(i + 1) + " " + items[i].getname();
			const char* name = str.c_str();
			terminal_print(1, i + 2, name);
		}
		terminal_print(30, 1, "player inventory:");
		for (int i = 0; i < pl.getAllFromInventory().size(); i++)
		{
			str = std::to_string(i + 4) + " " + pl.getAllFromInventory()[i];
			const char* name = str.c_str();
			terminal_print(30, i + 2, name);
		}
		terminal_print(1, 6, "Press ESC to exit");
		terminal_refresh();
		controler(pl, start);
	}
}
void Chest::chestPostMenu(Player& pl, int itemnumber)
{
	terminal_clear();
	std::string str;
	str = "You want to use " + items[itemnumber].getname() + "?";
	const char* names = str.c_str();
	terminal_print(1, 1, names);
	terminal_print(1,2,"1 Put it in the inventory");
	terminal_print(1, 3, "2 Delete the item");
	terminal_refresh();
	postcontroler(pl, itemnumber);
}
void Chest::postcontroler(Player& pl,int itemnumber)
{
	char key = terminal_read() + 19;
	switch (key)
	{
	case '1':
		pl.putToInventory(items[itemnumber]);
	case '2':
		items.erase(items.begin() + itemnumber);
	}
}
void Chest::controler(Player &pl, bool &start)
{
	char key= terminal_read() + 19;
	switch (key)
	{
	case '1':
		chestPostMenu(pl,0);
		break;
	case '2':
		chestPostMenu(pl,1);
		break;
	case'3':
		chestPostMenu(pl,2);
		break;
	case'4':
		pl.drop(0);
		break;
	case'5':
		pl.drop(1);
		break;
	case'6':
		pl.drop(2);
		break;
	case'7':
		pl.drop(3);
		break;
	case'8':
		pl.drop(4);
		break;
	case '<':
		start = false;
		break;
	}
}

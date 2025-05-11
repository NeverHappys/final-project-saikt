#define _CRT_SECURE_NO_WARNINGS

#include "Menu.h"
#include "BearLibTerminal.h"
#include "Player.h"

void Menu::menu(Player& pl, bool & stop)
{
	while (true) {
		terminal_clear();
		terminal_print(1, 1, "1. Continue");
		terminal_print(1, 2, "2. inventory");
		terminal_print(1, 3, "3. Exit");
		terminal_refresh();
		int key = terminal_read();
		if (key == 30) {
			break;
		}
		switch (key)
		{
		case 31:
			inventories(pl);
			break;
		case 32:
			stop = false;
			break;
		}
	}
}
void Menu::inventories(Player &pl) {
	terminal_clear();
	terminal_print(1, 1, "player inventory:");
	std::string str;
	for (int i = 0; i < pl.getAllFromInventory().size(); i++)
	{
		str = std::to_string(i+1) + " " + pl.getAllFromInventory()[i];
		const char* name = str.c_str();
		terminal_print(1, i + 2, name);
	}
	terminal_print(1, 7, "6. Exit to esc");
	terminal_refresh();
	int key = terminal_read();
	switch (key)
	{
	case 30:
		postmenu(pl, 0);
		break;
	case 31:
		postmenu(pl, 1);
		break;
	case 32:
		postmenu(pl, 2);
		break;
	case 33:
		postmenu(pl, 3);
		break;
	case 34:
		postmenu(pl, 4);
		break;
	case 35:
		break;
	}
}
void Menu::postmenu(Player& pl, int index) {
	terminal_clear();
	std::string str = pl.getFromInventory(index).c_str();
	const char* strs = str.c_str();
	terminal_print(1, 1, strs);
	terminal_print(1, 2, "1. Use");
	terminal_print(1, 3, "2. Drop");
	terminal_refresh();
	int key = terminal_read();
	switch (key)
	{
	case 30:
		pl.useItem(index);
		break;
	case 31:
		pl.drop(index);
		break;
	}
}

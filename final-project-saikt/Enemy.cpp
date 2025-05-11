#define _CRT_SECURE_NO_WARNINGS

#include "Enemy.h"
#include "Live.h"
#include "BearLibTerminal.h"
#include <string>
#include <cstring>

std::string Enemy::getName()
{
	return nameEnemy;
}
void Enemy::setName(std::string nameEnemy)
{
	this->nameEnemy = nameEnemy;
}

void Enemy::generator()
{
	std::string randname[3] = { "Ogr","Zombi","Elf" };
	nameEnemy = randname[rand() % 3];
	sethp(rand() % 200);
	setdamage(rand() % 20);
	setarmor(rand() % 5);
}
void Enemy::attack(Player& pl)
{
	sethp(gethp() - (pl.getdamage() - (pl.getdamage() * (getarmor() / 100))));
	pl.sethp(pl.gethp() - (getdamage() - (getdamage() * (pl.getarmor() / 100))));

}

void Enemy::def(Player& pl)
{
	pl.sethp(pl.gethp() - (getdamage() - (getdamage() - 5)));
}

void Enemy::run(Player& pl)
{
	pl.sethp(gethp() - (getdamage() * 2));
}

void Enemy::menu(Player& pl)
{
	generator();

	std::string str;
	std::string str1;
	std::string str2;
	std::string str3;
	std::string str4;
	std::string str5;
	std::string str6;

	bool a = true;

	terminal_open();
	
	while (gethp() > 0 && pl.gethp() > 0 && a)
	{
		terminal_clear();
	str = std::to_string(getdamage());
	str1 = std::to_string(getarmor());
	str2 = std::to_string(gethp());
	str3 = std::to_string(pl.getdamage());
	str4 = std::to_string(pl.getarmor());
	str5 = std::to_string(pl.gethp());
	str6 = getName();

	const char* endamage = str.c_str();
	const char* enarmor = str1.c_str();
	const char* enhp = str2.c_str();
	const char* pldamage = str3.c_str();
	const char* plarmor = str4.c_str();
	const char* plhp = str5.c_str();
	const char* nameenemy = str6.c_str();
	
	
	
	terminal_printf(1, 1, "Player characteristics:");
	terminal_printf(1, 2, "HP: ");
	terminal_print(5, 2, plhp);
	terminal_printf(1, 3, "Armour: ");
	terminal_printf(9, 3, plarmor);
	terminal_printf(1, 4, "Damage: ");
	terminal_printf(9, 4, pldamage);
	terminal_printf(30, 1, "Enemy characteristics:");
	terminal_printf(30,2, "Name: ");
	terminal_printf(36,2,nameenemy);
	terminal_printf(30, 3, "HP: ");
	terminal_printf(35, 3, enhp);
	terminal_printf(30, 4, "Armour: ");
	terminal_printf(38, 4, enarmor);
	terminal_printf(30, 5, "Damage: ");
	terminal_printf(38, 5, endamage);
	terminal_printf(1, 10, "1. Attack");
	terminal_printf(30, 10, "2. Defended");
	terminal_printf(60, 10, "3. Run");

		terminal_refresh();
		char key = terminal_read()+19;
		switch (key)
		{
		case '1':
			attack(pl);
			break;
		case '2':
			def(pl);
			break;
		case'3':
			run(pl);
			a = false;
			break;
		}
		
	}
}

#include "Player.h"

void Player::update(int id, int value)
{
	if (id == 1) {
		sethp(value + gethp());
	}
	else if (id == 2) {
		setmana(value + getmana());
	}
	else if (id == 3) {
		setarmor(value + getarmor());
	}
	else if (id == 4) {
		setdamage(value + getdamage());
	}
	else if (id == 5) {
		setcoins(value + getcoins());
	}
}

int Player::getcapacity()
{
	return capacity;
}

int Player::getcoins()
{
	return coins;
}

int Player::getmana()
{
	return mana;
}

void Player::setcoins(int coins)
{
	this->coins = coins;
}

void Player::setmana(int mana)
{
	this->mana = mana;
}

void  Player::setcapacity(int capacity)
{
	this->capacity = capacity;
}

bool Player::putToInventory(Item item)
{
	if (inventory.size() < capacity) {
		inventory.push_back(item);
		return true;
	}
	else {
		return false;
	}
}

std::vector<std::string> Player::getAllFromInventory()
{
	std::vector<std::string> names;
	if (inventory.size()!=0) {
		for (int i = 0; i < inventory.size();i++) {
			names.push_back(inventory[i].getname());
		}
		return names;
	}
	else {
		return names;
	}
}

std::string Player::getFromInventory(int index)
{
	if (index < inventory.size() && index >= 0) {
		return inventory[index].getname();
	}
	else {
		return "";
	}
}
std::string Player::drop(int index) {
	std::string names = "";
	if (index < inventory.size() && index >= 0)
	{
		names = inventory[index].getname();
		inventory.erase(inventory.begin() + index);
		return names;
	}
	else {
		return names;
	}
}
bool Player::allUseItem(std::string name) {
	bool checkItem = 0;
	for (int i = 0; i < inventory.size();i++) {
		if (name == inventory[i].getname()) {
			for (int j = 0; j < inventory[i].getid().size(); j++) {
				update(inventory[i].getid()[j], inventory[i].getvalue()[j]);
			}
			drop(i);
			checkItem = 1;
		}
	}
	return checkItem;
}
bool Player::useItem(int index) {
	if (index < inventory.size() && index >= 0)
	{
		for (int j = 0; j < inventory[index].getid().size(); j++) {
			update(inventory[index].getid()[j], inventory[index].getvalue()[j]);
		}
		drop(index);
		return 1;
	}
	else {
		return 0;
	}
}


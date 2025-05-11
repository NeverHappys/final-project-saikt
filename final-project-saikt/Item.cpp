#include "Item.h"

std::string Item::getname()
{
	return name;
}

std::vector<int> Item::getid()
{
	return id;
}

std::vector<int> Item::getvalue()
{
	return value;
}

void Item::setname(std::string name)
{
	this->name = name;
}

void Item::setid(std::vector<int> id)
{
	this->id = id;
}

void Item::setvalue(std::vector<int> value)
{
	this->value = value;
}

#pragma once
#include <iostream>
#include <vector>
class Item
{
private:
	std::string name;
	std::vector<int> id;
	std::vector<int> value;
public:
	Item(){}
	Item(std::string name, std::vector<int> id, std::vector<int> value) {
		this->name = name;
		this->id = id;
		this->value = value;
	}
	std::string getname();
	std::vector<int> getid();
	std::vector<int> getvalue();
	void setname(std::string name);
	void setid(std::vector<int> id);
	void setvalue(std::vector<int> value);
};


#include "Live.h"

int Live::gethp()
{
    return hp;
}

int Live::getdamage()
{
    return damage;
}

int Live::getarmor()
{
    return armor;
}

void Live::sethp(int hp)
{
    this->hp = hp;
}

void Live::setdamage(int damage)
{
    this->damage = damage;
}

void Live::setarmor(int armor)
{
    this->armor = armor;
}

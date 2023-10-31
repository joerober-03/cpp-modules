#include "Weapon.hpp"

Weapon::Weapon(std::string weapon) : type(weapon)
{
}

Weapon::~Weapon()
{
    //std::cout << "Weapon was destroyed" << std::endl;
}

void Weapon::setType(std::string newType)
{
    this->type = newType;
}

std::string Weapon::getType()
{
    return (this->type);
}
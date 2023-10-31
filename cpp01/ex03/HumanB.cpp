#include "HumanB.hpp"

HumanB::HumanB(std::string newName) : name(newName)
{
    this->weapon = NULL;
}

HumanB::~HumanB()
{
   // std::cout << "HumanB was destroyed" << std::endl;
}

void    HumanB::attack()
{
    if (this->weapon != NULL)
        std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
    else
        std::cout << this->name << " does not have a weapon to attack with" << std::endl;
}

void    HumanB::setWeapon(Weapon &newWeapon)
{
    this->weapon = &newWeapon;
}
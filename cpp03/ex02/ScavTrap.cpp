#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
    std::cout << "default ScavTrap constructor called" << std::endl;
    this->name = "default";
    this->hitPoint = 100;
    this->energyPoint = 50;
    this->attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &rhs)
{
    std::cout << "ScavTrap copy constructor called" << std::endl;
    *this = rhs;
}

ScavTrap    &ScavTrap::operator=(const ScavTrap &rhs)
{
    std::cout << "ScavTrap copy assignment operator called" << std::endl;
    this->name = rhs.name;
    this->hitPoint = rhs.hitPoint;
    this->energyPoint = rhs.energyPoint;
    this->attackDamage = rhs.attackDamage;
    return(*this);
}

ScavTrap::~ScavTrap(void)
{
    std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string newName)
{
    std::cout << "ScavTrap constructor called" << std::endl;
    this->name = newName;
    this->hitPoint = 100;
    this->energyPoint = 50;
    this->attackDamage = 20;
}

void    ScavTrap::attack(const std::string &target)
{
    if (this->hitPoint > 0)
    {
        if (this->energyPoint > 0)
        {
            std::cout << "ScavTrap " << this->name << " attacks " << target << " causing " << this->attackDamage << " Points of damage!" << std::endl;
            this->energyPoint--;
        }
        else
            std::cout << "ScavTrap " << this->name << " doesn't have any energy left" << std::endl;
    }
    else
        std::cout << "ScavTrap " << this->name << " doesn't have any hit points left" << std::endl;
}

void    ScavTrap::guardGate(void)
{
    std::cout << "ScavTrap " << this->name << " is now in Gate keeper mode" << std::endl;
}
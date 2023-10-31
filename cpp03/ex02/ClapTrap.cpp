#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : name("default"), hitPoint(10), energyPoint(10), attackDamage(0)
{
    std::cout << "default ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &rhs)
{
    std::cout << "ClapTrap copy constructor called" << std::endl;
    *this = rhs;
}

ClapTrap    &ClapTrap::operator=(const ClapTrap &rhs)
{
    std::cout << "ClapTrap copy assignment operator called" << std::endl;
    this->name = rhs.name;
    this->hitPoint = rhs.hitPoint;
    this->energyPoint = rhs.energyPoint;
    this->attackDamage = rhs.attackDamage;
    return(*this);
}

ClapTrap::~ClapTrap(void)
{
    std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string newName) : name(newName), hitPoint(10), energyPoint(10), attackDamage(0)
{
    std::cout << "ClapTrap constructor called" << std::endl;
}

void    ClapTrap::attack(const std::string &target)
{
    if (this->hitPoint > 0)
    {
        if (this->energyPoint > 0)
        {
            std::cout << "ClapTrap " << this->name << " attacks " << target << " causing " << this->attackDamage << " Points of damage!" << std::endl;
            this->energyPoint--;
        }
        else
            std::cout << "ClapTrap " << this->name << " doesn't have any energy left" << std::endl;
    }
    else
        std::cout << "ClapTrap " << this->name << " doesn't have any hit points left" << std::endl;
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    if (this->hitPoint > amount)
        this->hitPoint = this->hitPoint - amount;
    else
        this->hitPoint = 0;
    std::cout << "ClapTrap " << this->name << " takes " << amount << " points of damage, he now has " << this->hitPoint << " left" << std::endl;
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    if (this->hitPoint > 0)
    {
        if (this->energyPoint > 0)
        {
            this->hitPoint = this->hitPoint + amount;
            std::cout << "ClapTrap " << this->name << " repairs itself and regains " << amount << " hit points, he now has " << this->hitPoint << " left" << std::endl;
            this->energyPoint--;
        }
        else
            std::cout << "ClapTrap " << this->name << " doesn't have any energy left" << std::endl;
    }
    else
        std::cout << "ClapTrap " << this->name << " doesn't have any hit points left" << std::endl;
}
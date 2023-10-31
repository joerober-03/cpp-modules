#include "FragTrap.hpp"

FragTrap::FragTrap(void)
{
    std::cout << "default FragTrap constructor called" << std::endl;
    this->name = "default";
    this->hitPoint = 100;
    this->energyPoint = 100;
    this->attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &rhs)
{
    std::cout << "FragTrap copy constructor called" << std::endl;
    *this = rhs;
}

FragTrap    &FragTrap::operator=(const FragTrap &rhs)
{
    std::cout << "FragTrap copy assignment operator called" << std::endl;
    this->name = rhs.name;
    this->hitPoint = rhs.hitPoint;
    this->energyPoint = rhs.energyPoint;
    this->attackDamage = rhs.attackDamage;
    return(*this);
}

FragTrap::~FragTrap(void)
{
    std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap::FragTrap(const std::string newName)
{
    std::cout << "FragTrap constructor called" << std::endl;
    this->name = newName;
    this->hitPoint = 100;
    this->energyPoint = 100;
    this->attackDamage = 30;
}

void    FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << this->name << ": give me five brother" << std::endl;
}
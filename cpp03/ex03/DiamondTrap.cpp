#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void)
{
    std::cout << "default DiamondTrap constructor called" << std::endl;
    this->name = "default";
    ClapTrap::name = "default_clap_name";
    this->hitPoint = FragTrap::hitPoint;
    this->energyPoint = ScavTrap::energyPoint;
    this->attackDamage = FragTrap::attackDamage;
}

DiamondTrap::DiamondTrap(const DiamondTrap &rhs)
{
    std::cout << "DiamondTrap copy constructor called" << std::endl;
    *this = rhs;
}

DiamondTrap    &DiamondTrap::operator=(const DiamondTrap &rhs)
{
    std::cout << "DiamondTrap copy assignment operator called" << std::endl;
    this->name = rhs.name;
    this->hitPoint = rhs.hitPoint;
    this->energyPoint = rhs.energyPoint;
    this->attackDamage = rhs.attackDamage;
    return(*this);
}

DiamondTrap::~DiamondTrap(void)
{
    std::cout << "DiamondTrap destructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string newName)
{
    std::cout << "DiamondTrap constructor called" << std::endl;
    this->name = newName;
    ClapTrap::name = newName + "_clap_name";
    this->hitPoint = FragTrap::hitPoint;
    this->energyPoint = ScavTrap::energyPoint;
    this->attackDamage = FragTrap::attackDamage;
}

void    DiamondTrap::attack(const std::string &target)
{
    this->ScavTrap::attack(target);
}

void    DiamondTrap::whoAmI(void)
{
    std::cout << "who am I ?" << std::endl;
    std::cout << "my name is " << this->name << std::endl;
    std::cout << "my ClapTrap name is " << ClapTrap::name << std::endl;
}
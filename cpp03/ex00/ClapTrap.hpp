#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{

    private:

    std::string name;
    unsigned int         hitPoint;
    unsigned int         energyPoint;
    unsigned int         attackDamage;

    public:

    void    attack(const std::string &target);
    void    takeDamage(unsigned int amount);
    void    beRepaired(unsigned int amount);

    ClapTrap(void);
    ClapTrap(const ClapTrap &rhs);
    ClapTrap &operator=(const ClapTrap &rhs);
    ~ClapTrap(void);

    ClapTrap(const std::string name);
};

#endif
#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{

    private:

    std::string name;

    public:

    DiamondTrap(void);
    DiamondTrap(const DiamondTrap &rhs);
    DiamondTrap &operator=(const DiamondTrap &rhs);
    ~DiamondTrap(void);

    DiamondTrap(const std::string name);
    void    attack(const std::string &target);
    void    whoAmI(void);
};

#endif
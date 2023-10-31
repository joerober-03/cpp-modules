#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
    private:

    public:

    ScavTrap(void);
    ScavTrap(const ScavTrap &rhs);
    ScavTrap &operator=(const ScavTrap &rhs);
    ~ScavTrap(void);

    ScavTrap(const std::string name);
    void    attack(const std::string &target);
    void    guardGate(void);

};

#endif
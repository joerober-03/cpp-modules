#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
    private:

    public:

    FragTrap(void);
    FragTrap(const FragTrap &rhs);
    FragTrap &operator=(const FragTrap &rhs);
    ~FragTrap(void);

    FragTrap(const std::string name);
    void    highFivesGuys(void);
};

#endif
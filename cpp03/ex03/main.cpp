#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
    std::cout << std::endl;
    {
        DiamondTrap dt("diamond");
        dt.attack("silver");
        dt.attack("gold");
        dt.whoAmI();
        dt.highFivesGuys();
        dt.guardGate();
        dt.takeDamage(5);
        dt.beRepaired(1);
    }
    return 0;
}
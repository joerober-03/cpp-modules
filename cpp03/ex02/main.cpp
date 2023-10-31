#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    std::cout << std::endl;
    {
        FragTrap ft("frog");
        ft.attack("ant");
        ft.beRepaired(20);
        ft.takeDamage(118);
        FragTrap ftc(ft);
        ftc.takeDamage(3);
        ft.highFivesGuys();
        ftc.highFivesGuys();
    }
    return 0;
}
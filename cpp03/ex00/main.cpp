#include "ClapTrap.hpp"

int main()
{
    std::cout << std::endl;
    {
        ClapTrap ct("john");

        ct.attack("charlie");
        ct.takeDamage(4);
        ct.beRepaired(5);
        ct.beRepaired(1);
        ct.beRepaired(1);
        ct.beRepaired(1);
        ct.beRepaired(1);
        ct.beRepaired(1);
        ct.beRepaired(1);
        ct.beRepaired(1);
        ct.beRepaired(1);
        ct.beRepaired(1);
    }
    std::cout << std::endl;
    {
        ClapTrap ct("charlie");
        ct.takeDamage(9);
        ct.attack("john");
        ct.beRepaired(4);
        ct.takeDamage(5);
        ct.attack("charlie");
    }

    return 0;
}
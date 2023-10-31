#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    std::cout << std::endl;
    {
        ScavTrap st("bot");
        st.takeDamage(95);
        st.beRepaired(1000);
        ScavTrap stc(st);
        st.guardGate();
        st.attack("charlie");
        stc.guardGate();
        stc.takeDamage(543);
        st.takeDamage(19834);
        st.attack("test");
        stc.attack("john");
    }
    return 0;
}
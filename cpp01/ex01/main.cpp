#include "Zombie.hpp"

int main()
{
    {
        Zombie *zHorde = zombieHorde(100, "charlie");
        for (int i = 0; i < 100; i++)
            zHorde[i].announce();
        std::cout << std::endl;
        delete[] zHorde;
    }
    
    {
        Zombie *zHorde = zombieHorde(5, "john");
        for (int i = 0; i < 5; i++)
            zHorde[i].announce();
        std::cout << std::endl;
        delete[] zHorde;
    }

    {
        Zombie *zHorde = zombieHorde(1, "pascal");
        for (int i = 0; i < 1; i++)
            zHorde[i].announce();
        std::cout << std::endl;
        delete[] zHorde;
    }
}
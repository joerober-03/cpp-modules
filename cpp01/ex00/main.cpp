#include "Zombie.hpp"

int main()
{
    std::cout << "first zombie called john will be created (newzombie)" << std::endl;
    Zombie *nZombie = newZombie("john");
    //std::cout << std::endl;
    std::cout << "second zombie called dave will be created (randomchump)" << std::endl;
    randomChump("dave");
    nZombie->announce();
    delete nZombie;
}
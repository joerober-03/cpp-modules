#ifndef Zombie_HPP
# define Zombie_HPP

#include <iostream>

class Zombie
{
    private:

    std::string name;

    public:

    void announce(void);
    void setName(std::string name);
    Zombie(std::string name);
    Zombie();
    ~Zombie(void);
};

Zombie* zombieHorde( int N, std::string name );

#endif
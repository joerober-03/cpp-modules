#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
    private:

    Brain   *brain;

    protected:

    public:

    Dog(void);
    Dog(const Dog &rhs);
    Dog  &operator=(const Dog &rhs);
    ~Dog(void);

    void    makeSound(void) const;
    std::string getType(void) const;
    Brain   *getBrain(void) const;
};

#endif
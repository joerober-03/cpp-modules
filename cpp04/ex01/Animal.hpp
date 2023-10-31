#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
    private:

    protected:

    std::string type;

    public:

    Animal(void);
    Animal(const Animal &rhs);
    Animal  &operator=(const Animal &rhs);
    virtual ~Animal(void);

    virtual void    makeSound(void) const;
    virtual std::string getType(void) const;
};


#endif
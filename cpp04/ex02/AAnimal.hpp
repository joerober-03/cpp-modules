#ifndef AANIMAL_HPP
#define AANIMAL_HPP

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

    virtual void    makeSound(void) const = 0;
    virtual std::string getType(void) const;
};


#endif
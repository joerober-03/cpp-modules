#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
    private:

    protected:

    std::string type;

    public:

    WrongAnimal(void);
    WrongAnimal(const WrongAnimal &rhs);
    WrongAnimal  &operator=(const WrongAnimal &rhs);
    virtual ~WrongAnimal(void);

    void    makeSound(void) const;
    std::string getType(void) const;
};


#endif
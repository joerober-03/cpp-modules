#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
    std::cout << "default WrongAnimal constructor called" << std::endl;
    this->type = "Wrong animal";
}

WrongAnimal::WrongAnimal(const WrongAnimal &rhs)
{
    std::cout << "WrongAnimal copy constructor called" << std::endl;
    *this = rhs;
}

WrongAnimal  &WrongAnimal::operator=(const WrongAnimal &rhs)
{
    std::cout << "WrongAnimal copy assignment operator called" << std::endl;
    this->type = rhs.type;
    return(*this);
}

WrongAnimal::~WrongAnimal(void)
{
    std::cout << "WrongAnimal destructor called" << std::endl;
}

void    WrongAnimal::makeSound(void) const
{
    std::cout << "Wrong animal sound" << std::endl;
}

std::string WrongAnimal::getType(void) const
{
    return(this->type);
}
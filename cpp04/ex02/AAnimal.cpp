#include "AAnimal.hpp"

Animal::Animal(void)
{
    std::cout << "default Animal constructor called" << std::endl;
    this->type = "Animal";
}

Animal::Animal(const Animal &rhs)
{
    std::cout << "Animal copy constructor called" << std::endl;
    *this = rhs;
}

Animal  &Animal::operator=(const Animal &rhs)
{
    std::cout << "Animal copy assignment operator called" << std::endl;
    this->type = rhs.type;
    return(*this);
}

Animal::~Animal(void)
{
    std::cout << "Animal destructor called" << std::endl;
}

void    Animal::makeSound(void) const
{
    std::cout << "Animal sound" << std::endl;
}

std::string Animal::getType(void) const
{
    return(this->type);
}
#include "Dog.hpp"

Dog::Dog(void)
{
    std::cout << "default Dog constructor called" << std::endl;
    this->type = "Dog";
}

Dog::Dog(const Dog &rhs)
{
    std::cout << "Dog copy constructor called" << std::endl;
    *this = rhs;
}

Dog  &Dog::operator=(const Dog &rhs)
{
    std::cout << "Dog copy assignment operator called" << std::endl;
    this->type = rhs.type;
    return(*this);
}

Dog::~Dog(void)
{
    std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound(void) const
{
    std::cout << "Woof" << std::endl;
}

std::string Dog::getType(void) const
{
    return(this->type);
}
#include "Cat.hpp"

Cat::Cat(void)
{
    std::cout << "default Cat constructor called" << std::endl;
    this->type = "Cat";
    this->brain = new Brain();
}

Cat::Cat(const Cat &rhs)
{
    std::cout << "Cat copy constructor called" << std::endl;
    *this = rhs;
}

Cat  &Cat::operator=(const Cat &rhs)
{
    std::cout << "Cat copy assignment operator called" << std::endl;
    this->type = rhs.type;
    this->brain = new Brain(*rhs.brain);
    return(*this);
}

Cat::~Cat(void)
{
    std::cout << "Cat destructor called" << std::endl;
    delete this->brain;
}

void    Cat::makeSound(void) const
{
    std::cout << "Meow" << std::endl;
}

std::string Cat::getType(void) const
{
    return(this->type);
}

Brain *Cat::getBrain() const
{
	return this->brain;
}
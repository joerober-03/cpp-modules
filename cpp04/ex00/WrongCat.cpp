#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
    std::cout << "default WrongCat constructor called" << std::endl;
    this->type = "Wrong cat";
}

WrongCat::WrongCat(const WrongCat &rhs)
{
    std::cout << "WrongCat copy constructor called" << std::endl;
    *this = rhs;
}

WrongCat  &WrongCat::operator=(const WrongCat &rhs)
{
    std::cout << "WrongCat copy assignment operator called" << std::endl;
    this->type = rhs.type;
    return(*this);
}

WrongCat::~WrongCat(void)
{
    std::cout << "WrongCat destructor called" << std::endl;
}

void    WrongCat::makeSound(void) const
{
    std::cout << "Wrong meow" << std::endl;
}

std::string WrongCat::getType(void) const
{
    return(this->type);
}
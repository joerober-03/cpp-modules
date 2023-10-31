#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed(void)
{
    std::cout << "Default constructor called" << std::endl;
    this->value = 0;
}

Fixed::Fixed(const Fixed &rhs)
{
    std::cout << "Copy constructor called" << std::endl;
    this->value = rhs.getRawBits();
}

Fixed & Fixed::operator=(const Fixed &rhs)
{
    std::cout << "Copy assignment operator called" << std::endl;
    this->value = rhs.getRawBits();
    return(*this);
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->value);
}

void Fixed::setRawBits(int const raw)
{
    this->value = raw;
}
#include "Fixed.hpp"

Fixed::Fixed(void)
{
    std::cout << "Default constructor called" << std::endl;
    this->value = 0;
}

Fixed::Fixed(const Fixed &rhs)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = rhs;
}

Fixed::Fixed(const int num) : value(num << bitNumbers)
{
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float num) : value( roundf( num * ( 1 << bitNumbers ) ) )
{
    std::cout << "Float constructor called" << std::endl;
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
    //std::cout << "getRawBits member function called" << std::endl;
    return (this->value);
}

void Fixed::setRawBits(int const raw)
{
    this->value = raw;
}

std::ostream &operator<<(std::ostream &o, const Fixed &rhs)
{
    o << rhs.toFloat();
    return (o);
}

float Fixed::toFloat(void) const
{
    float F;
    F = static_cast< float >(this->getRawBits() / static_cast< float >(1 << bitNumbers));
    return (F);
}

int Fixed::toInt(void) const
{
    return (this->getRawBits() >> bitNumbers);
}
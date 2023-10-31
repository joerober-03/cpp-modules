#include "Fixed.hpp"

Fixed::Fixed(void)
{
    //std::cout << "Default constructor called" << std::endl;
    this->value = 0;
}

Fixed::~Fixed(void)
{
    //std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &rhs)
{
    //std::cout << "Copy constructor called" << std::endl;
    *this = rhs;
}

Fixed::Fixed(const int num) : value(num << bitNumbers)
{
    //std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float num) : value( roundf( num * ( 1 << bitNumbers ) ) )
{
    //std::cout << "Float constructor called" << std::endl;
}

Fixed   &Fixed::operator=(const Fixed &rhs)
{
    //std::cout << "Copy assignment operator called" << std::endl;
    this->value = rhs.getRawBits();
    return(*this);
}

Fixed   &Fixed::operator++(void)
{
    this->value++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed tmp = *this;
	++this->value;
	return (tmp);
}

Fixed   &Fixed::operator--(void)
{
    this->value--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed tmp = *this;
	--this->value;
	return (tmp);
}

Fixed   Fixed::operator+(const Fixed &rhs) const
{
    Fixed res(this->toFloat() + rhs.toFloat());
    return (res);
}

Fixed   Fixed::operator-(const Fixed &rhs) const
{
    Fixed res(this->toFloat() - rhs.toFloat());
    return (res);
}

Fixed   Fixed::operator*(const Fixed &rhs) const
{
    Fixed res(this->toFloat() * rhs.toFloat());
    return (res);
}

Fixed   Fixed::operator/(const Fixed &rhs) const
{
    Fixed res(this->toFloat() / rhs.toFloat());
    return (res);
}

bool   Fixed::operator<(const Fixed &rhs) const
{
    if (this->value < rhs.value)
        return true;
    return false;
}

bool   Fixed::operator>(const Fixed &rhs) const
{
    if (this->value > rhs.value)
        return true;
    return false;
}

bool   Fixed::operator<=(const Fixed &rhs) const
{
    if (this->value <= rhs.value)
        return true;
    return false;
}

bool   Fixed::operator>=(const Fixed &rhs) const
{
    if (this->value >= rhs.value)
        return true;
    return false;
}

bool   Fixed::operator==(const Fixed &rhs) const
{
    if (this->value == rhs.value)
        return true;
    return false;
}

bool   Fixed::operator!=(const Fixed &rhs) const
{
    if (this->value != rhs.value)
        return true;
    return false;
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

Fixed   &Fixed::min(Fixed &lhs, Fixed &rhs)
{
    if (lhs < rhs)
        return lhs;
    return rhs;
}

const Fixed   &Fixed::min(const Fixed &lhs, const Fixed &rhs)
{
    if (lhs < rhs)
        return lhs;
    return rhs;
}

Fixed   &Fixed::max(Fixed &lhs, Fixed &rhs)
{
    if (lhs > rhs)
        return lhs;
    return rhs;
}

const Fixed   &Fixed::max(const Fixed &lhs, const Fixed &rhs)
{
    if (lhs > rhs)
        return lhs;
    return rhs;
}
#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{

    private :

    int value;
    static const int bitNumbers = 8;

    public :

    Fixed(void);
    Fixed(const Fixed &rhs);
    Fixed   &operator=(const Fixed &rhs);
    ~Fixed(void);
    
    Fixed(const int num);
    Fixed(const float num);
    Fixed   &operator++(void);
    Fixed   operator++(int);
    Fixed   &operator--(void);
    Fixed   operator--(int);
    Fixed   operator+(const Fixed &rhs) const;
    Fixed   operator-(const Fixed &rhs) const;
    Fixed   operator*(const Fixed &rhs) const;
    Fixed   operator/(const Fixed &rhs) const;
    bool    operator<(const Fixed &rhs) const;
    bool    operator>(const Fixed &rhs) const;
    bool    operator<=(const Fixed &rhs) const;
    bool    operator>=(const Fixed &rhs) const;
    bool    operator==(const Fixed &rhs) const;
    bool    operator!=(const Fixed &rhs) const;

    static Fixed   &min(Fixed &lhs, Fixed &rhs);
    static const Fixed  &min(const Fixed &lhs, const Fixed &rhs);
    static Fixed   &max(Fixed &lhs, Fixed &rhs);
    static const Fixed  &max(const Fixed &lhs, const Fixed &rhs);
    int     getRawBits(void) const;
    void    setRawBits(int const raw);
    float   toFloat(void) const;
    int     toInt(void) const;
    
};

std::ostream    &operator<<(std::ostream &o, const Fixed &rhs);

#endif
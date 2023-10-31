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
    Fixed  &operator=(const Fixed &rhs);
    ~Fixed(void);

    Fixed(const int num);
    Fixed(const float num);

    int     getRawBits(void) const;
    void    setRawBits(int const raw);
    float   toFloat(void) const;
    int     toInt(void) const;
    
};

std::ostream    &operator<<(std::ostream &o, const Fixed &rhs);

#endif
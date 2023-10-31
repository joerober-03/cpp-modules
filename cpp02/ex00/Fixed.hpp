#ifndef FIXED_HPP
#define FIXED_HPP

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

    int     getRawBits(void) const;
    void    setRawBits(int const raw);
};

#endif
#include "Fixed.hpp"

int main( void )
{
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    Fixed c( Fixed( 10 ) + Fixed( 5 ) );
    Fixed d( Fixed( 10.1f ) - Fixed( 5.4f ) );
    Fixed e( Fixed( 100 ) / Fixed( 5 ) );

    if (b != a)
        std::cout << "b is not equal to a" << std::endl;
    if (d == d)
        std::cout << "d is equal to d" << std::endl;
    if (e > b)
        std::cout << "e is greater than b" << std::endl;
    if (a < b)
        std::cout << "a is not greater than b" << std::endl;
    if (c >= c)
        std::cout << "c is greater or equal to c" << std::endl;
    if (a <= a)
        std::cout << "a is equal or not greater than a" << std::endl;

    if (b != b)
        std::cout << "AAAAAAAAAAAAAAAAAAA" << std::endl;
    if (d == a)
        std::cout << "AAAAAAAAAAAAAAAAAAA" << std::endl;
    if (b > e)
        std::cout << "AAAAAAAAAAAAAAAAAAA" << std::endl;
    if (a < a)
        std::cout << "AAAAAAAAAAAAAAAAAAA" << std::endl;
    if (c >= e)
        std::cout << "AAAAAAAAAAAAAAAAAAA" << std::endl;
    if (b <= a)
        std::cout << "AAAAAAAAAAAAAAAAAAA" << std::endl;

    std::cout << std::endl;
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << --a << std::endl;
    std::cout << a << std::endl;
    std::cout << a-- << std::endl;
    std::cout << a << std::endl;
    std::cout << std::endl;

    std::cout << b << std::endl;
    std::cout << std::endl;

    std::cout << Fixed::min( a, b ) << std::endl;
    std::cout << Fixed::max( d, e ) << std::endl;
    
    return 0;
}
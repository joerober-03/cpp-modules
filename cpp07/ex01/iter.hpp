#include <iostream>

template < typename T > 
void    increment(T &c)
{
    c++;
}

template < typename T > 
void    decrement(T &c)
{
    c--;
}

template< typename T >
void    iter(T *str, size_t len, void (*func) (T &))
{
    size_t i = 0;
    while (i < len)
    {
        func(str[i]);
        i++;
    }
    i = 0;
    while (i < len)
    {
        std::cout << str[i] << " ";
        i++;
    }
    std::cout << std::endl;
}
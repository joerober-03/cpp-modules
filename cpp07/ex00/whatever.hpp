#pragma once

#include <iostream> 

template< typename T >
void    swap(T &x, T &y)
{
    T tmp;
    tmp = x;
    x = y;
    y = tmp;
}

template< typename T >
T   min(T const &x, T const &y)
{
    if (x < y)
        return (x);
    else
        return (y);
}

template< typename T >
T   max(T const &x, T const &y)
{
    if (x > y)
        return (x);
    else
        return (y);
}
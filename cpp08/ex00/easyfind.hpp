#pragma once

#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <deque>

class InstanceNotFound : public std::exception
{
    public:

    virtual const char* what() const throw()
    {
        return ("instance was not found");
    }
};

template < typename T >
void    easyfind(T cont, int i)
{
    typename T::const_iterator it;
    it = std::find(cont.begin(), cont.end(), i);
    if (it == cont.end())
       throw(InstanceNotFound());
    else
       std::cout << "instance found" << std::endl;
}
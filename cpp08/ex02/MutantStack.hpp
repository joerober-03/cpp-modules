#pragma once

#include <iostream>
#include <stack>
#include <list>

template <class T >
class MutantStack : public std::stack<T>
{
    private:

    public:

    typedef std::stack<T> stack;
    //code bellow accesses std::deque from container_type
    typedef typename MutantStack<T>::stack::container_type::iterator iterator;
    typedef typename MutantStack<T>::stack::container_type::reverse_iterator reverse_iterator;
    typedef typename MutantStack<T>::stack::container_type::const_iterator const_iterator;
    typedef typename MutantStack<T>::stack::container_type::const_reverse_iterator const_reverse_iterator;

    MutantStack(void)
    {
        //std::cout << "default MutantStack constructor called" << std::endl;
    }

    MutantStack(const MutantStack &rhs)
    {
        //std::cout << "MutantStack copy constructor called" << std::endl;
        *this = rhs;
    }

    MutantStack    &operator=(const MutantStack &rhs)
    {
        //std::cout << "MutantStack copy assignment operator called" << std::endl;
        this->stack = rhs.stack;
        return (*this);
    }

    ~MutantStack(void)
    {
        //std::cout << "MutantStack destructor called" << std::endl;
    }

    iterator begin()
    {
        return (stack::c.begin());
    }

    iterator end()
    {
        return (stack::c.end());
    }

    reverse_iterator rbegin()
    {
        return (stack::c.rbegin());
    }

    reverse_iterator rend()
    {
        return (stack::c.rend());
    }

    const_iterator begin() const
    {
        return (stack::c.begin());
    }

    const_iterator end() const
    {
        return (stack::c.end());
    }

    const_reverse_iterator rbegin() const
    {
        return (stack::c.rbegin());
    }

    const_reverse_iterator rend() const
    {
        return (stack::c.rend());
    }
};
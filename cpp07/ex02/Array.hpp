#pragma once

#include <iostream>

template < class T >
class Array
{
    private:

    T *array;
    unsigned int len;

    public:

    Array(void) : len(0)
    {
        //std::cout << "default Array constructor called" << std::endl;
        this->array = new T[this->len];
    }

    Array(const unsigned int i) : len(i)
    {
        //std::cout << "Array constructor called" << std::endl;
        this->array = new T[this->len];
    }

    Array(const Array &rhs)
    {
        //std::cout << "Array copy constructor called" << std::endl;
        *this = rhs;
    }

    Array &operator=(const Array &rhs)
    {
        //std::cout << "Array copy assignment operator called" << std::endl;
        this->len = rhs.len;
        this->array = new T[this->len];
        for (unsigned int i = 0; i < this->len; i++)
            this->array[i] = rhs.array[i];
        return (*this);
    }

    ~Array(void)
    {
        //std::cout << "Array destructor called" << std::endl;
        delete this->array;
    }

    class OutOfRange : public std::exception
    {
        public:
        
        virtual const char* what() const throw();
    };

    T &operator[](unsigned int i)
    {
        if (i >= this->len)
            throw (Array::OutOfRange());
        else
            return (this->array[i]);
    }

    unsigned int size(void) const
    {
        return (this->len);
    }

};

template< typename T >
const char* Array<T>::OutOfRange::what(void) const throw()
{
    return ("index is out of range !");
}
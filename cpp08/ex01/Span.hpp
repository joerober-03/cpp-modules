#pragma once

#include <vector>
#include <iostream>
#include <algorithm>
#include <unistd.h>

class Span
{
    private:

    const unsigned int N;
    std::vector<int> span;

    public:

    Span();
    Span(const Span &rhs);
    Span &operator=(const Span &rhs);
    ~Span();
    Span(unsigned int max);

    void    addNumber(const int num);
    void    addSeveralNumbers(const std::vector<int>::iterator begin, const std::vector<int>::iterator end);
    int shortestSpan(void);
    int longestSpan(void);

    class NoMoreSpace : public std::exception
    {
        public:

        virtual const char* what() const throw();
    };

    class NotEnoughNumbers : public std::exception
    {
        public:

        virtual const char* what() const throw();
    };

    //class InvalidValues : public std::exception
    //{
    //    public:
    //
    //    virtual const char* what() const throw();
    //};
};
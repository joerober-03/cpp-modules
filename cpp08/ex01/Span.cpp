#include "Span.hpp"

Span::Span(void) : N(0)
{
    //std::cout << "Span default constructor called" << std::endl;
}

Span::Span(const unsigned int max) : N(max)
{
    //std::cout << "Span constructor called" << std::endl;
}

Span::Span(const Span &rhs) : N(rhs.N)
{
    //std::cout << "Span copy constructor called" << std::endl;
    *this = rhs;
}

Span    &Span::operator=(const Span &rhs)
{
    //std::cout << "Span copy assignment operator called" << std::endl;
    this->span = rhs.span;
    return (*this);
}

Span::~Span(void)
{
    //std::cout << "Span destructor called" << std::endl;
}

void    Span::addNumber(const int num)
{
    if (this->span.size() < this->N)
    {
        this->span.push_back(num);
    }
    else
        throw (Span::NoMoreSpace());
}

//void    Span::addSeveralNumbers(int quantity, int min, int max)
//{
    //srand(time(NULL));
    //const int range  = (max - min) + 1;
    //if (quantity < 0 || (max - min) < 0)
    //    throw (Span::InvalidValues());
    //for (int i = 0; i < quantity; i++)
    //{
    //    if (this->span.size() < this->N)
    //    {
    //        this->span.push_back((rand() % range) + min);
    //    }
    //    else
    //        throw (Span::NoMoreSpace());
    //}
//}

void    Span::addSeveralNumbers(const std::vector<int>::iterator begin, const std::vector<int>::iterator end)
{
    int dist = std::distance(begin, end);
    if (static_cast<unsigned int>(dist) > this->N - this->span.size())
        throw (Span::NoMoreSpace());

    this->span.insert(this->span.begin(), begin, end);
}

int Span::shortestSpan(void)
{
    if (this->span.size() < 2)
        throw (Span::NotEnoughNumbers());
    std::vector<int> tmp;
    tmp = this->span;
    int minDiff = INT_MAX;

    sort(tmp.begin(), tmp.end());
    std::vector<int>::iterator it = tmp.begin();
	std::vector<int>::iterator it_next = tmp.begin() + 1;
	while (it_next != tmp.end())
    {
        if (*it_next - *it < minDiff)
            minDiff = *it_next - *it;
        ++it;
        ++it_next;
    }

    return (minDiff);
}

int Span::longestSpan(void)
{
    if (this->span.size() < 2)
        throw (Span::NotEnoughNumbers());
    std::vector<int> tmp;
    std::vector<int> tmp2;
    tmp = this->span;
    tmp2 = this->span;
    sort(tmp.rbegin(), tmp.rend());
    return (tmp[0] - tmp[this->span.size() - 1]);
}

const char* Span::NoMoreSpace::what(void) const throw()
{
    return ("vector is out of space !");
}

const char* Span::NotEnoughNumbers::what(void) const throw()
{
    return ("vector doesn't have enough numbers !");
}

//const char* Span::InvalidValues::what(void) const throw()
//{
//    return ("one or more values given to addSeveralValues are invalid !");
//}
#include "Brain.hpp"

Brain::Brain(void)
{
    std::cout << "default Brain constructor called" << std::endl;
    for (int i = 0; i < 100; i++)
        this->ideas[i] = "some random idea";
}

Brain::Brain(const Brain &rhs)
{
    std::cout << "Brain copy constructor called" << std::endl;
    *this = rhs;
}

Brain  &Brain::operator=(const Brain &rhs)
{
    std::cout << "Brain copy assignment operator called" << std::endl;
    for (int i = 0; i < 100; i++)
        this->ideas[i] = rhs.ideas[i] + "_copy";
    return(*this);
}

Brain::~Brain(void)
{
    std::cout << "Brain destructor called" << std::endl;
}

std::string Brain::getIdea(int i)
{
    return (this->ideas[i]);
}
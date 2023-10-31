#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{

    private:

    std::string ideas[100];

    protected:

    public:

    Brain(void);
    Brain(const Brain &rhs);
    Brain  &operator=(const Brain &rhs);
    ~Brain(void);

    std::string getIdea(int i);
};

#endif
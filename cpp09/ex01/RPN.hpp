#pragma once

#include <iostream>
#include <stack>

class RPN
{
    private:

    std::stack<float> stack;
    std::string input;

    void    plusOp(void);
    void    minusOp(void);
    void    divideOp(void);
    void    multOp(void);
    
    public:

    RPN(void);
    RPN(const std::string argv);
    RPN(const RPN &rhs);
    RPN &operator=(const RPN &rhs);
    ~RPN(void);

    class Error : public std::exception
    {
        public:

        virtual const char* what() const throw();
    };

    void    Calculate(void);
};
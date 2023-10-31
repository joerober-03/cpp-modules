#include "RPN.hpp"

RPN::RPN(void)
{
}

RPN::RPN(const std::string argv) : input(argv)
{
}

RPN::RPN(const RPN &rhs)
{
    *this = rhs;
}

RPN &RPN::operator=(const RPN &rhs)
{
    this->stack = rhs.stack;
    this->input = rhs.input;
    return (*this);
}

RPN::~RPN(void)
{
}

void    RPN::plusOp(void)
{
    if (this->stack.size() < 2)
        throw (RPN::Error());
    float x, y;
    x = this->stack.top();
    this->stack.pop();
    y = this->stack.top();
    this->stack.pop();
    this->stack.push(static_cast<float>(y) + static_cast<float>(x));
}

void    RPN::minusOp(void)
{
    if (this->stack.size() < 2)
        throw (RPN::Error());
    float x, y;
    x = this->stack.top();
    this->stack.pop();
    y = this->stack.top();
    this->stack.pop();
    this->stack.push(static_cast<float>(y) - static_cast<float>(x));
}

void    RPN::divideOp(void)
{
    if (this->stack.size() < 2)
        throw (RPN::Error());
    float x, y;
    x = this->stack.top();
    this->stack.pop();
    y = this->stack.top();
    this->stack.pop();
    this->stack.push(static_cast<float>(y) / static_cast<float>(x));
}

void    RPN::multOp(void)
{
    if (this->stack.size() < 2)
        throw (RPN::Error());
    float x, y;
    x = this->stack.top();
    this->stack.pop();
    y = this->stack.top();
    this->stack.pop();
    this->stack.push(static_cast<float>(y) * static_cast<float>(x));
}

void    RPN::Calculate(void)
{
    if (this->input.empty())
        throw (RPN::Error());
    int last;
    unsigned long i = 0;
    while (i < input.length())
    {
        while (isspace(input[i]) != 0)
            i++;
        if ((this->input[i] == '+' || this->input[i] == '-' || this->input[i] == '/' || this->input[i] == '*') && (this->input[i + 1] == 0 || this->input[i + 1] == 32))
        {
            if (this->input[i] == '+')
                plusOp();
            if (this->input[i] == '-')
                minusOp();
            if (this->input[i] == '/')
                divideOp();
            if (this->input[i] == '*')
                multOp();
            last = 0;
            i++;
        }
        else if (isdigit(this->input[i]) == 1 || this->input[i] == '-')
        {
            int j = i + 1;
            float num;
            while (isspace(input[j]) == 0 && input[j] != 0)
            {
                if (isdigit(this->input[j]) != 1)
                    throw (RPN::Error());
                j++;
            }
            try
            {
                num = stof(this->input.substr(i, (j - i)));
            }
            catch (...)
            {
                throw (RPN::Error());
            }
            this->stack.push(num);
            last = 1;
            i = j;
        }
        else if (this->input[i] != 0 && this->input[i] != 32)
            throw (RPN::Error());
    }
    if (last == 1 || this->stack.size() != 1)
        throw (RPN::Error());
    else
        std::cout << this->stack.top() << std::endl;
}

const char* RPN::Error::what() const throw()
{
    return ("Error");
}
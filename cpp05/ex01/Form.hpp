#pragma once
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:

    const std::string name;
    bool isSigned;
    const int signGrade;
    const int execGrade;

    public:
    
    Form();
    Form(const Form &rhs);
    Form &operator=(const Form &rhs);
    ~Form();
    Form(std::string name, int sign, int exec);

    int beSigned(const Bureaucrat &bureaucrat);

    std::string getName(void) const;
    unsigned int getExecGrade(void) const;
    unsigned int getSignGrade(void) const;
    bool getIsSigned(void) const;

    class GradeTooHighException : public std::exception
    {
        public:

        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
        public:
        
        virtual const char* what() const throw();
    };
};

std::ostream &operator<<(std::ostream &o, const Form &rhs);
#pragma once
#include <iostream>
#include <stdlib.h>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:

    const std::string name;
    bool isSigned;
    const int signGrade;
    const int execGrade;

    protected:

    public:
    
    AForm();
    AForm(const AForm &rhs);
    AForm &operator=(const AForm &rhs);
    virtual ~AForm();
    AForm(std::string name, int sign, int exec);

    int beSigned(const Bureaucrat &bureaucrat);
    virtual void execute(Bureaucrat const &executor) const = 0;

    std::string getName(void) const;
    int getExecGrade(void) const;
    int getSignGrade(void) const;
    bool getIsSigned(void) const;
    void setIsSigned(const bool &old);

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

    class FormNotSignedException : public std::exception
    {
        public:

        virtual const char* what() const throw();
    };
};

std::ostream &operator<<(std::ostream &o, const AForm &rhs);
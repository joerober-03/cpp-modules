#pragma once
#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat
{
    private:
    
    const std::string name;
    unsigned int grade;

    public:

    Bureaucrat();
    Bureaucrat(const Bureaucrat &rhs);
    Bureaucrat &operator=(const Bureaucrat &rhs);
    ~Bureaucrat();
    Bureaucrat(std::string name, int grade);

    std::string getName(void) const;
    int getGrade(void) const;

    void    signForm(Form &form) const;

    void    increment(void);
    void    decrement(void);

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

std::ostream &operator<<(std::ostream &o, const Bureaucrat &rhs);
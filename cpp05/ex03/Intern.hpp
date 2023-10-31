#pragma once

#include <iostream>
#include "AForm.hpp"

class Intern
{
    private:

    public:

    Intern();
    Intern(const Intern &rhs);
    Intern &operator=(const Intern &rhs);
    ~Intern();

    AForm *makeForm(const std::string formType, const std::string target);

    class UnknownFormException : public std::exception
    {
        public:

        virtual const char* what() const throw();
    };
};
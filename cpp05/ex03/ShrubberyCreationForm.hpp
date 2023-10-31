#pragma once

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
    private:
    
    const std::string target;

    public:

    ShrubberyCreationForm();
    ShrubberyCreationForm(const ShrubberyCreationForm &rhs);
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &rhs);
    ~ShrubberyCreationForm();
    ShrubberyCreationForm(const std::string target);

    void execute(Bureaucrat const &executor) const;
};
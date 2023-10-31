#pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    private:
    
    const std::string target;

    public:

    PresidentialPardonForm();
    PresidentialPardonForm(const PresidentialPardonForm &rhs);
    PresidentialPardonForm &operator=(const PresidentialPardonForm &rhs);
    ~PresidentialPardonForm();
    PresidentialPardonForm(const std::string target);

    void execute(Bureaucrat const &executor) const;
};
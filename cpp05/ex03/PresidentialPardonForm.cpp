#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("PresidentialPardonForm", 25, 5), target("default")
{
    //std::cout << "default PresidentialPardonForm constructor called" << std::endl;
    //this->isSigned = false;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm("PresidentialPardonForm", 25, 5), target(target)
{
    //std::cout << "PresidentialPardonForm constructor called" << std::endl;
    //this->isSigned = false;
}


PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &rhs) : AForm("PresidentialPardonForm", 25, 5), target(rhs.target)
{
    //std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
    *this = rhs;
}

PresidentialPardonForm  &PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs)
{
    //std::cout << "PresidentialPardonForm copy assignment operator called" << std::endl;
    this->setIsSigned(rhs.getIsSigned());
    return(*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
    //std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

void    PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
    (void)executor;
    
    std::cout << this->target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
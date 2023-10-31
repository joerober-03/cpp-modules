#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequestForm", 72, 45), target("default")
{
    //std::cout << "default RobotomyRequestForm constructor called" << std::endl;
    //this->isSigned = false;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("RobotomyRequestForm", 72, 45), target(target)
{
    //std::cout << "RobotomyRequestForm constructor called" << std::endl;
    //this->isSigned = false;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &rhs) : AForm("RobotomyRequestForm", 72, 45), target(rhs.target)
{
    //std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
    *this = rhs;
}

RobotomyRequestForm  &RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
{
    //std::cout << "RobotomyRequestForm copy assignment operator called" << std::endl;
    this->setIsSigned(rhs.getIsSigned());
    return(*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
    //std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

void    RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
    (void)executor;
    srand (time(NULL));
    int a = rand() % 2;

    std::cout << "bZZZZzzzzzZZZ" << std::endl;
    if (a == 0)
        std::cout << this->target << " has been successfully robotomized" << std::endl;
    else
        std::cout << "the robotomy failed..." << std::endl;
}
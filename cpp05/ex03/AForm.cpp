#include "AForm.hpp"

AForm::AForm(void) : name("default"), signGrade(150), execGrade(150)
{
    //std::cout << "default AForm constructor called" << std::endl;
    this->isSigned = false;
}

AForm::AForm(std::string name, int sign, int exec) : name(name), signGrade(sign), execGrade(exec)
{
    //std::cout << "AForm constructor called" << std::endl;
    this->isSigned = false;
    if (this->execGrade < 1 || this->signGrade < 1)
        throw (AForm::GradeTooHighException());
    else if (this->execGrade > 150 || this->signGrade > 150)
        throw (AForm::GradeTooLowException());
}

AForm::AForm(const AForm &rhs) : name(rhs.name), signGrade(rhs.signGrade), execGrade(rhs.execGrade)
{
    //std::cout << "AForm copy constructor called" << std::endl;
    *this = rhs;
}

AForm  &AForm::operator=(const AForm &rhs)
{
    //std::cout << "AForm copy assignment operator called" << std::endl;
    this->isSigned = rhs.isSigned;
    return(*this);
}

AForm::~AForm(void)
{
    //std::cout << "AForm destructor called" << std::endl;
}

int AForm::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() <= this->signGrade)
    {
        this->isSigned = true;
        return (1);
    }
    else
    {
        return (-1);
    }
}

std::string AForm::getName(void) const
{
    return (this->name);
}

int AForm::getExecGrade(void) const
{
    return (this->execGrade);
}

int AForm::getSignGrade(void) const
{
    return (this->signGrade);
}

bool	AForm::getIsSigned(void) const
{
	return (this->isSigned);
}

void    AForm::setIsSigned(const bool &old)
{
    this->isSigned = old;
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return ("Form grade is too high !");
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return ("Form grade is too low !");
}

const char* AForm::FormNotSignedException::what() const throw()
{
    return ("Form is not signed !");
}

std::ostream &operator<<(std::ostream &o, const AForm &rhs)
{
    o << "AForm name = " << rhs.getName() << std::endl;
    o << "AForm sign grade = " << rhs.getSignGrade() << std::endl;
    o << "AForm execution grade = " << rhs.getExecGrade() << std::endl;
    if (rhs.getIsSigned() == false)
        o << "AForm is not signed" << std::endl;
    else
        o << "AForm is signed" << std::endl;
    return (o);
}
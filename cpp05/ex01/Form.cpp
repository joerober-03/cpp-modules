#include "Form.hpp"

Form::Form(void) : name("default"), signGrade(150), execGrade(150)
{
    //std::cout << "default Form constructor called" << std::endl;
    this->isSigned = false;
}

Form::Form(std::string name, int sign, int exec) : name(name), signGrade(sign), execGrade(exec)
{
    //std::cout << "Form constructor called" << std::endl;
    this->isSigned = false;
    if (this->execGrade < 1 || this->signGrade < 1)
        throw (Form::GradeTooHighException());
    else if (this->execGrade > 150 || this->signGrade > 150)
        throw (Form::GradeTooLowException());
}

Form::Form(const Form &rhs) : name(rhs.name), signGrade(rhs.signGrade), execGrade(rhs.execGrade)
{
    //std::cout << "Form copy constructor called" << std::endl;
    *this = rhs;
}

Form  &Form::operator=(const Form &rhs)
{
    //std::cout << "Form copy assignment operator called" << std::endl;
    this->isSigned = rhs.isSigned;
    return(*this);
}

Form::~Form(void)
{
    //std::cout << "Form destructor called" << std::endl;
}

int Form::beSigned(const Bureaucrat &bureaucrat)
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

std::string Form::getName(void) const
{
    return (this->name);
}

unsigned int Form::getExecGrade(void) const
{
    return (this->execGrade);
}

unsigned int Form::getSignGrade(void) const
{
    return (this->signGrade);
}

bool	Form::getIsSigned(void) const
{
	return (this->isSigned);
}

const char* Form::GradeTooHighException::what() const throw()
{
    return ("Form grade is too high !");
}

const char* Form::GradeTooLowException::what() const throw()
{
    return ("Form grade is too low !");
}

std::ostream &operator<<(std::ostream &o, const Form &rhs)
{
    o << "Form name = " << rhs.getName() << std::endl;
    o << "Form sign grade = " << rhs.getSignGrade() << std::endl;
    o << "Form execution grade = " << rhs.getExecGrade() << std::endl;
    if (rhs.getIsSigned() == false)
        o << "The Form is not signed" << std::endl;
    else
        o << "The Form is signed" << std::endl;
    return (o);
}
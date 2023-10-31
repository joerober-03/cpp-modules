#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : name("default")
{
    //std::cout << "default Bureaucrat constructor called" << std::endl;
    this->grade = 150;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
    //std::cout << "Bureaucrat constructor called" << std::endl;
    this->grade = grade;
    if (grade < 1)
        throw (Bureaucrat::GradeTooHighException());
    else if (grade > 150)
        throw (Bureaucrat::GradeTooLowException());
}

Bureaucrat::Bureaucrat(const Bureaucrat &rhs) : name(rhs.name)
{
    //std::cout << "Bureaucrat copy constructor called" << std::endl;
    *this = rhs;
}

Bureaucrat  &Bureaucrat::operator=(const Bureaucrat &rhs)
{
   // std::cout << "Bureaucrat copy assignment operator called" << std::endl;
    this->grade = rhs.grade;
    return(*this);
}

Bureaucrat::~Bureaucrat(void)
{
    //std::cout << "Bureaucrat destructor called" << std::endl;
}

void    Bureaucrat::signForm(AForm &form) const
{
    if (form.getIsSigned() == true)
        std::cout << form.getName() << " is already signed !" << std::endl;
    else
    {
        if (form.beSigned(*this) == -1)
        {
            std::cout << this->name << " couldn't sign " << form.getName() << " because " << this->name << " doesn't have a grade high enough !" << std::endl;
            throw (AForm::GradeTooLowException());
        }
        else
            std::cout << this->name << " signed " << form.getName() << std::endl;
    }
}

void    Bureaucrat::executeForm(AForm const &executor) const
{
    if (executor.getIsSigned() == false)
    {
        throw(AForm::FormNotSignedException());

    }
    else if (this->getGrade() > executor.getExecGrade())
    {
        std::cout << this->name << " could not execute " << executor.getName() << " because his level is too low" << std::endl;
        throw(Bureaucrat::GradeTooLowException());
    }
    else
    {
        executor.execute(*this);
        std::cout << this->name << " executed " << executor.getName() << std::endl;
    }
}

std::string Bureaucrat::getName(void) const
{
    return (this->name);
}

int Bureaucrat::getGrade(void) const
{
    return (this->grade);
}

void    Bureaucrat::increment(void)
{
    if (this->grade > 1)
    {
        this->grade--;
        std::cout << "Bureaucrat grade incremented ! it is now " << this->grade << " !" << std::endl;
    }
    else
    {
        throw (Bureaucrat::GradeTooHighException());
    }
}

void    Bureaucrat::decrement(void)
{
    if (this->grade < 150)
    {
        this->grade++;
        std::cout << "Bureaucrat grade decremented ! it is now " << this->grade << " !" << std::endl;
    }
    else
    {
        throw (Bureaucrat::GradeTooLowException());
    }
}

const char* Bureaucrat::GradeTooHighException::what(void) const throw()
{
    return ("Bureaucrat grade is too high !");
}

const char* Bureaucrat::GradeTooLowException::what(void) const throw()
{
    return ("Bureaucrat grade is too low !");
}

std::ostream &operator<<(std::ostream &o, const Bureaucrat &rhs)
{
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return (o);
}
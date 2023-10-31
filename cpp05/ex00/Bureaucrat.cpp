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
    //std::cout << "Bureaucrat copy assignment operator called" << std::endl;
    this->grade = rhs.grade;
    return(*this);
}

Bureaucrat::~Bureaucrat(void)
{
    //std::cout << "Bureaucrat destructor called" << std::endl;
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
    return ("grade is too high !");
}

const char* Bureaucrat::GradeTooLowException::what(void) const throw()
{
    return ("grade is too low !");
}

std::ostream &operator<<(std::ostream &o, const Bureaucrat &rhs)
{
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return (o);
}
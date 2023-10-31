#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern(void)
{
    //std::cout << "default Intern constructor called" << std::endl;
}

Intern::Intern(const Intern &rhs)
{
    //std::cout << "Intern copy constructor called" << std::endl;
    *this = rhs;
}

Intern  &Intern::operator=(const Intern &rhs)
{
    //std::cout << "Intern copy assignment operator called" << std::endl;
    (void) &rhs;
    return(*this);
}

Intern::~Intern(void)
{
    //std::cout << "Intern destructor called" << std::endl;
}

AForm    *makeShrubbery(const std::string target)
{
    return (new ShrubberyCreationForm(target));
}

AForm    *makeRobotomy(const std::string target)
{
    return (new RobotomyRequestForm(target));
}

AForm    *makePresident(const std::string target)
{
    return (new PresidentialPardonForm(target));
}

const char* Intern::UnknownFormException::what() const throw()
{
    return ("Unknown Form Type !");
}

AForm *Intern::makeForm(const std::string formType, const std::string target)
{
    AForm *(*funcs[3])(std::string target) = { &makeShrubbery, &makeRobotomy, &makePresident};
    std::string types[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};

    int i = 0;
    while (i < 3 && types[i].compare(formType))
        i++;
    if (i < 3)
    {
        std::cout << "Intern creates " << formType << std::endl;
        return (funcs[i](target));
    }
    else
        std::cout << formType << " is not a valid form type" << std::endl;
    throw (Intern::UnknownFormException());
    return (NULL);
}

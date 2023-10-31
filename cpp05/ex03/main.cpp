#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
    try
	{
		Bureaucrat a("Judy", 1);
        Bureaucrat b;
        Bureaucrat c(a);
		std::cout << c << std::endl;
		std::cout << b << std::endl;
		std::cout << "Bureaucrat a's grade is " << a.getGrade() << std::endl;
        a.decrement();
		a.increment();
        c.decrement();
        b.increment();
        b.decrement();
		std::cout << "Bureaucrat b's grade is " << b.getGrade() << std::endl;
		std::cout << "Bureaucrat c's name is " << c.getName() << std::endl;
		a.increment();
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		Bureaucrat a("CEO", 1);
		Bureaucrat z("lower ranking employee", 98);
		Bureaucrat b(a);
		ShrubberyCreationForm scf("garden");
		RobotomyRequestForm rrf("john");
		PresidentialPardonForm ppf("juan");
		z.signForm(scf);
		z.executeForm(scf);
		a.signForm(rrf);
		a.executeForm(rrf);
		b.signForm(ppf);
		b.executeForm(ppf);
		z.executeForm(ppf);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << std::endl;
	try
	{
		Bureaucrat a("CEO", 5);
		Intern newIntern;
		AForm*	rrf;
		rrf = newIntern.makeForm("robotomy request", "Bender");
		AForm*	wrf;
		wrf = newIntern.makeForm("presidential pardon", "john");
		a.signForm(*rrf);
		a.signForm(*wrf);
		a.executeForm(*wrf);
		a.executeForm(*rrf);
		a.decrement();

		delete rrf;
		delete wrf;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		Bureaucrat b("Pascal", 99);
		Intern newIntern;
		AForm*	Form;
		Form = newIntern.makeForm("invalid_form", "sheesh");
		b.signForm(*Form);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
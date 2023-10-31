#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

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
		PresidentialPardonForm ppfc(ppf);
		z.signForm(scf);
		z.executeForm(scf);
		a.signForm(rrf);
		a.executeForm(rrf);
		b.signForm(ppf);
		b.executeForm(ppf);
		b.signForm(ppfc);
		z.executeForm(ppfc);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		Bureaucrat a("aaa", 5);
		PresidentialPardonForm test("test");
		std::cout << test << std::endl;
		a.signForm(test);
		PresidentialPardonForm test2(test);
		a.signForm(test2);
		a.decrement();
		a.executeForm(test2);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	

	return (0);
}
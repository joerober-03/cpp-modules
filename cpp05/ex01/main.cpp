#include "Bureaucrat.hpp"

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
		b.decrement();
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
		Form form("random form", 90, 140);
		Form sameForm(form);
		a.signForm(form);
		z.signForm(form);
		std::cout << sameForm;
		std::cout << form;
		z.signForm(sameForm);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		Form wrong("wrong", 1, 151);
		std::cout << wrong.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	

	return (0);
}
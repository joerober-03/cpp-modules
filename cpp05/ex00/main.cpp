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
		Bureaucrat wrong("wrong", 0);
		wrong.getName();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		Bureaucrat wrong2("wrong2", 151);
		wrong2.getGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	return (0);
}
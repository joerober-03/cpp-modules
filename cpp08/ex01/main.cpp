#include "Span.hpp"

int main()
{
    try
    {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
        sp.addNumber(2);
    }
    catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
    std::cout << std::endl;
    try
    {
        srand(time(NULL));
        Span sp = Span(100000);
        std::vector<int> range;
        for (int i = 0; i < 20; i++)
            range.push_back(rand() % INT_MAX);
        sp.addSeveralNumbers(range.begin(), range.end());
        Span sp2(sp);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
        std::cout << sp2.shortestSpan() << std::endl;
        std::cout << sp2.longestSpan() << std::endl;
        range.clear();
        for (int i = 0; i < 20000; i++) //99981 would be too high
            range.push_back(rand() % INT_MAX);
        sp.addSeveralNumbers(range.begin(), range.end());
        range.clear();
        for (int i = 0; i < 727; i++)
            range.push_back(rand() % INT_MAX);
        sp2.addSeveralNumbers(range.begin(), range.end());
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
        std::cout << sp2.shortestSpan() << std::endl;
        std::cout << sp2.longestSpan() << std::endl;
    }
    catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
    std::cout << std::endl;
    try
    {
        Span sp = Span(20);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
    return 0;
}
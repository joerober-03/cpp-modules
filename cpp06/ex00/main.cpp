#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    (void) argv;
    if (argc != 2)
        std::cout << "Wrong number of arguments" << std::endl << "ex: ./Convert \"*\"" << std::endl;
    else
    {
        try
        {
            ScalarConverter::convert(argv[1]);
        }
        catch (std::exception & e)
	    {
		    std::cerr << e.what() << std::endl;
	    }
    }
    return 0;
}
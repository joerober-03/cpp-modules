#include "RPN.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "The program needs one argument, ex: ./RPN \"8 9 *\"" << std::endl;
        return (1);
    }
    try
    {
        RPN rpn(argv[1]);
        rpn.Calculate();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}
#include "Harl.hpp"

int main(int argc, char **argv)
{
    Harl harl;

    if (argc != 2)
    {
        std::cout << "wrong number of args" << std::endl;
        return (1);
    }
    std::string str(argv[1]);
    harl.complain(str);
}
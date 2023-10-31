#include "Harl.hpp"

int main()
{
    Harl harl;

    std::cout << "*debug* ⌄⌄⌄" << std::endl;
    harl.complain("DEBUG");
    std::cout << "*info* ⌄⌄⌄" << std::endl;
    harl.complain("INFO");
    std::cout << "*warning* ⌄⌄⌄" << std::endl;
    harl.complain("WARNING");
    std::cout << "*error* ⌄⌄⌄" << std::endl;
    harl.complain("ERROR");
    std::cout << "*invalid* ⌄⌄⌄" << std::endl;
    harl.complain("INVALID");
}